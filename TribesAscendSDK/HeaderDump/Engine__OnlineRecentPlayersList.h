#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.OnlineRecentPlayersList." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.OnlineRecentPlayersList." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.OnlineRecentPlayersList." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlineRecentPlayersList : public Object
	{
	public:
			ADD_VAR( ::IntProperty, RecentPartiesAddIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RecentPlayersAddIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxRecentParties, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxRecentPlayers, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
