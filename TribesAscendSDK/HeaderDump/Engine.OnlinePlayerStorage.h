#pragma once
#include "Core.Object.h"
#include "Engine.Settings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlinePlayerStorage : public Object
	{
	public:
		enum EOnlineProfilePropertyOwner : byte
		{
			OPPO_None = 0,
			OPPO_OnlineService = 1,
			OPPO_Game = 2,
			OPPO_MAX = 3,
		};
		enum EOnlinePlayerStorageAsyncState : byte
		{
			OPAS_None = 0,
			OPAS_Read = 1,
			OPAS_Write = 2,
			OPAS_MAX = 3,
		};
		class OnlineProfileSetting
		{
		public:
			ADD_STRUCT(Settings::SettingsProperty, ProfileSetting, 4)
			ADD_STRUCT(OnlinePlayerStorage::EOnlineProfilePropertyOwner, Owner, 0)
		};
		ADD_STRUCT(ScriptArray<OnlinePlayerStorage::OnlineProfileSetting>, ProfileSettings, 68)
		ADD_STRUCT(ScriptArray<Settings::SettingsPropertyPropertyMetaData>, ProfileMappings, 80)
		ADD_STRUCT(int, DeviceID, 96)
		ADD_STRUCT(OnlinePlayerStorage::EOnlinePlayerStorageAsyncState, AsyncState, 92)
		ADD_STRUCT(int, VersionNumber, 60)
		ADD_STRUCT(int, VersionSettingsId, 64)
		bool GetProfileSettingId(ScriptName ProfileSettingName, int& ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingId");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = ProfileSettingName;
			*(int*)&params[8] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ProfileSettingId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		ScriptName GetProfileSettingName(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingName");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		ScriptString* GetProfileSettingColumnHeader(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingColumnHeader");
			byte params[16] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int FindProfileSettingIndex(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindProfileSettingIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int FindProfileMappingIndex(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindProfileMappingIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int FindProfileMappingIndexByName(ScriptName ProfileSettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindProfileMappingIndexByName");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ProfileSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int FindDefaultProfileMappingIndexByName(ScriptName ProfileSettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.FindDefaultProfileMappingIndexByName");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ProfileSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool IsProfileSettingIdMapped(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.IsProfileSettingIdMapped");
			byte params[8] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetProfileSettingValue(int ProfileSettingId, ScriptString*& Value, int ValueMapID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValue");
			byte params[24] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(ScriptString**)&params[4] = Value;
			*(int*)&params[16] = ValueMapID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(ScriptString**)&params[4];
			return *(bool*)&params[20];
		}
		ScriptName GetProfileSettingValueName(int ProfileSettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueName");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool GetProfileSettingValues(int ProfileSettingId, ScriptArray<ScriptName>& Values)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValues");
			byte params[20] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(ScriptArray<ScriptName>*)&params[4] = Values;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Values = *(ScriptArray<ScriptName>*)&params[4];
			return *(bool*)&params[16];
		}
		bool GetProfileSettingValueByName(ScriptName ProfileSettingName, ScriptString*& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueByName");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ProfileSettingName;
			*(ScriptString**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool SetProfileSettingValueByName(ScriptName ProfileSettingName, ScriptString*& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueByName");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = ProfileSettingName;
			*(ScriptString**)&params[8] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool SetProfileSettingValue(int ProfileSettingId, ScriptString*& NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValue");
			byte params[20] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(ScriptString**)&params[4] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		bool GetProfileSettingValueId(int ProfileSettingId, int& ValueId, int& ListIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueId");
			byte params[16] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(int*)&params[4] = ValueId;
			*(int*)&params[8] = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueId = *(int*)&params[4];
			ListIndex = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetProfileSettingValueFromListIndex(int ProfileSettingId, int ListIndex, int& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueFromListIndex");
			byte params[16] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(int*)&params[4] = ListIndex;
			*(int*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetProfileSettingValueInt(int ProfileSettingId, int& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetProfileSettingValueFloat(int ProfileSettingId, float& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingValueFloat");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		bool SetProfileSettingValueId(int ProfileSettingId, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueId");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetProfileSettingValueInt(int ProfileSettingId, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueInt");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetProfileSettingValueFloat(int ProfileSettingId, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetProfileSettingValueFloat");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileSettingId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetProfileSettingMappingType(int ProfileId, Settings::EPropertyValueMappingType& OutType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingMappingType");
			byte params[9] = { NULL };
			*(int*)&params[0] = ProfileId;
			*(Settings::EPropertyValueMappingType*)&params[4] = OutType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutType = *(Settings::EPropertyValueMappingType*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetProfileSettingMappingIds(int ProfileId, ScriptArray<int>& Ids)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingMappingIds");
			byte params[20] = { NULL };
			*(int*)&params[0] = ProfileId;
			*(ScriptArray<int>*)&params[4] = Ids;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Ids = *(ScriptArray<int>*)&params[4];
			return *(bool*)&params[16];
		}
		bool GetProfileSettingRange(int ProfileId, float& OutMinValue, float& OutMaxValue, float& RangeIncrement, byte& bFormatAsInt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetProfileSettingRange");
			byte params[21] = { NULL };
			*(int*)&params[0] = ProfileId;
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
		bool SetRangedProfileSettingValue(int ProfileId, float NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetRangedProfileSettingValue");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileId;
			*(float*)&params[4] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetRangedProfileSettingValue(int ProfileId, float& OutValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.GetRangedProfileSettingValue");
			byte params[12] = { NULL };
			*(int*)&params[0] = ProfileId;
			*(float*)&params[4] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		void AddSettingInt(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.AddSettingInt");
			byte params[4] = { NULL };
			*(int*)&params[0] = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSettingFloat(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.AddSettingFloat");
			byte params[4] = { NULL };
			*(int*)&params[0] = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void SetDefaultVersionNumber()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlinePlayerStorage.SetDefaultVersionNumber");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
