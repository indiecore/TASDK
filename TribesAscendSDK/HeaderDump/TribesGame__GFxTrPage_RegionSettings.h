#pragma once
#include "TribesGame__GFxTrPage.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_RegionSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_RegionSettings : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bFilter, 0x1)
		ADD_VAR(::BoolProperty, bForceChoose, 0x4)
		ADD_VAR(::BoolProperty, bServer, 0x2)
		ADD_VAR(::IntProperty, CurrFilterIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrFilterSite, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrRegion, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'FillOption'
	};
}
#undef ADD_VAR
