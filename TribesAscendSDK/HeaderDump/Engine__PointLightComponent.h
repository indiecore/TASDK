#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PointLightComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PointLightComponent." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PointLightComponent." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PointLightComponent : public LightComponent
	{
	public:
			ADD_STRUCT( ::VectorProperty, Translation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinShadowFalloffRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShadowFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Radius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShadowRadiusMultiplier, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
