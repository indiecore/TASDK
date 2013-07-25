#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
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
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'RequestActiveClass'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'GetArmorName'
		// Here lies the not-yet-implemented method 'GetEquipName'
	};
}
#undef ADD_VAR
