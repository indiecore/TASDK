#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrRabbitLeaderboard." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrRabbitLeaderboard." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrRabbitLeaderboard." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrRabbitLeaderboard : public Object
	{
	public:
			ADD_OBJECT( GfxTrHud, m_MoviePlayer )
			ADD_VAR( ::BoolProperty, bIsActive, 0x4 )
			ADD_OBJECT( TrPlayerController, TrPC )
			ADD_VAR( ::BoolProperty, bInitialized, 0x2 )
			ADD_VAR( ::BoolProperty, bUpdated, 0x1 )
			ADD_VAR( ::IntProperty, RemainingTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevSlots, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
