#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.OnlinePlayerStorage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlinePlayerStorage : public Object
	{
	public:
		ADD_VAR(::IntProperty, DeviceID, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AsyncState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VersionNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VersionSettingsId, 0xFFFFFFFF)
		bool GetProfileSettingId(ScriptName ProfileSettingName, int& ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingId");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = ProfileSettingName;
			*(int*)(params + 8) = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ProfileSettingId = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptName GetProfileSettingName(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingName");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetProfileSettingColumnHeader(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingColumnHeader");
			byte* params = (byte*)malloc(16);
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		int FindProfileSettingIndex(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindProfileSettingIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int FindProfileMappingIndex(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindProfileMappingIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int FindProfileMappingIndexByName(ScriptName ProfileSettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindProfileMappingIndexByName");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ProfileSettingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int FindDefaultProfileMappingIndexByName(ScriptName ProfileSettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindDefaultProfileMappingIndexByName");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ProfileSettingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsProfileSettingIdMapped(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.IsProfileSettingIdMapped");
			byte* params = (byte*)malloc(8);
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingValue(int ProfileSettingId, ScriptArray<wchar_t>& Value, int ValueMapID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValue");
			byte* params = (byte*)malloc(24);
			*(int*)params = ProfileSettingId;
			*(ScriptArray<wchar_t>*)(params + 4) = Value;
			*(int*)(params + 16) = ValueMapID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptName GetProfileSettingValueName(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueName");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingValues(int ProfileSettingId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Values)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValues");
			byte* params = (byte*)malloc(20);
			*(int*)params = ProfileSettingId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Values;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Values = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingValueByName(ScriptName ProfileSettingName, ScriptArray<wchar_t>& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueByName");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ProfileSettingName;
			*(ScriptArray<wchar_t>*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool SetProfileSettingValueByName(ScriptName ProfileSettingName, ScriptArray<wchar_t>& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueByName");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = ProfileSettingName;
			*(ScriptArray<wchar_t>*)(params + 8) = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewValue = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool SetProfileSettingValue(int ProfileSettingId, ScriptArray<wchar_t>& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValue");
			byte* params = (byte*)malloc(20);
			*(int*)params = ProfileSettingId;
			*(ScriptArray<wchar_t>*)(params + 4) = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewValue = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingValueId(int ProfileSettingId, int& ValueId, int& ListIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueId");
			byte* params = (byte*)malloc(16);
			*(int*)params = ProfileSettingId;
			*(int*)(params + 4) = ValueId;
			*(int*)(params + 8) = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueId = *(int*)(params + 4);
			ListIndex = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingValueFromListIndex(int ProfileSettingId, int ListIndex, int& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueFromListIndex");
			byte* params = (byte*)malloc(16);
			*(int*)params = ProfileSettingId;
			*(int*)(params + 4) = ListIndex;
			*(int*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingValueInt(int ProfileSettingId, int& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingValueFloat(int ProfileSettingId, float& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetProfileSettingValueId(int ProfileSettingId, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueId");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetProfileSettingValueInt(int ProfileSettingId, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetProfileSettingValueFloat(int ProfileSettingId, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileSettingId;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingMappingType(int ProfileId, byte& OutType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingMappingType");
			byte* params = (byte*)malloc(9);
			*(int*)params = ProfileId;
			*(params + 4) = OutType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutType = *(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingMappingIds(int ProfileId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Ids)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingMappingIds");
			byte* params = (byte*)malloc(20);
			*(int*)params = ProfileId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = Ids;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Ids = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetProfileSettingRange(int ProfileId, float& OutMinValue, float& OutMaxValue, float& RangeIncrement, byte& bFormatAsInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingRange");
			byte* params = (byte*)malloc(21);
			*(int*)params = ProfileId;
			*(float*)(params + 4) = OutMinValue;
			*(float*)(params + 8) = OutMaxValue;
			*(float*)(params + 12) = RangeIncrement;
			*(params + 16) = bFormatAsInt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutMinValue = *(float*)(params + 4);
			OutMaxValue = *(float*)(params + 8);
			RangeIncrement = *(float*)(params + 12);
			bFormatAsInt = *(params + 16);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool SetRangedProfileSettingValue(int ProfileId, float NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetRangedProfileSettingValue");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileId;
			*(float*)(params + 4) = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetRangedProfileSettingValue(int ProfileId, float& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetRangedProfileSettingValue");
			byte* params = (byte*)malloc(12);
			*(int*)params = ProfileId;
			*(float*)(params + 4) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddSettingInt(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.AddSettingInt");
			byte* params = (byte*)malloc(4);
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddSettingFloat(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.AddSettingFloat");
			byte* params = (byte*)malloc(4);
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetToDefaults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetToDefaults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AppendVersionToSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.AppendVersionToSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetVersionNumber()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetVersionNumber");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SetDefaultVersionNumber()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetDefaultVersionNumber");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
