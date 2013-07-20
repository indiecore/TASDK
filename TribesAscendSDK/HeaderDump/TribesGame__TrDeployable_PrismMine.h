#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable_PrismMine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable_PrismMine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable_PrismMine." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_PrismMine : public TrDeployable
	{
	public:
			ADD_OBJECT( SoundCue, m_HitSound )
			ADD_OBJECT( SoundCue, m_DeactivateSound )
			ADD_OBJECT( SoundCue, m_ActivateSound )
			ADD_OBJECT( ParticleSystem, m_LaserTemplate )
			ADD_VAR( ::IntProperty, m_DamageAmount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fSleepTimeAfterHit, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_DamageType )
			ADD_VAR( ::NameProperty, m_nSocketTraceName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPrismRadius, 0xFFFFFFFF )
			void CreateTripActor( class TrDeployable_PrismMine* Right, Vector LeftLocation, Vector RightLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.CreateTripActor" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class TrDeployable_PrismMine** )params = Right;
				*( Vector* )( params + 4 ) = LeftLocation;
				*( Vector* )( params + 16 ) = RightLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyTripActor( class TrTripActor* DestroyTrip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.DestroyTripActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrTripActor** )params = DestroyTrip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddTripActor( class TrTripActor* NewTrip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.AddTripActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrTripActor** )params = NewTrip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveTripActor( class TrTripActor* RemoveTrip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.RemoveTripActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrTripActor** )params = RemoveTrip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TripActivated( class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.TripActivated" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = Other;
				*( Vector* )( params + 4 ) = ActivateLocation;
				*( class TrTripActor** )( params + 16 ) = TripActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class ParticleSystem* GetParticleSystemName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.GetParticleSystemName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ParticleSystem** )( params + function->return_val_offset() );
			}

			bool GetTripSocketPosition( bool bIsLeft, Vector &SocketPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.GetTripSocketPosition" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.OnTripAwake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTripSleep(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.OnTripSleep" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeployComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.DeployComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool NoConnectionExists( class TrDeployable_PrismMine* AdjacentMine )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.NoConnectionExists" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrDeployable_PrismMine** )params = AdjacentMine;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void OnPowerStatusChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_PrismMine.OnPowerStatusChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
