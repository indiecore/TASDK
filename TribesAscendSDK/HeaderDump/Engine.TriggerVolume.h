#pragma once
#include "Engine.Projectile.h"
#include "Engine.Volume.h"
namespace UnrealScript
{
	class TriggerVolume : public Volume
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TriggerVolume.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.TriggerVolume.StopsProjectile");
			byte* params = (byte*)malloc(8);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
