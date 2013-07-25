#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_FriendActions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_FriendActions : public GFxTrPage
	{
	public:
		ADD_VAR(::ByteProperty, TargetOnlineState, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TargetPlayerIndex, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TargetPlayer, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForFriendActionPopup, 0x1)
		ADD_VAR(::IntProperty, FriendActionPopupIndex, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
