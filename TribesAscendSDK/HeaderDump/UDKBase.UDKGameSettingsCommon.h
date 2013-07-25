#pragma once
#include "Engine.OnlineGameSettings.h"
namespace UnrealScript
{
	class UDKGameSettingsCommon : public OnlineGameSettings
	{
	public:
		bool StringToBlob(ScriptArray<wchar_t>& InString, ScriptArray<wchar_t>& OutBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameSettingsCommon.StringToBlob");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = InString;
			*(ScriptArray<wchar_t>*)(params + 12) = OutBlob;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InString = *(ScriptArray<wchar_t>*)params;
			OutBlob = *(ScriptArray<wchar_t>*)(params + 12);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> BlobToString(ScriptArray<wchar_t>& InBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameSettingsCommon.BlobToString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = InBlob;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InBlob = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
