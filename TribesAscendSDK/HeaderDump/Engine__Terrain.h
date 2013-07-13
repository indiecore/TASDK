#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Terrain." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Terrain." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Terrain." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Terrain : public Info
	{
	public:
			ADD_VAR( ::IntProperty, EditorTessellationLevel, 0xFFFFFFFF )
			ADD_OBJECT( PhysicalMaterial, TerrainPhysMaterialOverride )
			ADD_VAR( ::BoolProperty, bShowWireframe, 0x8000 )
			ADD_VAR( ::BoolProperty, bUseWorldOriginTextureUVs, 0x4000 )
			ADD_VAR( ::BoolProperty, bShowingCollision, 0x2000 )
			ADD_VAR( ::BoolProperty, bHeightmapLocked, 0x1000 )
			ADD_VAR( ::BoolProperty, bLocked, 0x800 )
			ADD_VAR( ::BoolProperty, bMorphingGradientsEnabled, 0x400 )
			ADD_VAR( ::BoolProperty, bMorphingEnabled, 0x200 )
			ADD_VAR( ::BoolProperty, bAcceptsDynamicLights, 0x100 )
			ADD_VAR( ::BoolProperty, bAllowRigidBodyUnderneath, 0x80 )
			ADD_VAR( ::BoolProperty, bBlockRigidBody, 0x40 )
			ADD_VAR( ::BoolProperty, bEnableSpecular, 0x20 )
			ADD_VAR( ::BoolProperty, bCastDynamicShadow, 0x10 )
			ADD_VAR( ::BoolProperty, bForceDirectLightMap, 0x8 )
			ADD_VAR( ::BoolProperty, bCastShadow, 0x4 )
			ADD_VAR( ::BoolProperty, bBilinearFilterLightmapGeneration, 0x2 )
			ADD_VAR( ::BoolProperty, bIsOverridingLightResolution, 0x1 )
			ADD_VAR( ::IntProperty, StaticLightingResolution, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxComponentSize, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumPatchesY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumPatchesX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumVerticesY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumVerticesX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CollisionTesselationLevel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TessellationCheckDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TesselationDistanceScale, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinTessellationLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxTesselationLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumSectionsY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumSectionsX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NormalMapLayer, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
