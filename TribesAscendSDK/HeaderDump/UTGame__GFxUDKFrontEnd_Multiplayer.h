#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.GFxUDKFrontEnd_Multiplayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.GFxUDKFrontEnd_Multiplayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.GFxUDKFrontEnd_Multiplayer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxUDKFrontEnd_Multiplayer : public GFxUDKFrontEnd_Screen
	{
	public:
			ADD_OBJECT( GFxObject, MenuMC )
			ADD_OBJECT( GFxObject, ListDataProvider )
			ADD_OBJECT( GFxClikWidget, ListMC )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
