#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GFxUI.GFxMoviePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GFxUI.GFxMoviePlayer." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GFxUI.GFxMoviePlayer." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class GFxMoviePlayer : public Object
	{
	public:
			ADD_VAR( ::IntProperty, LocalPlayerOwnerIndex, 0xFFFFFFFF )
			ADD_OBJECT( SwfMovie, MovieInfo )
			ADD_VAR( ::BoolProperty, bAutoPlay, 0x80 )
			ADD_OBJECT( Object, ExternalInterface )
			ADD_VAR( ::BoolProperty, bPauseGameWhileActive, 0x100 )
			ADD_VAR( ::IntProperty, NextASUObject, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bMovieIsOpen, 0x1 )
			ADD_VAR( ::BoolProperty, bDisplayWithHudOff, 0x2 )
			ADD_VAR( ::BoolProperty, bEnableGammaCorrection, 0x4 )
			ADD_VAR( ::BoolProperty, bWidgetsInitializedThisFrame, 0x8 )
			ADD_VAR( ::BoolProperty, bLogUnhandedWidgetInitializations, 0x10 )
			ADD_VAR( ::BoolProperty, bAllowInput, 0x20 )
			ADD_VAR( ::BoolProperty, bAllowFocus, 0x40 )
			ADD_VAR( ::BoolProperty, bCloseOnLevelChange, 0x200 )
			ADD_VAR( ::BoolProperty, bOnlyOwnerFocusable, 0x400 )
			ADD_VAR( ::BoolProperty, bDiscardNonOwnerInput, 0x800 )
			ADD_VAR( ::BoolProperty, bCaptureInput, 0x1000 )
			ADD_VAR( ::BoolProperty, bIgnoreMouseInput, 0x2000 )
			ADD_VAR( ::BoolProperty, bForceSmoothAnimation, 0x4000 )
			ADD_OBJECT( TextureRenderTarget2D, RenderTexture )
			ADD_VAR( ::ByteProperty, TimingMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, RenderTextureMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Priority, 0xFFFFFFFF )
			ADD_OBJECT( GFxDataStoreSubscriber, DataStoreSubscriber )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
