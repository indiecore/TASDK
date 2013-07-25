#pragma once
#include "Core.Interface.h"
namespace UnrealScript
{
	class OnlineSystemInterface : public Interface
	{
	public:
		bool HasLinkConnection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.HasLinkConnection");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnLinkStatusChange(bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.OnLinkStatusChange");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnStorageDeviceChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.OnStorageDeviceChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnConnectionStatusChange(byte ConnectionStatus)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.OnConnectionStatusChange");
			byte* params = (byte*)malloc(1);
			*params = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnControllerChange(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.OnControllerChange");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			*(bool*)(params + 4) = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnExternalUIChange(bool bIsOpening)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.OnExternalUIChange");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsOpening;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddLinkStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LinkStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.AddLinkStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LinkStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearLinkStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* LinkStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.ClearLinkStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = LinkStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddExternalUIChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ExternalUIDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.AddExternalUIChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ExternalUIDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearExternalUIChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ExternalUIDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.ClearExternalUIChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ExternalUIDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetNetworkNotificationPosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.GetNetworkNotificationPosition");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void SetNetworkNotificationPosition(byte NewPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.SetNetworkNotificationPosition");
			byte* params = (byte*)malloc(1);
			*params = NewPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddControllerChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ControllerChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.AddControllerChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ControllerChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearControllerChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ControllerChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.ClearControllerChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ControllerChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsControllerConnected(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.IsControllerConnected");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddConnectionStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ConnectionStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.AddConnectionStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ConnectionStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearConnectionStatusChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ConnectionStatusDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.ClearConnectionStatusChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ConnectionStatusDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetNATType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.GetNATType");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void AddStorageDeviceChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StorageDeviceChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.AddStorageDeviceChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = StorageDeviceChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearStorageDeviceChangeDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* StorageDeviceChangeDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineSystemInterface.ClearStorageDeviceChangeDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = StorageDeviceChangeDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
