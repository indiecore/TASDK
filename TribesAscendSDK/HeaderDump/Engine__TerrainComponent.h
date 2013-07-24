#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.TerrainComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.TerrainComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TerrainComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::BoolProperty, bDisplayCollisionLevel, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RBHeightfield'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.TerrainComponent.TerrainBVTree' for the property named 'BVTree'!
		ADD_VAR(::IntProperty, FullBatch, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.EngineTypes.LightMapRef' for the property named 'LightMap'!
		ADD_VAR(::IntProperty, TrueSectionSizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TrueSectionSizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionSizeY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionSizeX, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SectionBaseX, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'TerrainObject'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
