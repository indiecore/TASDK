#pragma once
#include "Engine__Interaction.h"
#include "Engine__GameUISceneClient.h"
#include "Engine__LocalPlayer.h"
#include "Engine__DataStoreClient.h"
#include "Engine__UIManager.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.UIInteraction." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UIInteraction : public Interaction
	{
	public:
		ADD_OBJECT(GameUISceneClient, SceneClient)
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIInteraction.UIAxisEmulationData' for the property named 'AxisInputEmulation'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.UIInteraction.UIKeyRepeatData' for the property named 'MouseButtonRepeatInfo'!
		ADD_VAR(::IntProperty, DoubleClickPixelTolerance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DoubleClickTriggerSeconds, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MouseButtonRepeatDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AxisRepeatDelay, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UIAxisMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, UIJoystickDeadZone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bProcessInput, 0x1)
		ADD_OBJECT(DataStoreClient, DataStoreManager)
		ADD_OBJECT(ScriptClass, SceneClientClass)
		ADD_OBJECT(ScriptClass, UIManagerClass)
		ADD_OBJECT(UIManager, UIManager)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FCallbackEventDevice'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FGlobalDataStoreClientManager'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_FExec'!
		class DataStoreClient* GetDataStoreClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetDataStoreClient");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class DataStoreClient**)params;
			free(params);
			return returnVal;
		}
		bool IsLoggedIn(int ControllerId, bool bRequireOnlineLogin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.IsLoggedIn");
			byte* params = (byte*)malloc(12);
			*(int*)params = ControllerId;
			*(bool*)(params + 4) = bRequireOnlineLogin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsGamepadConnected(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.IsGamepadConnected");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetPlayerCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetPlayerCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetPlayerIndex(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetPlayerIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetPlayerControllerId(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetPlayerControllerId");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		class LocalPlayer* GetLocalPlayer(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLocalPlayer");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class LocalPlayer**)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.NotifyPlayerAdded");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.NotifyPlayerRemoved");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			*(class LocalPlayer**)(params + 4) = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetLoginStatus(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLoginStatus");
			byte* params = (byte*)malloc(5);
			*(int*)params = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		byte GetLowestLoginStatusOfControllers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLowestLoginStatusOfControllers");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool HasLinkConnection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.HasLinkConnection");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetLoggedInPlayerCount(bool bRequireOnlineLogin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLoggedInPlayerCount");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bRequireOnlineLogin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetNumGuestsLoggedIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetNumGuestsLoggedIn");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetConnectedGamepadCount(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* ControllerConnectionStatusOverrides)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetConnectedGamepadCount");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = ControllerConnectionStatusOverrides;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		byte GetNATType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetNATType");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.NotifyGameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
