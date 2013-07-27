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
		class SkelMeshActorControlTarget
		{
		public:
			ADD_OBJECT(Actor, TargetActor, 8)
			ADD_STRUCT(ScriptName, ControlName, 0)
		};
		class CheckpointRecord
		{
		public:
			ADD_STRUCT(Object::Rotator, Rotation, 16)
			ADD_STRUCT(Object::Vector, Location, 4)
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAnimSetList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.UpdateAnimSetList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnToggle");
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnSetMaterial");
			byte params[4] = { NULL };
			*(class SeqAct_SetMaterial**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.BeginAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.MAT_BeginAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.SetAnimPosition");
			byte params[36] = { NULL };
			*(ScriptName*)&params[0] = SlotName;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.FinishAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MAT_FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.MAT_FinishAnimControl");
			byte params[4] = { NULL };
			*(class InterpGroup**)&params[0] = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.PlayActorFaceFXAnim");
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)&params[0] = AnimSet;
			*(ScriptString**)&params[4] = GroupName;
			*(ScriptString**)&params[16] = SeqName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopActorFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.StopActorFaceFXAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetFaceFXAudioComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.GetFaceFXAudioComponent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0];
		}
		void OnPlayFaceFXAnim(class SeqAct_PlayFaceFXAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnPlayFaceFXAnim");
			byte params[4] = { NULL };
			*(class SeqAct_PlayFaceFXAnim**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.GetActorFaceFXAsset");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class FaceFXAsset**)&params[0];
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.IsActorPlayingFaceFXAnim");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnSetMesh(class SeqAct_SetMesh* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnSetMesh");
			byte params[4] = { NULL };
			*(class SeqAct_SetMesh**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUpdatePhysBonesFromAnim(class SeqAct_UpdatePhysBonesFromAnim* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnUpdatePhysBonesFromAnim");
			byte params[4] = { NULL };
			*(class SeqAct_UpdatePhysBonesFromAnim**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetSkelControlTarget(class SeqAct_SetSkelControlTarget* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnSetSkelControlTarget");
			byte params[4] = { NULL };
			*(class SeqAct_SetSkelControlTarget**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.DoKismetAttachment");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = Attachment;
			*(class SeqAct_AttachToActor**)&params[4] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Object::Vector HitLocation, Object::Vector Momentum, ScriptClass* DamageType, Actor::TraceHitInfo HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.TakeDamage");
			byte params[68] = { NULL };
			*(int*)&params[0] = Damage;
			*(class Controller**)&params[4] = EventInstigator;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = Momentum;
			*(ScriptClass**)&params[32] = DamageType;
			*(Actor::TraceHitInfo*)&params[36] = HitInfo;
			*(class Actor**)&params[64] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.ShouldSaveForCheckpoint");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CreateCheckpointRecord(SkeletalMeshActor::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.CreateCheckpointRecord");
			byte params[28] = { NULL };
			*(SkeletalMeshActor::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SkeletalMeshActor::CheckpointRecord*)&params[0];
		}
		void ApplyCheckpointRecord(SkeletalMeshActor::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.ApplyCheckpointRecord");
			byte params[28] = { NULL };
			*(SkeletalMeshActor::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(SkeletalMeshActor::CheckpointRecord*)&params[0];
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.PlayParticleEffect");
			byte params[8] = { NULL };
			*(class AnimNotify_PlayParticleEffect**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SkelMeshActorOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.SkelMeshActorOnParticleSystemFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.CreateForceField");
			byte params[8] = { NULL };
			*(class AnimNotify_ForceField**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
