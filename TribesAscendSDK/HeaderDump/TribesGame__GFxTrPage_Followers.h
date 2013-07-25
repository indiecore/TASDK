#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Followers." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Followers : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, MutalFriendLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SelectPromptLabel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemovingIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PrevPlayerId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FocusedIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Criteria, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
