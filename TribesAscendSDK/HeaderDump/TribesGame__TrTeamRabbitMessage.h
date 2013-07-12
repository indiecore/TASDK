#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrTeamRabbitMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrTeamRabbitMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrTeamRabbitMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrTeamRabbitMessage : public UTLocalMessage
	{
	public:
			ADD_VAR( ::StrProperty, LivesLeft, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, EnemyTeamHas, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YourTeamHas, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DroppedTheFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KillBonus, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YourTeamHasTheFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TheEnemyHasTheFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouHaveTheFlag, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
