#pragma once
#include "Engine__UIDataProvider_OnlinePlayerDataBase.h"
#include "Engine__LocalPlayer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.UIDataProvider_OnlineFriendMessages." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.UIDataProvider_OnlineFriendMessages." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlineFriendMessages : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_VAR(::StrProperty, LastInviteFrom, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MessageCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bWasDeniedCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bWasAcceptedCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, bIsFriendInviteCol, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SendingPlayerNameCol, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IUIListElementCellProvider'!
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnRegister");
			byte* params = (byte*)malloc(4);
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void OnFriendInviteReceived(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* RequestingPlayer, ScriptArray<wchar_t> RequestingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnFriendInviteReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = RequestingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = RequestingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFriendMessageReceived(byte LocalUserNum, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* SendingPlayer, ScriptArray<wchar_t> SendingNick, ScriptArray<wchar_t> Message)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnFriendMessageReceived");
			byte* params = (byte*)malloc(33);
			*params = LocalUserNum;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 4) = SendingPlayer;
			*(ScriptArray<wchar_t>*)(params + 12) = SendingNick;
			*(ScriptArray<wchar_t>*)(params + 24) = Message;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnLoginChange");
			byte* params = (byte*)malloc(1);
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameInviteReceived(byte LocalUserNum, ScriptArray<wchar_t> InviterName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.UIDataProvider_OnlineFriendMessages.OnGameInviteReceived");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(ScriptArray<wchar_t>*)(params + 4) = InviterName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
