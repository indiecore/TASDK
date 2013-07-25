#pragma once
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRegionSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRegionSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRegionSettings : public GFxObject
	{
	public:
		ADD_OBJECT(GFxObject, m_RegionSettingsList)
		ADD_VAR(::IntProperty, m_RegionSettingsCount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetPreferredSiteId'
		// Here lies the not-yet-implemented method 'LoadRegionSetting'
		// Here lies the not-yet-implemented method 'GetRegionName'
		// Here lies the not-yet-implemented method 'GetRegionIdAtIndex'
		// Here lies the not-yet-implemented method 'GetRegionIndexByName'
		// Here lies the not-yet-implemented method 'LoadRegions'
		// Here lies the not-yet-implemented method 'SetPreferredSiteId'
		// Here lies the not-yet-implemented method 'LoadRegionLabels'
		// Here lies the not-yet-implemented method 'SetPreferredRegion'
		// Here lies the not-yet-implemented method 'AddRegion'
		// Here lies the not-yet-implemented method 'AddSetting'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
