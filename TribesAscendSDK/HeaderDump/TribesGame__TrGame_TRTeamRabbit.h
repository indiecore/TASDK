#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGame_TRTeamRabbit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGame_TRTeamRabbit." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGame_TRTeamRabbit." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGame_TRTeamRabbit : public TrGame
	{
	public:
			ADD_OBJECT( TrFlagTeamRabbit, m_TeamRabbitFlag )
			ADD_VAR( ::IntProperty, m_nBuffAmount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, m_nBuffedTeamIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bPlayedAnnouncerRally, 0x2 )
			ADD_VAR( ::BoolProperty, m_bSpawnFlagOnNextKill, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
