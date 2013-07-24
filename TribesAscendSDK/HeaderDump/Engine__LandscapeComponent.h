#pragma once
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
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'EditToolRenderData'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightMapRef' for the property named 'LightMap'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'LightingGuid'!
		ADD_VAR(::IntProperty, StaticLightingResolution, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.BoxSphereBounds' for the property named 'CachedBoxSphereBounds'!
		ADD_OBJECT(Texture2D, HeightmapTexture)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'LayerUVPan'!
		ADD_VAR(::FloatProperty, HeightmapSubsectionOffset, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector4' for the property named 'HeightmapScaleBias'!
		ADD_VAR(::FloatProperty, WeightmapSubsectionOffset, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector4' for the property named 'WeightmapScaleBias'!
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
