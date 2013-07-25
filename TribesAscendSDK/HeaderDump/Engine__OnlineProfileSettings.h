#pragma once
#include "Engine__OnlinePlayerStorage.h"
namespace UnrealScript
{
	class OnlineProfileSettings : public OnlinePlayerStorage
	{
	public:
		bool GetProfileSettingDefaultId(int ProfileSettingId, int& DefaultId, int& ListIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineProfileSettings.GetProfileSettingDefaultId");
			byte* params = (byte*)malloc(16);
			*(int*)params = ProfileSettingId;
			*(int*)(params + 4) = DefaultId;
			*(int*)(params + 8) = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DefaultId = *(int*)(params + 4);
			ListIndex = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingDefaultInt(int ProfileSettingId, int& DefaultInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineProfileSettings.GetProfileSettingDefaultInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			*(int*)(params + 4) = DefaultInt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DefaultInt = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingDefaultFloat(int ProfileSettingId, float& DefaultFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineProfileSettings.GetProfileSettingDefaultFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			*(float*)(params + 4) = DefaultFloat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			DefaultFloat = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetToDefaults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineProfileSettings.SetToDefaults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AppendVersionToReadIds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineProfileSettings.AppendVersionToReadIds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyAvailableProfileSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineProfileSettings.ModifyAvailableProfileSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
