#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.GFxUDKFrontEnd_MainMenu." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.GFxUDKFrontEnd_MainMenu." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.GFxUDKFrontEnd_MainMenu." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_MainMenu : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_OBJECT( GFxClikWidget, ListMC )
			ADD_VAR( ::ByteProperty, LastSelectedIndex, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, UserNameTxt )
			ADD_OBJECT( GFxObject, UserLabelTxt )
			ADD_OBJECT( GFxObject, ListDataProvider )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
