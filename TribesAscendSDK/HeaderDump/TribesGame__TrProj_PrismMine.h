#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_PrismMine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_PrismMine." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_PrismMine." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_PrismMine : public TrProj_Mine
	{
	public:
			ADD_STRUCT( ::VectorProperty, r_vRightHit, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, r_vLeftHit, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, m_nSocketTraceName, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, m_LaserTemplate )
			ADD_VAR( ::FloatProperty, m_fTripDistance, 0xFFFFFFFF )
			ADD_OBJECT( TrTripActor, m_TripActor )
			void PawnEnteredDetonationArea( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.PawnEnteredDetonationArea" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitProjectile( Vector Direction, ScriptClass* ClassToInherit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.InitProjectile" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = Direction;
				*( ScriptClass** )( params + 12 ) = ClassToInherit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ArmedTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.ArmedTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateTripActor(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.CreateTripActor" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TripActivated( class Pawn* Other, Vector ActivateLocation, class TrTripActor* TripActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.TripActivated" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = Other;
				*( Vector* )( params + 4 ) = ActivateLocation;
				*( class TrTripActor** )( params + 16 ) = TripActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class ParticleSystem* GetParticleSystemName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.GetParticleSystemName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class ParticleSystem** )( params + function->return_val_offset() );
			}

			bool GetTripSocketPosition( bool bIsLeft, Vector &SocketPosition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.GetTripSocketPosition" );
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
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.OnTripAwake" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnTripSleep(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.OnTripSleep" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddTripActor( class TrTripActor* NewTrip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.AddTripActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrTripActor** )params = NewTrip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveTripActor( class TrTripActor* RemoveTrip )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_PrismMine.RemoveTripActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrTripActor** )params = RemoveTrip;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
