#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_MapSelect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_MapSelect." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_MapSelect." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_MapSelect : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_VAR( ::IntProperty, LastSelectedItem, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxClikWidget, ImgScrollerMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxClikWidget, ListMC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
