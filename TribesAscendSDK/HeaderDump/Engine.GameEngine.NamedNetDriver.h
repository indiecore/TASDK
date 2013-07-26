#pragma once
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameEngine.NamedNetDriver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameEngine.NamedNetDriver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NamedNetDriver
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, NetDriver, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, NetDriverName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
