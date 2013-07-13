#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.OnlinePlaylistGameTypeProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.OnlinePlaylistGameTypeProvider." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.OnlinePlaylistGameTypeProvider." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class OnlinePlaylistGameTypeProvider : public UIResourceDataProvider
	{
	public:
			ADD_VAR( ::IntProperty, GameTypeId, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Description, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DisplayName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PlaylistGameTypeName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
