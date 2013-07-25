#pragma once
#include "TribesGame__TrDevice.h"
namespace UnrealScript
{
	class TrDevice_NovaSlug : public TrDevice
	{
	public:
		void InstantFire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_NovaSlug.InstantFire");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_NovaSlug.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_NovaSlug.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
