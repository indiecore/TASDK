#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UDKBase.UDKUIResourceDataProvider." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UDKBase.UDKUIResourceDataProvider." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UDKBase.UDKUIResourceDataProvider." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKUIResourceDataProvider : public UIResourceDataProvider
	{
	public:
			ADD_VAR( ::StrProperty, IniName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bRemoveOnPS3, 0x8 )
			ADD_VAR( ::BoolProperty, bRemoveOnPC, 0x4 )
			ADD_VAR( ::BoolProperty, bRemoveOn360, 0x2 )
			ADD_VAR( ::BoolProperty, bSearchAllInis, 0x1 )
			ADD_VAR( ::StrProperty, FriendlyName, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
