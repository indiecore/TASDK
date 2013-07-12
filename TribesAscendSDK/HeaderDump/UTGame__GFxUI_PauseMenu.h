#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.GFxUI_PauseMenu." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.GFxUI_PauseMenu." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.GFxUI_PauseMenu." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUI_PauseMenu : public UTGFxTweenableMoviePlayer
	{
	public:
			ADD_VAR( ::StrProperty, ExitString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ResumeString, 0xFFFFFFFF )
			ADD_OBJECT( GFxClikWidget, Btn_ExitMC )
			ADD_OBJECT( GFxClikWidget, Btn_ResumeMC )
			ADD_OBJECT( GFxObject, Btn_Family_Wrapper )
			ADD_OBJECT( GFxObject, Btn_Exit_Wrapper )
			ADD_OBJECT( GFxObject, Btn_Resume_Wrapper )
			ADD_OBJECT( GFxObject, OverlayMC )
			ADD_OBJECT( GFxObject, PauseMC )
			ADD_OBJECT( GFxObject, RootMC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
