#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_FollowerActions." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_FollowerActions." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_FollowerActions." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_FollowerActions : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, AlreadyFriendText, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, TargetOnlineState, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, TargetPlayerIndex, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, TargetPlayer, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWaitingForFriendActionPopup, 0x1 )
			ADD_VAR( ::IntProperty, FriendActionPopupIndex, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
