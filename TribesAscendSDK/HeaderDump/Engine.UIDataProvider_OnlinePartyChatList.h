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
	class UIDataProvider_OnlinePartyChatList : public UIDataProvider_OnlinePlayerDataBase
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem::OnlinePartyMember>, PartyMembersList, 96)
		ADD_STRUCT(ScriptArray<ScriptString*>, NatTypes, 108)
		ADD_STRUCT(ScriptString*, IsPlayingThisGameCol, 192)
		ADD_STRUCT(ScriptString*, IsInGameSessionCol, 180)
		ADD_STRUCT(ScriptString*, IsTalkingCol, 168)
		ADD_STRUCT(ScriptString*, IsInPartyVoiceCol, 156)
		ADD_STRUCT(ScriptString*, IsLocalCol, 144)
		ADD_STRUCT(ScriptString*, NatTypeCol, 132)
		ADD_STRUCT(ScriptString*, NickNameCol, 120)
		ADD_STRUCT(Object::Pointer, VfTable_IUIListElementCellProvider, 92)
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28236);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28240);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28243);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshMembersList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28247);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
