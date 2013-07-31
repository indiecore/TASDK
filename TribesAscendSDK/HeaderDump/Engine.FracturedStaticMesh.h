#pragma once
#include "Engine.StaticMesh.h"
#include "Engine.ParticleSystem.h"
#include "Engine.MaterialInterface.h"
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
	class FracturedStaticMesh : public StaticMesh
	{
	public:
		ADD_OBJECT(ParticleSystem, FragmentDestroyEffect, 436)
		ADD_STRUCT(ScriptArray<class ParticleSystem*>, FragmentDestroyEffects, 440)
		ADD_STRUCT(float, FragmentDestroyEffectScale, 452)
		ADD_STRUCT(float, FragmentHealthScale, 456)
		ADD_STRUCT(float, FragmentMinHealth, 460)
		ADD_STRUCT(float, FragmentMaxHealth, 464)
		ADD_BOOL(bUniformFragmentHealth, 468, 0x1)
		ADD_OBJECT(StaticMesh, SourceCoreMesh, 376)
		ADD_STRUCT(float, CoreMeshScale, 380)
		ADD_BOOL(bSliceUsingCoreCollision, 432, 0x1)
		ADD_STRUCT(float, ChunkLinVel, 472)
		ADD_STRUCT(float, ChunkAngVel, 476)
		ADD_STRUCT(float, ChunkLinHorizontalScale, 480)
		ADD_STRUCT(float, ExplosionVelScale, 484)
		ADD_BOOL(bCompositeChunksExplodeOnImpact, 488, 0x1)
		ADD_BOOL(bFixIsolatedChunks, 492, 0x1)
		ADD_BOOL(bAlwaysBreakOffIsolatedIslands, 496, 0x1)
		ADD_BOOL(bSpawnPhysicsChunks, 500, 0x1)
		ADD_STRUCT(float, ChanceOfPhysicsChunk, 504)
		ADD_STRUCT(float, ExplosionChanceOfPhysicsChunk, 508)
		ADD_STRUCT(float, NormalPhysicsChunkScaleMin, 512)
		ADD_STRUCT(float, NormalPhysicsChunkScaleMax, 516)
		ADD_STRUCT(float, ExplosionPhysicsChunkScaleMin, 520)
		ADD_STRUCT(float, ExplosionPhysicsChunkScaleMax, 524)
		ADD_STRUCT(float, MinConnectionSupportArea, 528)
		ADD_OBJECT(MaterialInterface, DynamicOutsideMaterial, 532)
		ADD_OBJECT(MaterialInterface, LoseChunkOutsideMaterial, 536)
		ADD_STRUCT(int, OutsideMaterialIndex, 540)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
