#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ReachSpec." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ReachSpec." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ReachSpec." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ReachSpec : public Object
	{
	public:
		ADD_OBJECT(Actor, BlockedBy)
		ADD_VAR(::BoolProperty, bDisabled, 0x10)
		ADD_VAR(::BoolProperty, bSkipPrune, 0x8)
		ADD_VAR(::BoolProperty, bCheckForObstructions, 0x4)
		ADD_VAR(::BoolProperty, bCanCutCorners, 0x2)
		ADD_VAR(::BoolProperty, bAddToNavigationOctree, 0x1)
		ADD_VAR(::ByteProperty, PathColorIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bPruned, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxLandingVelocity, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, reachFlags, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CollisionHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CollisionRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.ActorReference' for the property named 'End'!
		ADD_OBJECT(NavigationPoint, Start)
		ADD_STRUCT(::VectorProperty, Direction, 0xFFFFFFFF
		ADD_VAR(::IntProperty, Distance, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'NavOctreeObject'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
