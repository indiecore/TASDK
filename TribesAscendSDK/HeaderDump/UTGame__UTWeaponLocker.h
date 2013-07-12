#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTWeaponLocker." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTWeaponLocker." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTWeaponLocker." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTWeaponLocker : public UTPickupFactory
	{
	public:
			ADD_VAR( ::FloatProperty, NextProximityCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ScaleRate, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, WeaponSpawnEffectTemplate )
			ADD_OBJECT( ParticleSystem, ActiveEffectTemplate )
			ADD_OBJECT( ParticleSystem, InactiveEffectTemplate )
			ADD_VAR( ::FloatProperty, ProximityDistanceSquared, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentWeaponScaleX, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bScalingUp, 0x4 )
			ADD_VAR( ::BoolProperty, bPlayerNearby, 0x2 )
			ADD_VAR( ::BoolProperty, bIsActive, 0x1 )
			ADD_VAR( ::StrProperty, LockerString, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
