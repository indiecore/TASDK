#pragma once
#include "Engine__UIDataStore_StringBase.h"
namespace UnrealScript
{
	class UIDataStore_InputAlias : public UIDataStore_StringBase
	{
	public:
		ScriptArray<wchar_t> GetAliasFontMarkup(ScriptName DesiredAlias, byte OverridePlatform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.GetAliasFontMarkup");
			byte* params = (byte*)malloc(21);
			*(ScriptName*)params = DesiredAlias;
			*(params + 8) = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetAliasFontMarkupByIndex(int AliasIndex, byte OverridePlatform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.GetAliasFontMarkupByIndex");
			byte* params = (byte*)malloc(17);
			*(int*)params = AliasIndex;
			*(params + 4) = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName GetAliasInputKeyName(ScriptName DesiredAlias, byte OverridePlatform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.GetAliasInputKeyName");
			byte* params = (byte*)malloc(17);
			*(ScriptName*)params = DesiredAlias;
			*(params + 8) = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptName GetAliasInputKeyNameByIndex(int AliasIndex, byte OverridePlatform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.GetAliasInputKeyNameByIndex");
			byte* params = (byte*)malloc(13);
			*(int*)params = AliasIndex;
			*(params + 4) = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetAliasInputKeyData(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.RawInputKeyEventData'!
void*& out_InputKeyData, ScriptName DesiredAlias, byte OverridePlatform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.GetAliasInputKeyData");
			byte* params = (byte*)malloc(25);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.RawInputKeyEventData'!
void**)params = out_InputKeyData;
			*(ScriptName*)(params + 12) = DesiredAlias;
			*(params + 20) = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_InputKeyData = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.RawInputKeyEventData'!
void**)params;
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool GetAliasInputKeyDataByIndex(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.RawInputKeyEventData'!
void*& out_InputKeyData, int AliasIndex, byte OverridePlatform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.GetAliasInputKeyDataByIndex");
			byte* params = (byte*)malloc(21);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.RawInputKeyEventData'!
void**)params = out_InputKeyData;
			*(int*)(params + 12) = AliasIndex;
			*(params + 16) = OverridePlatform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_InputKeyData = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.UIRoot.RawInputKeyEventData'!
void**)params;
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		int FindInputAliasIndex(ScriptName DesiredAlias)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.FindInputAliasIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = DesiredAlias;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool HasAliasMappingForPlatform(ScriptName DesiredAlias, byte DesiredPlatform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataStore_InputAlias.HasAliasMappingForPlatform");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = DesiredAlias;
			*(params + 8) = DesiredPlatform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
