#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerEditCallin." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerEditCallin : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, CallinType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBoundsPopup, 0x2)
		ADD_VAR(::BoolProperty, bPopup, 0x1)
		ADD_VAR(::IntProperty, popupIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BuildupIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CooldownIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PriceIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EnabledIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ORBNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SUPNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TACNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxBOunds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinBounds, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'SetSubTitle'
		// Here lies the not-yet-implemented method 'PopupData'
		// Here lies the not-yet-implemented method 'PopupComplete'
		// Here lies the not-yet-implemented method 'ShowBoundsError'
		// Here lies the not-yet-implemented method 'CheckDescription'
		// Here lies the not-yet-implemented method 'FillDescription'
		// Here lies the not-yet-implemented method 'ShowModel'
	};
}
#undef ADD_VAR
