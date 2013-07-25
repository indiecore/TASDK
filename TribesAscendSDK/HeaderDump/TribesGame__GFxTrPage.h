#pragma once
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage : public GFxObject
	{
	public:
		ADD_VAR(::StrProperty, HelpButtonYLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonXLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonBLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonALabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonYKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonXKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonBKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, HelpButtonAKey, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PageLabel, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, PageLabelOverride, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShowTribesLogo, 0x200)
		ADD_VAR(::BoolProperty, bParentLocked, 0x100)
		ADD_VAR(::BoolProperty, bHasModifiers, 0x80)
		ADD_VAR(::BoolProperty, bCreated, 0x40)
		ADD_VAR(::BoolProperty, bActive, 0x20)
		ADD_VAR(::BoolProperty, bAllowBack, 0x10)
		ADD_VAR(::BoolProperty, bEndOfLine, 0x8)
		ADD_VAR(::BoolProperty, bRemoveOption, 0x4)
		ADD_VAR(::BoolProperty, bModifyOption, 0x2)
		ADD_VAR(::BoolProperty, bFillingFocus, 0x1)
		ADD_VAR(::IntProperty, LoadoutEquipType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LoadoutClassId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NewAction, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OptionCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DataCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActiveIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ScrollIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonYNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonXNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonBNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HelpButtonANum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoBack, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActiveLoadout, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'AddAction'
		// Here lies the not-yet-implemented method 'AddActionNumber'
		// Here lies the not-yet-implemented method 'AddActionString'
		// Here lies the not-yet-implemented method 'AddActionPage'
		// Here lies the not-yet-implemented method 'AddActionSet'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'ModifyFocus'
		// Here lies the not-yet-implemented method 'HelpButton'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOptions'
		// Here lies the not-yet-implemented method 'IsOwned'
		// Here lies the not-yet-implemented method 'CheckPurchasable'
		// Here lies the not-yet-implemented method 'IsEquipMaxed'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'FillDefault'
		// Here lies the not-yet-implemented method 'CheckUpgrades'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillUpgrades'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'FillPage'
		// Here lies the not-yet-implemented method 'ClearActions'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'FillClass'
		// Here lies the not-yet-implemented method 'FillEquipTypes'
		// Here lies the not-yet-implemented method 'NewClassEquip'
		// Here lies the not-yet-implemented method 'NewClassUpgrade'
		// Here lies the not-yet-implemented method 'NewEquipUpgrade'
		// Here lies the not-yet-implemented method 'RevertSetting'
		// Here lies the not-yet-implemented method 'OnPurchaseSuccess'
		// Here lies the not-yet-implemented method 'ActionUp'
		// Here lies the not-yet-implemented method 'ActionDown'
		// Here lies the not-yet-implemented method 'RefreshButtons'
		// Here lies the not-yet-implemented method 'KeyEvent'
		// Here lies the not-yet-implemented method 'UpdateDealTimer'
		// Here lies the not-yet-implemented method 'UpdateQueueTimer'
		// Here lies the not-yet-implemented method 'ProfileUp'
		// Here lies the not-yet-implemented method 'ProfileDown'
		// Here lies the not-yet-implemented method 'ResetRunaway'
		// Here lies the not-yet-implemented method 'ShowReticule'
		// Here lies the not-yet-implemented method 'SaveReticule'
		// Here lies the not-yet-implemented method 'OnClose'
	};
}
#undef ADD_VAR
