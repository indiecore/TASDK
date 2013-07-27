#pragma once
#include "Engine.UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine.OnlineSubsystem.h"
#include "Core.Object.h"
#include "Engine.LocalPlayer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlineFriendMessages : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem::OnlineFriendMessage>, Messages, 96)
		ADD_STRUCT(ScriptString*, LastInviteFrom, 168)
		ADD_STRUCT(ScriptString*, MessageCol, 156)
		ADD_STRUCT(ScriptString*, bWasDeniedCol, 144)
		ADD_STRUCT(ScriptString*, bWasAcceptedCol, 132)
		ADD_STRUCT(ScriptString*, bIsFriendInviteCol, 120)
		ADD_STRUCT(ScriptString*, SendingPlayerNameCol, 108)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 92)
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnRegister");
			byte params[4] = { NULL };
			*(class LocalPlayer**)&params[0] = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnUnregister");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReadMessages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.ReadMessages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnFriendInviteReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId RequestingPlayer, ScriptString* RequestingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnFriendInviteReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = RequestingPlayer;
			*(ScriptString**)&params[12] = RequestingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFriendMessageReceived(byte LocalUserNum, OnlineSubsystem::UniqueNetId SendingPlayer, ScriptString* SendingNick, ScriptString* Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnFriendMessageReceived");
			byte params[33] = { NULL };
			params[0] = LocalUserNum;
			*(OnlineSubsystem::UniqueNetId*)&params[4] = SendingPlayer;
			*(ScriptString**)&params[12] = SendingNick;
			*(ScriptString**)&params[24] = Message;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnLoginChange");
			byte params[1] = { NULL };
			params[0] = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptString* InviterName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnGameInviteReceived");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(ScriptString**)&params[4] = InviterName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
