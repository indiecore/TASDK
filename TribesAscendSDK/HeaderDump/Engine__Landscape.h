#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Landscape." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Landscape." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Landscape." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Landscape : public Info
	{
	public:
			ADD_VAR( ::IntProperty, NumSubsections, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SubsectionSizeQuads, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ComponentSizeQuads, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StreamingDistanceMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, StaticLightingResolution, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxLODLevel, 0xFFFFFFFF )
			ADD_OBJECT( Material, LandscapeMaterial )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
