#pragma once
#include "Engine__SeqAct_AttachToActor.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__Actor.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__Controller.h"
#include "Engine__SeqAct_Teleport.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.KAsset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.KAsset." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class KAsset : public Actor
	{
	public:
		ADD_OBJECT(PhysicsAsset, ReplicatedPhysAsset)
		ADD_OBJECT(SkeletalMesh, ReplicatedMesh)
		ADD_VAR(::BoolProperty, bBlockPawns, 0x4)
		ADD_VAR(::BoolProperty, bWakeOnLevelStart, 0x2)
		ADD_VAR(::BoolProperty, bDamageAppliesImpulse, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'SetMeshAndPhysAsset'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'TakeRadiusDamage'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'OnTeleport'
		// Here lies the not-yet-implemented method 'DoKismetAttachment'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
