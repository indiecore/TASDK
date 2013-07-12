#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrTeamRabbitStats." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrTeamRabbitStats." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrTeamRabbitStats." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrTeamRabbitStats : public Object
	{
	public:
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::BoolProperty, bIsActive, 0x1 )
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_VAR( ::IntProperty, TeamHoldingFlag, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TeamScore, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForcingUpdate, 0x2 )
			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MyTeam, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
