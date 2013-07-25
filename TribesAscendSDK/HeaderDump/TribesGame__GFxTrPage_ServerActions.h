#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerActions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerActions : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bPopup, 0x1)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BanPlayerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, KickPlayerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GotoMapServerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, KillServerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DisableServerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EnableServerNum, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
