#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrBrowserManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrBrowserManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrBrowserManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrBrowserManager : public Object
	{
	public:
			ADD_VAR( ::StrProperty, URLCreateSteamAccount, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLRecoverUsername, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLRecoverPassword, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLCreateAccount, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLActivateKey, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLClassVideo, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLRedirect, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLProfile, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLSupport, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLBooster, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLStore, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLAlert, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, URLGold, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
