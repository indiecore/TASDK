#pragma once
#include "Engine.LocalPlayer.h"
#include "Engine.Interaction.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.GameUISceneClient.h"
#include "Engine.UIManager.h"
#include "Engine.UIRoot.h"
#include "Core.Object.h"
#include "Engine.DataStoreClient.h"
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
	class UIInteraction : public Interaction
	{
	public:
		class UIKeyRepeatData
		{
		public:
			ADD_STRUCT(Object::Double, NextRepeatTime, 8)
			ADD_STRUCT(ScriptName, CurrentRepeatKey, 0)
		};
		class UIAxisEmulationData : public UIKeyRepeatData
		{
		public:
			ADD_BOOL(bEnabled, 16, 0x1)
		};
		ADD_OBJECT(GameUISceneClient, SceneClient, 132)
		ADD_STRUCT(ScriptArray<ScriptName>, SupportedDoubleClickKeys, 136)
		ADD_STRUCT(ScriptArray<UIRoot::UIAxisEmulationDefinition>, ConfiguredAxisEmulationDefinitions, 196)
		ADD_STRUCT(UIInteraction::UIAxisEmulationData, AxisInputEmulation, 268)
		ADD_STRUCT(UIInteraction::UIKeyRepeatData, MouseButtonRepeatInfo, 180)
		ADD_STRUCT(int, DoubleClickPixelTolerance, 176)
		ADD_STRUCT(float, DoubleClickTriggerSeconds, 172)
		ADD_STRUCT(float, MouseButtonRepeatDelay, 168)
		ADD_STRUCT(float, AxisRepeatDelay, 164)
		ADD_STRUCT(float, UIAxisMultiplier, 160)
		ADD_STRUCT(float, UIJoystickDeadZone, 156)
		ADD_BOOL(bProcessInput, 152, 0x1)
		ADD_OBJECT(DataStoreClient, DataStoreManager, 148)
		ADD_OBJECT(ScriptClass, SceneClientClass, 128)
		ADD_OBJECT(ScriptClass, UIManagerClass, 124)
		ADD_OBJECT(UIManager, UIManager, 120)
		ADD_STRUCT(Object::Pointer, VfTable_FCallbackEventDevice, 116)
		ADD_STRUCT(Object::Pointer, VfTable_FGlobalDataStoreClientManager, 112)
		ADD_STRUCT(Object::Pointer, VfTable_FExec, 108)
		class DataStoreClient* GetDataStoreClient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetDataStoreClient");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class DataStoreClient**)&params[0];
		}
		bool IsLoggedIn(int ControllerId, bool bRequireOnlineLogin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.IsLoggedIn");
			byte params[12] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(bool*)&params[4] = bRequireOnlineLogin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool IsGamepadConnected(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.IsGamepadConnected");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetPlayerCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetPlayerCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetPlayerIndex(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetPlayerIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetPlayerControllerId(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetPlayerControllerId");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		class LocalPlayer* GetLocalPlayer(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLocalPlayer");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class LocalPlayer**)&params[4];
		}
		void NotifyPlayerAdded(int PlayerIndex, class LocalPlayer* AddedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.NotifyPlayerAdded");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = AddedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPlayerRemoved(int PlayerIndex, class LocalPlayer* RemovedPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.NotifyPlayerRemoved");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			*(class LocalPlayer**)&params[4] = RemovedPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		OnlineSubsystem::ELoginStatus GetLoginStatus(int ControllerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLoginStatus");
			byte params[5] = { NULL };
			*(int*)&params[0] = ControllerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::ELoginStatus*)&params[4];
		}
		OnlineSubsystem::ELoginStatus GetLowestLoginStatusOfControllers()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLowestLoginStatusOfControllers");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::ELoginStatus*)&params[0];
		}
		bool HasLinkConnection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.HasLinkConnection");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetLoggedInPlayerCount(bool bRequireOnlineLogin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetLoggedInPlayerCount");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bRequireOnlineLogin;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetNumGuestsLoggedIn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetNumGuestsLoggedIn");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetConnectedGamepadCount(ScriptArray<bool> ControllerConnectionStatusOverrides)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetConnectedGamepadCount");
			byte params[16] = { NULL };
			*(ScriptArray<bool>*)&params[0] = ControllerConnectionStatusOverrides;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		OnlineSubsystem::ENATType GetNATType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.GetNATType");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(OnlineSubsystem::ENATType*)&params[0];
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIInteraction.NotifyGameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
