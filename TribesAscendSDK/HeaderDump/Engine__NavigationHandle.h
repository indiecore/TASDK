#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavigationHandle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavigationHandle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavigationHandle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavigationHandle : public Object
	{
	public:
		ADD_VAR(::FloatProperty, LastPathFailTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LastPathError, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationHandle.NavMeshPathParams' for the property named 'CachedPathParams'!
		ADD_OBJECT(NavMeshPathGoalEvaluator, PathGoalList)
		ADD_OBJECT(NavMeshPathConstraint, PathConstraintList)
		ADD_VAR(::BoolProperty, bUltraVerbosePathDebugging, 0x8)
		ADD_VAR(::BoolProperty, bDebugConstraintsAndGoalEvals, 0x4)
		ADD_VAR(::BoolProperty, bUseORforEvaluateGoal, 0x2)
		ADD_VAR(::BoolProperty, bSkipRouteCacheUpdates, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.BasedPosition' for the property named 'FinalDestination'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SubGoal_DestPoly'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CurrentEdge'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'BestUnfinishedPathPoint'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.NavigationHandle.PathStore' for the property named 'PathCache'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'AnchorPoly'!
		ADD_OBJECT(Pylon, AnchorPylon)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
