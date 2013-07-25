#pragma once
#include "TribesGame__GFxTrPage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Loadouts." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Loadouts : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bInSelection, 0x1)
		ADD_VAR(::BoolProperty, bClassLocked, 0x2)
		ADD_VAR(::StrProperty, LoadoutClassName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bConfirmationPopup, 0x10)
		ADD_VAR(::BoolProperty, bSelectionPopup, 0x8)
		ADD_VAR(::BoolProperty, bCurrencyPopup, 0x4)
		ADD_VAR(::IntProperty, ModelEquip, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, XPAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GPAmount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
