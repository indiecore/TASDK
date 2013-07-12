#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTVehicleFactory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTVehicleFactory." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTVehicleFactory." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTVehicleFactory : public UDKVehicleFactory
	{
	public:
			ADD_VAR( ::BoolProperty, bStartNeutral, 0x2 )
			ADD_VAR( ::BoolProperty, bKeyVehicle, 0x8 )
			ADD_OBJECT( UTGameObjective, ReverseObjective )
			ADD_VAR( ::BoolProperty, bForceAvoidReversing, 0x10 )
			ADD_VAR( ::BoolProperty, bDisabled, 0x4 )
			ADD_VAR( ::BoolProperty, bMayReverseSpawnDirection, 0x1 )
			ADD_VAR( ::FloatProperty, SpawnZOffset, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
