#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.GFxMinimap." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.GFxMinimap." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.GFxMinimap." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxMinimap : public GFxObject
	{
	public:
			ADD_VAR( ::IntProperty, IconsFlagCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconsBlueCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconsRedCount, 0xFFFFFFFF )
			ADD_OBJECT( GFxObject, IconsFlagMC )
			ADD_OBJECT( GFxObject, IconsBlueMC )
			ADD_OBJECT( GFxObject, IconsRedMC )
			ADD_OBJECT( GFxObject, MapMC )
			ADD_OBJECT( GFxObject, CompassIcon )
			ADD_OBJECT( GFxObject, PlayerIcon )
			ADD_VAR( ::BoolProperty, bNeedsUpdateData, 0x1 )
			ADD_VAR( ::IntProperty, MapTexSize, 0xFFFFFFFF )
			ADD_OBJECT( UTMapInfo, MapInfo )
			ADD_OBJECT( WorldInfo, ThisWorld )
			ADD_OBJECT( GFxMinimapHud, HUD )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
