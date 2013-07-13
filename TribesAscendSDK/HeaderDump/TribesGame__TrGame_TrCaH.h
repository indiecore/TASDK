#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrGame_TrCaH." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrGame_TrCaH." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrGame_TrCaH." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrGame_TrCaH : public TrGame
	{
	public:
			ADD_VAR( ::IntProperty, m_nPostCapturePointTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nTicketCountTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_5PointGoalScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_4PointGoalScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_3PointGoalScore, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nRemainingTicketTime, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
