#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrRabbitScoreMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrRabbitScoreMessage." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrRabbitScoreMessage." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrRabbitScoreMessage : public UTLocalMessage
	{
	public:
			ADD_OBJECT( SoundCue, m_sFlagReturnedToStand )
			ADD_OBJECT( SoundCue, m_sYouPickedUpFlag )
			ADD_OBJECT( SoundCue, m_sOtherIsNewLeadeCue )
			ADD_OBJECT( SoundCue, m_sYouAreNewLeadeCue )
			ADD_VAR( ::StrProperty, GetToTheFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, KillTheRabbit, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherDroppedFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouDroppedFlag, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherIsNewLeader, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouAreNewLeader, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OtherScoreFlagTouch, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, YouScoreFlagTouch, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
