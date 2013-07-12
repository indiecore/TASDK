#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " IpDrv.PartyBeaconHost." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty IpDrv.PartyBeaconHost." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty IpDrv.PartyBeaconHost." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PartyBeaconHost : public PartyBeacon
	{
	public:
			ADD_VAR( ::ByteProperty, BeaconState, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bBestFitTeamAssignment, 0x1 )
			ADD_VAR( ::IntProperty, ReservedHostTeamNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ForceTeamNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ConnectionBacklog, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, OnlineSessionName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumConsumedReservations, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumReservations, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumPlayersPerTeam, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumTeams, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
