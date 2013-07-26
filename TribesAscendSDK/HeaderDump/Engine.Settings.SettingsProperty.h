#pragma once
#include "Engine.Settings.SettingsData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Settings.SettingsProperty." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Settings.SettingsProperty." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SettingsProperty
	{
	public:
		ADD_VAR(::IntProperty, PropertyId, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<SettingsData>, Data, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, AdvertisementType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
