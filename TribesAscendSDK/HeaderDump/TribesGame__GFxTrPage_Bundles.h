#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Bundles." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Bundles : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, classIdRequired, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DescriptionLabel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingForClassRequiredPopup, 0x2)
		ADD_VAR(::BoolProperty, bWaitingForBundleOwnedPopup, 0x1)
		ADD_VAR(::IntProperty, selectedVendorItemId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, selectedActionIdx, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
	};
}
#undef ADD_VAR
