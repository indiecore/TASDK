#pragma once
#include "Engine__MeshComponent.h"
#include "Engine__AnimNode.h"
#include "Engine__PhysicsAssetInstance.h"
#include "Engine__PhysicsAsset.h"
#include "Engine__SkeletalMeshSocket.h"
#include "Engine__AnimTree.h"
#include "Engine__SkeletalMesh.h"
#include "Engine__Material.h"
#include "Engine__RB_BodyInstance.h"
#include "Engine__AnimSequence.h"
#include "Engine__SkelControlBase.h"
#include "Engine__MorphTarget.h"
#include "Engine__MorphNodeBase.h"
#include "Engine__FaceFXAnimSet.h"
#include "Engine__SoundCue.h"
#include "Engine__AnimNotify_ForceField.h"
#include "Engine__AnimNotify_PlayParticleEffect.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkeletalMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkeletalMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SkeletalMeshComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkeletalMeshComponent : public MeshComponent
	{
	public:
		ADD_OBJECT(AnimNode, Animations)
		ADD_OBJECT(PhysicsAssetInstance, PhysicsAssetInstance)
		ADD_OBJECT(PhysicsAsset, PhysicsAsset)
		ADD_OBJECT(SkeletalMesh, SkeletalMesh)
		ADD_OBJECT(AnimTree, AnimTreeTemplate)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ApexClothing'!
		ADD_VAR(::FloatProperty, PhysicsWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GlobalAnimRateScale, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'MeshObject'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'WireframeColor'!
		ADD_VAR(::IntProperty, LowUpdateFrameRate, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShouldIgnoreParentAnimComponent, 0x1)
		ADD_VAR(::IntProperty, ForcedLodModel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinLodModel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PredictedLODLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OldPredictedLODLevel, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDistanceFactor, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bForceWireframe, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bForceRefpose, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bOldForceRefPose, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bNoSkeletonUpdate, 0x1)
		ADD_VAR(::IntProperty, bDisplayBones, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bShowPrePhysBones, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bHideSkin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bForceRawOffset, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bIgnoreControllers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bTransformFromAnimParent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TickTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InitTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CachedAtomsTag, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bUseSingleBodyPhysics, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bRequiredBonesUpToDate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinDistFactorForKinematicUpdate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FramesPhysicsAsleep, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSkipAllUpdateWhenPhysicsAsleep, 0x1)
		ADD_VAR(::BoolProperty, bConsiderAllBodiesForBounds, 0x2)
		ADD_VAR(::BoolProperty, bUpdateSkelWhenNotRendered, 0x4)
		ADD_VAR(::BoolProperty, bIgnoreControllersWhenNotRendered, 0x8)
		ADD_VAR(::BoolProperty, bTickAnimNodesWhenNotRendered, 0x10)
		ADD_VAR(::BoolProperty, bNotUpdatingKinematicDueToDistance, 0x20)
		ADD_VAR(::BoolProperty, bForceDiscardRootMotion, 0x40)
		ADD_VAR(::BoolProperty, bRootMotionModeChangeNotify, 0x80)
		ADD_VAR(::BoolProperty, bRootMotionExtractedNotify, 0x100)
		ADD_VAR(::BoolProperty, bDisableFaceFXMaterialInstanceCreation, 0x200)
		ADD_VAR(::BoolProperty, bAnimTreeInitialised, 0x400)
		ADD_VAR(::BoolProperty, bForceMeshObjectUpdate, 0x800)
		ADD_VAR(::BoolProperty, bHasPhysicsAssetInstance, 0x1000)
		ADD_VAR(::BoolProperty, bUpdateKinematicBonesFromAnimation, 0x2000)
		ADD_VAR(::BoolProperty, bUpdateJointsFromAnimation, 0x4000)
		ADD_VAR(::BoolProperty, bSkelCompFixed, 0x8000)
		ADD_VAR(::BoolProperty, bHasHadPhysicsBlendedIn, 0x10000)
		ADD_VAR(::BoolProperty, bForceUpdateAttachmentsInTick, 0x20000)
		ADD_VAR(::BoolProperty, bEnableFullAnimWeightBodies, 0x40000)
		ADD_VAR(::BoolProperty, bPerBoneVolumeEffects, 0x80000)
		ADD_VAR(::BoolProperty, bPerBoneMotionBlur, 0x100000)
		ADD_VAR(::BoolProperty, bSyncActorLocationToRootRigidBody, 0x200000)
		ADD_VAR(::BoolProperty, bUseRawData, 0x400000)
		ADD_VAR(::BoolProperty, bDisableWarningWhenAnimNotFound, 0x800000)
		ADD_VAR(::BoolProperty, bOverrideAttachmentOwnerVisibility, 0x1000000)
		ADD_VAR(::BoolProperty, bNeedsToDeleteHitMask, 0x2000000)
		ADD_VAR(::BoolProperty, bPauseAnims, 0x4000000)
		ADD_VAR(::BoolProperty, bChartDistanceFactor, 0x8000000)
		ADD_VAR(::BoolProperty, bEnableLineCheckWithBounds, 0x10000000)
		ADD_VAR(::BoolProperty, bCanHighlightSelectedSections, 0x20000000)
		ADD_STRUCT(::VectorProperty, LineCheckBoundsScale, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bEnableClothSimulation, 0x1)
		ADD_VAR(::BoolProperty, bDisableClothCollision, 0x2)
		ADD_VAR(::BoolProperty, bClothFrozen, 0x4)
		ADD_VAR(::BoolProperty, bAutoFreezeClothWhenNotRendered, 0x8)
		ADD_VAR(::BoolProperty, bClothAwakeOnStartup, 0x10)
		ADD_VAR(::BoolProperty, bClothBaseVelClamp, 0x20)
		ADD_VAR(::BoolProperty, bClothBaseVelInterp, 0x40)
		ADD_VAR(::BoolProperty, bAttachClothVertsToBaseBody, 0x80)
		ADD_VAR(::BoolProperty, bIsClothOnStaticObject, 0x100)
		ADD_VAR(::BoolProperty, bUpdatedFixedClothVerts, 0x200)
		ADD_VAR(::BoolProperty, bClothPositionalDampening, 0x400)
		ADD_VAR(::BoolProperty, bClothWindRelativeToOwner, 0x800)
		ADD_VAR(::BoolProperty, bRecentlyRendered, 0x1000)
		ADD_VAR(::BoolProperty, bCacheAnimSequenceNodes, 0x2000)
		ADD_VAR(::BoolProperty, bNeedsInstanceWeightUpdate, 0x4000)
		ADD_VAR(::BoolProperty, bAlwaysUseInstanceWeights, 0x8000)
		ADD_VAR(::BoolProperty, bUpdateComposeSkeletonPasses, 0x10000)
		ADD_VAR(::BoolProperty, bValidTemporarySavedAnimSets, 0x20000)
		ADD_STRUCT(::VectorProperty, FrozenLocalToWorldPos, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, FrozenLocalToWorldRot, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ClothExternalForce, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ClothWind, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, ClothBaseVelClampRange, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, ClothBlendWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothDynamicBlendWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothBlendMinDistanceFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothBlendMaxDistanceFactor, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, MinPosDampRange, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MaxPosDampRange, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MinPosDampScale, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, MaxPosDampScale, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ClothSim'!
		ADD_VAR(::IntProperty, SceneIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumClothMeshVerts, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumClothMeshIndices, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumClothMeshParentIndices, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClothDirtyBufferFlag, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClothRBChannel, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer' for the property named 'ClothRBCollideWithChannels'!
		ADD_VAR(::FloatProperty, ClothForceScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothImpulseScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothAttachmentTearFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClothUseCompartment, 0x1)
		ADD_VAR(::FloatProperty, MinDistanceForClothReset, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, LastClothLocation, 0xFFFFFFFF
		ADD_VAR(::ByteProperty, ApexClothingRBChannel, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer' for the property named 'ApexClothingRBCollideWithChannels'!
		ADD_VAR(::BoolProperty, bAutoFreezeApexClothingWhenNotRendered, 0x1)
		ADD_STRUCT(::VectorProperty, WindVelocity, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, WindVelocityBlendTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSkipInitClothing, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SoftBodySim'!
		ADD_VAR(::IntProperty, SoftBodySceneIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableSoftBodySimulation, 0x1)
		ADD_VAR(::IntProperty, NumSoftBodyTetraVerts, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumSoftBodyTetraIndices, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyImpulseScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSoftBodyFrozen, 0x1)
		ADD_VAR(::BoolProperty, bAutoFreezeSoftBodyWhenNotRendered, 0x2)
		ADD_VAR(::BoolProperty, bSoftBodyAwakeOnStartup, 0x4)
		ADD_VAR(::BoolProperty, bSoftBodyUseCompartment, 0x8)
		ADD_VAR(::ByteProperty, SoftBodyRBChannel, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.PrimitiveComponent.RBCollisionChannelContainer' for the property named 'SoftBodyRBCollideWithChannels'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'SoftBodyASVPlane'!
		ADD_OBJECT(Material, LimitMaterial)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.BoneAtom' for the property named 'RootMotionDelta'!
		ADD_STRUCT(::VectorProperty, RootMotionVelocity, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, RootBoneTranslation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, RootMotionAccelScale, 0xFFFFFFFF
		ADD_VAR(::ByteProperty, RootMotionMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PreviousRMM, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PendingRMM, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, OldPendingRMM, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, bRMMOneFrameDelay, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RootMotionRotationMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FaceFXBlendMode, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'FaceFXActorInstance'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.BoneAtom' for the property named 'LocalToWorldBoneAtom'!
		ADD_VAR(::FloatProperty, ProgressiveDrawingFraction, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CustomSortAlternateIndexMode, 0xFFFFFFFF)
		void AttachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName BoneName, Vector RelativeLocation, Rotator RelativeRotation, Vector RelativeScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachComponent");
			byte* params = (byte*)malloc(48);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)(params + 4) = BoneName;
			*(Vector*)(params + 12) = RelativeLocation;
			*(Rotator*)(params + 24) = RelativeRotation;
			*(Vector*)(params + 36) = RelativeScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DetachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.DetachComponent");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AttachComponentToSocket(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachComponentToSocket");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)(params + 4) = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetSocketWorldLocationAndRotation(ScriptName InSocketName, Vector& OutLocation, Rotator& OutRotation, int Space)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetSocketWorldLocationAndRotation");
			byte* params = (byte*)malloc(40);
			*(ScriptName*)params = InSocketName;
			*(Vector*)(params + 8) = OutLocation;
			*(Rotator*)(params + 20) = OutRotation;
			*(int*)(params + 32) = Space;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutLocation = *(Vector*)(params + 8);
			OutRotation = *(Rotator*)(params + 20);
			auto returnVal = *(bool*)(params + 36);
			free(params);
			return returnVal;
		}
		class SkeletalMeshSocket* GetSocketByName(ScriptName InSocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetSocketByName");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InSocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMeshSocket**)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName GetSocketBoneName(ScriptName InSocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetSocketBoneName");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = InSocketName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FindComponentAttachedToBone(ScriptName InBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindComponentAttachedToBone");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 8);
			free(params);
			return returnVal;
		}
		bool IsComponentAttached(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.IsComponentAttached");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)(params + 4) = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void AttachedComponents(ScriptClass* BaseClass, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& OutComponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachedComponents");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = BaseClass;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OutComponent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutComponent = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4);
			free(params);
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* GetTransformMatrix()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetTransformMatrix");
			byte* params = (byte*)malloc(64);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)params;
			free(params);
			return returnVal;
		}
		void SetSkeletalMesh(class SkeletalMesh* NewMesh, bool bKeepSpaceBases)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetSkeletalMesh");
			byte* params = (byte*)malloc(8);
			*(class SkeletalMesh**)params = NewMesh;
			*(bool*)(params + 4) = bKeepSpaceBases;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPhysicsAsset(class PhysicsAsset* NewPhysicsAsset, bool bForceReInit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetPhysicsAsset");
			byte* params = (byte*)malloc(8);
			*(class PhysicsAsset**)params = NewPhysicsAsset;
			*(bool*)(params + 4) = bForceReInit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetForceRefPose(bool bNewForceRefPose)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetForceRefPose");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewForceRefPose;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetEnableClothSimulation(bool bInEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetEnableClothSimulation");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothFrozen(bool bNewFrozen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothFrozen");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewFrozen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetEnableClothingSimulation(bool bInEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetEnableClothingSimulation");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bInEnable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateClothParams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateClothParams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetClothExternalForce(Vector InForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothExternalForce");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = InForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAttachClothVertsToBaseBody(bool bAttachVerts)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetAttachClothVertsToBaseBody");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAttachVerts;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetClothVertsToRefPose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.ResetClothVertsToRefPose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetClothAttachmentResponseCoefficient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothAttachmentResponseCoefficient");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothAttachmentTearFactor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothAttachmentTearFactor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothBendingStiffness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothBendingStiffness");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothCollisionResponseCoefficient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothCollisionResponseCoefficient");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothDampingCoefficient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothDampingCoefficient");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		int GetClothFlags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothFlags");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		float GetClothFriction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothFriction");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothPressure()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothPressure");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothSleepLinearVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothSleepLinearVelocity");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		int GetClothSolverIterations()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothSolverIterations");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		float GetClothStretchingStiffness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothStretchingStiffness");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothTearFactor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothTearFactor");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		float GetClothThickness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothThickness");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		void SetClothAttachmentResponseCoefficient(float ClothAttachmentResponseCoefficient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothAttachmentResponseCoefficient");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothAttachmentResponseCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothAttachmentTearFactor(float ClothAttachTearFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothAttachmentTearFactor");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothAttachTearFactor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothBendingStiffness(float ClothBendingStiffness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothBendingStiffness");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothBendingStiffness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothCollisionResponseCoefficient(float ClothCollisionResponseCoefficient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothCollisionResponseCoefficient");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothCollisionResponseCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothDampingCoefficient(float ClothDampingCoefficient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothDampingCoefficient");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothDampingCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothFlags(int ClothFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothFlags");
			byte* params = (byte*)malloc(4);
			*(int*)params = ClothFlags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothFriction(float ClothFriction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothFriction");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothFriction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothPressure(float ClothPressure)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothPressure");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothPressure;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothSleepLinearVelocity(float ClothSleepLinearVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothSleepLinearVelocity");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothSleepLinearVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothSolverIterations(int ClothSolverIterations)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothSolverIterations");
			byte* params = (byte*)malloc(4);
			*(int*)params = ClothSolverIterations;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothStretchingStiffness(float ClothStretchingStiffness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothStretchingStiffness");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothStretchingStiffness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothTearFactor(float ClothTearFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothTearFactor");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothTearFactor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothThickness(float ClothThickness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothThickness");
			byte* params = (byte*)malloc(4);
			*(float*)params = ClothThickness;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothSleep(bool IfClothSleep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothSleep");
			byte* params = (byte*)malloc(4);
			*(bool*)params = IfClothSleep;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothPosition(Vector ClothOffSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothPosition");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = ClothOffSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothVelocity(Vector VelocityOffSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothVelocity");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = VelocityOffSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AttachClothToCollidingShapes(bool AttatchTwoWay, bool AttachTearable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachClothToCollidingShapes");
			byte* params = (byte*)malloc(8);
			*(bool*)params = AttatchTwoWay;
			*(bool*)(params + 4) = AttachTearable;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableClothValidBounds(bool IfEnableClothValidBounds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.EnableClothValidBounds");
			byte* params = (byte*)malloc(4);
			*(bool*)params = IfEnableClothValidBounds;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetClothValidBounds(Vector ClothValidBoundsMin, Vector ClothValidBoundsMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothValidBounds");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = ClothValidBoundsMin;
			*(Vector*)(params + 12) = ClothValidBoundsMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateSoftBodyParams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateSoftBodyParams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSoftBodyFrozen(bool bNewFrozen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetSoftBodyFrozen");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewFrozen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void WakeSoftBody()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.WakeSoftBody");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class AnimSequence* FindAnimSequence(ScriptName AnimSeqName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindAnimSequence");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = AnimSeqName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimSequence**)(params + 8);
			free(params);
			return returnVal;
		}
		void SaveAnimSets()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SaveAnimSets");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestoreSavedAnimSets()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.RestoreSavedAnimSets");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetAnimRateByDuration(ScriptName AnimSeqName, float Duration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetAnimRateByDuration");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = AnimSeqName;
			*(float*)(params + 8) = Duration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		float GetAnimLength(ScriptName AnimSeqName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetAnimLength");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = AnimSeqName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		class MorphTarget* FindMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindMorphTarget");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MorphTarget**)(params + 8);
			free(params);
			return returnVal;
		}
		class AnimNode* FindAnimNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindAnimNode");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class AnimNode**)(params + 8);
			free(params);
			return returnVal;
		}
		void AllAnimNodes(ScriptClass* BaseClass, class AnimNode*& Node)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AllAnimNodes");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = BaseClass;
			*(class AnimNode**)(params + 4) = Node;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Node = *(class AnimNode**)(params + 4);
			free(params);
		}
		class SkelControlBase* FindSkelControl(ScriptName InControlName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindSkelControl");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InControlName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkelControlBase**)(params + 8);
			free(params);
			return returnVal;
		}
		class MorphNodeBase* FindMorphNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindMorphNode");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MorphNodeBase**)(params + 8);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void* GetBoneQuaternion(ScriptName BoneName, int Space)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneQuaternion");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = BoneName;
			*(int*)(params + 8) = Space;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Quat'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		Vector GetBoneLocation(ScriptName BoneName, int Space)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneLocation");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = BoneName;
			*(int*)(params + 8) = Space;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		int MatchRefBone(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.MatchRefBone");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName GetBoneName(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneName");
			byte* params = (byte*)malloc(12);
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void* GetBoneMatrix(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneMatrix");
			byte* params = (byte*)malloc(68);
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Matrix'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		ScriptName GetParentBone(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetParentBone");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetBoneNames(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& BoneNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneNames");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = BoneNames;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BoneNames = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		bool BoneIsChildOf(ScriptName BoneName, ScriptName ParentBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.BoneIsChildOf");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = BoneName;
			*(ScriptName*)(params + 8) = ParentBoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		Vector GetRefPosePosition(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetRefPosePosition");
			byte* params = (byte*)malloc(16);
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetBoneAxis(ScriptName BoneName, byte Axis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneAxis");
			byte* params = (byte*)malloc(21);
			*(ScriptName*)params = BoneName;
			*(params + 8) = Axis;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 12);
			free(params);
			return returnVal;
		}
		void TransformToBoneSpace(ScriptName BoneName, Vector InPosition, Rotator InRotation, Vector& OutPosition, Rotator& OutRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.TransformToBoneSpace");
			byte* params = (byte*)malloc(56);
			*(ScriptName*)params = BoneName;
			*(Vector*)(params + 8) = InPosition;
			*(Rotator*)(params + 20) = InRotation;
			*(Vector*)(params + 32) = OutPosition;
			*(Rotator*)(params + 44) = OutRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutPosition = *(Vector*)(params + 32);
			OutRotation = *(Rotator*)(params + 44);
			free(params);
		}
		void TransformFromBoneSpace(ScriptName BoneName, Vector InPosition, Rotator InRotation, Vector& OutPosition, Rotator& OutRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.TransformFromBoneSpace");
			byte* params = (byte*)malloc(56);
			*(ScriptName*)params = BoneName;
			*(Vector*)(params + 8) = InPosition;
			*(Rotator*)(params + 20) = InRotation;
			*(Vector*)(params + 32) = OutPosition;
			*(Rotator*)(params + 44) = OutRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutPosition = *(Vector*)(params + 32);
			OutRotation = *(Rotator*)(params + 44);
			free(params);
		}
		ScriptName FindClosestBone(Vector TestLocation, Vector& BoneLocation, float IgnoreScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindClosestBone");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = TestLocation;
			*(Vector*)(params + 12) = BoneLocation;
			*(float*)(params + 24) = IgnoreScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			BoneLocation = *(Vector*)(params + 12);
			auto returnVal = *(ScriptName*)(params + 28);
			free(params);
			return returnVal;
		}
		Vector GetClosestCollidingBoneLocation(Vector TestLocation, bool bCheckZeroExtent, bool bCheckNonZeroExtent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClosestCollidingBoneLocation");
			byte* params = (byte*)malloc(32);
			*(Vector*)params = TestLocation;
			*(bool*)(params + 12) = bCheckZeroExtent;
			*(bool*)(params + 16) = bCheckNonZeroExtent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 20);
			free(params);
			return returnVal;
		}
		void SetAnimTreeTemplate(class AnimTree* NewTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetAnimTreeTemplate");
			byte* params = (byte*)malloc(4);
			*(class AnimTree**)params = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetParentAnimComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewParentAnimComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetParentAnimComponent");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewParentAnimComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateParentBoneMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateParentBoneMap");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitSkelControls()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.InitSkelControls");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitMorphTargets()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.InitMorphTargets");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindConstraintIndex(ScriptName ConstraintName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindConstraintIndex");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = ConstraintName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptName FindConstraintBoneName(int ConstraintIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindConstraintBoneName");
			byte* params = (byte*)malloc(12);
			*(int*)params = ConstraintIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 4);
			free(params);
			return returnVal;
		}
		class RB_BodyInstance* FindBodyInstanceNamed(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindBodyInstanceNamed");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class RB_BodyInstance**)(params + 8);
			free(params);
			return returnVal;
		}
		void SetHasPhysicsAssetInstance(bool bHasInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetHasPhysicsAssetInstance");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bHasInstance;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateRBBonesFromSpaceBases(bool bMoveUnfixedBodies, bool bTeleport)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateRBBonesFromSpaceBases");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bMoveUnfixedBodies;
			*(bool*)(params + 4) = bTeleport;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceSkelUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.ForceSkelUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAnimations()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateAnimations");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetBonesWithinRadius(Vector Origin, float Radius, int TraceFlags, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBonesWithinRadius");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = Origin;
			*(float*)(params + 12) = Radius;
			*(int*)(params + 16) = TraceFlags;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20) = out_Bones;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Bones = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 20);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void AddInstanceVertexWeightBoneParented(ScriptName BoneName, bool bPairWithParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AddInstanceVertexWeightBoneParented");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = BoneName;
			*(bool*)(params + 8) = bPairWithParent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveInstanceVertexWeightBoneParented(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.RemoveInstanceVertexWeightBoneParented");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int FindInstanceVertexweightBonePair(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshComponent.BonePair'!
void* Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindInstanceVertexweightBonePair");
			byte* params = (byte*)malloc(20);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.SkeletalMeshComponent.BonePair'!
void**)params = Bones;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		void UpdateInstanceVertexWeightBones(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* BonePairs)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateInstanceVertexWeightBones");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = BonePairs;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ToggleInstanceVertexWeights(bool bEnable, int LODIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.ToggleInstanceVertexWeights");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bEnable;
			*(int*)(params + 4) = LODIdx;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool PlayFaceFXAnim(class FaceFXAnimSet* FaceFXAnimSetRef, ScriptArray<wchar_t> AnimName, ScriptArray<wchar_t> GroupName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.PlayFaceFXAnim");
			byte* params = (byte*)malloc(36);
			*(class FaceFXAnimSet**)params = FaceFXAnimSetRef;
			*(ScriptArray<wchar_t>*)(params + 4) = AnimName;
			*(ScriptArray<wchar_t>*)(params + 16) = GroupName;
			*(class SoundCue**)(params + 28) = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 32);
			free(params);
			return returnVal;
		}
		void StopFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.StopFaceFXAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPlayingFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.IsPlayingFaceFXAnim");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void DeclareFaceFXRegister(ScriptArray<wchar_t> RegName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.DeclareFaceFXRegister");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = RegName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetFaceFXRegister(ScriptArray<wchar_t> RegName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetFaceFXRegister");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = RegName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		void SetFaceFXRegister(ScriptArray<wchar_t> RegName, float RegVal, byte RegOp, float InterpDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetFaceFXRegister");
			byte* params = (byte*)malloc(21);
			*(ScriptArray<wchar_t>*)params = RegName;
			*(float*)(params + 12) = RegVal;
			*(params + 16) = RegOp;
			*(float*)(params + 20) = InterpDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFaceFXRegisterEx(ScriptArray<wchar_t> RegName, byte RegOp, float FirstValue, float FirstInterpDuration, float NextValue, float NextInterpDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetFaceFXRegisterEx");
			byte* params = (byte*)malloc(29);
			*(ScriptArray<wchar_t>*)params = RegName;
			*(params + 12) = RegOp;
			*(float*)(params + 16) = FirstValue;
			*(float*)(params + 20) = FirstInterpDuration;
			*(float*)(params + 24) = NextValue;
			*(float*)(params + 28) = NextInterpDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HideBone(int BoneIndex, byte PhysBodyOption)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.HideBone");
			byte* params = (byte*)malloc(5);
			*(int*)params = BoneIndex;
			*(params + 4) = PhysBodyOption;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnHideBone(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UnHideBone");
			byte* params = (byte*)malloc(4);
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsBoneHidden(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.IsBoneHidden");
			byte* params = (byte*)malloc(8);
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void HideBoneByName(ScriptName BoneName, byte PhysBodyOption)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.HideBoneByName");
			byte* params = (byte*)malloc(9);
			*(ScriptName*)params = BoneName;
			*(params + 8) = PhysBodyOption;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnHideBoneByName(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UnHideBoneByName");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateMeshForBrokenConstraints()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateMeshForBrokenConstraints");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowMaterialSection(int MaterialID, bool bShow, int LODIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.ShowMaterialSection");
			byte* params = (byte*)malloc(12);
			*(int*)params = MaterialID;
			*(bool*)(params + 4) = bShow;
			*(int*)(params + 8) = LODIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayAnim(ScriptName AnimName, float Duration, bool bLoop, bool bRestartIfAlreadyPlaying, float StartTime, bool bPlayBackwards)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.PlayAnim");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = AnimName;
			*(float*)(params + 8) = Duration;
			*(bool*)(params + 12) = bLoop;
			*(bool*)(params + 16) = bRestartIfAlreadyPlaying;
			*(float*)(params + 20) = StartTime;
			*(bool*)(params + 24) = bPlayBackwards;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.StopAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.CreateForceField");
			byte* params = (byte*)malloc(8);
			*(class AnimNotify_ForceField**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.PlayParticleEffect");
			byte* params = (byte*)malloc(8);
			*(class AnimNotify_PlayParticleEffect**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void SkelMeshCompOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SkelMeshCompOnParticleSystemFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BreakConstraint(Vector Impulse, Vector HitLocation, ScriptName InBoneName, bool bVelChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.BreakConstraint");
			byte* params = (byte*)malloc(36);
			*(Vector*)params = Impulse;
			*(Vector*)(params + 12) = HitLocation;
			*(ScriptName*)(params + 24) = InBoneName;
			*(bool*)(params + 32) = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
