#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__GFxTrAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Class." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Class : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bViewingEquip, 0x2)
		ADD_VAR(::BoolProperty, bClassLocked, 0x1)
		ADD_VAR(::IntProperty, NumRenameLoadout, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'GetEquipType'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'GetArmorName'
		// Here lies the not-yet-implemented method 'GetEquipName'
		// Here lies the not-yet-implemented method 'HelpButton'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
	};
}
#undef ADD_VAR
