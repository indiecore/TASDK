#pragma once
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ProcBuilding.PBEdgeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty ProcBuilding.PBEdgeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBEdgeInfo
	{
	public:
		ADD_STRUCT(::VectorProperty, EdgeEnd, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EdgeStart, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ScopeAIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ScopeAEdge, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ScopeBIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ScopeBEdge, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, EdgeAngle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
