#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUIFrontEnd_TitleScreen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUIFrontEnd_TitleScreen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUIFrontEnd_TitleScreen." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUIFrontEnd_TitleScreen : public GFxMoviePlayer
	{
	public:
			ADD_VAR( ::ByteProperty, Selection, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CampaignMap, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, InstantActionMap, 0xFFFFFFFF )
			ADD_OBJECT( GFxClikWidget, MenuBtn6MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn5MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn4MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn3MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn2MC )
			ADD_OBJECT( GFxClikWidget, MenuBtn1MC )
			ADD_OBJECT( GFxObject, BlackMC )
			ADD_OBJECT( GFxObject, MenuButtonsMC )
			ADD_OBJECT( GFxObject, MainMenuMC )
			ADD_OBJECT( GFxObject, TitleScreenMC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
