#pragma once
#include "TribesGame.TrDevice.h"
#include "Engine.Projectile.h"
namespace UnrealScript
{
	class TrDevice_SN7 : public TrDevice
	{
	public:
		class Projectile* ProjectileFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_SN7.ProjectileFire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Projectile**)params;
			free(params);
			return returnVal;
		}
	};
}
