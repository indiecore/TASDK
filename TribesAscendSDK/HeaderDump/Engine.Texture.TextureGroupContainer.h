#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Texture.TextureGroupContainer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TextureGroupContainer
	{
	public:
		ADD_VAR(::BoolProperty, TEXTUREGROUP_ImageBasedReflection, 0x4000000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Terrain_Weightmap, 0x2000000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Terrain_Heightmap, 0x1000000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_ColorLookupTable, 0x800000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Shadowmap, 0x400000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_ProcBuilding_LightMap, 0x200000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_ProcBuilding_Face, 0x100000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_MobileFlattened, 0x80000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_RenderTarget, 0x40000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Lightmap, 0x20000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_UI, 0x10000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Skybox, 0x8000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_EffectsNotFiltered, 0x4000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Effects, 0x2000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Cinematic, 0x1000)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_VehicleSpecular, 0x800)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_VehicleNormalMap, 0x400)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Vehicle, 0x200)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_WeaponSpecular, 0x100)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_WeaponNormalMap, 0x80)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Weapon, 0x40)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_CharacterSpecular, 0x20)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_CharacterNormalMap, 0x10)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_Character, 0x8)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_WorldSpecular, 0x4)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_WorldNormalMap, 0x2)
		ADD_VAR(::BoolProperty, TEXTUREGROUP_World, 0x1)
	};
}
#undef ADD_VAR
