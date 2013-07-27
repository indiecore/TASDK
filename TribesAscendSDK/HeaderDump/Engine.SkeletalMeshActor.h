#pragma once
#include "Engine.Actor.h"
#include "Engine.InterpGroup.h"
#include "Engine.SeqAct_SetMaterial.h"
#include "Engine.MaterialInterface.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SeqAct_PlayFaceFXAnim.h"
#include "Engine.SoundCue.h"
#include "Engine.FaceFXAsset.h"
#include "Engine.SeqAct_AttachToActor.h"
#include "Engine.SeqAct_SetMesh.h"
#include "Engine.SeqAct_UpdatePhysBonesFromAnim.h"
#include "Engine.SeqAct_SetSkelControlTarget.h"
#include "Engine.Controller.h"
#include "Core.Object.h"
#include "Engine.AnimNotify_PlayParticleEffect.h"
#include "Engine.AnimNotify_ForceField.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SkeletalMeshActor : public Actor
	{
	public:
		struct SkelMeshActorControlTarget
		{
		public:
			ADD_OBJECT(Actor, TargetActor, 8)
			ADD_STRUCT(ScriptName, ControlName, 0)
		};
		struct CheckpointRecord
		{
		public:
			ADD_STRUCT(Rotator, Rotation, 16)
			ADD_STRUCT(Vector, Location, 4)
			ADD_BOOL(bSavedPosition, 0, 0x4)
			ADD_BOOL(bHidden, 0, 0x2)
			ADD_BOOL(bReplicated, 0, 0x1)
		};
		ADD_STRUCT(ScriptArray<SkeletalMeshActor::SkelMeshActorControlTarget>, ControlTargets, 500)
		ADD_STRUCT(ScriptArray<class InterpGroup*>, InterpGroupList, 512)
		ADD_STRUCT(float, SavedCurrentTime, 532)
		ADD_STRUCT(ScriptName, SavedAnimSeqName, 524)
		ADD_OBJECT(MaterialInterface, ReplicatedMaterial, 496)
		ADD_OBJECT(SkeletalMesh, ReplicatedMesh, 492)
		ADD_BOOL(bCollideActors_OldValue, 476, 0x8)
		ADD_BOOL(bForceSaveInCheckpoint, 476, 0x4)
		ADD_BOOL(bShouldDoAnimNotifies, 476, 0x2)
		ADD_BOOL(bDamageAppliesImpulse, 476, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26654);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26655);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAnimSetList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26656);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26657);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26659);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26662);
			byte params[4] = { NULL };
			*(class SeqAct_SetMaterial**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26664);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26666);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26668);
			byte params[36] = { NULL };
			*(ScriptName*)params = SlotName;
			*(int*)&params[8] = ChannelIndex;
			*(ScriptName*)&params[12] = InAnimSeqName;
			*(float*)&params[20] = InPosition;
			*(bool*)&params[24] = bFireNotifies;
			*(bool*)&params[28] = bLooping;
			*(bool*)&params[32] = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26677);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26679);
			byte params[4] = { NULL };
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26681);
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)params = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26687);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFaceFXAudioComponent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26688);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
		}
		void OnPlayFaceFXAnim(class SeqAct_PlayFaceFXAnim* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26690);
			byte params[4] = { NULL };
			*(class SeqAct_PlayFaceFXAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26693);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FaceFXAsset**)params;
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26695);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnSetMesh(class SeqAct_SetMesh* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26697);
			byte params[4] = { NULL };
			*(class SeqAct_SetMesh**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdatePhysBonesFromAnim(class SeqAct_UpdatePhysBonesFromAnim* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26699);
			byte params[4] = { NULL };
			*(class SeqAct_UpdatePhysBonesFromAnim**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetSkelControlTarget(class SeqAct_SetSkelControlTarget* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26701);
			byte params[4] = { NULL };
			*(class SeqAct_SetSkelControlTarget**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26704);
			byte params[8] = { NULL };
			*(class Actor**)params = Attachment;
			*(class SeqAct_AttachToActor**)&params[4] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26711);
			byte params[68] = { NULL };
			*(int*)params = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Vector*)&params[8] = HitLocation;
			*(Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26720);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CreateCheckpointRecord(SkeletalMeshActor::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26722);
			byte params[28] = { NULL };
			*(SkeletalMeshActor::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SkeletalMeshActor::CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(SkeletalMeshActor::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26724);
			byte params[28] = { NULL };
			*(SkeletalMeshActor::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SkeletalMeshActor::CheckpointRecord*)params;
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26726);
			byte params[8] = { NULL };
			*(class AnimNotify_PlayParticleEffect**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SkelMeshActorOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26732);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26734);
			byte params[8] = { NULL };
			*(class AnimNotify_ForceField**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
