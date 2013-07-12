#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrHUDTeamCTFStats." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrHUDTeamCTFStats." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrHUDTeamCTFStats." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrHUDTeamCTFStats : public Object
	{
	public:
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::BoolProperty, bIsActive, 0x1 )
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_OBJECT( PlayerReplicationInfo, FlagHolderPRI )
			ADD_VAR( ::ByteProperty, bEmptyFlagStatus, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, FlagState, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GeneratorDowntime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GeneratorPower, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TeamScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FlagReturnTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MyTeam, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
