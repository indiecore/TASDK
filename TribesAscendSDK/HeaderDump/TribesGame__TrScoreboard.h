#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrScoreboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrScoreboard." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrScoreboard." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrScoreboard : public Object
	{
	public:
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::BoolProperty, bIsActive, 0x8 )
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_VAR( ::BoolProperty, bCheckPing, 0x10 )
			ADD_VAR( ::BoolProperty, bInitialized, 0x4 )
			ADD_VAR( ::BoolProperty, bUpdated, 0x2 )
			ADD_VAR( ::BoolProperty, bTeamGame, 0x1 )
			ADD_VAR( ::IntProperty, DSIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BEIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DSOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevActiveSlot, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevDSSLots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevBESlots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DSSlots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, BESlots, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MAX_PLAYER_INDEX, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
