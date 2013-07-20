#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable_TripSensor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable_TripSensor." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable_TripSensor." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_TripSensor : public TrDeployable_Sensor
	{
	public:
			void AddTripActor( class TrTripActor* NewTrip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_TripSensor.AddTripActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrTripActor** )params = NewTrip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveTripActor( class TrTripActor* RemoveTrip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_TripSensor.RemoveTripActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrTripActor** )params = RemoveTrip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TripActivated( class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_TripSensor.TripActivated" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = Other;
				*( Vector* )( params + 4 ) = ActivateLocation;
				*( class TrTripActor** )( params + 16 ) = TripActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class ParticleSystem* GetParticleSystemName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_TripSensor.GetParticleSystemName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ParticleSystem** )( params + function->return_val_offset() );
			}

			bool GetTripSocketPosition( bool bIsLeft, Vector &SocketPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_TripSensor.GetTripSocketPosition" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( bool* )params = bIsLeft;
				*( Vector* )( params + 4 ) = SocketPosition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SocketPosition = *( Vector* )( params + 4 );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnTripAwake(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_TripSensor.OnTripAwake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTripSleep(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_TripSensor.OnTripSleep" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
