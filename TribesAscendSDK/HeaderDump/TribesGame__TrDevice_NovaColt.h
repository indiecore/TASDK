#pragma once
#include "TribesGame__TrDevice.h"
namespace UnrealScript
{
	class TrDevice_NovaColt : public TrDevice
	{
	public:
		bool ShouldRefire()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_NovaColt.ShouldRefire");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void FireAmmunition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_NovaColt.FireAmmunition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrDevice_NovaColt.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
