#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTSquadAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTSquadAI." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTSquadAI." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTSquadAI : public UDKSquadAI
	{
	public:
			ADD_OBJECT( Controller, SquadLeader )
			ADD_OBJECT( UTBot, SquadMembers )
			ADD_VAR( ::FloatProperty, FormationSize, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShouldUseGatherPoints, 0x20 )
			ADD_VAR( ::BoolProperty, bAddTransientCosts, 0x10 )
			ADD_VAR( ::BoolProperty, bRoamingSquad, 0x8 )
			ADD_VAR( ::BoolProperty, bFreelanceDefend, 0x4 )
			ADD_VAR( ::BoolProperty, bFreelanceAttack, 0x2 )
			ADD_VAR( ::BoolProperty, bFreelance, 0x1 )
			ADD_VAR( ::IntProperty, MaxSquadSize, 0xFFFFFFFF )
			ADD_OBJECT( Pawn, Enemies )
			ADD_VAR( ::NameProperty, CurrentOrders, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SupportStringTrailer, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FreelanceString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HoldString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AttackString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefendString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SupportString, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Size, 0xFFFFFFFF )
			ADD_OBJECT( UTSquadAI, NextSquad )
			ADD_OBJECT( UTPlayerReplicationInfo, LeaderPRI )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
