#pragma once
#include "Core.Object.h"
#include "Engine.GameInfo.h"
namespace UnrealScript
{
	class Settings : public Object
	{
	public:
		void UpdateFromURL(ScriptArray<wchar_t>& URL, class GameInfo* Game)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.UpdateFromURL");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = URL;
			*(class GameInfo**)(params + 12) = Game;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void BuildURL(ScriptArray<wchar_t>& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.BuildURL");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void AppendContextsToURL(ScriptArray<wchar_t>& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.AppendContextsToURL");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void AppendPropertiesToURL(ScriptArray<wchar_t>& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.AppendPropertiesToURL");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void AppendDataBindingsToURL(ScriptArray<wchar_t>& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.AppendDataBindingsToURL");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			URL = *(ScriptArray<wchar_t>*)params;
			free(params);
		}
		void GetQoSAdvertisedStringSettings(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& QoSSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetQoSAdvertisedStringSettings");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = QoSSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			QoSSettings = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void GetQoSAdvertisedProperties(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& QoSProps)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetQoSAdvertisedProperties");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = QoSProps;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			QoSProps = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		bool GetRangedPropertyValue(int PropertyId, float& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetRangedPropertyValue");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropertyId;
			*(float*)(params + 4) = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutValue = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetRangedPropertyValue(int PropertyId, float NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetRangedPropertyValue");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropertyId;
			*(float*)(params + 4) = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetPropertyRange(int PropertyId, float& OutMinValue, float& OutMaxValue, float& RangeIncrement, byte& bFormatAsInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyRange");
			byte* params = (byte*)malloc(21);
			*(int*)params = PropertyId;
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
		bool GetPropertyMappingType(int PropertyId, byte& OutType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyMappingType");
			byte* params = (byte*)malloc(9);
			*(int*)params = PropertyId;
			*(params + 4) = OutType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutType = *(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool HasStringSetting(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.HasStringSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool HasProperty(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.HasProperty");
			byte* params = (byte*)malloc(8);
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateProperties(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Props, bool bShouldAddIfMissing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.UpdateProperties");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Props;
			*(bool*)(params + 12) = bShouldAddIfMissing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Props = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void UpdateStringSettings(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Settings, bool bShouldAddIfMissing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.UpdateStringSettings");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Settings;
			*(bool*)(params + 12) = bShouldAddIfMissing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Settings = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		byte GetPropertyType(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyType");
			byte* params = (byte*)malloc(5);
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		bool GetPropertyValueId(int PropertyId, int& ValueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyValueId");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropertyId;
			*(int*)(params + 4) = ValueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueId = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetPropertyValueId(int PropertyId, int ValueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetPropertyValueId");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropertyId;
			*(int*)(params + 4) = ValueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetStringProperty(int PropertyId, ScriptArray<wchar_t>& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringProperty");
			byte* params = (byte*)malloc(20);
			*(int*)params = PropertyId;
			*(ScriptArray<wchar_t>*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void SetStringProperty(int PropertyId, ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringProperty");
			byte* params = (byte*)malloc(16);
			*(int*)params = PropertyId;
			*(ScriptArray<wchar_t>*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetIntProperty(int PropertyId, int& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetIntProperty");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropertyId;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetIntProperty(int PropertyId, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetIntProperty");
			byte* params = (byte*)malloc(8);
			*(int*)params = PropertyId;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetFloatProperty(int PropertyId, float& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetFloatProperty");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropertyId;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetFloatProperty(int PropertyId, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetFloatProperty");
			byte* params = (byte*)malloc(8);
			*(int*)params = PropertyId;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool SetPropertyFromStringByName(ScriptName PropertyName, ScriptArray<wchar_t>& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetPropertyFromStringByName");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = PropertyName;
			*(ScriptArray<wchar_t>*)(params + 8) = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewValue = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPropertyAsStringByName(ScriptName PropertyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyAsStringByName");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = PropertyName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPropertyAsString(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyAsString");
			byte* params = (byte*)malloc(16);
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPropertyColumnHeader(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyColumnHeader");
			byte* params = (byte*)malloc(16);
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptName GetPropertyName(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyName");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetPropertyId(ScriptName PropertyName, int& PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyId");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = PropertyName;
			*(int*)(params + 8) = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PropertyId = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool SetStringSettingValueFromStringByName(ScriptName StringSettingName, ScriptArray<wchar_t>& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringSettingValueFromStringByName");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = StringSettingName;
			*(ScriptArray<wchar_t>*)(params + 8) = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			NewValue = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptName GetStringSettingValueNameByName(ScriptName StringSettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueNameByName");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = StringSettingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName GetStringSettingValueName(int StringSettingId, int ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueName");
			byte* params = (byte*)malloc(16);
			*(int*)params = StringSettingId;
			*(int*)(params + 4) = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsWildcardStringSetting(int StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.IsWildcardStringSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetStringSettingColumnHeader(int StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingColumnHeader");
			byte* params = (byte*)malloc(16);
			*(int*)params = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptName GetStringSettingName(int StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingName");
			byte* params = (byte*)malloc(12);
			*(int*)params = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		bool GetStringSettingId(ScriptName StringSettingName, int& StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingId");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = StringSettingName;
			*(int*)(params + 8) = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			StringSettingId = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetStringSettingValueByName(ScriptName StringSettingName, int& ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueByName");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = StringSettingName;
			*(int*)(params + 8) = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueIndex = *(int*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetStringSettingValueByName(ScriptName StringSettingName, int ValueIndex, bool bShouldAutoAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringSettingValueByName");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = StringSettingName;
			*(int*)(params + 8) = ValueIndex;
			*(bool*)(params + 12) = bShouldAutoAdd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetStringSettingValueNames(int StringSettingId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Values)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueNames");
			byte* params = (byte*)malloc(20);
			*(int*)params = StringSettingId;
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
		bool IncrementStringSettingValue(int StringSettingId, int Direction, bool bShouldWrap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.IncrementStringSettingValue");
			byte* params = (byte*)malloc(16);
			*(int*)params = StringSettingId;
			*(int*)(params + 4) = Direction;
			*(bool*)(params + 8) = bShouldWrap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool GetStringSettingValue(int StringSettingId, int& ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValue");
			byte* params = (byte*)malloc(12);
			*(int*)params = StringSettingId;
			*(int*)(params + 4) = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ValueIndex = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetStringSettingValue(int StringSettingId, int ValueIndex, bool bShouldAutoAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringSettingValue");
			byte* params = (byte*)malloc(12);
			*(int*)params = StringSettingId;
			*(int*)(params + 4) = ValueIndex;
			*(bool*)(params + 8) = bShouldAutoAdd;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetSettingsDataDateTime(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, int& OutInt1, int& OutInt2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataDateTime");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(int*)(params + 12) = OutInt1;
			*(int*)(params + 16) = OutInt2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			OutInt1 = *(int*)(params + 12);
			OutInt2 = *(int*)(params + 16);
			free(params);
		}
		void GetSettingsDataBlob(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataBlob");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = OutBlob;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			OutBlob = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
		}
		int GetSettingsDataInt(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataInt");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetSettingsDataFloat(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataFloat");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSettingsDataString(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataString");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void EmptySettingsData(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.EmptySettingsData");
			byte* params = (byte*)malloc(12);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			free(params);
		}
		void SetSettingsData(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data2Copy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsData");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)(params + 12) = Data2Copy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			Data2Copy = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)(params + 12);
			free(params);
		}
		void SetSettingsDataBlob(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& InBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataBlob");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = InBlob;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			InBlob = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
		}
		void SetSettingsDataDateTime(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, int InInt1, int InInt2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataDateTime");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(int*)(params + 12) = InInt1;
			*(int*)(params + 16) = InInt2;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			free(params);
		}
		void SetSettingsDataInt(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataInt");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(int*)(params + 12) = InInt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			free(params);
		}
		void SetSettingsDataFloat(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataFloat");
			byte* params = (byte*)malloc(16);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(float*)(params + 12) = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			free(params);
		}
		void SetSettingsDataString(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void*& Data, ScriptArray<wchar_t> InString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataString");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params = Data;
			*(ScriptArray<wchar_t>*)(params + 12) = InString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Data = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Settings.SettingsData'!
void**)params;
			free(params);
		}
	};
}
