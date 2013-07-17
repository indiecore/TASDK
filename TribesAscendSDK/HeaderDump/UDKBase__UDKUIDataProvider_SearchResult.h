#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKUIDataProvider_SearchResult." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKUIDataProvider_SearchResult." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKUIDataProvider_SearchResult." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKUIDataProvider_SearchResult : public UIDataProvider_Settings
	{
	public:
			ADD_VAR( ::StrProperty, IconFontPathName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, MapNameTag, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ServerFlagsTag, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, GameModeFriendlyNameTag, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PlayerRatioTag, 0xFFFFFFFF )
			bool IsPrivateServer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKUIDataProvider_SearchResult.IsPrivateServer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
