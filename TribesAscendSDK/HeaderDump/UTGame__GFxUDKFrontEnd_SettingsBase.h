#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.GFxUDKFrontEnd_SettingsBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.GFxUDKFrontEnd_SettingsBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.GFxUDKFrontEnd_SettingsBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_SettingsBase : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_OBJECT( UIDataStore_OnlineGameSettings, SettingsDataStore )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_VAR( ::StrProperty, SelectedOptionSet, 0xFFFFFFFF )
			ADD_OBJECT( GFxClikWidget, ListMC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
