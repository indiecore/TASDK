#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerActions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerActions : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bPopup, 0x1)
		ADD_VAR(::IntProperty, PopupNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BanPlayerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, KickPlayerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GotoMapServerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, KillServerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DisableServerNum, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EnableServerNum, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'ShowModel'
	};
}
#undef ADD_VAR
