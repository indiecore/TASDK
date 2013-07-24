#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdDestination." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.GameCrowdDestination." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdDestination." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdDestination : public GameCrowdInteractionPoint
	{
	public:
		ADD_OBJECT(GameCrowdPopulationManager, MyPopMgr)
		ADD_VAR(::FloatProperty, LastSpawnTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Priority, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdAgent, AgentEnRoute)
		ADD_VAR(::FloatProperty, SpawnRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteractionDelay, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, InteractionTag, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExactReachTolerance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CustomerCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Frequency, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Capacity, 0xFFFFFFFF)
		ADD_OBJECT(GameCrowdDestinationQueuePoint, QueueHead)
		ADD_VAR(::BoolProperty, bHasNavigationMesh, 0x20000)
		ADD_VAR(::BoolProperty, bAdjacentToVisibleNode, 0x10000)
		ADD_VAR(::BoolProperty, bIsBeyondSpawnDistance, 0x8000)
		ADD_VAR(::BoolProperty, bCanSpawnHereNow, 0x4000)
		ADD_VAR(::BoolProperty, bWillBeVisible, 0x2000)
		ADD_VAR(::BoolProperty, bIsVisible, 0x1000)
		ADD_VAR(::BoolProperty, bSoftPerimeter, 0x800)
		ADD_VAR(::BoolProperty, bSpawnAtEdge, 0x400)
		ADD_VAR(::BoolProperty, bLineSpawner, 0x200)
		ADD_VAR(::BoolProperty, bAllowsSpawning, 0x100)
		ADD_VAR(::BoolProperty, bHasRestrictions, 0x80)
		ADD_VAR(::BoolProperty, bMustReachExactly, 0x40)
		ADD_VAR(::BoolProperty, bFleeDestination, 0x20)
		ADD_VAR(::BoolProperty, bSkipBehaviorIfPanicked, 0x10)
		ADD_VAR(::BoolProperty, bAvoidWhenPanicked, 0x8)
		ADD_VAR(::BoolProperty, bLastAllowableResult, 0x4)
		ADD_VAR(::BoolProperty, bAllowAsPreviousDestination, 0x2)
		ADD_VAR(::BoolProperty, bKillWhenReached, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'VfTable_IEditorLinkSelectionInterface'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
