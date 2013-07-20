#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProj_Grenade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProj_Grenade." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProj_Grenade." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProj_Grenade : public TrProjectile
	{
	public:
			ADD_VAR( ::BoolProperty, m_bStuckOnPlayer, 0x1 )
			ADD_VAR( ::FloatProperty, m_fProxyDetonationHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fProxyDetonationRadius, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_CollisionProxyClass )
			ADD_OBJECT( TrCollisionProxy, m_CollisionProxy )
			ADD_VAR( ::FloatProperty, m_fStuckMomentumMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fStuckDamageMultiplier, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_OverloadHitNormal, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_StuckOnPawnLoopingSound )
			ADD_OBJECT( ParticleSystem, m_StuckOnTargetTemplate )
			ADD_VAR( ::FloatProperty, m_fExplosionTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bSpawnProxyOnInit, 0x80 )
			ADD_VAR( ::BoolProperty, m_bScanProxyOnInit, 0x40 )
			ADD_VAR( ::BoolProperty, m_bFullyInheritVelocity, 0x20 )
			ADD_VAR( ::BoolProperty, m_bDoRandSpin, 0x10 )
			ADD_VAR( ::BoolProperty, m_bBounceRequiredForExplode, 0x8 )
			ADD_VAR( ::BoolProperty, m_bExplodeOnTouchEvent, 0x4 )
			ADD_VAR( ::BoolProperty, m_bTimedExplosion, 0x2 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitProjectile( Vector Direction, ScriptClass* ClassToInherit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.InitProjectile" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = Direction;
				*( ScriptClass** )( params + 12 ) = ClassToInherit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnCollisionProxy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.SpawnCollisionProxy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyCollisionProxy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.DestroyCollisionProxy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyInheritance( Vector ProjectileDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.ApplyInheritance" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = ProjectileDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Timer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.Timer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.HitWall" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )params = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessTouch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.ProcessTouch" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )params = Other;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PhysicsVolumeChange( class PhysicsVolume* NewVolume )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.PhysicsVolumeChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PhysicsVolume** )params = NewVolume;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Explode( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.Explode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool StickToTarget( class Actor* Target, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.StickToTarget" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )params = Target;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayStuckOnEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.PlayStuckOnEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MyOnParticleSystemFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.MyOnParticleSystemFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnEnteredDetonationArea( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.PawnEnteredDetonationArea" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnLeftDetonationArea( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.PawnLeftDetonationArea" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NativeExplode( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProj_Grenade.NativeExplode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )params = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
