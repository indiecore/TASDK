#pragma once
#include "Core__Object.h"
#include "Engine__FaceFXAsset.h"
#include "Engine__PhysicsAsset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SkeletalMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SkeletalMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SkeletalMesh." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SkeletalMesh : public Object
	{
	public:
		ADD_OBJECT(FaceFXAsset, FaceFXAsset)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.BoxSphereBounds' for the property named 'Bounds'!
		ADD_STRUCT(::VectorProperty, Origin, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, RotOrigin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SkeletalDepth, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.IndirectArray_Mirror' for the property named 'LODModels'!
		ADD_VAR(::ByteProperty, SkelMirrorAxis, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SkelMirrorFlipAxis, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPerPolyUseSoftWeighting, 0x1)
		ADD_VAR(::BoolProperty, bUseSimpleLineCollision, 0x2)
		ADD_VAR(::BoolProperty, bUseSimpleBoxCollision, 0x4)
		ADD_VAR(::BoolProperty, bForceCPUSkinning, 0x8)
		ADD_VAR(::BoolProperty, bUseFullPrecisionUVs, 0x10)
		ADD_VAR(::BoolProperty, bUsePackedPosition, 0x20)
		ADD_OBJECT(PhysicsAsset, BoundsPreviewAsset)
		ADD_VAR(::IntProperty, LODBiasPC, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LODBiasPS3, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LODBiasXbox360, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SourceFilePath, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SourceFileTimestamp, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClothMovementScaleGenMode, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothToAnimMeshMaxDist, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLimitClothToAnimMesh, 0x1)
		ADD_VAR(::IntProperty, ClothWeldingDomain, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceNoWelding, 0x1)
		ADD_VAR(::IntProperty, NumFreeClothVerts, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClothHierarchyLevels, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableClothBendConstraints, 0x1)
		ADD_VAR(::BoolProperty, bEnableClothDamping, 0x2)
		ADD_VAR(::BoolProperty, bUseClothCOMDamping, 0x4)
		ADD_VAR(::FloatProperty, ClothStretchStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothBendStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothThickness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothDamping, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClothIterations, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClothHierarchicalIterations, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothFriction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothRelativeGridSpacing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothPressure, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothCollisionResponseCoefficient, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothAttachmentResponseCoefficient, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothAttachmentTearFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothSleepLinearVelocity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HardStretchLimitFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHardStretchLimit, 0x1)
		ADD_VAR(::BoolProperty, bEnableClothOrthoBendConstraints, 0x2)
		ADD_VAR(::BoolProperty, bEnableClothSelfCollision, 0x4)
		ADD_VAR(::BoolProperty, bEnableClothPressure, 0x8)
		ADD_VAR(::BoolProperty, bEnableClothTwoWayCollision, 0x10)
		ADD_VAR(::BoolProperty, bEnableClothLineChecks, 0x1)
		ADD_VAR(::BoolProperty, bClothMetal, 0x2)
		ADD_VAR(::FloatProperty, ClothMetalImpulseThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothMetalPenetrationDepth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ClothMetalMaxDeformationDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableClothTearing, 0x1)
		ADD_VAR(::FloatProperty, ClothTearFactor, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClothTearReserve, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableValidBounds, 0x1)
		ADD_STRUCT(::VectorProperty, ValidBoundsMin, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ValidBoundsMax, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Map_Mirror' for the property named 'ClothTornTriMap'!
		ADD_VAR(::FloatProperty, SoftBodyVolumeStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyStretchingStiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyParticleRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyDamping, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SoftBodySolverIterations, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyFriction, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyRelativeGridSpacing, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodySleepLinearVelocity, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableSoftBodySelfCollision, 0x1)
		ADD_VAR(::FloatProperty, SoftBodyAttachmentResponse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyCollisionResponse, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SoftBodyDetailLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SoftBodySubdivisionLevel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSoftBodyIsoSurface, 0x1)
		ADD_VAR(::BoolProperty, bEnableSoftBodyDamping, 0x2)
		ADD_VAR(::BoolProperty, bUseSoftBodyCOMDamping, 0x4)
		ADD_VAR(::FloatProperty, SoftBodyAttachmentThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableSoftBodyTwoWayCollision, 0x1)
		ADD_VAR(::FloatProperty, SoftBodyAttachmentTearFactor, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableSoftBodyLineChecks, 0x1)
		ADD_VAR(::BoolProperty, bHasVertexColors, 0x2)
		ADD_VAR(::FloatProperty, StreamingDistanceMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ReleaseResourcesFence, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.QWord' for the property named 'SkelMeshRUID'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
