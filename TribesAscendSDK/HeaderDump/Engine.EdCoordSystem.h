#pragma once
#include "Core.Object.h"
#include "Core.Object.Matrix.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.EdCoordSystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.EdCoordSystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class EdCoordSystem : public Object
	{
	public:
		ADD_VAR(::StrProperty, Desc, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, M, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
