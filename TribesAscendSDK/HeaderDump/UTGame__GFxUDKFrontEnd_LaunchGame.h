#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_LaunchGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_LaunchGame." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_LaunchGame." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_LaunchGame : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_OBJECT( GFxObject, MutatorsLabelTxt )
			ADD_OBJECT( GFxObject, RespawnLabelTxt )
			ADD_OBJECT( GFxObject, TimeLabelTxt )
			ADD_OBJECT( GFxObject, ScoreLabelTxt )
			ADD_OBJECT( GFxObject, OpponentsLabelTxt )
			ADD_OBJECT( GFxObject, BotLvlLabelTxt )
			ADD_OBJECT( GFxObject, MapLabelTxt )
			ADD_OBJECT( GFxObject, MutatorsTxt )
			ADD_OBJECT( GFxObject, RespawnTxt )
			ADD_OBJECT( GFxObject, MapTxt )
			ADD_OBJECT( GFxObject, TimeTxt )
			ADD_OBJECT( GFxObject, ScoreTxt )
			ADD_OBJECT( GFxObject, OpponentsTxt )
			ADD_OBJECT( GFxObject, BotLvlTxt )
			ADD_OBJECT( GFxObject, GameTitleTxt )
			ADD_OBJECT( GFxObject, MapNameTxt )
			ADD_OBJECT( GFxObject, MapImageMC )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxClikWidget, ListMC )
			ADD_VAR( ::StrProperty, DefaultGameModePrefixes, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultMapImage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultGameModeSettings, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultGameMode, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DefaultMapName, 0xFFFFFFFF )
			ADD_OBJECT( UTUIDataStore_MenuItems, MenuDataStore )
			ADD_OBJECT( UTUIDataStore_StringList, StringListDataStore )
			ADD_OBJECT( UIDataStore_OnlineGameSettings, SettingsDataStore )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
