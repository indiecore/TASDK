#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " GameFramework.MobilePlayerInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty GameFramework.MobilePlayerInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty GameFramework.MobilePlayerInput." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class MobilePlayerInput : public PlayerInput
	{
	public:
			ADD_STRUCT( ::VectorProperty, DeviceAccelerometerRawData, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDeviceHasGyroscope, 0x10 )
			ADD_STRUCT( ::VectorProperty, DeviceGyroRawData, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DeviceMotionAttitude, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DeviceMotionRotationRate, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DeviceMotionGravity, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, DeviceMotionAcceleration, 0xFFFFFFFF )
			bool HasZones(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.HasZones" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void* GetCurrentZones(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.GetCurrentZones" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, MobileYaw, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileYawCenter, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileYawMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobilePitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobilePitchCenter, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobilePitchMultiplier, 0xFFFFFFFF )
			class MobileMenuScene* OpenMenuScene( ScriptClass* SceneClass, ScriptArray< wchar_t > Mode )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.OpenMenuScene" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )( params + 0 ) = SceneClass;
				*( ScriptArray< wchar_t >* )( params + 4 ) = Mode;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MobileMenuScene** )( params + function->return_val_offset() );
			}

			void OnInputTouch( int Handle, byte Type, void* TouchLocation, float DeviceTimestamp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.OnInputTouch" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( int* )( params + 0 ) = Handle;
				*( byte* )( params + 4 ) = Type;
				*( void** )( params + 8 ) = TouchLocation;
				*( float* )( params + 16 ) = DeviceTimestamp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool OnPreviewTouch( float X, float Y )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.OnPreviewTouch" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )( params + 0 ) = X;
				*( float* )( params + 4 ) = Y;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnTouchNotHandledInMenu(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.OnTouchNotHandledInMenu" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnMobileMotion( class PlayerInput* PlayerInput, Vector CurrentAttitude, Vector CurrentRotationRate, Vector CurrentGravity, Vector CurrentAcceleration )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.OnMobileMotion" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( class PlayerInput** )( params + 0 ) = PlayerInput;
				*( Vector* )( params + 4 ) = CurrentAttitude;
				*( Vector* )( params + 16 ) = CurrentRotationRate;
				*( Vector* )( params + 28 ) = CurrentGravity;
				*( Vector* )( params + 40 ) = CurrentAcceleration;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::FloatProperty, MobileInactiveTime, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, NativeDebugString, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoneTimeout, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileTapRepeatTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileMinHoldForTap, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileDoubleTapTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobileYawDeadzoneSize, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MobilePitchDeadzoneSize, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDeviceHasAccelerometer, 0x20 )
			ADD_VAR( ::BoolProperty, bFakeMobileTouches, 0x8 )
			ADD_VAR( ::BoolProperty, bDisableTouchInput, 0x4 )
			ADD_VAR( ::BoolProperty, bAllowTouchesInCinematic, 0x2 )
			ADD_VAR( ::BoolProperty, bSupportsAccelerometer, 0x1 )
			ADD_VAR( ::IntProperty, CurrentMobileGroup, 0xFFFFFFFF )
			ADD_OBJECT( MobileMenuObject, InteractiveObject )
			void NativeInitializeInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.NativeInitializeInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NativeInitializeInputZones(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.NativeInitializeInputZones" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendInputKey( ScriptName Key, byte Event, float AmountDepressed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.SendInputKey" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( ScriptName* )( params + 0 ) = Key;
				*( byte* )( params + 8 ) = Event;
				*( float* )( params + 12 ) = AmountDepressed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendInputAxis( ScriptName Key, float Delta, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.SendInputAxis" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptName* )( params + 0 ) = Key;
				*( float* )( params + 8 ) = Delta;
				*( float* )( params + 12 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.InitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientInitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.ClientInitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitTouchSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.InitTouchSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeInputZones(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.InitializeInputZones" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RefreshKismetLinks(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.RefreshKismetLinks" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddKismetEventHandler( class SeqEvent_MobileBase* NewHandler )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.AddKismetEventHandler" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqEvent_MobileBase** )( params + 0 ) = NewHandler;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddKismetRawInputEventHandler( class SeqEvent_MobileRawInput* NewHandler )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.AddKismetRawInputEventHandler" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class SeqEvent_MobileRawInput** )( params + 0 ) = NewHandler;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class MobileInputZone* FindZone( ScriptArray< wchar_t > ZoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.FindZone" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = ZoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MobileInputZone** )( params + function->return_val_offset() );
			}

			class MobileInputZone* FindorAddZone( ScriptArray< wchar_t > ZoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.FindorAddZone" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = ZoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class MobileInputZone** )( params + function->return_val_offset() );
			}

			void CloseMenuScene( class MobileMenuScene* SceneToClose )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.CloseMenuScene" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class MobileMenuScene** )( params + 0 ) = SceneToClose;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CloseAllMenus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.CloseAllMenus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderMenus( class Canvas* Canvas, float RenderDelta )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.RenderMenus" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( float* )( params + 4 ) = RenderDelta;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreClientTravel( ScriptArray< wchar_t > PendingURL, byte TravelType, bool bIsSeamlessTravel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function GameFramework.MobilePlayerInput.PreClientTravel" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = PendingURL;
				*( byte* )( params + 12 ) = TravelType;
				*( bool* )( params + 16 ) = bIsSeamlessTravel;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
