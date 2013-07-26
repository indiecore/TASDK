#pragma once
#include "Engine.UIDataProvider_SettingsArray.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UIDataProvider_Settings.SettingsArrayProvider." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UIDataProvider_Settings.SettingsArrayProvider." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SettingsArrayProvider
	{
	public:
		ADD_OBJECT(UIDataProvider_SettingsArray, Provider)
		ADD_VAR(::NameProperty, SettingsName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SettingsId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
