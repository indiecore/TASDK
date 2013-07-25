#pragma once
#include "TribesGame__GFxTrPage_VendorTable.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_NameChange." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_NameChange : public GFxTrPage_VendorTable
	{
	public:
		ADD_VAR(::BoolProperty, bWaitingForNewNameInput, 0x1)
		ADD_VAR(::StrProperty, NamePopupTitle, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'ShowModel'
	};
}
#undef ADD_VAR
