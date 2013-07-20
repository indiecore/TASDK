#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKPlayerController." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKPlayerController." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKPlayerController : public GamePlayerController
	{
	public:
			ADD_VAR( ::FloatProperty, PulseTimer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VehicleCheckRadiusScaling, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, ShakeRot, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ShakeOffset, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUsePhysicsRotation, 0x10 )
			ADD_VAR( ::BoolProperty, bPulseTeamColor, 0x8 )
			ADD_VAR( ::BoolProperty, bConsolePlayer, 0x4 )
			ADD_VAR( ::BoolProperty, bAcuteHearing, 0x2 )
			ADD_VAR( ::BoolProperty, bDedicatedServerSpectator, 0x1 )
			ADD_OBJECT( UDKEmitCameraEffect, CameraEffect )
			ADD_OBJECT( CameraAnimInst, CameraAnimPlayer )
			void SetGamma( float GammaValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.SetGamma" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = GammaValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetHardwarePhysicsEnabled( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.SetHardwarePhysicsEnabled" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsKeyboardAvailable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.IsKeyboardAvailable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsMouseAvailable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.IsMouseAvailable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RemoveCameraEffect( class UDKEmitCameraEffect* CamEmitter )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.RemoveCameraEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKEmitCameraEffect** )params = CamEmitter;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientSpawnCameraEffect( ScriptClass* CameraEffectClass )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.ClientSpawnCameraEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = CameraEffectClass;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearCameraEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.ClearCameraEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Pawn* GetTargetAdhesionFrictionTarget( float MaxDistance, Vector &CamLoc, Rotator &CamRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.GetTargetAdhesionFrictionTarget" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = MaxDistance;
				*( Vector* )( params + 4 ) = CamLoc;
				*( Rotator* )( params + 16 ) = CamRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CamLoc = *( Vector* )( params + 4 );
				CamRot = *( Rotator* )( params + 16 );
				return *( class Pawn** )( params + function->return_val_offset() );
			}

			bool IsControllerTiltActive(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.IsControllerTiltActive" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetControllerTiltDesiredIfAvailable( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.SetControllerTiltDesiredIfAvailable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetControllerTiltActive( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.SetControllerTiltActive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetOnlyUseControllerTiltInput( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.SetOnlyUseControllerTiltInput" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetUseTiltForwardAndBack( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKPlayerController.SetUseTiltForwardAndBack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
