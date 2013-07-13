#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_BlockedPlayers." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_BlockedPlayers." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_BlockedPlayers." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_BlockedPlayers : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, FlyoutTitle, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, UnblockOption, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BlockedStatus, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BlockSubtext, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BlockOption, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWaitingForFriendRemovePopup, 0x2 )
			ADD_VAR( ::BoolProperty, bWaitingForFriendAddPopup, 0x1 )
			ADD_VAR( ::IntProperty, RemovingIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevPlayerId, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FocusedIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
