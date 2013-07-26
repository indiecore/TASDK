#pragma once
#include "Core.Object.Set_Mirror.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Object.Map_Mirror." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Map_Mirror
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Set_Mirror>, Pairs, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
