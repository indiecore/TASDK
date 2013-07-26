#pragma once
#include "Core.Object.Vector2D.h"
#include "Core.Object.Pointer.h"
#include "Engine.Texture2D.h"
#include "Core.Object.BoxSphereBounds.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.EngineTypes.LightMapRef.h"
#include "Core.Object.Guid.h"
#include "Core.Object.Vector4.h"
#include "Engine.MaterialInstanceConstant.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.LandscapeComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.LandscapeComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.LandscapeComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class LandscapeComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::IntProperty, CollisionMipLevel, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, EditToolRenderData, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LightMapRef>, LightMap, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Guid>, LightingGuid, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StaticLightingResolution, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<BoxSphereBounds>, CachedBoxSphereBounds, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, HeightmapTexture)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, LayerUVPan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HeightmapSubsectionOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector4>, HeightmapScaleBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeightmapSubsectionOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector4>, WeightmapScaleBias, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, EditingAlphaLayerName, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, MaterialInstance)
		ADD_VAR(::IntProperty, NumSubsections, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SubsectionSizeQuads, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ComponentSizeQuads, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseX, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
