#pragma once
#include "Core.Object.Vector.h"
#include "TribesGame.TrProj_Mine.h"
namespace UnrealScript
{
	class TrProj_MotionSensor : public TrProj_Mine
	{
	public:
		void Explode(Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MotionSensor.Explode");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = HitLocation;
			*(Vector*)(params + 12) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetonateObsolete(bool bDetonateFromDamage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrProj_MotionSensor.DetonateObsolete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDetonateFromDamage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
