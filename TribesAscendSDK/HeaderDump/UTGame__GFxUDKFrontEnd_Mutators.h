#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.GFxUDKFrontEnd_Mutators." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.GFxUDKFrontEnd_Mutators." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.GFxUDKFrontEnd_Mutators." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_Mutators : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_VAR( ::BoolProperty, bFirstUpdateAfterActivation, 0x1 )
			ADD_OBJECT( GFxObject, ConfigListDataProvider )
			ADD_OBJECT( GFxClikWidget, ConfigListMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxClikWidget, ListMC )
			ADD_OBJECT( UTUIDataStore_MenuItems, MenuDataStore )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
