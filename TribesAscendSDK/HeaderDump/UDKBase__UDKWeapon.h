#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKWeapon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKWeapon : public Weapon
	{
	public:
			ADD_VAR( ::FloatProperty, AimTraceRange, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, HitEnemy, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bConsiderProjectileAcceleration, 0x2 )
			ADD_VAR( ::BoolProperty, bLeadTarget, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
