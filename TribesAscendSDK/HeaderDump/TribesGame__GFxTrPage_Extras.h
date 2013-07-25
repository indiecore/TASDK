#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Extras." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Extras : public GFxTrPage
	{
	public:
		ADD_VAR(::StrProperty, PromoPopupTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, C1P3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, C1P2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, C1P1, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForClaimPromoPopup, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForCheatCodePopup, 0x1)
		ADD_VAR(::IntProperty, CheatCodeAction, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClaimPromotionAction, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
	};
}
#undef ADD_VAR
