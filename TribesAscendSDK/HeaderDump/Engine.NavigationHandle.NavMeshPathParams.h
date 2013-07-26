#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " NavigationHandle.NavMeshPathParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty NavigationHandle.NavMeshPathParams." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshPathParams
	{
	public:
		ADD_VAR(::FloatProperty, MaxHoverDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinWalkableZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDropHeight, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SearchStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SearchLaneMultiplier, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SearchExtent, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAbleToSearch, 0x4)
		ADD_VAR(::BoolProperty, bNeedsMantleValidityTest, 0x2)
		ADD_VAR(::BoolProperty, bCanMantle, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, Interface, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
