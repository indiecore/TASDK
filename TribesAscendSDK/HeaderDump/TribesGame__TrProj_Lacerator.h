#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_Lacerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_Lacerator." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_Lacerator." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_Lacerator : public TrProjectile
	{
	public:
			ADD_OBJECT( CameraAnim, ShortRangeKillAnim )
			ADD_VAR( ::BoolProperty, bShrinking, 0x2 )
			ADD_VAR( ::BoolProperty, bCheckShortRangeKill, 0x1 )
			ADD_OBJECT( SoundCue, HitPawnSound )
			ADD_OBJECT( ParticleSystem, RockSmokeTemplate )
			ADD_OBJECT( ParticleSystem, BounceTemplate )
			ADD_VAR( ::FloatProperty, ShrinkTimer, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageAttenuation, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, Bounces, 0xFFFFFFFF )
			void InitProjectile( Vector Direction, ScriptClass* ClassToInherit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.InitProjectile" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = Direction;
				*( ScriptClass** )( params + 12 ) = ClassToInherit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnFlightEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.SpawnFlightEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InternalSpawnFlightEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.InternalSpawnFlightEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetDamage( class Actor* Other, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.GetDamage" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float GetMomentumTransfer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.GetMomentumTransfer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void ProcessTouch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.ProcessTouch" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Landed( Vector HitNormal, class Actor* FloorActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.Landed" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = FloorActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SpawnImpactEffect( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.SpawnImpactEffect" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void HitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.HitWall" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartToShrink(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.StartToShrink" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MyOnParticleSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Lacerator.MyOnParticleSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
