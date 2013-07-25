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
		// Here lies the not-yet-implemented method 'AttachComponent'
		// Here lies the not-yet-implemented method 'DetachComponent'
		// Here lies the not-yet-implemented method 'AttachComponentToSocket'
		// Here lies the not-yet-implemented method 'GetSocketWorldLocationAndRotation'
		// Here lies the not-yet-implemented method 'GetSocketByName'
		// Here lies the not-yet-implemented method 'GetSocketBoneName'
		// Here lies the not-yet-implemented method 'FindComponentAttachedToBone'
		// Here lies the not-yet-implemented method 'IsComponentAttached'
		// Here lies the not-yet-implemented method 'AttachedComponents'
		// Here lies the not-yet-implemented method 'GetTransformMatrix'
		// Here lies the not-yet-implemented method 'SetSkeletalMesh'
		// Here lies the not-yet-implemented method 'SetPhysicsAsset'
		// Here lies the not-yet-implemented method 'SetForceRefPose'
		// Here lies the not-yet-implemented method 'SetEnableClothSimulation'
		// Here lies the not-yet-implemented method 'SetClothFrozen'
		// Here lies the not-yet-implemented method 'SetEnableClothingSimulation'
		// Here lies the not-yet-implemented method 'UpdateClothParams'
		// Here lies the not-yet-implemented method 'SetClothExternalForce'
		// Here lies the not-yet-implemented method 'SetAttachClothVertsToBaseBody'
		// Here lies the not-yet-implemented method 'ResetClothVertsToRefPose'
		// Here lies the not-yet-implemented method 'GetClothAttachmentResponseCoefficient'
		// Here lies the not-yet-implemented method 'GetClothAttachmentTearFactor'
		// Here lies the not-yet-implemented method 'GetClothBendingStiffness'
		// Here lies the not-yet-implemented method 'GetClothCollisionResponseCoefficient'
		// Here lies the not-yet-implemented method 'GetClothDampingCoefficient'
		// Here lies the not-yet-implemented method 'GetClothFlags'
		// Here lies the not-yet-implemented method 'GetClothFriction'
		// Here lies the not-yet-implemented method 'GetClothPressure'
		// Here lies the not-yet-implemented method 'GetClothSleepLinearVelocity'
		// Here lies the not-yet-implemented method 'GetClothSolverIterations'
		// Here lies the not-yet-implemented method 'GetClothStretchingStiffness'
		// Here lies the not-yet-implemented method 'GetClothTearFactor'
		// Here lies the not-yet-implemented method 'GetClothThickness'
		// Here lies the not-yet-implemented method 'SetClothAttachmentResponseCoefficient'
		// Here lies the not-yet-implemented method 'SetClothAttachmentTearFactor'
		// Here lies the not-yet-implemented method 'SetClothBendingStiffness'
		// Here lies the not-yet-implemented method 'SetClothCollisionResponseCoefficient'
		// Here lies the not-yet-implemented method 'SetClothDampingCoefficient'
		// Here lies the not-yet-implemented method 'SetClothFlags'
		// Here lies the not-yet-implemented method 'SetClothFriction'
		// Here lies the not-yet-implemented method 'SetClothPressure'
		// Here lies the not-yet-implemented method 'SetClothSleepLinearVelocity'
		// Here lies the not-yet-implemented method 'SetClothSolverIterations'
		// Here lies the not-yet-implemented method 'SetClothStretchingStiffness'
		// Here lies the not-yet-implemented method 'SetClothTearFactor'
		// Here lies the not-yet-implemented method 'SetClothThickness'
		// Here lies the not-yet-implemented method 'SetClothSleep'
		// Here lies the not-yet-implemented method 'SetClothPosition'
		// Here lies the not-yet-implemented method 'SetClothVelocity'
		// Here lies the not-yet-implemented method 'AttachClothToCollidingShapes'
		// Here lies the not-yet-implemented method 'EnableClothValidBounds'
		// Here lies the not-yet-implemented method 'SetClothValidBounds'
		// Here lies the not-yet-implemented method 'UpdateSoftBodyParams'
		// Here lies the not-yet-implemented method 'SetSoftBodyFrozen'
		// Here lies the not-yet-implemented method 'WakeSoftBody'
		// Here lies the not-yet-implemented method 'FindAnimSequence'
		// Here lies the not-yet-implemented method 'SaveAnimSets'
		// Here lies the not-yet-implemented method 'RestoreSavedAnimSets'
		// Here lies the not-yet-implemented method 'GetAnimRateByDuration'
		// Here lies the not-yet-implemented method 'GetAnimLength'
		// Here lies the not-yet-implemented method 'FindMorphTarget'
		// Here lies the not-yet-implemented method 'FindAnimNode'
		// Here lies the not-yet-implemented method 'AllAnimNodes'
		// Here lies the not-yet-implemented method 'FindSkelControl'
		// Here lies the not-yet-implemented method 'FindMorphNode'
		// Here lies the not-yet-implemented method 'GetBoneQuaternion'
		// Here lies the not-yet-implemented method 'GetBoneLocation'
		// Here lies the not-yet-implemented method 'MatchRefBone'
		// Here lies the not-yet-implemented method 'GetBoneName'
		// Here lies the not-yet-implemented method 'GetBoneMatrix'
		// Here lies the not-yet-implemented method 'GetParentBone'
		// Here lies the not-yet-implemented method 'GetBoneNames'
		// Here lies the not-yet-implemented method 'BoneIsChildOf'
		// Here lies the not-yet-implemented method 'GetRefPosePosition'
		// Here lies the not-yet-implemented method 'GetBoneAxis'
		// Here lies the not-yet-implemented method 'TransformToBoneSpace'
		// Here lies the not-yet-implemented method 'TransformFromBoneSpace'
		// Here lies the not-yet-implemented method 'FindClosestBone'
		// Here lies the not-yet-implemented method 'GetClosestCollidingBoneLocation'
		// Here lies the not-yet-implemented method 'SetAnimTreeTemplate'
		// Here lies the not-yet-implemented method 'SetParentAnimComponent'
		// Here lies the not-yet-implemented method 'UpdateParentBoneMap'
		// Here lies the not-yet-implemented method 'InitSkelControls'
		// Here lies the not-yet-implemented method 'InitMorphTargets'
		// Here lies the not-yet-implemented method 'FindConstraintIndex'
		// Here lies the not-yet-implemented method 'FindConstraintBoneName'
		// Here lies the not-yet-implemented method 'FindBodyInstanceNamed'
		// Here lies the not-yet-implemented method 'SetHasPhysicsAssetInstance'
		// Here lies the not-yet-implemented method 'UpdateRBBonesFromSpaceBases'
		// Here lies the not-yet-implemented method 'ForceSkelUpdate'
		// Here lies the not-yet-implemented method 'UpdateAnimations'
		// Here lies the not-yet-implemented method 'GetBonesWithinRadius'
		// Here lies the not-yet-implemented method 'AddInstanceVertexWeightBoneParented'
		// Here lies the not-yet-implemented method 'RemoveInstanceVertexWeightBoneParented'
		// Here lies the not-yet-implemented method 'FindInstanceVertexweightBonePair'
		// Here lies the not-yet-implemented method 'UpdateInstanceVertexWeightBones'
		// Here lies the not-yet-implemented method 'ToggleInstanceVertexWeights'
		// Here lies the not-yet-implemented method 'PlayFaceFXAnim'
		// Here lies the not-yet-implemented method 'StopFaceFXAnim'
		// Here lies the not-yet-implemented method 'IsPlayingFaceFXAnim'
		// Here lies the not-yet-implemented method 'DeclareFaceFXRegister'
		// Here lies the not-yet-implemented method 'GetFaceFXRegister'
		// Here lies the not-yet-implemented method 'SetFaceFXRegister'
		// Here lies the not-yet-implemented method 'SetFaceFXRegisterEx'
		// Here lies the not-yet-implemented method 'HideBone'
		// Here lies the not-yet-implemented method 'UnHideBone'
		// Here lies the not-yet-implemented method 'IsBoneHidden'
		// Here lies the not-yet-implemented method 'HideBoneByName'
		// Here lies the not-yet-implemented method 'UnHideBoneByName'
		// Here lies the not-yet-implemented method 'UpdateMeshForBrokenConstraints'
		// Here lies the not-yet-implemented method 'ShowMaterialSection'
		// Here lies the not-yet-implemented method 'PlayAnim'
		// Here lies the not-yet-implemented method 'StopAnim'
		// Here lies the not-yet-implemented method 'CreateForceField'
		// Here lies the not-yet-implemented method 'PlayParticleEffect'
		// Here lies the not-yet-implemented method 'SkelMeshCompOnParticleSystemFinished'
		// Here lies the not-yet-implemented method 'BreakConstraint'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
