#pragma once
#include "Engine.MaterialInterface.h"
#include "Engine.ApexAsset.h"
#include "Engine.FractureMaterial.h"
#include "Core.Object.h"
#include "Engine.PhysicalMaterial.h"
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
	class ApexDestructibleAsset : public ApexAsset
	{
	public:
		class NxDestructibleDepthParameters
		{
		public:
			ADD_BOOL(USER_FLAG_3, 0, 0x80)
			ADD_BOOL(USER_FLAG_2, 0, 0x40)
			ADD_BOOL(USER_FLAG_1, 0, 0x20)
			ADD_BOOL(USER_FLAG_0, 0, 0x10)
			ADD_BOOL(IGNORE_CONTACT_CALLBACKS, 0, 0x8)
			ADD_BOOL(IGNORE_RAYCAST_CALLBACKS, 0, 0x4)
			ADD_BOOL(IGNORE_POSE_UPDATES, 0, 0x2)
			ADD_BOOL(TAKE_IMPACT_DAMAGE, 0, 0x1)
		};
		class NxDestructibleParametersFlag
		{
		public:
			ADD_BOOL(USE_VALID_BOUNDS, 0, 0x80)
			ADD_BOOL(ACCURATE_RAYCASTS, 0, 0x40)
			ADD_BOOL(CRUMBLE_SMALLEST_CHUNKS, 0, 0x20)
			ADD_BOOL(DEBRIS_MAX_SEPARATION, 0, 0x10)
			ADD_BOOL(DEBRIS_TIMEOUT, 0, 0x8)
			ADD_BOOL(WORLD_SUPPORT, 0, 0x4)
			ADD_BOOL(ASSET_DEFINED_SUPPORT, 0, 0x2)
			ADD_BOOL(ACCUMULATE_DAMAGE, 0, 0x1)
		};
		class NxDestructibleParameters
		{
		public:
			ADD_STRUCT(ScriptArray<ApexDestructibleAsset::NxDestructibleDepthParameters>, DepthParameters, 116)
			ADD_STRUCT(float, FractureImpulseScale, 112)
			ADD_STRUCT(float, GrbParticleSpacing, 108)
			ADD_STRUCT(float, GrbVolumeLimit, 104)
			ADD_STRUCT(ApexDestructibleAsset::NxDestructibleParametersFlag, Flags, 100)
			ADD_STRUCT(float, MassScaleExponent, 96)
			ADD_STRUCT(float, MaxChunkSpeed, 92)
			ADD_STRUCT(Object::Box, ValidBounds, 64)
			ADD_STRUCT(float, DebrisMaxSeparationMax, 60)
			ADD_STRUCT(float, DebrisMaxSeparationMin, 56)
			ADD_STRUCT(float, DebrisLifetimeMax, 52)
			ADD_STRUCT(float, DebrisLifetimeMin, 48)
			ADD_STRUCT(int, EssentialDepth, 44)
			ADD_STRUCT(int, DebrisDepth, 40)
			ADD_STRUCT(int, SupportDepth, 36)
			ADD_BOOL(bFormExtendedStructures, 32, 0x1)
			ADD_STRUCT(float, DeformationPercentLimit, 28)
			ADD_STRUCT(float, DamageToPercentDeformation, 24)
			ADD_STRUCT(float, MaterialStrength, 20)
			ADD_STRUCT(float, ImpactVelocityThreshold, 16)
			ADD_STRUCT(float, ForceToDamage, 12)
			ADD_STRUCT(float, DamageCap, 8)
			ADD_STRUCT(float, DamageToRadius, 4)
			ADD_STRUCT(float, DamageThreshold, 0)
		};
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 112)
		ADD_STRUCT(ScriptArray<class FractureMaterial*>, FractureMaterials, 124)
		ADD_STRUCT(ApexDestructibleAsset::NxDestructibleParameters, DestructibleParameters, 172)
		ADD_STRUCT(ScriptString*, DustEmitterName, 160)
		ADD_STRUCT(ScriptString*, CrumbleEmitterName, 148)
		ADD_BOOL(bDynamic, 144, 0x2)
		ADD_BOOL(bHasUniqueAssetMaterialNames, 144, 0x1)
		ADD_STRUCT(Object::Pointer, MDestructibleThumbnailComponent, 140)
		ADD_OBJECT(PhysicalMaterial, DefaultPhysMaterial, 136)
		ADD_STRUCT(Object::Pointer, MApexAsset, 108)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
