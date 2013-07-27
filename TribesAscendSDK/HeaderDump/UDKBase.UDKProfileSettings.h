#pragma once
#include "Engine.OnlineProfileSettings.h"
#include "Engine.LocalPlayer.h"
namespace UnrealScript
{
	class UDKProfileSettings : public OnlineProfileSettings
	{
	public:
		void ResetToDefault(int ProfileId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKProfileSettings.ResetToDefault");
			byte params[4] = { NULL };
			*(int*)&params[0] = ProfileId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetKeysToDefault(class LocalPlayer* InPlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKProfileSettings.ResetKeysToDefault");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = InPlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
