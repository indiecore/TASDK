#pragma once
#include "Engine__Actor.h"
#include "Engine__SeqAct_Toggle.h"
#include "Engine__FaceFXAnimSet.h"
#include "Engine__InterpGroup.h"
#include "Engine__MaterialInterface.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__SeqAct_SetMaterial.h"
#include "Engine__SoundCue.h"
#include "Engine__SeqAct_PlayFaceFXAnim.h"
#include "Engine__FaceFXAsset.h"
#include "Engine__SeqAct_SetMesh.h"
#include "Engine__SeqAct_UpdatePhysBonesFromAnim.h"
#include "Engine__SeqAct_SetSkelControlTarget.h"
#include "Engine__SeqAct_AttachToActor.h"
#include "Engine__Controller.h"
#include "Engine__AnimNotify_PlayParticleEffect.h"
#include "Engine__AnimNotify_ForceField.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkeletalMeshActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SkeletalMeshActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkeletalMeshActor : public Actor
	{
	public:
		ADD_VAR(::FloatProperty, SavedCurrentTime, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SavedAnimSeqName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, ReplicatedMaterial)
		ADD_OBJECT(SkeletalMesh, ReplicatedMesh)
		ADD_VAR(::BoolProperty, bCollideActors_OldValue, 0x8)
		ADD_VAR(::BoolProperty, bForceSaveInCheckpoint, 0x4)
		ADD_VAR(::BoolProperty, bShouldDoAnimNotifies, 0x2)
		ADD_VAR(::BoolProperty, bDamageAppliesImpulse, 0x1)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'UpdateAnimSetList'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'OnToggle'
		// Here lies the not-yet-implemented method 'OnSetMaterial'
		// Here lies the not-yet-implemented method 'BeginAnimControl'
		// Here lies the not-yet-implemented method 'MAT_BeginAnimControl'
		// Here lies the not-yet-implemented method 'SetAnimPosition'
		// Here lies the not-yet-implemented method 'FinishAnimControl'
		// Here lies the not-yet-implemented method 'MAT_FinishAnimControl'
		// Here lies the not-yet-implemented method 'PlayActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'StopActorFaceFXAnim'
		// Here lies the not-yet-implemented method 'GetFaceFXAudioComponent'
		// Here lies the not-yet-implemented method 'OnPlayFaceFXAnim'
		// Here lies the not-yet-implemented method 'GetActorFaceFXAsset'
		// Here lies the not-yet-implemented method 'IsActorPlayingFaceFXAnim'
		// Here lies the not-yet-implemented method 'OnSetMesh'
		// Here lies the not-yet-implemented method 'OnUpdatePhysBonesFromAnim'
		// Here lies the not-yet-implemented method 'OnSetSkelControlTarget'
		// Here lies the not-yet-implemented method 'DoKismetAttachment'
		// Here lies the not-yet-implemented method 'TakeDamage'
		// Here lies the not-yet-implemented method 'ShouldSaveForCheckpoint'
		// Here lies the not-yet-implemented method 'CreateCheckpointRecord'
		// Here lies the not-yet-implemented method 'ApplyCheckpointRecord'
		// Here lies the not-yet-implemented method 'PlayParticleEffect'
		// Here lies the not-yet-implemented method 'SkelMeshActorOnParticleSystemFinished'
		// Here lies the not-yet-implemented method 'CreateForceField'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
