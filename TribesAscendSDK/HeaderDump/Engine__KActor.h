#pragma once
#include "Engine__DynamicSMActor.h"
#include "Engine__PhysicalMaterial.h"
#include "Engine__Controller.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__SeqAct_Teleport.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.KActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class KActor : public DynamicSMActor
	{
	public:
		ADD_STRUCT(::RotatorProperty, InitialRotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, InitialLocation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ReplicatedDrawScale3D, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, AngErrorAccumulator, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.RigidBodyState' for the property named 'RBState'!
		ADD_VAR(::FloatProperty, MaxPhysicsVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightMaxTorque, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StayUprightTorqueFactor, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.PhysEffectInfo' for the property named 'SlideEffectInfo'!
		ADD_VAR(::FloatProperty, LastSlideTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.PhysEffectInfo' for the property named 'ImpactEffectInfo'!
		ADD_VAR(::FloatProperty, LastImpactTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDisableClientSidePawnInteractions, 0x80)
		ADD_VAR(::BoolProperty, bNeedsRBStateReplication, 0x40)
		ADD_VAR(::BoolProperty, bLimitMaxPhysicsVelocity, 0x20)
		ADD_VAR(::BoolProperty, bEnableStayUprightSpring, 0x10)
		ADD_VAR(::BoolProperty, bSlideActive, 0x8)
		ADD_VAR(::BoolProperty, bCurrentSlide, 0x4)
		ADD_VAR(::BoolProperty, bWakeOnLevelStart, 0x2)
		ADD_VAR(::BoolProperty, bDamageAppliesImpulse, 0x1)
		// Here lies the not-yet-implemented method 'GetKActorPhysMaterial'
		// Here lies the not-yet-implemented method 'ResolveRBState'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'FellOutOfWorld'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'SetPhysicalCollisionProperties'
		// Here lies the not-yet-implemented method 'SpawnedByKismet'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'ApplyImpulse'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'OnTeleport'
		// Here lies the not-yet-implemented method 'Reset'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
