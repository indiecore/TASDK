#pragma once
#include "TribesGame__GFxTrPage_VendorTable.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ClanTagChange." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ClanTagChange : public GFxTrPage_VendorTable
	{
	public:
		ADD_VAR(::StrProperty, RemovePopupTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ChangePopupTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RemovePopupBody, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ChangePopupBody, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemoveItem, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ChangeItem, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, xpPrice, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, gpPrice, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrencyNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ConfirmNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EntryNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'ShowModel'
	};
}
#undef ADD_VAR
