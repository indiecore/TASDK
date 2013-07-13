#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.MobileHUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.MobileHUD." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.MobileHUD." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MobileHUD : public HUD
	{
	public:
			ADD_VAR( ::FloatProperty, MobileTiltSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileTiltY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileTiltX, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, SliderImages )
			ADD_OBJECT( Texture2D, TrackballTouchIndicator )
			ADD_OBJECT( Texture2D, TrackballBackground )
			ADD_OBJECT( Font, ButtonFont )
			ADD_OBJECT( Texture2D, ButtonImages )
			ADD_OBJECT( Texture2D, JoystickHat )
			ADD_OBJECT( Texture2D, JoystickBackground )
			ADD_VAR( ::BoolProperty, bShowMotionDebug, 0x80 )
			ADD_VAR( ::BoolProperty, bDebugZonePresses, 0x40 )
			ADD_VAR( ::BoolProperty, bDebugZones, 0x20 )
			ADD_VAR( ::BoolProperty, bDebugTouches, 0x10 )
			ADD_VAR( ::BoolProperty, bShowMobileTilt, 0x8 )
			ADD_VAR( ::BoolProperty, bForceMobileHUD, 0x4 )
			ADD_VAR( ::BoolProperty, bShowMobileHud, 0x2 )
			ADD_VAR( ::BoolProperty, bShowGameHud, 0x1 )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
