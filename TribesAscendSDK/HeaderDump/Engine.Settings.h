#pragma once
#include "Core.Object.h"
#include "Engine.GameInfo.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Settings : public Object
	{
	public:
		enum EOnlineDataAdvertisementType : byte
		{
			ODAT_DontAdvertise = 0,
			ODAT_OnlineService = 1,
			ODAT_QoS = 2,
			ODAT_OnlineServiceAndQoS = 3,
			ODAT_MAX = 4,
		};
		enum ESettingsDataType : byte
		{
			SDT_Empty = 0,
			SDT_Int32 = 1,
			SDT_Int64 = 2,
			SDT_Double = 3,
			SDT_String = 4,
			SDT_Float = 5,
			SDT_Blob = 6,
			SDT_DateTime = 7,
			SDT_MAX = 8,
		};
		enum EPropertyValueMappingType : byte
		{
			PVMT_RawValue = 0,
			PVMT_PredefinedValues = 1,
			PVMT_Ranged = 2,
			PVMT_IdMapped = 3,
			PVMT_MAX = 4,
		};
		class IdToStringMapping
		{
		public:
			ADD_STRUCT(int, Id, 0)
			ADD_STRUCT(ScriptName, Name, 4)
		};
		class StringIdToStringMapping
		{
		public:
			ADD_STRUCT(int, Id, 0)
			ADD_STRUCT(ScriptName, Name, 4)
			ADD_BOOL(bIsWildcard, 12, 0x1)
		};
		class LocalizedStringSetting
		{
		public:
			ADD_STRUCT(int, Id, 0)
			ADD_STRUCT(int, ValueIndex, 4)
			ADD_STRUCT(Settings::EOnlineDataAdvertisementType, AdvertisementType, 8)
		};
		class SettingsData
		{
		public:
			ADD_STRUCT(Settings::ESettingsDataType, Type, 0)
			ADD_STRUCT(int, Value1, 4)
			ADD_STRUCT(Object::Pointer, Value2, 8)
		};
		class LocalizedStringSettingMetaData
		{
		public:
			ADD_STRUCT(int, Id, 0)
			ADD_STRUCT(ScriptName, Name, 4)
			ADD_STRUCT(ScriptString*, ColumnHeaderText, 12)
			ADD_STRUCT(ScriptArray<Settings::StringIdToStringMapping>, ValueMappings, 24)
		};
		class SettingsPropertyPropertyMetaData
		{
		public:
			ADD_STRUCT(int, Id, 0)
			ADD_STRUCT(ScriptName, Name, 4)
			ADD_STRUCT(ScriptString*, ColumnHeaderText, 12)
			ADD_STRUCT(Settings::EPropertyValueMappingType, MappingType, 24)
			ADD_STRUCT(ScriptArray<Settings::IdToStringMapping>, ValueMappings, 28)
			ADD_STRUCT(ScriptArray<Settings::SettingsData>, PredefinedValues, 40)
			ADD_STRUCT(float, MinVal, 52)
			ADD_STRUCT(float, MaxVal, 56)
			ADD_STRUCT(float, RangeIncrement, 60)
		};
		class SettingsProperty
		{
		public:
			ADD_STRUCT(int, PropertyId, 0)
			ADD_STRUCT(Settings::SettingsData, Data, 4)
			ADD_STRUCT(Settings::EOnlineDataAdvertisementType, AdvertisementType, 16)
		};
		ADD_STRUCT(ScriptArray<Settings::LocalizedStringSetting>, LocalizedSettings, 60)
		ADD_STRUCT(ScriptArray<Settings::SettingsProperty>, Properties, 72)
		ADD_STRUCT(ScriptArray<Settings::LocalizedStringSettingMetaData>, LocalizedSettingsMappings, 84)
		ADD_STRUCT(ScriptArray<Settings::SettingsPropertyPropertyMetaData>, PropertyMappings, 96)
		void UpdateFromURL(ScriptString*& URL, class GameInfo* Game)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.UpdateFromURL");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = URL;
			*(class GameInfo**)&params[12] = Game;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)&params[0];
		}
		void BuildURL(ScriptString*& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.BuildURL");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)&params[0];
		}
		void AppendContextsToURL(ScriptString*& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.AppendContextsToURL");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)&params[0];
		}
		void AppendPropertiesToURL(ScriptString*& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.AppendPropertiesToURL");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)&params[0];
		}
		void AppendDataBindingsToURL(ScriptString*& URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.AppendDataBindingsToURL");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			URL = *(ScriptString**)&params[0];
		}
		void GetQoSAdvertisedStringSettings(ScriptArray<Settings::LocalizedStringSetting>& QoSSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetQoSAdvertisedStringSettings");
			byte params[12] = { NULL };
			*(ScriptArray<Settings::LocalizedStringSetting>*)&params[0] = QoSSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			QoSSettings = *(ScriptArray<Settings::LocalizedStringSetting>*)&params[0];
		}
		void GetQoSAdvertisedProperties(ScriptArray<Settings::SettingsProperty>& QoSProps)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetQoSAdvertisedProperties");
			byte params[12] = { NULL };
			*(ScriptArray<Settings::SettingsProperty>*)&params[0] = QoSProps;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			QoSProps = *(ScriptArray<Settings::SettingsProperty>*)&params[0];
		}
		bool GetRangedPropertyValue(int PropertyId, float& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetRangedPropertyValue");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(float*)&params[4] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		bool SetRangedPropertyValue(int PropertyId, float NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetRangedPropertyValue");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(float*)&params[4] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetPropertyRange(int PropertyId, float& OutMinValue, float& OutMaxValue, float& RangeIncrement, byte& bFormatAsInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyRange");
			byte params[21] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(float*)&params[4] = OutMinValue;
			*(float*)&params[8] = OutMaxValue;
			*(float*)&params[12] = RangeIncrement;
			params[16] = bFormatAsInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutMinValue = *(float*)&params[4];
			OutMaxValue = *(float*)&params[8];
			RangeIncrement = *(float*)&params[12];
			bFormatAsInt = params[16];
			return *(bool*)&params[20];
		}
		bool GetPropertyMappingType(int PropertyId, Settings::EPropertyValueMappingType& OutType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyMappingType");
			byte params[9] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(Settings::EPropertyValueMappingType*)&params[4] = OutType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutType = *(Settings::EPropertyValueMappingType*)&params[4];
			return *(bool*)&params[8];
		}
		bool HasStringSetting(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.HasStringSetting");
			byte params[8] = { NULL };
			*(int*)&params[0] = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool HasProperty(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.HasProperty");
			byte params[8] = { NULL };
			*(int*)&params[0] = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void UpdateProperties(ScriptArray<Settings::SettingsProperty>& Props, bool bShouldAddIfMissing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.UpdateProperties");
			byte params[16] = { NULL };
			*(ScriptArray<Settings::SettingsProperty>*)&params[0] = Props;
			*(bool*)&params[12] = bShouldAddIfMissing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Props = *(ScriptArray<Settings::SettingsProperty>*)&params[0];
		}
		void UpdateStringSettings(ScriptArray<Settings::LocalizedStringSetting>& Settings, bool bShouldAddIfMissing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.UpdateStringSettings");
			byte params[16] = { NULL };
			*(ScriptArray<Settings::LocalizedStringSetting>*)&params[0] = Settings;
			*(bool*)&params[12] = bShouldAddIfMissing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Settings = *(ScriptArray<Settings::LocalizedStringSetting>*)&params[0];
		}
		Settings::ESettingsDataType GetPropertyType(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyType");
			byte params[5] = { NULL };
			*(int*)&params[0] = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Settings::ESettingsDataType*)&params[4];
		}
		bool GetPropertyValueId(int PropertyId, int& ValueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyValueId");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(int*)&params[4] = ValueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueId = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool SetPropertyValueId(int PropertyId, int ValueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetPropertyValueId");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(int*)&params[4] = ValueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetStringProperty(int PropertyId, ScriptString*& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringProperty");
			byte params[20] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(ScriptString**)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		void SetStringProperty(int PropertyId, ScriptString* Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringProperty");
			byte params[16] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(ScriptString**)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetIntProperty(int PropertyId, int& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetIntProperty");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		void SetIntProperty(int PropertyId, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetIntProperty");
			byte params[8] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetFloatProperty(int PropertyId, float& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetFloatProperty");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		void SetFloatProperty(int PropertyId, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetFloatProperty");
			byte params[8] = { NULL };
			*(int*)&params[0] = PropertyId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool SetPropertyFromStringByName(ScriptName PropertyName, ScriptString*& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetPropertyFromStringByName");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = PropertyName;
			*(ScriptString**)&params[8] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		ScriptString* GetPropertyAsStringByName(ScriptName PropertyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyAsStringByName");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = PropertyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		ScriptString* GetPropertyAsString(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyAsString");
			byte params[16] = { NULL };
			*(int*)&params[0] = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptString* GetPropertyColumnHeader(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyColumnHeader");
			byte params[16] = { NULL };
			*(int*)&params[0] = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptName GetPropertyName(int PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyName");
			byte params[12] = { NULL };
			*(int*)&params[0] = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool GetPropertyId(ScriptName PropertyName, int& PropertyId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetPropertyId");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = PropertyName;
			*(int*)&params[8] = PropertyId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PropertyId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool SetStringSettingValueFromStringByName(ScriptName StringSettingName, ScriptString*& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringSettingValueFromStringByName");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = StringSettingName;
			*(ScriptString**)&params[8] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		ScriptName GetStringSettingValueNameByName(ScriptName StringSettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueNameByName");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = StringSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		ScriptName GetStringSettingValueName(int StringSettingId, int ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueName");
			byte params[16] = { NULL };
			*(int*)&params[0] = StringSettingId;
			*(int*)&params[4] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		bool IsWildcardStringSetting(int StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.IsWildcardStringSetting");
			byte params[8] = { NULL };
			*(int*)&params[0] = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptString* GetStringSettingColumnHeader(int StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingColumnHeader");
			byte params[16] = { NULL };
			*(int*)&params[0] = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		ScriptName GetStringSettingName(int StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingName");
			byte params[12] = { NULL };
			*(int*)&params[0] = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool GetStringSettingId(ScriptName StringSettingName, int& StringSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingId");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = StringSettingName;
			*(int*)&params[8] = StringSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			StringSettingId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetStringSettingValueByName(ScriptName StringSettingName, int& ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueByName");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = StringSettingName;
			*(int*)&params[8] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueIndex = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		void SetStringSettingValueByName(ScriptName StringSettingName, int ValueIndex, bool bShouldAutoAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringSettingValueByName");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = StringSettingName;
			*(int*)&params[8] = ValueIndex;
			*(bool*)&params[12] = bShouldAutoAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetStringSettingValueNames(int StringSettingId, ScriptArray<Settings::IdToStringMapping>& Values)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValueNames");
			byte params[20] = { NULL };
			*(int*)&params[0] = StringSettingId;
			*(ScriptArray<Settings::IdToStringMapping>*)&params[4] = Values;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Values = *(ScriptArray<Settings::IdToStringMapping>*)&params[4];
			return *(bool*)&params[16];
		}
		bool IncrementStringSettingValue(int StringSettingId, int Direction, bool bShouldWrap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.IncrementStringSettingValue");
			byte params[16] = { NULL };
			*(int*)&params[0] = StringSettingId;
			*(int*)&params[4] = Direction;
			*(bool*)&params[8] = bShouldWrap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool GetStringSettingValue(int StringSettingId, int& ValueIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetStringSettingValue");
			byte params[12] = { NULL };
			*(int*)&params[0] = StringSettingId;
			*(int*)&params[4] = ValueIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueIndex = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		void SetStringSettingValue(int StringSettingId, int ValueIndex, bool bShouldAutoAdd)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetStringSettingValue");
			byte params[12] = { NULL };
			*(int*)&params[0] = StringSettingId;
			*(int*)&params[4] = ValueIndex;
			*(bool*)&params[8] = bShouldAutoAdd;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetSettingsDataDateTime(Settings::SettingsData& Data, int& OutInt1, int& OutInt2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataDateTime");
			byte params[20] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(int*)&params[12] = OutInt1;
			*(int*)&params[16] = OutInt2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
			OutInt1 = *(int*)&params[12];
			OutInt2 = *(int*)&params[16];
		}
		void GetSettingsDataBlob(Settings::SettingsData& Data, ScriptArray<byte>& OutBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataBlob");
			byte params[24] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(ScriptArray<byte>*)&params[12] = OutBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
			OutBlob = *(ScriptArray<byte>*)&params[12];
		}
		int GetSettingsDataInt(Settings::SettingsData& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataInt");
			byte params[16] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
			return *(int*)&params[12];
		}
		float GetSettingsDataFloat(Settings::SettingsData& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataFloat");
			byte params[16] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
			return *(float*)&params[12];
		}
		ScriptString* GetSettingsDataString(Settings::SettingsData& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.GetSettingsDataString");
			byte params[24] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
			return *(ScriptString**)&params[12];
		}
		void EmptySettingsData(Settings::SettingsData& Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.EmptySettingsData");
			byte params[12] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
		}
		void SetSettingsData(Settings::SettingsData& Data, Settings::SettingsData& Data2Copy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsData");
			byte params[24] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(Settings::SettingsData*)&params[12] = Data2Copy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
			Data2Copy = *(Settings::SettingsData*)&params[12];
		}
		void SetSettingsDataBlob(Settings::SettingsData& Data, ScriptArray<byte>& InBlob)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataBlob");
			byte params[24] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(ScriptArray<byte>*)&params[12] = InBlob;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
			InBlob = *(ScriptArray<byte>*)&params[12];
		}
		void SetSettingsDataDateTime(Settings::SettingsData& Data, int InInt1, int InInt2)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataDateTime");
			byte params[20] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(int*)&params[12] = InInt1;
			*(int*)&params[16] = InInt2;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
		}
		void SetSettingsDataInt(Settings::SettingsData& Data, int InInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataInt");
			byte params[16] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(int*)&params[12] = InInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
		}
		void SetSettingsDataFloat(Settings::SettingsData& Data, float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataFloat");
			byte params[16] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(float*)&params[12] = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
		}
		void SetSettingsDataString(Settings::SettingsData& Data, ScriptString* InString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Settings.SetSettingsDataString");
			byte params[24] = { NULL };
			*(Settings::SettingsData*)&params[0] = Data;
			*(ScriptString**)&params[12] = InString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Data = *(Settings::SettingsData*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
