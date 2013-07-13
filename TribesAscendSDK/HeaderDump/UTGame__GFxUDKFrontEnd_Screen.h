#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_Screen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_Screen." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_Screen." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_Screen : public GFxUDKFrontEnd_View
	{
	public:
			ADD_VAR( ::StrProperty, CancelButtonImage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AcceptButtonImage, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CancelButtonHelpText, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AcceptButtonHelpText, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, InfoTxt )
			ADD_OBJECT( GFxObject, HelpTxt )
			ADD_OBJECT( GFxObject, LogoMC )
			ADD_OBJECT( GFxObject, FooterMC )
			ADD_OBJECT( GFxObject, TitleMC )
			ADD_OBJECT( GFxClikWidget, BackBtn )
			ADD_VAR( ::StrProperty, ViewTitle, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
