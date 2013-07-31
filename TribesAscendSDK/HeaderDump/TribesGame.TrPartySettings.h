#pragma once
#include "Engine.OnlineGameSettings.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.LocalPlayer.h"
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
	class TrPartySettings : public OnlineGameSettings
	{
	public:
		ADD_STRUCT(ScriptArray<OnlineSubsystem::OnlinePartyMember>, MemberList, 184)
		ADD_OBJECT(OnlineSubsystem, OnlineSub, 172)
		void Init(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100605);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Close()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100607);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnLoginChange(byte LocalUserNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100608);
			byte params[1] = { NULL };
			*params = LocalUserNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RefreshMembersList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(100612);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
