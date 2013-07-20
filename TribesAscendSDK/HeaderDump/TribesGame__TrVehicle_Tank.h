#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVehicle_Tank." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVehicle_Tank." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVehicle_Tank." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicle_Tank : public TrVehicle
	{
	public:
			ADD_VAR( ::FloatProperty, m_CameraShakeEffectiveRadius, 0xFFFFFFFF )
			ADD_OBJECT( CameraShake, m_FireCameraShake )
			ADD_VAR( ::ByteProperty, GunnerFiringMode, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, GunnerFlashCount, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, GunnerWeaponRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, GunnerFlashLocation, 0xFFFFFFFF )
			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_Tank.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleWeaponFireEffects( Vector HitLocation, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_Tank.VehicleWeaponFireEffects" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitLocation;
				*( int* )( params + 12 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessViewRotationBasedOnSeat( int SeatIndex, float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_Tank.ProcessViewRotationBasedOnSeat" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( int* )params = SeatIndex;
				*( float* )( params + 4 ) = DeltaTime;
				*( Rotator* )( params + 8 ) = out_ViewRotation;
				*( Rotator* )( params + 20 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 8 );
				out_DeltaRot = *( Rotator* )( params + 20 );
			}

			Rotator LimitViewRotation( Rotator LimitViewRotation, float LimitViewPitchMin, float LimitViewPitchMax )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle_Tank.LimitViewRotation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Rotator* )params = LimitViewRotation;
				*( float* )( params + 12 ) = LimitViewPitchMin;
				*( float* )( params + 16 ) = LimitViewPitchMax;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
