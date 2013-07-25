#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_FriendJoin." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_FriendJoin : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, NotInAGameSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SocialSubtext, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SocialTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SelectPromptSubtext, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForMessagePopup, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForFriendAddPopup, 0x1)
		ADD_VAR(::IntProperty, SpecActionIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevPlayerId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FocusedIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Criteria, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
