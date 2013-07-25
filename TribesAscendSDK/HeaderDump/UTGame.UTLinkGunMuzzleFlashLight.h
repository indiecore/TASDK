#pragma once
#include "UDKBase.UDKExplosionLight.h"
namespace UnrealScript
{
	class UTLinkGunMuzzleFlashLight : public UDKExplosionLight
	{
	public:
		void SetTeam(byte NewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTLinkGunMuzzleFlashLight.SetTeam");
			byte* params = (byte*)malloc(1);
			*params = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
