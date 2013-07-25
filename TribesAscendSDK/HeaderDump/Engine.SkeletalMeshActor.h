#pragma once
#include "Engine.Actor.h"
#include "Engine.MaterialInterface.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.SeqAct_SetMaterial.h"
#include "Engine.InterpGroup.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SeqAct_PlayFaceFXAnim.h"
#include "Engine.SoundCue.h"
#include "Engine.FaceFXAsset.h"
#include "Engine.SeqAct_AttachToActor.h"
#include "Engine.SeqAct_SetMesh.h"
#include "Engine.SeqAct_UpdatePhysBonesFromAnim.h"
#include "Engine.SeqAct_SetSkelControlTarget.h"
#include "Engine.Controller.h"
#include "Engine.AnimNotify_PlayParticleEffect.h"
#include "Engine.AnimNotify_ForceField.h"
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
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnToggle");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetMaterial(class SeqAct_SetMaterial* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnSetMaterial");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetMaterial**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.BeginAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_BeginAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.MAT_BeginAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAnimPosition(ScriptName SlotName, int ChannelIndex, ScriptName InAnimSeqName, float InPosition, bool bFireNotifies, bool bLooping, bool bEnableRootMotion)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.SetAnimPosition");
			byte* params = (byte*)malloc(36);
			*(ScriptName*)params = SlotName;
			*(int*)(params + 8) = ChannelIndex;
			*(ScriptName*)(params + 12) = InAnimSeqName;
			*(float*)(params + 20) = InPosition;
			*(bool*)(params + 24) = bFireNotifies;
			*(bool*)(params + 28) = bLooping;
			*(bool*)(params + 32) = bEnableRootMotion;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.FinishAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MAT_FinishAnimControl(class InterpGroup* InInterpGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.MAT_FinishAnimControl");
			byte* params = (byte*)malloc(4);
			*(class InterpGroup**)params = InInterpGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PlayActorFaceFXAnim(class FaceFXAnimSet* AnimSet, ScriptArray<wchar_t> GroupName, ScriptArray<wchar_t> SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.PlayActorFaceFXAnim");
			byte* params = (byte*)malloc(36);
			*(class FaceFXAnimSet**)params = AnimSet;
			*(ScriptArray<wchar_t>*)(params + 4) = GroupName;
			*(ScriptArray<wchar_t>*)(params + 16) = SeqName;
			*(class SoundCue**)(params + 28) = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		void OnPlayFaceFXAnim(class SeqAct_PlayFaceFXAnim* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnPlayFaceFXAnim");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_PlayFaceFXAnim**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class FaceFXAsset* GetActorFaceFXAsset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.GetActorFaceFXAsset");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class FaceFXAsset**)params;
			free(params);
			return returnVal;
		}
		bool IsActorPlayingFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.IsActorPlayingFaceFXAnim");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnSetMesh(class SeqAct_SetMesh* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnSetMesh");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetMesh**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUpdatePhysBonesFromAnim(class SeqAct_UpdatePhysBonesFromAnim* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnUpdatePhysBonesFromAnim");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_UpdatePhysBonesFromAnim**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetSkelControlTarget(class SeqAct_SetSkelControlTarget* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.OnSetSkelControlTarget");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetSkelControlTarget**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DoKismetAttachment(class Actor* Attachment, class SeqAct_AttachToActor* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.DoKismetAttachment");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Attachment;
			*(class SeqAct_AttachToActor**)(params + 4) = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TakeDamage(int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, 
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void* HitInfo, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.TakeDamage");
			byte* params = (byte*)malloc(68);
			*(int*)params = Damage;
			*(class Controller**)(params + 4) = EventInstigator;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = Momentum;
			*(ScriptClass**)(params + 32) = DamageType;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Actor.TraceHitInfo'!
void**)(params + 36) = HitInfo;
			*(class Actor**)(params + 64) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.ShouldSaveForCheckpoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshActor.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.CreateCheckpointRecord");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshActor.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshActor.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshActor.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(28);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshActor.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshActor.CheckpointRecord'!
void**)params;
			free(params);
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.PlayParticleEffect");
			byte* params = (byte*)malloc(8);
			*(class AnimNotify_PlayParticleEffect**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SkelMeshActorOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.SkelMeshActorOnParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshActor.CreateForceField");
			byte* params = (byte*)malloc(8);
			*(class AnimNotify_ForceField**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
