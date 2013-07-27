#pragma once
#include "Engine.SoundCue.h"
#include "Engine.MeshComponent.h"
#include "Engine.PhysicsAsset.h"
#include "Engine.AnimNode.h"
#include "Engine.PhysicsAssetInstance.h"
#include "Engine.AnimSet.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.AnimTree.h"
#include "Core.Object.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SkelControlBase.h"
#include "Engine.MorphTargetSet.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.Material.h"
#include "Engine.SkeletalMeshSocket.h"
#include "Engine.AnimSequence.h"
#include "Engine.MorphTarget.h"
#include "Engine.MorphNodeBase.h"
#include "Engine.RB_BodyInstance.h"
#include "Engine.AnimNotify_ForceField.h"
#include "Engine.AnimNotify_PlayParticleEffect.h"
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
	class SkeletalMeshComponent : public MeshComponent
	{
	public:
		enum EPhysBodyOp : byte
		{
			PBO_None = 0,
			PBO_Term = 1,
			PBO_Disable = 2,
			PBO_MAX = 3,
		};
		enum EFaceFXRegOp : byte
		{
			FXRO_Add = 0,
			FXRO_Multiply = 1,
			FXRO_Replace = 2,
			FXRO_MAX = 3,
		};
		enum EFaceFXBlendMode : byte
		{
			FXBM_Overwrite = 0,
			FXBM_Additive = 1,
			FXBM_MAX = 2,
		};
		enum EInstanceWeightUsage : byte
		{
			IWU_PartialSwap = 0,
			IWU_FullSwap = 1,
			IWU_MAX = 2,
		};
		enum ERootMotionRotationMode : byte
		{
			RMRM_Ignore = 0,
			RMRM_RotateActor = 1,
			RMRM_MAX = 2,
		};
		enum ERootMotionMode : byte
		{
			RMM_Translate = 0,
			RMM_Velocity = 1,
			RMM_Ignore = 2,
			RMM_Accel = 3,
			RMM_Relative = 4,
			RMM_MAX = 5,
		};
		enum EMaxDistanceScaleMode : byte
		{
			MDSM_Multiply = 0,
			MDSM_Substract = 1,
			MDSM_MAX = 2,
		};
		class BonePair
		{
		public:
			ADD_STRUCT(ScriptName, Bones, 0)
		};
		class Attachment
		{
		public:
			ADD_STRUCT(ScriptName, BoneName, 4)
			ADD_STRUCT(Object::Vector, RelativeLocation, 12)
			ADD_STRUCT(Object::Rotator, RelativeRotation, 24)
			ADD_STRUCT(Object::Vector, RelativeScale, 36)
		};
		class ActiveMorph
		{
		public:
			ADD_OBJECT(MorphTarget, Target, 0)
			ADD_STRUCT(float, Weight, 4)
		};
		class SkelMeshComponentLODInfo
		{
		public:
			ADD_STRUCT(SkeletalMeshComponent::EInstanceWeightUsage, InstanceWeightUsage, 16)
			ADD_STRUCT(ScriptArray<bool>, HiddenMaterials, 0)
			ADD_BOOL(bNeedsInstanceWeightUpdate, 12, 0x1)
			ADD_BOOL(bAlwaysUseInstanceWeights, 12, 0x2)
			ADD_STRUCT(int, InstanceWeightIdx, 20)
		};
		ADD_OBJECT(AnimNode, Animations, 512)
		ADD_OBJECT(PhysicsAssetInstance, PhysicsAssetInstance, 580)
		ADD_STRUCT(ScriptArray<SkeletalMeshComponent::SkelMeshComponentLODInfo>, LODInfo, 976)
		ADD_OBJECT(PhysicsAsset, PhysicsAsset, 576)
		ADD_OBJECT(SkeletalMesh, SkeletalMesh, 500)
		ADD_OBJECT(AnimTree, AnimTreeTemplate, 508)
		ADD_STRUCT(ScriptArray<class AnimNode*>, AnimTickArray, 516)
		ADD_STRUCT(ScriptArray<class AnimNode*>, AnimAlwaysTickArray, 528)
		ADD_STRUCT(ScriptArray<int>, AnimTickRelevancyArray, 540)
		ADD_STRUCT(ScriptArray<float>, AnimTickWeightsArray, 552)
		ADD_STRUCT(ScriptArray<class SkelControlBase*>, SkelControlTickArray, 564)
		ADD_STRUCT(Object::Pointer, ApexClothing, 584)
		ADD_STRUCT(float, PhysicsWeight, 588)
		ADD_STRUCT(float, GlobalAnimRateScale, 592)
		ADD_STRUCT(Object::Pointer, MeshObject, 596)
		ADD_STRUCT(Object::Color, WireframeColor, 600)
		ADD_STRUCT(ScriptArray<Object::BoneAtom>, SpaceBases, 604)
		ADD_STRUCT(ScriptArray<Object::BoneAtom>, LocalAtoms, 616)
		ADD_STRUCT(ScriptArray<Object::BoneAtom>, CachedLocalAtoms, 628)
		ADD_STRUCT(ScriptArray<Object::BoneAtom>, CachedSpaceBases, 640)
		ADD_STRUCT(int, LowUpdateFrameRate, 652)
		ADD_STRUCT(ScriptArray<byte>, RequiredBones, 656)
		ADD_STRUCT(ScriptArray<byte>, ComposeOrderedRequiredBones, 668)
		ADD_BOOL(bShouldIgnoreParentAnimComponent, 684, 0x1)
		ADD_STRUCT(ScriptArray<int>, ParentBoneMap, 688)
		ADD_STRUCT(ScriptArray<class AnimSet*>, AnimSets, 700)
		ADD_STRUCT(ScriptArray<class AnimSet*>, TemporarySavedAnimSets, 712)
		ADD_STRUCT(ScriptArray<class MorphTargetSet*>, MorphSets, 724)
		ADD_STRUCT(ScriptArray<SkeletalMeshComponent::ActiveMorph>, ActiveMorphs, 736)
		ADD_STRUCT(ScriptArray<SkeletalMeshComponent::ActiveMorph>, ActiveCurveMorphs, 748)
		ADD_STRUCT(ScriptArray<SkeletalMeshComponent::Attachment>, Attachments, 820)
		ADD_STRUCT(ScriptArray<byte>, SkelControlIndex, 832)
		ADD_STRUCT(ScriptArray<byte>, PostPhysSkelControlIndex, 844)
		ADD_STRUCT(int, ForcedLodModel, 856)
		ADD_STRUCT(int, MinLodModel, 860)
		ADD_STRUCT(int, PredictedLODLevel, 864)
		ADD_STRUCT(int, OldPredictedLODLevel, 868)
		ADD_STRUCT(float, MaxDistanceFactor, 872)
		ADD_STRUCT(int, bForceWireframe, 876)
		ADD_STRUCT(int, bForceRefpose, 880)
		ADD_STRUCT(int, bOldForceRefPose, 884)
		ADD_BOOL(bNoSkeletonUpdate, 888, 0x1)
		ADD_STRUCT(int, bDisplayBones, 892)
		ADD_STRUCT(int, bShowPrePhysBones, 896)
		ADD_STRUCT(int, bHideSkin, 900)
		ADD_STRUCT(int, bForceRawOffset, 904)
		ADD_STRUCT(int, bIgnoreControllers, 908)
		ADD_STRUCT(int, bTransformFromAnimParent, 912)
		ADD_STRUCT(int, TickTag, 916)
		ADD_STRUCT(int, InitTag, 920)
		ADD_STRUCT(int, CachedAtomsTag, 924)
		ADD_STRUCT(int, bUseSingleBodyPhysics, 928)
		ADD_STRUCT(int, bRequiredBonesUpToDate, 932)
		ADD_STRUCT(float, MinDistFactorForKinematicUpdate, 936)
		ADD_STRUCT(int, FramesPhysicsAsleep, 940)
		ADD_BOOL(bSkipAllUpdateWhenPhysicsAsleep, 944, 0x1)
		ADD_BOOL(bConsiderAllBodiesForBounds, 944, 0x2)
		ADD_BOOL(bUpdateSkelWhenNotRendered, 944, 0x4)
		ADD_BOOL(bIgnoreControllersWhenNotRendered, 944, 0x8)
		ADD_BOOL(bTickAnimNodesWhenNotRendered, 944, 0x10)
		ADD_BOOL(bNotUpdatingKinematicDueToDistance, 944, 0x20)
		ADD_BOOL(bForceDiscardRootMotion, 944, 0x40)
		ADD_BOOL(bRootMotionModeChangeNotify, 944, 0x80)
		ADD_BOOL(bRootMotionExtractedNotify, 944, 0x100)
		ADD_BOOL(bDisableFaceFXMaterialInstanceCreation, 944, 0x200)
		ADD_BOOL(bAnimTreeInitialised, 944, 0x400)
		ADD_BOOL(bForceMeshObjectUpdate, 944, 0x800)
		ADD_BOOL(bHasPhysicsAssetInstance, 944, 0x1000)
		ADD_BOOL(bUpdateKinematicBonesFromAnimation, 944, 0x2000)
		ADD_BOOL(bUpdateJointsFromAnimation, 944, 0x4000)
		ADD_BOOL(bSkelCompFixed, 944, 0x8000)
		ADD_BOOL(bHasHadPhysicsBlendedIn, 944, 0x10000)
		ADD_BOOL(bForceUpdateAttachmentsInTick, 944, 0x20000)
		ADD_BOOL(bEnableFullAnimWeightBodies, 944, 0x40000)
		ADD_BOOL(bPerBoneVolumeEffects, 944, 0x80000)
		ADD_BOOL(bPerBoneMotionBlur, 944, 0x100000)
		ADD_BOOL(bSyncActorLocationToRootRigidBody, 944, 0x200000)
		ADD_BOOL(bUseRawData, 944, 0x400000)
		ADD_BOOL(bDisableWarningWhenAnimNotFound, 944, 0x800000)
		ADD_BOOL(bOverrideAttachmentOwnerVisibility, 944, 0x1000000)
		ADD_BOOL(bNeedsToDeleteHitMask, 944, 0x2000000)
		ADD_BOOL(bPauseAnims, 944, 0x4000000)
		ADD_BOOL(bChartDistanceFactor, 944, 0x8000000)
		ADD_BOOL(bEnableLineCheckWithBounds, 944, 0x10000000)
		ADD_BOOL(bCanHighlightSelectedSections, 944, 0x20000000)
		ADD_STRUCT(Object::Vector, LineCheckBoundsScale, 948)
		ADD_BOOL(bEnableClothSimulation, 960, 0x1)
		ADD_BOOL(bDisableClothCollision, 960, 0x2)
		ADD_BOOL(bClothFrozen, 960, 0x4)
		ADD_BOOL(bAutoFreezeClothWhenNotRendered, 960, 0x8)
		ADD_BOOL(bClothAwakeOnStartup, 960, 0x10)
		ADD_BOOL(bClothBaseVelClamp, 960, 0x20)
		ADD_BOOL(bClothBaseVelInterp, 960, 0x40)
		ADD_BOOL(bAttachClothVertsToBaseBody, 960, 0x80)
		ADD_BOOL(bIsClothOnStaticObject, 960, 0x100)
		ADD_BOOL(bUpdatedFixedClothVerts, 960, 0x200)
		ADD_BOOL(bClothPositionalDampening, 960, 0x400)
		ADD_BOOL(bClothWindRelativeToOwner, 960, 0x800)
		ADD_BOOL(bRecentlyRendered, 960, 0x1000)
		ADD_BOOL(bCacheAnimSequenceNodes, 960, 0x2000)
		ADD_BOOL(bNeedsInstanceWeightUpdate, 960, 0x4000)
		ADD_BOOL(bAlwaysUseInstanceWeights, 960, 0x8000)
		ADD_BOOL(bUpdateComposeSkeletonPasses, 960, 0x10000)
		ADD_BOOL(bValidTemporarySavedAnimSets, 960, 0x20000)
		ADD_STRUCT(ScriptArray<SkeletalMeshComponent::BonePair>, InstanceVertexWeightBones, 964)
		ADD_STRUCT(Object::Vector, FrozenLocalToWorldPos, 988)
		ADD_STRUCT(Object::Rotator, FrozenLocalToWorldRot, 1000)
		ADD_STRUCT(Object::Vector, ClothExternalForce, 1012)
		ADD_STRUCT(Object::Vector, ClothWind, 1024)
		ADD_STRUCT(Object::Vector, ClothBaseVelClampRange, 1036)
		ADD_STRUCT(float, ClothBlendWeight, 1048)
		ADD_STRUCT(float, ClothDynamicBlendWeight, 1052)
		ADD_STRUCT(float, ClothBlendMinDistanceFactor, 1056)
		ADD_STRUCT(float, ClothBlendMaxDistanceFactor, 1060)
		ADD_STRUCT(Object::Vector, MinPosDampRange, 1064)
		ADD_STRUCT(Object::Vector, MaxPosDampRange, 1076)
		ADD_STRUCT(Object::Vector, MinPosDampScale, 1088)
		ADD_STRUCT(Object::Vector, MaxPosDampScale, 1100)
		ADD_STRUCT(Object::Pointer, ClothSim, 1112)
		ADD_STRUCT(int, SceneIndex, 1116)
		ADD_STRUCT(ScriptArray<Object::Vector>, ClothMeshPosData, 1120)
		ADD_STRUCT(ScriptArray<Object::Vector>, ClothMeshNormalData, 1132)
		ADD_STRUCT(ScriptArray<int>, ClothMeshIndexData, 1144)
		ADD_STRUCT(int, NumClothMeshVerts, 1156)
		ADD_STRUCT(int, NumClothMeshIndices, 1160)
		ADD_STRUCT(ScriptArray<int>, ClothMeshParentData, 1164)
		ADD_STRUCT(int, NumClothMeshParentIndices, 1176)
		ADD_STRUCT(ScriptArray<Object::Vector>, ClothMeshWeldedPosData, 1180)
		ADD_STRUCT(ScriptArray<Object::Vector>, ClothMeshWeldedNormalData, 1192)
		ADD_STRUCT(ScriptArray<int>, ClothMeshWeldedIndexData, 1204)
		ADD_STRUCT(int, ClothDirtyBufferFlag, 1216)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, ClothRBChannel, 1220)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, ClothRBCollideWithChannels, 1224)
		ADD_STRUCT(float, ClothForceScale, 1228)
		ADD_STRUCT(float, ClothImpulseScale, 1232)
		ADD_STRUCT(float, ClothAttachmentTearFactor, 1236)
		ADD_BOOL(bClothUseCompartment, 1240, 0x1)
		ADD_STRUCT(float, MinDistanceForClothReset, 1244)
		ADD_STRUCT(Object::Vector, LastClothLocation, 1248)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, ApexClothingRBChannel, 1260)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, ApexClothingRBCollideWithChannels, 1264)
		ADD_BOOL(bAutoFreezeApexClothingWhenNotRendered, 1268, 0x1)
		ADD_STRUCT(Object::Vector, WindVelocity, 1272)
		ADD_STRUCT(float, WindVelocityBlendTime, 1284)
		ADD_BOOL(bSkipInitClothing, 1288, 0x1)
		ADD_STRUCT(Object::Pointer, SoftBodySim, 1292)
		ADD_STRUCT(int, SoftBodySceneIndex, 1296)
		ADD_BOOL(bEnableSoftBodySimulation, 1300, 0x1)
		ADD_STRUCT(ScriptArray<Object::Vector>, SoftBodyTetraPosData, 1304)
		ADD_STRUCT(ScriptArray<int>, SoftBodyTetraIndexData, 1316)
		ADD_STRUCT(int, NumSoftBodyTetraVerts, 1328)
		ADD_STRUCT(int, NumSoftBodyTetraIndices, 1332)
		ADD_STRUCT(float, SoftBodyImpulseScale, 1336)
		ADD_BOOL(bSoftBodyFrozen, 1340, 0x1)
		ADD_BOOL(bAutoFreezeSoftBodyWhenNotRendered, 1340, 0x2)
		ADD_BOOL(bSoftBodyAwakeOnStartup, 1340, 0x4)
		ADD_BOOL(bSoftBodyUseCompartment, 1340, 0x8)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, SoftBodyRBChannel, 1344)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, SoftBodyRBCollideWithChannels, 1348)
		ADD_STRUCT(Object::Pointer, SoftBodyASVPlane, 1352)
		ADD_OBJECT(Material, LimitMaterial, 1356)
		ADD_STRUCT(Object::BoneAtom, RootMotionDelta, 1360)
		ADD_STRUCT(Object::Vector, RootMotionVelocity, 1392)
		ADD_STRUCT(Object::Vector, RootBoneTranslation, 1404)
		ADD_STRUCT(Object::Vector, RootMotionAccelScale, 1416)
		ADD_STRUCT(SkeletalMeshComponent::ERootMotionMode, RootMotionMode, 1428)
		ADD_STRUCT(SkeletalMeshComponent::ERootMotionMode, PreviousRMM, 1429)
		ADD_STRUCT(SkeletalMeshComponent::ERootMotionMode, PendingRMM, 1430)
		ADD_STRUCT(SkeletalMeshComponent::ERootMotionMode, OldPendingRMM, 1431)
		ADD_STRUCT(int, bRMMOneFrameDelay, 1432)
		ADD_STRUCT(SkeletalMeshComponent::ERootMotionRotationMode, RootMotionRotationMode, 1436)
		ADD_STRUCT(SkeletalMeshComponent::EFaceFXBlendMode, FaceFXBlendMode, 1437)
		ADD_STRUCT(Object::Pointer, FaceFXActorInstance, 1440)
		ADD_STRUCT(ScriptArray<byte>, BoneVisibility, 1448)
		ADD_STRUCT(Object::BoneAtom, LocalToWorldBoneAtom, 1472)
		ADD_STRUCT(float, ProgressiveDrawingFraction, 1504)
		ADD_STRUCT(byte, CustomSortAlternateIndexMode, 1508)
		void AttachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName BoneName, Object::Vector RelativeLocation, Object::Rotator RelativeRotation, Object::Vector RelativeScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachComponent");
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Component;
			*(ScriptName*)&params[4] = BoneName;
			*(Object::Vector*)&params[12] = RelativeLocation;
			*(Object::Rotator*)&params[24] = RelativeRotation;
			*(Object::Vector*)&params[36] = RelativeScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.DetachComponent");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Component;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachComponentToSocket(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName SocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachComponentToSocket");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Component;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetSocketWorldLocationAndRotation(ScriptName InSocketName, Object::Vector& OutLocation, Object::Rotator& OutRotation, int Space)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetSocketWorldLocationAndRotation");
			byte params[40] = { NULL };
			*(ScriptName*)&params[0] = InSocketName;
			*(Object::Vector*)&params[8] = OutLocation;
			*(Object::Rotator*)&params[20] = OutRotation;
			*(int*)&params[32] = Space;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutLocation = *(Object::Vector*)&params[8];
			OutRotation = *(Object::Rotator*)&params[20];
			return *(bool*)&params[36];
		}
		class SkeletalMeshSocket* GetSocketByName(ScriptName InSocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetSocketByName");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InSocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMeshSocket**)&params[8];
		}
		ScriptName GetSocketBoneName(ScriptName InSocketName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetSocketBoneName");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = InSocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FindComponentAttachedToBone(ScriptName InBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindComponentAttachedToBone");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8];
		}
		bool IsComponentAttached(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.IsComponentAttached");
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Component;
			*(ScriptName*)&params[4] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AttachedComponents(ScriptClass* BaseClass, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& OutComponent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachedComponents");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OutComponent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutComponent = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		Object::Matrix GetTransformMatrix()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetTransformMatrix");
			byte params[64] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[0];
		}
		void SetSkeletalMesh(class SkeletalMesh* NewMesh, bool bKeepSpaceBases)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetSkeletalMesh");
			byte params[8] = { NULL };
			*(class SkeletalMesh**)&params[0] = NewMesh;
			*(bool*)&params[4] = bKeepSpaceBases;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPhysicsAsset(class PhysicsAsset* NewPhysicsAsset, bool bForceReInit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetPhysicsAsset");
			byte params[8] = { NULL };
			*(class PhysicsAsset**)&params[0] = NewPhysicsAsset;
			*(bool*)&params[4] = bForceReInit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetForceRefPose(bool bNewForceRefPose)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetForceRefPose");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewForceRefPose;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEnableClothSimulation(bool bInEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetEnableClothSimulation");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothFrozen(bool bNewFrozen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothFrozen");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewFrozen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEnableClothingSimulation(bool bInEnable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetEnableClothingSimulation");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateClothParams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateClothParams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetClothExternalForce(Object::Vector InForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothExternalForce");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = InForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAttachClothVertsToBaseBody(bool bAttachVerts)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetAttachClothVertsToBaseBody");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAttachVerts;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetClothVertsToRefPose()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.ResetClothVertsToRefPose");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetClothAttachmentResponseCoefficient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothAttachmentResponseCoefficient");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothAttachmentTearFactor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothAttachmentTearFactor");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothBendingStiffness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothBendingStiffness");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothCollisionResponseCoefficient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothCollisionResponseCoefficient");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothDampingCoefficient()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothDampingCoefficient");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		int GetClothFlags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothFlags");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		float GetClothFriction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothFriction");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothPressure()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothPressure");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothSleepLinearVelocity()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothSleepLinearVelocity");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		int GetClothSolverIterations()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothSolverIterations");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		float GetClothStretchingStiffness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothStretchingStiffness");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothTearFactor()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothTearFactor");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		float GetClothThickness()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClothThickness");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		void SetClothAttachmentResponseCoefficient(float ClothAttachmentResponseCoefficient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothAttachmentResponseCoefficient");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothAttachmentResponseCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothAttachmentTearFactor(float ClothAttachTearFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothAttachmentTearFactor");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothAttachTearFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothBendingStiffness(float ClothBendingStiffness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothBendingStiffness");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothBendingStiffness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothCollisionResponseCoefficient(float ClothCollisionResponseCoefficient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothCollisionResponseCoefficient");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothCollisionResponseCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothDampingCoefficient(float ClothDampingCoefficient)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothDampingCoefficient");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothDampingCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothFlags(int ClothFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothFlags");
			byte params[4] = { NULL };
			*(int*)&params[0] = ClothFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothFriction(float ClothFriction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothFriction");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothFriction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothPressure(float ClothPressure)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothPressure");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothPressure;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothSleepLinearVelocity(float ClothSleepLinearVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothSleepLinearVelocity");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothSleepLinearVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothSolverIterations(int ClothSolverIterations)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothSolverIterations");
			byte params[4] = { NULL };
			*(int*)&params[0] = ClothSolverIterations;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothStretchingStiffness(float ClothStretchingStiffness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothStretchingStiffness");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothStretchingStiffness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothTearFactor(float ClothTearFactor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothTearFactor");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothTearFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothThickness(float ClothThickness)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothThickness");
			byte params[4] = { NULL };
			*(float*)&params[0] = ClothThickness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothSleep(bool IfClothSleep)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothSleep");
			byte params[4] = { NULL };
			*(bool*)&params[0] = IfClothSleep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothPosition(Object::Vector ClothOffSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothPosition");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = ClothOffSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothVelocity(Object::Vector VelocityOffSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothVelocity");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = VelocityOffSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachClothToCollidingShapes(bool AttatchTwoWay, bool AttachTearable)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AttachClothToCollidingShapes");
			byte params[8] = { NULL };
			*(bool*)&params[0] = AttatchTwoWay;
			*(bool*)&params[4] = AttachTearable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableClothValidBounds(bool IfEnableClothValidBounds)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.EnableClothValidBounds");
			byte params[4] = { NULL };
			*(bool*)&params[0] = IfEnableClothValidBounds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothValidBounds(Object::Vector ClothValidBoundsMin, Object::Vector ClothValidBoundsMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetClothValidBounds");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = ClothValidBoundsMin;
			*(Object::Vector*)&params[12] = ClothValidBoundsMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSoftBodyParams()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateSoftBodyParams");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSoftBodyFrozen(bool bNewFrozen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetSoftBodyFrozen");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewFrozen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WakeSoftBody()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.WakeSoftBody");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class AnimSequence* FindAnimSequence(ScriptName AnimSeqName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindAnimSequence");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = AnimSeqName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimSequence**)&params[8];
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
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = AnimSeqName;
			*(float*)&params[8] = Duration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetAnimLength(ScriptName AnimSeqName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetAnimLength");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = AnimSeqName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		class MorphTarget* FindMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindMorphTarget");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MorphTarget**)&params[8];
		}
		class AnimNode* FindAnimNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindAnimNode");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNode**)&params[8];
		}
		void AllAnimNodes(ScriptClass* BaseClass, class AnimNode*& Node)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AllAnimNodes");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class AnimNode**)&params[4] = Node;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Node = *(class AnimNode**)&params[4];
		}
		class SkelControlBase* FindSkelControl(ScriptName InControlName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindSkelControl");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InControlName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkelControlBase**)&params[8];
		}
		class MorphNodeBase* FindMorphNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindMorphNode");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MorphNodeBase**)&params[8];
		}
		Object::Quat GetBoneQuaternion(ScriptName BoneName, int Space)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneQuaternion");
			byte params[28] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(int*)&params[8] = Space;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[16];
		}
		Object::Vector GetBoneLocation(ScriptName BoneName, int Space)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneLocation");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(int*)&params[8] = Space;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		int MatchRefBone(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.MatchRefBone");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptName GetBoneName(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneName");
			byte params[12] = { NULL };
			*(int*)&params[0] = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		Object::Matrix GetBoneMatrix(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneMatrix");
			byte params[68] = { NULL };
			*(int*)&params[0] = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[16];
		}
		ScriptName GetParentBone(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetParentBone");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		void GetBoneNames(ScriptArray<ScriptName>& BoneNames)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneNames");
			byte params[12] = { NULL };
			*(ScriptArray<ScriptName>*)&params[0] = BoneNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BoneNames = *(ScriptArray<ScriptName>*)&params[0];
		}
		bool BoneIsChildOf(ScriptName BoneName, ScriptName ParentBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.BoneIsChildOf");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(ScriptName*)&params[8] = ParentBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		Object::Vector GetRefPosePosition(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetRefPosePosition");
			byte params[16] = { NULL };
			*(int*)&params[0] = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[4];
		}
		Object::Vector GetBoneAxis(ScriptName BoneName, Object::EAxis Axis)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBoneAxis");
			byte params[21] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(Object::EAxis*)&params[8] = Axis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[12];
		}
		void TransformToBoneSpace(ScriptName BoneName, Object::Vector InPosition, Object::Rotator InRotation, Object::Vector& OutPosition, Object::Rotator& OutRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.TransformToBoneSpace");
			byte params[56] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(Object::Vector*)&params[8] = InPosition;
			*(Object::Rotator*)&params[20] = InRotation;
			*(Object::Vector*)&params[32] = OutPosition;
			*(Object::Rotator*)&params[44] = OutRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPosition = *(Object::Vector*)&params[32];
			OutRotation = *(Object::Rotator*)&params[44];
		}
		void TransformFromBoneSpace(ScriptName BoneName, Object::Vector InPosition, Object::Rotator InRotation, Object::Vector& OutPosition, Object::Rotator& OutRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.TransformFromBoneSpace");
			byte params[56] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(Object::Vector*)&params[8] = InPosition;
			*(Object::Rotator*)&params[20] = InRotation;
			*(Object::Vector*)&params[32] = OutPosition;
			*(Object::Rotator*)&params[44] = OutRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPosition = *(Object::Vector*)&params[32];
			OutRotation = *(Object::Rotator*)&params[44];
		}
		ScriptName FindClosestBone(Object::Vector TestLocation, Object::Vector& BoneLocation, float IgnoreScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindClosestBone");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = TestLocation;
			*(Object::Vector*)&params[12] = BoneLocation;
			*(float*)&params[24] = IgnoreScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BoneLocation = *(Object::Vector*)&params[12];
			return *(ScriptName*)&params[28];
		}
		Object::Vector GetClosestCollidingBoneLocation(Object::Vector TestLocation, bool bCheckZeroExtent, bool bCheckNonZeroExtent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetClosestCollidingBoneLocation");
			byte params[32] = { NULL };
			*(Object::Vector*)&params[0] = TestLocation;
			*(bool*)&params[12] = bCheckZeroExtent;
			*(bool*)&params[16] = bCheckNonZeroExtent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[20];
		}
		void SetAnimTreeTemplate(class AnimTree* NewTemplate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetAnimTreeTemplate");
			byte params[4] = { NULL };
			*(class AnimTree**)&params[0] = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetParentAnimComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewParentAnimComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetParentAnimComponent");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = NewParentAnimComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = ConstraintName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptName FindConstraintBoneName(int ConstraintIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindConstraintBoneName");
			byte params[12] = { NULL };
			*(int*)&params[0] = ConstraintIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		class RB_BodyInstance* FindBodyInstanceNamed(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindBodyInstanceNamed");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class RB_BodyInstance**)&params[8];
		}
		void SetHasPhysicsAssetInstance(bool bHasInstance)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetHasPhysicsAssetInstance");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bHasInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRBBonesFromSpaceBases(bool bMoveUnfixedBodies, bool bTeleport)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateRBBonesFromSpaceBases");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bMoveUnfixedBodies;
			*(bool*)&params[4] = bTeleport;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		bool GetBonesWithinRadius(Object::Vector Origin, float Radius, int TraceFlags, ScriptArray<ScriptName>& out_Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetBonesWithinRadius");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = Origin;
			*(float*)&params[12] = Radius;
			*(int*)&params[16] = TraceFlags;
			*(ScriptArray<ScriptName>*)&params[20] = out_Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Bones = *(ScriptArray<ScriptName>*)&params[20];
			return *(bool*)&params[32];
		}
		void AddInstanceVertexWeightBoneParented(ScriptName BoneName, bool bPairWithParent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.AddInstanceVertexWeightBoneParented");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(bool*)&params[8] = bPairWithParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveInstanceVertexWeightBoneParented(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.RemoveInstanceVertexWeightBoneParented");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int FindInstanceVertexweightBonePair(SkeletalMeshComponent::BonePair Bones)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.FindInstanceVertexweightBonePair");
			byte params[20] = { NULL };
			*(SkeletalMeshComponent::BonePair*)&params[0] = Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		void UpdateInstanceVertexWeightBones(ScriptArray<SkeletalMeshComponent::BonePair> BonePairs)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateInstanceVertexWeightBones");
			byte params[12] = { NULL };
			*(ScriptArray<SkeletalMeshComponent::BonePair>*)&params[0] = BonePairs;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleInstanceVertexWeights(bool bEnable, int LODIdx)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.ToggleInstanceVertexWeights");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bEnable;
			*(int*)&params[4] = LODIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayFaceFXAnim(class FaceFXAnimSet* FaceFXAnimSetRef, ScriptString* AnimName, ScriptString* GroupName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.PlayFaceFXAnim");
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)&params[0] = FaceFXAnimSetRef;
			*(ScriptString**)&params[4] = AnimName;
			*(ScriptString**)&params[16] = GroupName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.StopFaceFXAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPlayingFaceFXAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.IsPlayingFaceFXAnim");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void DeclareFaceFXRegister(ScriptString* RegName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.DeclareFaceFXRegister");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = RegName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetFaceFXRegister(ScriptString* RegName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.GetFaceFXRegister");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = RegName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void SetFaceFXRegister(ScriptString* RegName, float RegVal, SkeletalMeshComponent::EFaceFXRegOp RegOp, float InterpDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetFaceFXRegister");
			byte params[21] = { NULL };
			*(ScriptString**)&params[0] = RegName;
			*(float*)&params[12] = RegVal;
			*(SkeletalMeshComponent::EFaceFXRegOp*)&params[16] = RegOp;
			*(float*)&params[20] = InterpDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFaceFXRegisterEx(ScriptString* RegName, SkeletalMeshComponent::EFaceFXRegOp RegOp, float FirstValue, float FirstInterpDuration, float NextValue, float NextInterpDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SetFaceFXRegisterEx");
			byte params[29] = { NULL };
			*(ScriptString**)&params[0] = RegName;
			*(SkeletalMeshComponent::EFaceFXRegOp*)&params[12] = RegOp;
			*(float*)&params[16] = FirstValue;
			*(float*)&params[20] = FirstInterpDuration;
			*(float*)&params[24] = NextValue;
			*(float*)&params[28] = NextInterpDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideBone(int BoneIndex, SkeletalMeshComponent::EPhysBodyOp PhysBodyOption)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.HideBone");
			byte params[5] = { NULL };
			*(int*)&params[0] = BoneIndex;
			*(SkeletalMeshComponent::EPhysBodyOp*)&params[4] = PhysBodyOption;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnHideBone(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UnHideBone");
			byte params[4] = { NULL };
			*(int*)&params[0] = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsBoneHidden(int BoneIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.IsBoneHidden");
			byte params[8] = { NULL };
			*(int*)&params[0] = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void HideBoneByName(ScriptName BoneName, SkeletalMeshComponent::EPhysBodyOp PhysBodyOption)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.HideBoneByName");
			byte params[9] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			*(SkeletalMeshComponent::EPhysBodyOp*)&params[8] = PhysBodyOption;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnHideBoneByName(ScriptName BoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UnHideBoneByName");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateMeshForBrokenConstraints()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.UpdateMeshForBrokenConstraints");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowMaterialSection(int MaterialID, bool bShow, int LODIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.ShowMaterialSection");
			byte params[12] = { NULL };
			*(int*)&params[0] = MaterialID;
			*(bool*)&params[4] = bShow;
			*(int*)&params[8] = LODIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAnim(ScriptName AnimName, float Duration, bool bLoop, bool bRestartIfAlreadyPlaying, float StartTime, bool bPlayBackwards)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.PlayAnim");
			byte params[28] = { NULL };
			*(ScriptName*)&params[0] = AnimName;
			*(float*)&params[8] = Duration;
			*(bool*)&params[12] = bLoop;
			*(bool*)&params[16] = bRestartIfAlreadyPlaying;
			*(float*)&params[20] = StartTime;
			*(bool*)&params[24] = bPlayBackwards;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.StopAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.CreateForceField");
			byte params[8] = { NULL };
			*(class AnimNotify_ForceField**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.PlayParticleEffect");
			byte params[8] = { NULL };
			*(class AnimNotify_PlayParticleEffect**)&params[0] = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SkelMeshCompOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.SkelMeshCompOnParticleSystemFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakConstraint(Object::Vector Impulse, Object::Vector HitLocation, ScriptName InBoneName, bool bVelChange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SkeletalMeshComponent.BreakConstraint");
			byte params[36] = { NULL };
			*(Object::Vector*)&params[0] = Impulse;
			*(Object::Vector*)&params[12] = HitLocation;
			*(ScriptName*)&params[24] = InBoneName;
			*(bool*)&params[32] = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
