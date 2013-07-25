#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Equip." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Equip : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bReticulesOpen, 0x2)
		ADD_VAR(::BoolProperty, bUpgradePurchase, 0x1)
		ADD_VAR(::IntProperty, ReticuleIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PurchasingUpgrade, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PurchasingEquip, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FocusedEquip, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ViewedEquip, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoldPrice, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, xpPrice, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'ShowReticule'
		// Here lies the not-yet-implemented method 'HideReticule'
		// Here lies the not-yet-implemented method 'OnPurchaseSuccess'
		// Here lies the not-yet-implemented method 'SetActiveEquip'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'FillSkin'
		// Here lies the not-yet-implemented method 'CheckUpgrades'
		// Here lies the not-yet-implemented method 'FillUpgrades'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'FillPricingSkin'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'CheckPurchasable'
		// Here lies the not-yet-implemented method 'IsEquipMaxed'
		// Here lies the not-yet-implemented method 'IsOwned'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupDataSkin'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'SaveReticule'
		// Here lies the not-yet-implemented method 'OnClose'
	};
}
#undef ADD_VAR
