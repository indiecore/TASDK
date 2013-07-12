#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.GFxUDKFrontEnd_FilterDialog." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.GFxUDKFrontEnd_FilterDialog." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.GFxUDKFrontEnd_FilterDialog." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_FilterDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
			ADD_OBJECT( GFxObject, GameTypeOptionItem )
			ADD_OBJECT( GFxObject, DataProvider )
			ADD_VAR( ::BoolProperty, bFiltersHaveChanged, 0x1 )
			ADD_OBJECT( GFxClikWidget, FilterListMC )
			ADD_OBJECT( UTDataStore_GameSearchDM, SearchDataStore )
			ADD_OBJECT( UTUIDataStore_MenuItems, MenuDataStore )
			ADD_OBJECT( UTUIDataStore_StringList, StringListDataStore )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
