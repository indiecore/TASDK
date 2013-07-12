#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.GameReplicationInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.GameReplicationInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.GameReplicationInfo." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GameReplicationInfo : public ReplicationInfo
	{
	public:
			ADD_VAR( ::BoolProperty, bMatchHasBegun, 0x2 )
			ADD_OBJECT( Actor, Winner )
			ADD_VAR( ::StrProperty, ServerName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TimeLimit, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GoalScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RemainingMinute, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ElapsedTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bFriendlyFire, 0x8 )
			ADD_VAR( ::BoolProperty, bMatchIsOver, 0x4 )
			ADD_VAR( ::BoolProperty, bStopCountDown, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
