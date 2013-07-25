#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerTeam." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerTeam : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bBoundsPopup, 0x8)
		ADD_VAR(::BoolProperty, bPopupBaseDestPopup, 0x4)
		ADD_VAR(::BoolProperty, bDisparityPopup, 0x2)
		ADD_VAR(::BoolProperty, bMaxPlayerPopup, 0x1)
		ADD_VAR(::IntProperty, MaxBOunds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinBounds, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
