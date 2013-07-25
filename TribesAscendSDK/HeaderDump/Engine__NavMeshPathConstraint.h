#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshPathConstraint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavMeshPathConstraint." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPathConstraint : public Object
	{
	public:
		ADD_VAR(::FloatProperty, AddedHeuristicCost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AddedDirectCost, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumThrownOutNodes, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumNodesProcessed, 0xFFFFFFFF)
		ADD_OBJECT(NavMeshPathConstraint, NextConstraint)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
