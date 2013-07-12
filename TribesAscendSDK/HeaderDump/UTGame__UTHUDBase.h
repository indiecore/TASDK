#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTHUDBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTHUDBase." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTHUDBase." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTHUDBase : public UDKHUD
	{
	public:
			ADD_VAR( ::BoolProperty, bCrosshairShow, 0x4 )
			ADD_OBJECT( Texture2D, IconHudTexture )
			ADD_VAR( ::BoolProperty, bCrosshairOnFriendly, 0x8 )
			ADD_VAR( ::FloatProperty, ResolutionScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPickupTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ConfiguredCrosshairScaling, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bGreenCrosshair, 0x10 )
			ADD_VAR( ::BoolProperty, bIsSplitScreen, 0x1 )
			ADD_VAR( ::IntProperty, ViewY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, ViewX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ResolutionScaleX, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, ConsoleIconFontClassName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastTimeTooltipDrawn, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bEnableActorOverlays, 0x2 )
			ADD_OBJECT( UTGameReplicationInfo, UTGRI )
			ADD_OBJECT( UTPlayerController, UTPlayerOwner )
			ADD_OBJECT( GFxUI_PauseMenu, PauseMenuMovie )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
