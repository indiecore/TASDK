#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKExplosionLight." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKExplosionLight." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKExplosionLight." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKExplosionLight : public PointLightComponent
	{
	public:
			ADD_VAR( ::IntProperty, TimeShiftIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Lifetime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HighDetailFrameTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bInitialized, 0x2 )
			ADD_VAR( ::BoolProperty, bCheckFrameRate, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
