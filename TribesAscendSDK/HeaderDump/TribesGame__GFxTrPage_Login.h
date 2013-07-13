#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.GFxTrPage_Login." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.GFxTrPage_Login." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.GFxTrPage_Login." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxTrPage_Login : public GFxTrPage
	{
	public:
			ADD_VAR( ::StrProperty, CreateAccountLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpPasswordLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpUsernameLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, CheckboxLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, PasswordLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, UsernameLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, BetaKeyLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, AccountLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, SubmitLabel, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, HelpLabel, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
