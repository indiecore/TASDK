#pragma once
#include "Engine__OnlineProfileSettings.h"
#include "Engine__LocalPlayer.h"
namespace UnrealScript
{
	class UDKProfileSettings : public OnlineProfileSettings
	{
	public:
		void ResetToDefault(int ProfileId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKProfileSettings.ResetToDefault");
			byte* params = (byte*)malloc(4);
			*(int*)params = ProfileId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetKeysToDefault(class LocalPlayer* InPlayerOwner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKProfileSettings.ResetKeysToDefault");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayerOwner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
