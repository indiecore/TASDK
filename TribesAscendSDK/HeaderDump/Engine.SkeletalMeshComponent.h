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
		struct BonePair
		{
		public:
			ADD_STRUCT(ScriptName, Bones, 0)
		};
		struct Attachment
		{
		public:
			ADD_STRUCT(ScriptName, BoneName, 4)
			ADD_STRUCT(Vector, RelativeLocation, 12)
			ADD_STRUCT(Rotator, RelativeRotation, 24)
			ADD_STRUCT(Vector, RelativeScale, 36)
		};
		struct ActiveMorph
		{
		public:
			ADD_OBJECT(MorphTarget, Target, 0)
			ADD_STRUCT(float, Weight, 4)
		};
		struct SkelMeshComponentLODInfo
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
		ADD_STRUCT(Vector, LineCheckBoundsScale, 948)
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
		ADD_STRUCT(Vector, FrozenLocalToWorldPos, 988)
		ADD_STRUCT(Rotator, FrozenLocalToWorldRot, 1000)
		ADD_STRUCT(Vector, ClothExternalForce, 1012)
		ADD_STRUCT(Vector, ClothWind, 1024)
		ADD_STRUCT(Vector, ClothBaseVelClampRange, 1036)
		ADD_STRUCT(float, ClothBlendWeight, 1048)
		ADD_STRUCT(float, ClothDynamicBlendWeight, 1052)
		ADD_STRUCT(float, ClothBlendMinDistanceFactor, 1056)
		ADD_STRUCT(float, ClothBlendMaxDistanceFactor, 1060)
		ADD_STRUCT(Vector, MinPosDampRange, 1064)
		ADD_STRUCT(Vector, MaxPosDampRange, 1076)
		ADD_STRUCT(Vector, MinPosDampScale, 1088)
		ADD_STRUCT(Vector, MaxPosDampScale, 1100)
		ADD_STRUCT(Object::Pointer, ClothSim, 1112)
		ADD_STRUCT(int, SceneIndex, 1116)
		ADD_STRUCT(ScriptArray<Vector>, ClothMeshPosData, 1120)
		ADD_STRUCT(ScriptArray<Vector>, ClothMeshNormalData, 1132)
		ADD_STRUCT(ScriptArray<int>, ClothMeshIndexData, 1144)
		ADD_STRUCT(int, NumClothMeshVerts, 1156)
		ADD_STRUCT(int, NumClothMeshIndices, 1160)
		ADD_STRUCT(ScriptArray<int>, ClothMeshParentData, 1164)
		ADD_STRUCT(int, NumClothMeshParentIndices, 1176)
		ADD_STRUCT(ScriptArray<Vector>, ClothMeshWeldedPosData, 1180)
		ADD_STRUCT(ScriptArray<Vector>, ClothMeshWeldedNormalData, 1192)
		ADD_STRUCT(ScriptArray<int>, ClothMeshWeldedIndexData, 1204)
		ADD_STRUCT(int, ClothDirtyBufferFlag, 1216)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, ClothRBChannel, 1220)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, ClothRBCollideWithChannels, 1224)
		ADD_STRUCT(float, ClothForceScale, 1228)
		ADD_STRUCT(float, ClothImpulseScale, 1232)
		ADD_STRUCT(float, ClothAttachmentTearFactor, 1236)
		ADD_BOOL(bClothUseCompartment, 1240, 0x1)
		ADD_STRUCT(float, MinDistanceForClothReset, 1244)
		ADD_STRUCT(Vector, LastClothLocation, 1248)
		ADD_STRUCT(PrimitiveComponent::ERBCollisionChannel, ApexClothingRBChannel, 1260)
		ADD_STRUCT(PrimitiveComponent::RBCollisionChannelContainer, ApexClothingRBCollideWithChannels, 1264)
		ADD_BOOL(bAutoFreezeApexClothingWhenNotRendered, 1268, 0x1)
		ADD_STRUCT(Vector, WindVelocity, 1272)
		ADD_STRUCT(float, WindVelocityBlendTime, 1284)
		ADD_BOOL(bSkipInitClothing, 1288, 0x1)
		ADD_STRUCT(Object::Pointer, SoftBodySim, 1292)
		ADD_STRUCT(int, SoftBodySceneIndex, 1296)
		ADD_BOOL(bEnableSoftBodySimulation, 1300, 0x1)
		ADD_STRUCT(ScriptArray<Vector>, SoftBodyTetraPosData, 1304)
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
		ADD_STRUCT(Vector, RootMotionVelocity, 1392)
		ADD_STRUCT(Vector, RootBoneTranslation, 1404)
		ADD_STRUCT(Vector, RootMotionAccelScale, 1416)
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
void* Component, ScriptName BoneName, Vector RelativeLocation, Rotator RelativeRotation, Vector RelativeScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6946);
			byte params[48] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)&params[4] = BoneName;
			*(Vector*)&params[12] = RelativeLocation;
			*(Rotator*)&params[24] = RelativeRotation;
			*(Vector*)&params[36] = RelativeScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DetachComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6952);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachComponentToSocket(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName SocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6954);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)&params[4] = SocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetSocketWorldLocationAndRotation(ScriptName InSocketName, Vector& OutLocation, Rotator& OutRotation, int Space)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6957);
			byte params[40] = { NULL };
			*(ScriptName*)params = InSocketName;
			*(Vector*)&params[8] = OutLocation;
			*(Rotator*)&params[20] = OutRotation;
			*(int*)&params[32] = Space;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutLocation = *(Vector*)&params[8];
			OutRotation = *(Rotator*)&params[20];
			return *(bool*)&params[36];
		}
		class SkeletalMeshSocket* GetSocketByName(ScriptName InSocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6963);
			byte params[12] = { NULL };
			*(ScriptName*)params = InSocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkeletalMeshSocket**)&params[8];
		}
		ScriptName GetSocketBoneName(ScriptName InSocketName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6966);
			byte params[16] = { NULL };
			*(ScriptName*)params = InSocketName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* FindComponentAttachedToBone(ScriptName InBoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6969);
			byte params[12] = { NULL };
			*(ScriptName*)params = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[8];
		}
		bool IsComponentAttached(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Component, ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6972);
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Component;
			*(ScriptName*)&params[4] = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AttachedComponents(ScriptClass* BaseClass, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*& OutComponent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6976);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6979);
			byte params[64] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)params;
		}
		void SetSkeletalMesh(class SkeletalMesh* NewMesh, bool bKeepSpaceBases)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6981);
			byte params[8] = { NULL };
			*(class SkeletalMesh**)params = NewMesh;
			*(bool*)&params[4] = bKeepSpaceBases;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPhysicsAsset(class PhysicsAsset* NewPhysicsAsset, bool bForceReInit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6984);
			byte params[8] = { NULL };
			*(class PhysicsAsset**)params = NewPhysicsAsset;
			*(bool*)&params[4] = bForceReInit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetForceRefPose(bool bNewForceRefPose)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6987);
			byte params[4] = { NULL };
			*(bool*)params = bNewForceRefPose;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEnableClothSimulation(bool bInEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6989);
			byte params[4] = { NULL };
			*(bool*)params = bInEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothFrozen(bool bNewFrozen)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6991);
			byte params[4] = { NULL };
			*(bool*)params = bNewFrozen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEnableClothingSimulation(bool bInEnable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6993);
			byte params[4] = { NULL };
			*(bool*)params = bInEnable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateClothParams()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6995);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetClothExternalForce(Vector InForce)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6996);
			byte params[12] = { NULL };
			*(Vector*)params = InForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAttachClothVertsToBaseBody(bool bAttachVerts)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6998);
			byte params[4] = { NULL };
			*(bool*)params = bAttachVerts;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetClothVertsToRefPose()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7000);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetClothAttachmentResponseCoefficient()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7001);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothAttachmentTearFactor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7003);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothBendingStiffness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7005);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothCollisionResponseCoefficient()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7007);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothDampingCoefficient()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7009);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		int GetClothFlags()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7011);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		float GetClothFriction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7013);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothPressure()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7015);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothSleepLinearVelocity()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7017);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		int GetClothSolverIterations()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7019);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		float GetClothStretchingStiffness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7021);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothTearFactor()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7023);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		float GetClothThickness()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7025);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		void SetClothAttachmentResponseCoefficient(float ClothAttachmentResponseCoefficient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7027);
			byte params[4] = { NULL };
			*(float*)params = ClothAttachmentResponseCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothAttachmentTearFactor(float ClothAttachTearFactor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7029);
			byte params[4] = { NULL };
			*(float*)params = ClothAttachTearFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothBendingStiffness(float ClothBendingStiffness)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7031);
			byte params[4] = { NULL };
			*(float*)params = ClothBendingStiffness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothCollisionResponseCoefficient(float ClothCollisionResponseCoefficient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7033);
			byte params[4] = { NULL };
			*(float*)params = ClothCollisionResponseCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothDampingCoefficient(float ClothDampingCoefficient)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7035);
			byte params[4] = { NULL };
			*(float*)params = ClothDampingCoefficient;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothFlags(int ClothFlags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7037);
			byte params[4] = { NULL };
			*(int*)params = ClothFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothFriction(float ClothFriction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7039);
			byte params[4] = { NULL };
			*(float*)params = ClothFriction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothPressure(float ClothPressure)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7041);
			byte params[4] = { NULL };
			*(float*)params = ClothPressure;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothSleepLinearVelocity(float ClothSleepLinearVelocity)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7043);
			byte params[4] = { NULL };
			*(float*)params = ClothSleepLinearVelocity;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothSolverIterations(int ClothSolverIterations)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7045);
			byte params[4] = { NULL };
			*(int*)params = ClothSolverIterations;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothStretchingStiffness(float ClothStretchingStiffness)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7047);
			byte params[4] = { NULL };
			*(float*)params = ClothStretchingStiffness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothTearFactor(float ClothTearFactor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7049);
			byte params[4] = { NULL };
			*(float*)params = ClothTearFactor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothThickness(float ClothThickness)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7051);
			byte params[4] = { NULL };
			*(float*)params = ClothThickness;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothSleep(bool IfClothSleep)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7053);
			byte params[4] = { NULL };
			*(bool*)params = IfClothSleep;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothPosition(Vector ClothOffSet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7055);
			byte params[12] = { NULL };
			*(Vector*)params = ClothOffSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothVelocity(Vector VelocityOffSet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7057);
			byte params[12] = { NULL };
			*(Vector*)params = VelocityOffSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AttachClothToCollidingShapes(bool AttatchTwoWay, bool AttachTearable)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7059);
			byte params[8] = { NULL };
			*(bool*)params = AttatchTwoWay;
			*(bool*)&params[4] = AttachTearable;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableClothValidBounds(bool IfEnableClothValidBounds)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7062);
			byte params[4] = { NULL };
			*(bool*)params = IfEnableClothValidBounds;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetClothValidBounds(Vector ClothValidBoundsMin, Vector ClothValidBoundsMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7064);
			byte params[24] = { NULL };
			*(Vector*)params = ClothValidBoundsMin;
			*(Vector*)&params[12] = ClothValidBoundsMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSoftBodyParams()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7067);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetSoftBodyFrozen(bool bNewFrozen)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7068);
			byte params[4] = { NULL };
			*(bool*)params = bNewFrozen;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void WakeSoftBody()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7070);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class AnimSequence* FindAnimSequence(ScriptName AnimSeqName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7071);
			byte params[12] = { NULL };
			*(ScriptName*)params = AnimSeqName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimSequence**)&params[8];
		}
		void SaveAnimSets()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7074);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestoreSavedAnimSets()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7075);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetAnimRateByDuration(ScriptName AnimSeqName, float Duration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7076);
			byte params[16] = { NULL };
			*(ScriptName*)params = AnimSeqName;
			*(float*)&params[8] = Duration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		float GetAnimLength(ScriptName AnimSeqName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7082);
			byte params[12] = { NULL };
			*(ScriptName*)params = AnimSeqName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		class MorphTarget* FindMorphTarget(ScriptName MorphTargetName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7087);
			byte params[12] = { NULL };
			*(ScriptName*)params = MorphTargetName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MorphTarget**)&params[8];
		}
		class AnimNode* FindAnimNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7090);
			byte params[12] = { NULL };
			*(ScriptName*)params = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class AnimNode**)&params[8];
		}
		void AllAnimNodes(ScriptClass* BaseClass, class AnimNode*& Node)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7093);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class AnimNode**)&params[4] = Node;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Node = *(class AnimNode**)&params[4];
		}
		class SkelControlBase* FindSkelControl(ScriptName InControlName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7096);
			byte params[12] = { NULL };
			*(ScriptName*)params = InControlName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SkelControlBase**)&params[8];
		}
		class MorphNodeBase* FindMorphNode(ScriptName InNodeName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7099);
			byte params[12] = { NULL };
			*(ScriptName*)params = InNodeName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MorphNodeBase**)&params[8];
		}
		Object::Quat GetBoneQuaternion(ScriptName BoneName, int Space)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7102);
			byte params[28] = { NULL };
			*(ScriptName*)params = BoneName;
			*(int*)&params[8] = Space;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Quat*)&params[16];
		}
		Vector GetBoneLocation(ScriptName BoneName, int Space)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7106);
			byte params[24] = { NULL };
			*(ScriptName*)params = BoneName;
			*(int*)&params[8] = Space;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		int MatchRefBone(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7110);
			byte params[12] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptName GetBoneName(int BoneIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7113);
			byte params[12] = { NULL };
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		Object::Matrix GetBoneMatrix(int BoneIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7116);
			byte params[68] = { NULL };
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Matrix*)&params[16];
		}
		ScriptName GetParentBone(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7119);
			byte params[16] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[8];
		}
		void GetBoneNames(ScriptArray<ScriptName>& BoneNames)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7122);
			byte params[12] = { NULL };
			*(ScriptArray<ScriptName>*)params = BoneNames;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BoneNames = *(ScriptArray<ScriptName>*)params;
		}
		bool BoneIsChildOf(ScriptName BoneName, ScriptName ParentBoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7125);
			byte params[20] = { NULL };
			*(ScriptName*)params = BoneName;
			*(ScriptName*)&params[8] = ParentBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		Vector GetRefPosePosition(int BoneIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7129);
			byte params[16] = { NULL };
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[4];
		}
		Vector GetBoneAxis(ScriptName BoneName, Object::EAxis Axis)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7132);
			byte params[21] = { NULL };
			*(ScriptName*)params = BoneName;
			*(Object::EAxis*)&params[8] = Axis;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[12];
		}
		void TransformToBoneSpace(ScriptName BoneName, Vector InPosition, Rotator InRotation, Vector& OutPosition, Rotator& OutRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7136);
			byte params[56] = { NULL };
			*(ScriptName*)params = BoneName;
			*(Vector*)&params[8] = InPosition;
			*(Rotator*)&params[20] = InRotation;
			*(Vector*)&params[32] = OutPosition;
			*(Rotator*)&params[44] = OutRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPosition = *(Vector*)&params[32];
			OutRotation = *(Rotator*)&params[44];
		}
		void TransformFromBoneSpace(ScriptName BoneName, Vector InPosition, Rotator InRotation, Vector& OutPosition, Rotator& OutRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7142);
			byte params[56] = { NULL };
			*(ScriptName*)params = BoneName;
			*(Vector*)&params[8] = InPosition;
			*(Rotator*)&params[20] = InRotation;
			*(Vector*)&params[32] = OutPosition;
			*(Rotator*)&params[44] = OutRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutPosition = *(Vector*)&params[32];
			OutRotation = *(Rotator*)&params[44];
		}
		ScriptName FindClosestBone(Vector TestLocation, Vector& BoneLocation, float IgnoreScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7148);
			byte params[36] = { NULL };
			*(Vector*)params = TestLocation;
			*(Vector*)&params[12] = BoneLocation;
			*(float*)&params[24] = IgnoreScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			BoneLocation = *(Vector*)&params[12];
			return *(ScriptName*)&params[28];
		}
		Vector GetClosestCollidingBoneLocation(Vector TestLocation, bool bCheckZeroExtent, bool bCheckNonZeroExtent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7153);
			byte params[32] = { NULL };
			*(Vector*)params = TestLocation;
			*(bool*)&params[12] = bCheckZeroExtent;
			*(bool*)&params[16] = bCheckNonZeroExtent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[20];
		}
		void SetAnimTreeTemplate(class AnimTree* NewTemplate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7158);
			byte params[4] = { NULL };
			*(class AnimTree**)params = NewTemplate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetParentAnimComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* NewParentAnimComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7160);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = NewParentAnimComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateParentBoneMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7162);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitSkelControls()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7163);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitMorphTargets()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7164);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindConstraintIndex(ScriptName ConstraintName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7165);
			byte params[12] = { NULL };
			*(ScriptName*)params = ConstraintName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptName FindConstraintBoneName(int ConstraintIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7168);
			byte params[12] = { NULL };
			*(int*)params = ConstraintIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[4];
		}
		class RB_BodyInstance* FindBodyInstanceNamed(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7171);
			byte params[12] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class RB_BodyInstance**)&params[8];
		}
		void SetHasPhysicsAssetInstance(bool bHasInstance)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7174);
			byte params[4] = { NULL };
			*(bool*)params = bHasInstance;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRBBonesFromSpaceBases(bool bMoveUnfixedBodies, bool bTeleport)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7176);
			byte params[8] = { NULL };
			*(bool*)params = bMoveUnfixedBodies;
			*(bool*)&params[4] = bTeleport;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceSkelUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7179);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateAnimations()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7180);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool GetBonesWithinRadius(Vector Origin, float Radius, int TraceFlags, ScriptArray<ScriptName>& out_Bones)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7181);
			byte params[36] = { NULL };
			*(Vector*)params = Origin;
			*(float*)&params[12] = Radius;
			*(int*)&params[16] = TraceFlags;
			*(ScriptArray<ScriptName>*)&params[20] = out_Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Bones = *(ScriptArray<ScriptName>*)&params[20];
			return *(bool*)&params[32];
		}
		void AddInstanceVertexWeightBoneParented(ScriptName BoneName, bool bPairWithParent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7188);
			byte params[12] = { NULL };
			*(ScriptName*)params = BoneName;
			*(bool*)&params[8] = bPairWithParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveInstanceVertexWeightBoneParented(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7191);
			byte params[8] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int FindInstanceVertexweightBonePair(SkeletalMeshComponent::BonePair Bones)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7193);
			byte params[20] = { NULL };
			*(SkeletalMeshComponent::BonePair*)params = Bones;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		void UpdateInstanceVertexWeightBones(ScriptArray<SkeletalMeshComponent::BonePair> BonePairs)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7199);
			byte params[12] = { NULL };
			*(ScriptArray<SkeletalMeshComponent::BonePair>*)params = BonePairs;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ToggleInstanceVertexWeights(bool bEnable, int LODIdx)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7202);
			byte params[8] = { NULL };
			*(bool*)params = bEnable;
			*(int*)&params[4] = LODIdx;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool PlayFaceFXAnim(class FaceFXAnimSet* FaceFXAnimSetRef, ScriptString* AnimName, ScriptString* GroupName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7205);
			byte params[36] = { NULL };
			*(class FaceFXAnimSet**)params = FaceFXAnimSetRef;
			*(ScriptString**)&params[4] = AnimName;
			*(ScriptString**)&params[16] = GroupName;
			*(class SoundCue**)&params[28] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[32];
		}
		void StopFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7211);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPlayingFaceFXAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7212);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void DeclareFaceFXRegister(ScriptString* RegName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7214);
			byte params[12] = { NULL };
			*(ScriptString**)params = RegName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetFaceFXRegister(ScriptString* RegName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7216);
			byte params[16] = { NULL };
			*(ScriptString**)params = RegName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[12];
		}
		void SetFaceFXRegister(ScriptString* RegName, float RegVal, SkeletalMeshComponent::EFaceFXRegOp RegOp, float InterpDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7219);
			byte params[21] = { NULL };
			*(ScriptString**)params = RegName;
			*(float*)&params[12] = RegVal;
			*(SkeletalMeshComponent::EFaceFXRegOp*)&params[16] = RegOp;
			*(float*)&params[20] = InterpDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFaceFXRegisterEx(ScriptString* RegName, SkeletalMeshComponent::EFaceFXRegOp RegOp, float FirstValue, float FirstInterpDuration, float NextValue, float NextInterpDuration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7224);
			byte params[29] = { NULL };
			*(ScriptString**)params = RegName;
			*(SkeletalMeshComponent::EFaceFXRegOp*)&params[12] = RegOp;
			*(float*)&params[16] = FirstValue;
			*(float*)&params[20] = FirstInterpDuration;
			*(float*)&params[24] = NextValue;
			*(float*)&params[28] = NextInterpDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HideBone(int BoneIndex, SkeletalMeshComponent::EPhysBodyOp PhysBodyOption)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7231);
			byte params[5] = { NULL };
			*(int*)params = BoneIndex;
			*(SkeletalMeshComponent::EPhysBodyOp*)&params[4] = PhysBodyOption;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnHideBone(int BoneIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7234);
			byte params[4] = { NULL };
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsBoneHidden(int BoneIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7236);
			byte params[8] = { NULL };
			*(int*)params = BoneIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void HideBoneByName(ScriptName BoneName, SkeletalMeshComponent::EPhysBodyOp PhysBodyOption)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7239);
			byte params[9] = { NULL };
			*(ScriptName*)params = BoneName;
			*(SkeletalMeshComponent::EPhysBodyOp*)&params[8] = PhysBodyOption;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnHideBoneByName(ScriptName BoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7242);
			byte params[8] = { NULL };
			*(ScriptName*)params = BoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateMeshForBrokenConstraints()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7244);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ShowMaterialSection(int MaterialID, bool bShow, int LODIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7245);
			byte params[12] = { NULL };
			*(int*)params = MaterialID;
			*(bool*)&params[4] = bShow;
			*(int*)&params[8] = LODIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAnim(ScriptName AnimName, float Duration, bool bLoop, bool bRestartIfAlreadyPlaying, float StartTime, bool bPlayBackwards)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7249);
			byte params[28] = { NULL };
			*(ScriptName*)params = AnimName;
			*(float*)&params[8] = Duration;
			*(bool*)&params[12] = bLoop;
			*(bool*)&params[16] = bRestartIfAlreadyPlaying;
			*(float*)&params[20] = StartTime;
			*(bool*)&params[24] = bPlayBackwards;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7267);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CreateForceField(class AnimNotify_ForceField* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7269);
			byte params[8] = { NULL };
			*(class AnimNotify_ForceField**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool PlayParticleEffect(class AnimNotify_PlayParticleEffect* AnimNotifyData)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7276);
			byte params[8] = { NULL };
			*(class AnimNotify_PlayParticleEffect**)params = AnimNotifyData;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void SkelMeshCompOnParticleSystemFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* PSC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7302);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = PSC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BreakConstraint(Vector Impulse, Vector HitLocation, ScriptName InBoneName, bool bVelChange)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7304);
			byte params[36] = { NULL };
			*(Vector*)params = Impulse;
			*(Vector*)&params[12] = HitLocation;
			*(ScriptName*)&params[24] = InBoneName;
			*(bool*)&params[32] = bVelChange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
