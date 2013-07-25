#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_PartyInvite." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_PartyInvite : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, MemberName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_InviteFailed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_SendMessage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_InviteSent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Action_ByName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
