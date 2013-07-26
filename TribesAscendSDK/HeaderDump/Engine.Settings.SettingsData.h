#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Settings.SettingsData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Settings.SettingsData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SettingsData
	{
	public:
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Value1, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Value2, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
