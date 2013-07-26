#pragma once
#include "Core.Object.Color.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Console.scrollbackData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Console.scrollbackData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class scrollbackData
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Color>, OverrideColor, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Text, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
