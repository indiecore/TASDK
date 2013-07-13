#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_PlayNow." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_PlayNow." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_PlayNow." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_PlayNow : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, SeasonUpcomingSubtext, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NoFriendsOnlineLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RegionsSubtext, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RegionsLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, RankedLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CustomServerLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JoinFriendLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JoinFriendInGameSubLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, JoinFriendSubLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CustomServerSubtext, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ComingSoonSubtext, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
