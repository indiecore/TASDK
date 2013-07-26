#pragma once
#include "Engine.NavMeshPathConstraint.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.NavMeshPathConstraintCacheDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty WorldInfo.NavMeshPathConstraintCacheDatum." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPathConstraintCacheDatum
	{
	public:
		ADD_VAR(::IntProperty, ListIdx, 0xFFFFFFFF)
		ADD_OBJECT(NavMeshPathConstraint, List)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
