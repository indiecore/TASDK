#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrAccoladeManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrAccoladeManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrAccoladeManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrAccoladeManager : public Object
	{
	public:
			ADD_VAR( ::IntProperty, m_nLastFlagReturnTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLastFlagGrabTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAXIMUM_EMERGENCY_GRAB_DISTANCE, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAXIMUM_FLAG_DEFENSE_DISTANCE, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MINIMUM_ULTRA_GRAB_SPEED, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MINIMUM_FAST_GRAB_SPEED, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAXIMUM_LLAMA_GRAB_SPEED, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MINIMUM_TIME_FLAG_CREDITS, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCurrSpinfusorKillStreak, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCurrExplosiveKillStreak, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCurrSnipingKillStreak, 0xFFFFFFFF )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_OBJECT( TrPlayerController, m_TrPC )
			ADD_OBJECT( TrGame, m_TrG )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
