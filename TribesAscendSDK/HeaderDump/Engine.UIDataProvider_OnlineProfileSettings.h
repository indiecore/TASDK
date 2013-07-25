#pragma once
#include "Engine.UIDataProvider_OnlinePlayerStorage.h"
#include "Engine.OnlinePlayerStorage.h"
namespace UnrealScript
{
	class UIDataProvider_OnlineProfileSettings : public UIDataProvider_OnlinePlayerStorage
	{
	public:
		bool ReadData(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum, int DeviceID, class OnlinePlayerStorage* PlayerStorage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.ReadData");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.WriteData");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.GetData");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.AddReadCompleteDelegate");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.ClearReadCompleteDelegate");
			byte* params = (byte*)malloc(9);
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)params = PlayerInterface;
			*(params + 8) = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RefreshStorageData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.RefreshStorageData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
