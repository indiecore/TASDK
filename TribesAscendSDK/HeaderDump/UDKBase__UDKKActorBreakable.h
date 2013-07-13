#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKKActorBreakable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKKActorBreakable." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKKActorBreakable." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKKActorBreakable : public KActor
	{
	public:
			ADD_OBJECT( Controller, InstigatorController )
			ADD_OBJECT( ParticleSystem, BrokenTemplate )
			ADD_VAR( ::IntProperty, DOEResetThreshold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EncroachDamage_Self, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, EncroachDamage_Other, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Health, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBroken, 0x20 )
			ADD_VAR( ::BoolProperty, bBreakWhenCausingDamage, 0x10 )
			ADD_VAR( ::BoolProperty, bTakeDamageOnEncroachment, 0x8 )
			ADD_VAR( ::BoolProperty, bResetDOEWhenAsleep, 0x4 )
			ADD_VAR( ::BoolProperty, bDamageOnEncroachment, 0x2 )
			ADD_VAR( ::BoolProperty, bHasHealth, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
