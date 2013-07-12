#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " Engine.OnlinePlaylistProvider." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty Engine.OnlinePlaylistProvider." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty Engine.OnlinePlaylistProvider." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlaylistProvider : public UIResourceDataProvider
	{
	public:
			ADD_VAR( ::IntProperty, Priority, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsArbitrated, 0x1 )
			ADD_VAR( ::StrProperty, DisplayName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, PlaylistId, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
