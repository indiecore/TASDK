#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrFriendManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrFriendManager." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrFriendManager." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrFriendManager : public TrObject
	{
	public:
			ADD_VAR( ::BoolProperty, AddFriendSuccess, 0x1 )
			ADD_VAR( ::StrProperty, RecentlyAddedFriend, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, GFxList )
			ADD_VAR( ::IntProperty, GFxCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevBlockedCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevFollowerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PrevFriendCount, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
