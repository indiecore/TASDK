#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrCaHStats." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrCaHStats." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrCaHStats." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrCaHStats : public Object
	{
	public:
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::IntProperty, RoundNum, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, NumCapturePointsHeld, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RoundScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TeamScore, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceUpdateNextTick, 0x4 )
			ADD_VAR( ::BoolProperty, bForcingUpdate, 0x2 )
			ADD_VAR( ::BoolProperty, bIsActive, 0x1 )
			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MyTeam, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
