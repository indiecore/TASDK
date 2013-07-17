#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.PlayerInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.PlayerInput." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.PlayerInput." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class PlayerInput : public Input
	{
	public:
			ADD_VAR( ::FloatProperty, aTurn, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aLookUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aForward, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aStrafe, 0xFFFFFFFF )
			byte CheckForDoubleClickMove( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.CheckForDoubleClickMove" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, RawJoyUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RawJoyRight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aUp, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUsingGamepad, 0x1 )
			ADD_VAR( ::FloatProperty, AutoUnlockTurnTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MouseSamplingTotal, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MouseSamples, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SmoothedMouse, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZeroTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, FOVSetting, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bYAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bXAxis, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, bStrafe, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookUpScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookRightScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MoveStrafeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MoveForwardSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RawJoyLookUp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RawJoyLookRight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3Gyro, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3AccelZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3AccelY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aPS3AccelX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aLeftAnalogTrigger, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aRightAnalogTrigger, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aMouseY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aMouseX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aBaseZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aBaseY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aBaseX, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FlyingYawSensitivity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FlyingPitchSensitivity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MouseSensitivity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleClickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleClickTimer, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, LastAxisKeyName, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bLockTurnUntilRelease, 0x8000 )
			ADD_VAR( ::BoolProperty, bEnableFOVScaling, 0x4000 )
			ADD_VAR( ::BoolProperty, bUseToggleZoom, 0x2000 )
			ADD_VAR( ::BoolProperty, bEnableMouseSmoothing, 0x1000 )
			ADD_VAR( ::BoolProperty, bEdgeRight, 0x800 )
			ADD_VAR( ::BoolProperty, bEdgeLeft, 0x400 )
			ADD_VAR( ::BoolProperty, bEdgeBack, 0x200 )
			ADD_VAR( ::BoolProperty, bEdgeForward, 0x100 )
			ADD_VAR( ::BoolProperty, bWasRight, 0x80 )
			ADD_VAR( ::BoolProperty, bWasLeft, 0x40 )
			ADD_VAR( ::BoolProperty, bWasBack, 0x20 )
			ADD_VAR( ::BoolProperty, bWasForward, 0x10 )
			ADD_VAR( ::BoolProperty, bInvertAirVehicles, 0x8 )
			ADD_VAR( ::BoolProperty, bInvertTurn, 0x4 )
			ADD_VAR( ::BoolProperty, bInvertMouse, 0x2 )
			bool InvertMouse(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.InvertMouse" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool InvertTurn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.InvertTurn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetSensitivity( float F )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.SetSensitivity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = F;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawHUD( class HUD* H )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.DrawHUD" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class HUD** )( params + 0 ) = H;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreProcessInput( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.PreProcessInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostProcessInput( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.PostProcessInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustMouseSensitivity( float FOVScale )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.AdjustMouseSensitivity" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = FOVScale;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsMouseSmoothEnabled(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.IsMouseSmoothEnabled" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayerInput_( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.PlayerInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessInputMatching( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.ProcessInputMatching" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CatchDoubleClickInput(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.CatchDoubleClickInput" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Jump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.Jump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SmartJump(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.SmartJump" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearSmoothing(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.ClearSmoothing" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float SmoothMouse( float aMouse, float DeltaTime, byte &SampleCount, int Index )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.SmoothMouse" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( float* )( params + 0 ) = aMouse;
				*( float* )( params + 4 ) = DeltaTime;
				*( byte* )( params + 8 ) = SampleCount;
				*( int* )( params + 12 ) = Index;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SampleCount = *( byte* )( params + 8 );
				return *( float* )( params + function->return_val_offset() );
			}

			void InitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.InitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientInitInputSystem(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.ClientInitInputSystem" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreClientTravel( ScriptArray< wchar_t > PendingURL, byte TravelType, bool bIsSeamlessTravel )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.PlayerInput.PreClientTravel" );
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
