#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine__OnlinePlayerStorage.h"
#include "Engine__LocalPlayer.h"
#include "Engine__UIDataProvider.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlinePlayerStorage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIDataProvider_OnlinePlayerStorage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerStorage : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_VAR(::IntProperty, DeviceStorageSizeNeeded, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasErrorLastRead, 0x1)
		ADD_VAR(::NameProperty, ProviderName, 0xFFFFFFFF)
		ADD_OBJECT(OnlinePlayerStorage, Profile)
		bool ReadData(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.ReadData");
			byte* params = (byte*)malloc(21);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			*(params + 8) = LocalUserNum;
			*(int*)(params + 12) = DeviceID;
			*(class OnlinePlayerStorage**)(params + 16) = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool WriteData(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.WriteData");
			byte* params = (byte*)malloc(21);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			*(params + 8) = LocalUserNum;
			*(int*)(params + 12) = DeviceID;
			*(class OnlinePlayerStorage**)(params + 16) = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool GetData(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.GetData");
			byte* params = (byte*)malloc(17);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			*(params + 8) = LocalUserNum;
			*(class OnlinePlayerStorage**)(params + 12) = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AddReadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.AddReadCompleteDelegate");
			byte* params = (byte*)malloc(9);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			*(params + 8) = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.ClearReadCompleteDelegate");
			byte* params = (byte*)malloc(9);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			*(params + 8) = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.OnRegister");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnReadStorageComplete(byte LocalUserNum, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.OnReadStorageComplete");
			byte* params = (byte*)malloc(5);
			*params = LocalUserNum;
			*(bool*)(params + 4) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshStorageData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.RefreshStorageData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnDeviceSelectionComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.OnDeviceSelectionComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ArrayProviderPropertyChanged(class UIDataProvider* SourceProvider, ScriptName PropTag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.ArrayProviderPropertyChanged");
			byte* params = (byte*)malloc(12);
			*(class UIDataProvider**)params = SourceProvider;
			*(ScriptName*)(params + 4) = PropTag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSettingValueUpdated(ScriptName SettingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.OnSettingValueUpdated");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SettingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnStorageDeviceChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlinePlayerStorage.OnStorageDeviceChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
