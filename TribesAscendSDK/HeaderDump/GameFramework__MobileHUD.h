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
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRender(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.PostRender" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMobileDebugString( float XPos, float YPos, ScriptArray< wchar_t > Str )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.DrawMobileDebugString" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( float* )params = XPos;
				*( float* )( params + 4 ) = YPos;
				*( ScriptArray< wchar_t >* )( params + 8 ) = Str;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShowMobileHud(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.ShowMobileHud" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RenderMobileMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.RenderMobileMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawInputZoneOverlays(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.DrawInputZoneOverlays" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMobileZone_Button( class MobileInputZone* Zone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.DrawMobileZone_Button" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MobileInputZone** )params = Zone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMobileZone_Joystick( class MobileInputZone* Zone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.DrawMobileZone_Joystick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MobileInputZone** )params = Zone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMobileZone_Trackball( class MobileInputZone* Zone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.DrawMobileZone_Trackball" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MobileInputZone** )params = Zone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMobileTilt( class MobilePlayerInput* MobileInput )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.DrawMobileTilt" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MobilePlayerInput** )params = MobileInput;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawMobileZone_Slider( class MobileInputZone* Zone )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.DrawMobileZone_Slider" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MobileInputZone** )params = Zone;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshKismetLinks(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.RefreshKismetLinks" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddKismetRenderEvent( class SeqEvent_HudRender* NewEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.AddKismetRenderEvent" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqEvent_HudRender** )params = NewEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderKismetHud(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobileHUD.RenderKismetHud" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
