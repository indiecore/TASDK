#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.LandscapeComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.LandscapeComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.LandscapeComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class LandscapeComponent : public PrimitiveComponent
	{
	public:
			ADD_VAR( ::IntProperty, CollisionMipLevel, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StaticLightingResolution, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, HeightmapTexture )
			ADD_VAR( ::FloatProperty, HeightmapSubsectionOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WeightmapSubsectionOffset, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, EditingAlphaLayerName, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, MaterialInstance )
			ADD_VAR( ::IntProperty, NumSubsections, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SubsectionSizeQuads, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ComponentSizeQuads, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionBaseY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SectionBaseX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
