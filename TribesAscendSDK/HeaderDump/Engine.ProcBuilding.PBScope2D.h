#pragma once
#include "Core.Object.Matrix.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ProcBuilding.PBScope2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ProcBuilding.PBScope2D." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBScope2D
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Matrix>, ScopeFrame, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DimX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DimZ, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
