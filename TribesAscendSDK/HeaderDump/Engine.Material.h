#pragma once
#include "Engine.MaterialExpressionCompound.h"
#include "Engine.EngineTypes.h"
#include "Engine.MaterialInterface.h"
#include "Engine.MaterialExpression.h"
#include "Engine.Texture2D.h"
#include "Engine.MaterialExpressionComment.h"
#include "Engine.PhysicalMaterial.h"
#include "Engine.Texture.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Material : public MaterialInterface
	{
	public:
		struct MaterialInput
		{
		public:
			ADD_STRUCT(int, GCC64_Padding, 24)
			ADD_STRUCT(int, MaskA, 20)
			ADD_STRUCT(int, MaskB, 16)
			ADD_STRUCT(int, MaskG, 12)
			ADD_STRUCT(int, MaskR, 8)
			ADD_STRUCT(int, Mask, 4)
			ADD_OBJECT(MaterialExpression, Expression, 0)
		};
		struct ColorMaterialInput : public MaterialInput
		{
		public:
			ADD_STRUCT(Object::Color, Constant, 32)
			ADD_BOOL(UseConstant, 28, 0x1)
		};
		struct ScalarMaterialInput : public MaterialInput
		{
		public:
			ADD_STRUCT(float, Constant, 32)
			ADD_BOOL(UseConstant, 28, 0x1)
		};
		struct VectorMaterialInput : public MaterialInput
		{
		public:
			ADD_STRUCT(Vector, Constant, 32)
			ADD_BOOL(UseConstant, 28, 0x1)
		};
		struct Vector2MaterialInput : public MaterialInput
		{
		public:
			ADD_STRUCT(float, ConstantY, 36)
			ADD_STRUCT(float, ConstantX, 32)
			ADD_BOOL(UseConstant, 28, 0x1)
		};
		ADD_STRUCT(ScriptArray<class MaterialExpression*>, Expressions, 1172)
		ADD_STRUCT(ScriptArray<class MaterialExpressionComment*>, EditorComments, 1184)
		ADD_STRUCT(ScriptArray<class MaterialExpressionCompound*>, EditorCompounds, 1196)
		ADD_STRUCT(ScriptArray<class Texture*>, ReferencedTextures, 1268)
		ADD_STRUCT(ScriptArray<Object::Guid>, ReferencedTextureGuids, 1280)
		ADD_STRUCT(int, EditorYaw, 1168)
		ADD_STRUCT(int, EditorPitch, 1164)
		ADD_STRUCT(int, EditorY, 1160)
		ADD_STRUCT(int, EditorX, 1156)
		ADD_STRUCT(Object::Pointer, DefaultMaterialInstances, 1144)
		ADD_STRUCT(Object::Pointer, MaterialResources, 1136)
		ADD_BOOL(bIsPreviewMaterial, 1132, 0x1000)
		ADD_BOOL(bIsMasked, 1132, 0x800)
		ADD_BOOL(bUsesDistortion, 1132, 0x400)
		ADD_BOOL(bIsFallbackMaterial, 1132, 0x200)
		ADD_BOOL(bAllowLightmapSpecular, 1132, 0x100)
		ADD_BOOL(bPerPixelCameraVector, 1132, 0x80)
		ADD_BOOL(Wireframe, 1132, 0x40)
		ADD_BOOL(bUseImageBasedReflections, 1132, 0x20)
		ADD_BOOL(bUsedWithScreenDoorFade, 1132, 0x10)
		ADD_BOOL(bUsedWithAPEXMeshes, 1132, 0x8)
		ADD_BOOL(bUsedWithSplineMeshes, 1132, 0x4)
		ADD_BOOL(bUsedWithInstancedMeshes, 1132, 0x2)
		ADD_BOOL(bUsedWithRadialBlur, 1132, 0x1)
		ADD_BOOL(bUsedWithMorphTargets, 1128, 0x80000000)
		ADD_BOOL(bUsedWithMaterialEffect, 1128, 0x40000000)
		ADD_BOOL(bUsedWithDecals, 1128, 0x20000000)
		ADD_BOOL(bUsedWithFluidSurfaces, 1128, 0x10000000)
		ADD_BOOL(bUsedWithInstancedMeshParticles, 1128, 0x8000000)
		ADD_BOOL(bUsedWithGammaCorrection, 1128, 0x4000000)
		ADD_BOOL(bUsedWithLensFlare, 1128, 0x2000000)
		ADD_BOOL(bUsedWithStaticLighting, 1128, 0x1000000)
		ADD_BOOL(bUsedWithSpeedTree, 1128, 0x800000)
		ADD_BOOL(bUsedWithParticleSubUV, 1128, 0x400000)
		ADD_BOOL(bUsedWithBeamTrails, 1128, 0x200000)
		ADD_BOOL(bUsedWithParticleSprites, 1128, 0x100000)
		ADD_BOOL(bUsedWithParticleSystem, 1128, 0x80000)
		ADD_BOOL(bUsedWithFracturedMeshes, 1128, 0x40000)
		ADD_BOOL(bUsedWithLandscape, 1128, 0x20000)
		ADD_BOOL(bUsedWithTerrain, 1128, 0x10000)
		ADD_BOOL(bUsedWithSkeletalMesh, 1128, 0x8000)
		ADD_BOOL(bUsedAsSpecialEngineMaterial, 1128, 0x4000)
		ADD_BOOL(bUsedWithFogVolumes, 1128, 0x2000)
		ADD_BOOL(bUsedAsLightFunction, 1128, 0x1000)
		ADD_BOOL(bCastLitTranslucencyShadowAsMasked, 1128, 0x800)
		ADD_BOOL(bUseLitTranslucencyPostRenderDepthPass, 1128, 0x400)
		ADD_BOOL(bUseLitTranslucencyDepthPass, 1128, 0x200)
		ADD_BOOL(bUseOneLayerDistortion, 1128, 0x100)
		ADD_BOOL(bAllowTranslucencyDoF, 1128, 0x80)
		ADD_BOOL(bTranslucencyInheritDominantShadowsFromOpaque, 1128, 0x40)
		ADD_BOOL(bTranslucencyReceiveDominantShadowsFromStatic, 1128, 0x20)
		ADD_BOOL(bAllowFog, 1128, 0x10)
		ADD_BOOL(bDisableDepthTest, 1128, 0x8)
		ADD_BOOL(TwoSidedSeparatePass, 1128, 0x4)
		ADD_BOOL(TwoSided, 1128, 0x2)
		ADD_BOOL(EnableSubsurfaceScattering, 1128, 0x1)
		ADD_STRUCT(Material::ScalarMaterialInput, SubsurfaceScatteringRadius, 1092)
		ADD_STRUCT(Material::ColorMaterialInput, SubsurfaceAbsorptionColor, 1056)
		ADD_STRUCT(Material::ColorMaterialInput, SubsurfaceInscatteringColor, 1020)
		ADD_STRUCT(Material::Vector2MaterialInput, TessellationFactors, 980)
		ADD_STRUCT(Material::VectorMaterialInput, WorldDisplacement, 936)
		ADD_STRUCT(Material::VectorMaterialInput, WorldPositionOffset, 892)
		ADD_STRUCT(Material::ColorMaterialInput, TwoSidedLightingColor, 856)
		ADD_STRUCT(Material::ScalarMaterialInput, TwoSidedLightingMask, 820)
		ADD_STRUCT(Material::VectorMaterialInput, AnisotropicDirection, 776)
		ADD_STRUCT(Material::ColorMaterialInput, CustomSkylightDiffuse, 740)
		ADD_STRUCT(Material::ColorMaterialInput, CustomLighting, 704)
		ADD_STRUCT(EngineTypes::EMaterialTessellationMode, D3D11TessellationMode, 702)
		ADD_STRUCT(EngineTypes::EMaterialLightingModel, LightingModel, 701)
		ADD_STRUCT(EngineTypes::EBlendMode, BlendMode, 700)
		ADD_STRUCT(Material::Vector2MaterialInput, Distortion, 660)
		ADD_STRUCT(float, OpacityMaskClipValue, 656)
		ADD_STRUCT(Material::ScalarMaterialInput, OpacityMask, 620)
		ADD_STRUCT(Material::ScalarMaterialInput, Opacity, 584)
		ADD_STRUCT(Material::ColorMaterialInput, EmissiveColor, 548)
		ADD_STRUCT(Material::VectorMaterialInput, Normal, 504)
		ADD_STRUCT(Material::ScalarMaterialInput, SpecularPower, 468)
		ADD_STRUCT(Material::ColorMaterialInput, SpecularColor, 432)
		ADD_STRUCT(Material::ScalarMaterialInput, DiffusePower, 396)
		ADD_STRUCT(Material::ColorMaterialInput, DiffuseColor, 360)
		ADD_OBJECT(PhysicalMaterial, WhitePhysicalMaterial, 356)
		ADD_OBJECT(PhysicalMaterial, BlackPhysicalMaterial, 352)
		ADD_STRUCT(int, PhysMaterialMaskUVChannel, 348)
		ADD_OBJECT(Texture2D, PhysMaterialMask, 344)
		ADD_OBJECT(ScriptClass, PhysicalMaterial, 340)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial, 336)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
