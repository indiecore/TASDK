#pragma once
#include "Engine.UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.UIDataProvider.h"
#include "Engine.LocalPlayer.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerStorage : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		struct PlayerStorageArrayProvider
		{
		public:
			ADD_OBJECT(UIDataProvider_OnlinePlayerStorageArray, Provider, 12)
			ADD_STRUCT(ScriptName, PlayerStorageName, 4)
			ADD_STRUCT(int, PlayerStorageId, 0)
		};
		ADD_STRUCT(ScriptArray<UIDataProvider_OnlinePlayerStorage::PlayerStorageArrayProvider>, PlayerStorageArrayProviders, 108)
		ADD_STRUCT(int, DeviceStorageSizeNeeded, 120)
		ADD_BOOL(bWasErrorLastRead, 104, 0x1)
		ADD_STRUCT(ScriptName, ProviderName, 96)
		ADD_OBJECT(OnlinePlayerStorage, Profile, 92)
		bool ReadData(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28260);
			byte params[21] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			params[8] = LocalUserNum;
			*(int*)&params[12] = DeviceID;
			*(class OnlinePlayerStorage**)&params[16] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool WriteData(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28266);
			byte params[21] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			params[8] = LocalUserNum;
			*(int*)&params[12] = DeviceID;
			*(class OnlinePlayerStorage**)&params[16] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool GetData(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28272);
			byte params[17] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			params[8] = LocalUserNum;
			*(class OnlinePlayerStorage**)&params[12] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddReadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28278);
			byte params[9] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			params[8] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28281);
			byte params[9] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			params[8] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28284);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28288);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28291);
			byte params[5] = { NULL };
			*params = LocalUserNum;
			*(bool*)&params[4] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28296);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshStorageData()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28302);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnDeviceSelectionComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28305);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ArrayProviderPropertyChanged(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28309);
			byte params[12] = { NULL };
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)&params[4] = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSettingValueUpdated(ScriptName SettingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28314);
			byte params[8] = { NULL };
			*(ScriptName*)params = SettingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnStorageDeviceChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28318);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
