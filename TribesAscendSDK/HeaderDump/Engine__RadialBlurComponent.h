#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.RadialBlurComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.RadialBlurComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.RadialBlurComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class RadialBlurComponent : public ActorComponent
	{
	public:
			ADD_VAR( ::BoolProperty, bEnabled, 0x2 )
			ADD_VAR( ::BoolProperty, bRenderAsVelocity, 0x1 )
			ADD_VAR( ::FloatProperty, DistanceFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxCullDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurOpacity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurFalloffExponent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BlurScale, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, DepthPriorityGroup, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, Material )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
