#pragma once
#include "Engine.Info.h"
#include "Engine.EngineTypes.h"
#include "Engine.TerrainWeightMapTexture.h"
#include "Core.Object.h"
#include "Engine.LightComponent.h"
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
	class Terrain : public Info
	{
	public:
		class TerrainHeight
		{
		};
		class TerrainInfoData
		{
		};
		class TerrainLayer
		{
		public:
			ADD_STRUCT(int, MaxY, 44)
			ADD_STRUCT(int, MaxX, 40)
			ADD_STRUCT(int, MinY, 36)
			ADD_STRUCT(int, MinX, 32)
			ADD_STRUCT(Object::Color, WireframeColor, 28)
			ADD_STRUCT(Object::Color, HighlightColor, 24)
			ADD_BOOL(Hidden, 20, 0x4)
			ADD_BOOL(WireframeHighlighted, 20, 0x2)
			ADD_BOOL(Highlighted, 20, 0x1)
			ADD_STRUCT(int, AlphaMapIndex, 16)
			ADD_OBJECT(TerrainLayerSetup, Setup, 12)
			ADD_STRUCT(ScriptString*, Name, 0)
		};
		class AlphaMap
		{
		};
		class TerrainWeightedMaterial
		{
		};
		class SelectedTerrainVertex
		{
		public:
			ADD_STRUCT(int, Weight, 8)
			ADD_STRUCT(int, Y, 4)
			ADD_STRUCT(int, X, 0)
		};
		class TerrainDecorationInstance
		{
		public:
			ADD_STRUCT(int, Yaw, 16)
			ADD_STRUCT(float, Scale, 12)
			ADD_STRUCT(float, Y, 8)
			ADD_STRUCT(float, X, 4)
		};
		class TerrainDecoration
		{
		public:
			ADD_STRUCT(ScriptArray<Terrain::TerrainDecorationInstance>, Instances, 24)
			ADD_STRUCT(int, RandSeed, 20)
			ADD_STRUCT(float, SlopeRotationBlend, 16)
			ADD_STRUCT(float, Density, 12)
			ADD_STRUCT(float, MaxScale, 8)
			ADD_STRUCT(float, MinScale, 4)
			ADD_OBJECT(PrimitiveComponentFactory, Factory, 0)
		};
		class TerrainMaterialResource
		{
		};
		class CachedTerrainMaterialArray
		{
		public:
			ADD_STRUCT(ScriptArray<Object::Pointer>, CachedMaterials, 0)
		};
		class TerrainDecoLayer
		{
		public:
			ADD_STRUCT(ScriptArray<Terrain::TerrainDecoration>, Decorations, 12)
			ADD_STRUCT(int, AlphaMapIndex, 24)
			ADD_STRUCT(ScriptString*, Name, 0)
		};
		ADD_STRUCT(ScriptArray<Terrain::TerrainHeight>, Heights, 476)
		ADD_STRUCT(ScriptArray<Terrain::TerrainInfoData>, InfoData, 488)
		ADD_STRUCT(ScriptArray<Terrain::TerrainLayer>, Layers, 500)
		ADD_STRUCT(ScriptArray<Terrain::TerrainDecoLayer>, DecoLayers, 516)
		ADD_STRUCT(ScriptArray<Terrain::AlphaMap>, AlphaMaps, 528)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, TerrainComponents, 540)
		ADD_STRUCT(ScriptArray<Terrain::TerrainWeightedMaterial>, WeightedMaterials, 560)
		ADD_STRUCT(ScriptArray<class TerrainWeightMapTexture*>, WeightedTextureMaps, 572)
		ADD_STRUCT(ScriptArray<Terrain::SelectedTerrainVertex>, SelectedVertices, 700)
		ADD_STRUCT(Object::Guid, LightingGuid, 716)
		ADD_STRUCT(Object::Color, WireframeColor, 712)
		ADD_STRUCT(int, EditorTessellationLevel, 696)
		ADD_STRUCT(Object::Pointer, ReleaseResourcesFence, 692)
		ADD_STRUCT(EngineTypes::LightmassPrimitiveSettings, LightmassSettings, 664)
		ADD_STRUCT(LightComponent::LightingChannelContainer, LightingChannels, 660)
		ADD_OBJECT(PhysicalMaterial, TerrainPhysMaterialOverride, 656)
		ADD_BOOL(bShowWireframe, 652, 0x8000)
		ADD_BOOL(bUseWorldOriginTextureUVs, 652, 0x4000)
		ADD_BOOL(bShowingCollision, 652, 0x2000)
		ADD_BOOL(bHeightmapLocked, 652, 0x1000)
		ADD_BOOL(bLocked, 652, 0x800)
		ADD_BOOL(bMorphingGradientsEnabled, 652, 0x400)
		ADD_BOOL(bMorphingEnabled, 652, 0x200)
		ADD_BOOL(bAcceptsDynamicLights, 652, 0x100)
		ADD_BOOL(bAllowRigidBodyUnderneath, 652, 0x80)
		ADD_BOOL(bBlockRigidBody, 652, 0x40)
		ADD_BOOL(bEnableSpecular, 652, 0x20)
		ADD_BOOL(bCastDynamicShadow, 652, 0x10)
		ADD_BOOL(bForceDirectLightMap, 652, 0x8)
		ADD_BOOL(bCastShadow, 652, 0x4)
		ADD_BOOL(bBilinearFilterLightmapGeneration, 652, 0x2)
		ADD_BOOL(bIsOverridingLightResolution, 652, 0x1)
		ADD_STRUCT(int, StaticLightingResolution, 648)
		ADD_STRUCT(int, MaxComponentSize, 644)
		ADD_STRUCT(int, NumPatchesY, 640)
		ADD_STRUCT(int, NumPatchesX, 636)
		ADD_STRUCT(int, NumVerticesY, 632)
		ADD_STRUCT(int, NumVerticesX, 628)
		ADD_STRUCT(Terrain::CachedTerrainMaterialArray, CachedTerrainMaterials, 604)
		ADD_STRUCT(int, CollisionTesselationLevel, 600)
		ADD_STRUCT(float, TessellationCheckDistance, 596)
		ADD_STRUCT(float, TesselationDistanceScale, 592)
		ADD_STRUCT(int, MinTessellationLevel, 588)
		ADD_STRUCT(int, MaxTesselationLevel, 584)
		ADD_STRUCT(int, NumSectionsY, 556)
		ADD_STRUCT(int, NumSectionsX, 552)
		ADD_STRUCT(int, NormalMapLayer, 512)
		void CalcLayerBounds()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Terrain.CalcLayerBounds");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Terrain.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
