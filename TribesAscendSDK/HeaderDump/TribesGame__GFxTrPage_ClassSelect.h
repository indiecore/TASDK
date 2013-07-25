#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ClassSelect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ClassSelect : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bClassDeniedPopup, 0x1)
		ADD_VAR(::IntProperty, XPAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GPAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PurchasingClass, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FocusedClass, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'RefreshClassList'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'RequestActiveClass'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'OnPurchaseSuccess'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'GetEquipName'
	};
}
#undef ADD_VAR
