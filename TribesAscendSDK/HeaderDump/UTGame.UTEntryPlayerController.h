#pragma once
#include "UTGame.UTPlayerController.h"
#include "Engine.PostProcessChain.h"
#include "Engine.LocalPlayer.h"
#include "Engine.OnlineSubsystem.h"
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
	class UTEntryPlayerController : public UTPlayerController
	{
	public:
		ADD_STRUCT(ScriptArray<class PostProcessChain*>, OldPostProcessChain, 2180)
		ADD_OBJECT(LocalPlayer, OldPlayer, 2192)
		ADD_OBJECT(PostProcessChain, EntryPostProcessChain, 2176)
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47416);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestorePostProcessing()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47417);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47419);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47420);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptString* RequestingNick)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47424);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(ScriptString**)&params[4] = RequestingNick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47427);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47432);
			byte params[33] = { NULL };
			*params = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnConnectionStatusChange(OnlineSubsystem::EOnlineServerConnectionStatus ConnectionStatus)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47437);
			byte params[1] = { NULL };
			*(OnlineSubsystem::EOnlineServerConnectionStatus*)params = ConnectionStatus;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLinkStatusChanged(bool bConnected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47440);
			byte params[4] = { NULL };
			*(bool*)params = bConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void QuitToMainMenu()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47443);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPawnConstructionScene(bool bShow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47444);
			byte params[4] = { NULL };
			*(bool*)params = bShow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowMidGameMenu(ScriptName TabTag, bool bEnableInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47446);
			byte params[12] = { NULL };
			*(ScriptName*)params = TabTag;
			*(bool*)&params[8] = bEnableInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowScoreboard()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47449);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
