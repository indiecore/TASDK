#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrProjectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrProjectile." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrProjectile." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrProjectile : public UTProjectile
	{
	public:
			ADD_VAR( ::BoolProperty, m_bTether, 0x40 )
			ADD_VAR( ::BoolProperty, m_bSimulateAutonomousProjectiles, 0x80 )
			ADD_VAR( ::ByteProperty, m_SpawnedEquipPoint, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nTetherId, 0xFFFFFFFF )
			bool IsBlockedByBlocker( class Actor* DamageInstigator, class Actor* Target, class Actor* OriginActor, bool CheckWorldGeometry, Vector AltOriginLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.IsBlockedByBlocker" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )( params + 0 ) = DamageInstigator;
				*( class Actor** )( params + 4 ) = Target;
				*( class Actor** )( params + 8 ) = OriginActor;
				*( bool* )( params + 12 ) = CheckWorldGeometry;
				*( Vector* )( params + 16 ) = AltOriginLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bIsBullet, 0x100 )
			ADD_STRUCT( ::VectorProperty, r_vSpawnLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fInstigatorExtraZMomentum, 0xFFFFFFFF )
			ADD_OBJECT( TrDevice, SpawnedFromDevice )
			ADD_VAR( ::FloatProperty, m_fAlwaysRelevantDistanceSquared, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinLifespan, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxLifespan, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, m_vAccelDirection, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClientSimulatedSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTweenSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCurrentTetherTweenAmount, 0xFFFFFFFF )
			ADD_OBJECT( TrProjectile, c_ChildTetheredProjectile )
			ADD_OBJECT( TrProjectile, c_ParentTetheredProjectile )
			ADD_VAR( ::FloatProperty, m_fInstigatorMomentumTransferMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAmbientSoundFadeOut, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAmbientSoundFadeIn, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDirectHitMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBounceDampingPercent, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nPerPlayerMaxDeployed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxProjInheritPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fProjInheritVelocityPctZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fProjInheritVelocityPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fXYDamageRadius, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bAuthoritativeExploding, 0x20 )
			ADD_VAR( ::BoolProperty, m_bOrientToWall, 0x10 )
			ADD_VAR( ::BoolProperty, m_bHasBounced, 0x8 )
			ADD_VAR( ::BoolProperty, m_bFastProjectile, 0x4 )
			ADD_VAR( ::BoolProperty, m_bDebugProjectileRadius, 0x2 )
			ADD_VAR( ::BoolProperty, m_bLimitXYDamageCheck, 0x1 )
			ADD_OBJECT( ScriptClass, m_SpawnedDeployableClass )
			void OrientToSlope( Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.OrientToSlope" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector CalculateHitLocation( class Actor* shooter, Vector ShotDirection, Vector ShotLocation, float ClampedMaxSpeed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.CalculateHitLocation" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = shooter;
				*( Vector* )( params + 4 ) = ShotDirection;
				*( Vector* )( params + 16 ) = ShotLocation;
				*( float* )( params + 28 ) = ClampedMaxSpeed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.PreBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ExplodeFromTimeLimit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ExplodeFromTimeLimit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientReceivedProjectileToTether(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ClientReceivedProjectileToTether" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateProjectileLight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.CreateProjectileLight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetonateObsolete( bool bDetonateFromAOE )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.DetonateObsolete" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bDetonateFromAOE;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DestroyOldestOverLimit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.DestroyOldestOverLimit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetMaxDeployedLimit(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.GetMaxDeployedLimit" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void Init( Vector Direction )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.Init" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = Direction;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitProjectile( Vector Direction, ScriptClass* ClassToInherit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.InitProjectile" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = Direction;
				*( ScriptClass** )( params + 12 ) = ClassToInherit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyInheritance( Vector ProjectileDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ApplyInheritance" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = ProjectileDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientCheckFastSpawnExplode(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ClientCheckFastSpawnExplode" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnExplosionEffects( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.SpawnExplosionEffects" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class SoundCue* GetExplosionSound( class PhysicalMaterial* HitMaterial, class Actor* HitActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.GetExplosionSound" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PhysicalMaterial** )( params + 0 ) = HitMaterial;
				*( class Actor** )( params + 4 ) = HitActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class SoundCue** )( params + function->return_val_offset() );
			}

			void Explode( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.Explode" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShutDown(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ShutDown" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Bounce( class Actor* Other, Vector WallNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.Bounce" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 4 ) = WallNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ProjectileHurtRadius( Vector HurtOrigin, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ProjectileHurtRadius" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = HurtOrigin;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HurtRadius_Internal( float DamageAmount, float InDamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, Vector AltHurtOrigin, class Actor* IgnoredActor, class Controller* InstigatedByController, bool bDoFullDamage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.HurtRadius_Internal" );
				byte *params = ( byte* )( malloc( 52 ) );
				*( float* )( params + 0 ) = DamageAmount;
				*( float* )( params + 4 ) = InDamageRadius;
				*( ScriptClass** )( params + 8 ) = DamageType;
				*( float* )( params + 12 ) = Momentum;
				*( Vector* )( params + 16 ) = HurtOrigin;
				*( Vector* )( params + 28 ) = AltHurtOrigin;
				*( class Actor** )( params + 40 ) = IgnoredActor;
				*( class Controller** )( params + 44 ) = InstigatedByController;
				*( bool* )( params + 48 ) = bDoFullDamage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void HitWall( Vector HitNormal, class Actor* Wall )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.HitWall" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( Vector* )( params + 0 ) = HitNormal;
				*( class Actor** )( params + 12 ) = Wall;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Touch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.Touch" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessTouch( class Actor* Other, Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrProjectile.ProcessTouch" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class Actor** )( params + 0 ) = Other;
				*( Vector* )( params + 4 ) = HitLocation;
				*( Vector* )( params + 16 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
