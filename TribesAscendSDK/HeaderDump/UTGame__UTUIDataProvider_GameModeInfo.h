#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTUIDataProvider_GameModeInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTUIDataProvider_GameModeInfo." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTUIDataProvider_GameModeInfo." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTUIDataProvider_GameModeInfo : public UTUIResourceDataProvider
	{
	public:
			ADD_VAR( ::StrProperty, GameMode, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultMap, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Prefixes, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameSettingsClass, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, Description, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PreviewImageMarkup, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconVL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconUL, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconV, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, IconU, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, IconImage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, OptionSet, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameSearchClass, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
