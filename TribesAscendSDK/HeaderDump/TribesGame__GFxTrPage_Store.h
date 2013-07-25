#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Store." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Store : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, PromoPopupTitle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClaimPromotionAction, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, NoNameChangeInGame, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForClaimPromoPopup, 0x10)
		ADD_VAR(::BoolProperty, bConfirmationPopup, 0x8)
		ADD_VAR(::BoolProperty, bClassRequiredPopup, 0x4)
		ADD_VAR(::BoolProperty, bSelectionPopup, 0x2)
		ADD_VAR(::BoolProperty, bCurrencyPopup, 0x1)
		ADD_VAR(::IntProperty, classIdRequired, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumGold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumDeal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HZCost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, xpCost, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
	};
}
#undef ADD_VAR
