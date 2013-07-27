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
		struct OnlineProfileSetting
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22410);
			byte params[16] = { NULL };
			*(ScriptName*)params = ProfileSettingName;
			*(int*)&params[8] = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ProfileSettingId = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		ScriptName GetProfileSettingName(int ProfileSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22414);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		ScriptString* GetProfileSettingColumnHeader(int ProfileSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22417);
			byte params[16] = { NULL };
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
		int FindProfileSettingIndex(int ProfileSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22420);
			byte params[8] = { NULL };
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int FindProfileMappingIndex(int ProfileSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22423);
			byte params[8] = { NULL };
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int FindProfileMappingIndexByName(ScriptName ProfileSettingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22426);
			byte params[12] = { NULL };
			*(ScriptName*)params = ProfileSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int FindDefaultProfileMappingIndexByName(ScriptName ProfileSettingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22429);
			byte params[12] = { NULL };
			*(ScriptName*)params = ProfileSettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool IsProfileSettingIdMapped(int ProfileSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22432);
			byte params[8] = { NULL };
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool GetProfileSettingValue(int ProfileSettingId, ScriptString*& Value, int ValueMapID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22435);
			byte params[24] = { NULL };
			*(int*)params = ProfileSettingId;
			*(ScriptString**)&params[4] = Value;
			*(int*)&params[16] = ValueMapID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(ScriptString**)&params[4];
			return *(bool*)&params[20];
		}
		ScriptName GetProfileSettingValueName(int ProfileSettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22440);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		bool GetProfileSettingValues(int ProfileSettingId, ScriptArray<ScriptName>& Values)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22443);
			byte params[20] = { NULL };
			*(int*)params = ProfileSettingId;
			*(ScriptArray<ScriptName>*)&params[4] = Values;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Values = *(ScriptArray<ScriptName>*)&params[4];
			return *(bool*)&params[16];
		}
		bool GetProfileSettingValueByName(ScriptName ProfileSettingName, ScriptString*& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22448);
			byte params[24] = { NULL };
			*(ScriptName*)params = ProfileSettingName;
			*(ScriptString**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool SetProfileSettingValueByName(ScriptName ProfileSettingName, ScriptString*& NewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22452);
			byte params[24] = { NULL };
			*(ScriptName*)params = ProfileSettingName;
			*(ScriptString**)&params[8] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		bool SetProfileSettingValue(int ProfileSettingId, ScriptString*& NewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22456);
			byte params[20] = { NULL };
			*(int*)params = ProfileSettingId;
			*(ScriptString**)&params[4] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			NewValue = *(ScriptString**)&params[4];
			return *(bool*)&params[16];
		}
		bool GetProfileSettingValueId(int ProfileSettingId, int& ValueId, int& ListIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22460);
			byte params[16] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = ValueId;
			*(int*)&params[8] = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ValueId = *(int*)&params[4];
			ListIndex = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetProfileSettingValueFromListIndex(int ProfileSettingId, int ListIndex, int& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22465);
			byte params[16] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = ListIndex;
			*(int*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetProfileSettingValueInt(int ProfileSettingId, int& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22470);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetProfileSettingValueFloat(int ProfileSettingId, float& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22474);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		bool SetProfileSettingValueId(int ProfileSettingId, int Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22478);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetProfileSettingValueInt(int ProfileSettingId, int Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22482);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool SetProfileSettingValueFloat(int ProfileSettingId, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22486);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(float*)&params[4] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetProfileSettingMappingType(int ProfileId, Settings::EPropertyValueMappingType& OutType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22490);
			byte params[9] = { NULL };
			*(int*)params = ProfileId;
			*(Settings::EPropertyValueMappingType*)&params[4] = OutType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutType = *(Settings::EPropertyValueMappingType*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetProfileSettingMappingIds(int ProfileId, ScriptArray<int>& Ids)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22494);
			byte params[20] = { NULL };
			*(int*)params = ProfileId;
			*(ScriptArray<int>*)&params[4] = Ids;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Ids = *(ScriptArray<int>*)&params[4];
			return *(bool*)&params[16];
		}
		bool GetProfileSettingRange(int ProfileId, float& OutMinValue, float& OutMaxValue, float& RangeIncrement, byte& bFormatAsInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22499);
			byte params[21] = { NULL };
			*(int*)params = ProfileId;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22506);
			byte params[12] = { NULL };
			*(int*)params = ProfileId;
			*(float*)&params[4] = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool GetRangedProfileSettingValue(int ProfileId, float& OutValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22510);
			byte params[12] = { NULL };
			*(int*)params = ProfileId;
			*(float*)&params[4] = OutValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutValue = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		void AddSettingInt(int SettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22514);
			byte params[4] = { NULL };
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSettingFloat(int SettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22516);
			byte params[4] = { NULL };
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetToDefaults()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22518);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AppendVersionToSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22519);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetVersionNumber()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22520);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void SetDefaultVersionNumber()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22522);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
