#pragma once
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHUDSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrHUDSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrHUDSettings : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, SettingsCount, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, SettingsList)
		// Here lies the not-yet-implemented method 'GetCurrentValue'
		// Here lies the not-yet-implemented method 'SaveSetting'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
