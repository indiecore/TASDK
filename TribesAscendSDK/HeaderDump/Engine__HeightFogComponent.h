#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.HeightFogComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.HeightFogComponent." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.HeightFogComponent." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class HeightFogComponent : public ActorComponent
	{
	public:
			ADD_VAR( ::FloatProperty, StartDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExtinctionDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LightBrightness, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Density, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Height, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnabled, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
