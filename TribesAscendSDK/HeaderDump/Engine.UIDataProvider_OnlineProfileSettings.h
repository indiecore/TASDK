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
			byte params[21] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = PlayerInterface;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.WriteData");
			byte params[21] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = PlayerInterface;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.GetData");
			byte params[17] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = PlayerInterface;
			params[8] = LocalUserNum;
			*(class OnlinePlayerStorage**)&params[12] = PlayerStorage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AddReadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.AddReadCompleteDelegate");
			byte params[9] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = PlayerInterface;
			params[8] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadCompleteDelegate(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void* PlayerInterface, byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.ClearReadCompleteDelegate");
			byte params[9] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.InterfaceProperty'!
void**)&params[0] = PlayerInterface;
			params[8] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshStorageData()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineProfileSettings.RefreshStorageData");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
