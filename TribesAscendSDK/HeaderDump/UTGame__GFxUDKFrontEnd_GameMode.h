#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.GFxUDKFrontEnd_GameMode." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.GFxUDKFrontEnd_GameMode." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.GFxUDKFrontEnd_GameMode." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_GameMode : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_OBJECT( GFxClikWidget, ImgScrollerMC )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxClikWidget, ListMC )
			ADD_VAR( ::StrProperty, MapName, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, GameMode, 0xFFFFFFFF )
			ADD_OBJECT( UTUIDataStore_StringList, StringListDataStore )
			ADD_OBJECT( UIDataStore_OnlineGameSettings, SettingsDataStore )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
