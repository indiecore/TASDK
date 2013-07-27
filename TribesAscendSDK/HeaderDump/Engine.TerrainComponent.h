#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.EngineTypes.h"
#include "Engine.ShadowMap2D.h"
#include "Core.Object.h"
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
namespace UnrealScript
{
	class TerrainComponent : public PrimitiveComponent
	{
	public:
		struct TerrainPatchBounds
		{
		public:
			ADD_STRUCT(float, MaxDisplacement, 8)
			ADD_STRUCT(float, MaxHeight, 4)
			ADD_STRUCT(float, MinHeight, 0)
		};
		struct TerrainMaterialMask
		{
		public:
			ADD_STRUCT(int, NumBits, 8)
			ADD_STRUCT(QWord, BitMask, 0)
		};
		struct TerrainBVTree
		{
		public:
			ADD_STRUCT(ScriptArray<int>, Nodes, 0)
		};
		ADD_STRUCT(ScriptArray<class ShadowMap2D*>, ShadowMaps, 488)
		ADD_STRUCT(ScriptArray<Object::Guid>, IrrelevantLights, 500)
		ADD_STRUCT(ScriptArray<TerrainComponent::TerrainPatchBounds>, PatchBounds, 544)
		ADD_STRUCT(ScriptArray<TerrainComponent::TerrainMaterialMask>, BatchMaterials, 556)
		ADD_STRUCT(ScriptArray<Vector>, CollisionVertices, 584)
		ADD_BOOL(bDisplayCollisionLevel, 600, 0x1)
		ADD_STRUCT(Object::Pointer, RBHeightfield, 596)
		ADD_STRUCT(TerrainComponent::TerrainBVTree, BVTree, 572)
		ADD_STRUCT(int, FullBatch, 568)
		ADD_STRUCT(EngineTypes::LightMapRef, LightMap, 540)
		ADD_STRUCT(int, TrueSectionSizeY, 536)
		ADD_STRUCT(int, TrueSectionSizeX, 532)
		ADD_STRUCT(int, SectionSizeY, 528)
		ADD_STRUCT(int, SectionSizeX, 524)
		ADD_STRUCT(int, SectionBaseY, 520)
		ADD_STRUCT(int, SectionBaseX, 516)
		ADD_STRUCT(Object::Pointer, TerrainObject, 512)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
