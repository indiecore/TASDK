#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTDamageType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTDamageType." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTDamageType." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTDamageType : public DamageType
	{
	public:
			ADD_OBJECT( CameraAnim, DamageCameraAnim )
			ADD_VAR( ::BoolProperty, bLocationalHit, 0x2 )
			ADD_OBJECT( ScriptClass, DamageWeaponClass )
			ScriptClass* GetDeathCameraEffectInstigator( class UTPawn* UTP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.GetDeathCameraEffectInstigator" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = UTP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bDirectDamage, 0x10 )
			float GetHitEffectDuration( class Pawn* P, float Damage )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.GetHitEffectDuration" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( float* )( params + 4 ) = Damage;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool ShouldGib( class UTPawn* DeadPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.ShouldGib" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = DeadPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bHeadGibCamera, 0x40000 )
			ScriptClass* GetDeathCameraEffectVictim( class UTPawn* UTP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.GetDeathCameraEffectVictim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = UTP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, GibPerterbation, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bUseDamageBasedDeathEffects, 0x2000 )
			ADD_VAR( ::NameProperty, DeathAnim, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bAnimateHipsForDeathAnim, 0x8000 )
			ADD_VAR( ::FloatProperty, DeathAnimRate, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSeversHead, 0x20 )
			ADD_VAR( ::FloatProperty, MotorDecayTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StopAnimAfterDamageInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DamageOverlayTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, XRayEffectTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bCausesBloodSplatterDecals, 0x80000 )
			ADD_VAR( ::BoolProperty, bCausesBlood, 0x1 )
			ADD_VAR( ::FloatProperty, PhysicsTakeHitMomentumThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSpecialDeathCamera, 0x4000 )
			ADD_VAR( ::BoolProperty, bThrowRagdoll, 0x100 )
			ADD_VAR( ::BoolProperty, bOverrideHitEffectColor, 0x20000 )
			ADD_VAR( ::StrProperty, MaleSuicide, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, FemaleSuicide, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, DeathString, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, CustomTauntIndex, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, RewardEvent, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, RewardAnnouncementSwitch, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, RewardAnnouncementClass )
			ADD_VAR( ::IntProperty, RewardCount, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SuicideStatsName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DeathStatsName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, KillStatsName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, NodeDamageScaling, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, DeathCameraEffectInstigator )
			ADD_OBJECT( ScriptClass, DeathCameraEffectVictim )
			ADD_OBJECT( ParticleSystem, GibTrail )
			ADD_VAR( ::IntProperty, DamageWeaponFireMode, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, AlwaysGibDamageThreshold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MinAccumulateDamageThreshold, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, GibThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDontHurtInstigator, 0x100000 )
			ADD_VAR( ::BoolProperty, bComplainFriendlyFire, 0x10000 )
			ADD_VAR( ::BoolProperty, bSelfDestructDamage, 0x1000 )
			ADD_VAR( ::BoolProperty, bVehicleHit, 0x800 )
			ADD_VAR( ::BoolProperty, bBulletHit, 0x400 )
			ADD_VAR( ::BoolProperty, bLeaveBodyEffect, 0x200 )
			ADD_VAR( ::BoolProperty, bUseTearOffMomentum, 0x80 )
			ADD_VAR( ::BoolProperty, bCauseConvulsions, 0x40 )
			ADD_VAR( ::BoolProperty, bNeverGibs, 0x8 )
			ADD_VAR( ::BoolProperty, bAlwaysGibs, 0x4 )
			ADD_VAR( ::FloatProperty, DeathOverlayTime, 0xFFFFFFFF )
			ScriptArray< wchar_t > DeathMessage( class PlayerReplicationInfo* Killer, class PlayerReplicationInfo* Victim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.DeathMessage" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Killer;
				*( class PlayerReplicationInfo** )( params + 4 ) = Victim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > SuicideMessage( class PlayerReplicationInfo* Victim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.SuicideMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerReplicationInfo** )( params + 0 ) = Victim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void SpawnHitEffect( class Pawn* P, float Damage, Vector Momentum, ScriptName BoneName, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.SpawnHitEffect" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( float* )( params + 4 ) = Damage;
				*( Vector* )( params + 8 ) = Momentum;
				*( ScriptName* )( params + 20 ) = BoneName;
				*( Vector* )( params + 28 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int IncrementKills( class UTPlayerReplicationInfo* KillerPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.IncrementKills" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = KillerPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void IncrementDeaths( class UTPlayerReplicationInfo* KilledPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.IncrementDeaths" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = KilledPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementSuicides( class UTPlayerReplicationInfo* KilledPRI )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.IncrementSuicides" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = KilledPRI;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetStatsName( ScriptName StatType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.GetStatsName" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = StatType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void ScoreKill( class UTPlayerReplicationInfo* KillerPRI, class UTPlayerReplicationInfo* KilledPRI, class Pawn* KilledPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.ScoreKill" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = KillerPRI;
				*( class UTPlayerReplicationInfo** )( params + 4 ) = KilledPRI;
				*( class Pawn** )( params + 8 ) = KilledPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnTornOff( class UTPawn* DeadPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.PawnTornOff" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = DeadPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnGibEffects( class UTGib* Gib )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.SpawnGibEffects" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTGib** )( params + 0 ) = Gib;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DoCustomDamageEffects( class UTPawn* ThePawn, ScriptClass* TheDamageType, void* &HitInfo, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.DoCustomDamageEffects" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class UTPawn** )( params + 0 ) = ThePawn;
				*( ScriptClass** )( params + 4 ) = TheDamageType;
				*( void** )( params + 8 ) = HitInfo;
				*( Vector* )( params + 36 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HitInfo = *( void** )( params + 8 );
			}

			void CreateDeathSkeleton( class UTPawn* ThePawn, ScriptClass* TheDamageType, void* &HitInfo, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.CreateDeathSkeleton" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class UTPawn** )( params + 0 ) = ThePawn;
				*( ScriptClass** )( params + 4 ) = TheDamageType;
				*( void** )( params + 8 ) = HitInfo;
				*( Vector* )( params + 36 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HitInfo = *( void** )( params + 8 );
			}

			void BoneBreaker( class UTPawn* ThePawn, Vector Impulse, Vector HitLocation, ScriptName BoneName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.BoneBreaker" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class UTPawn** )( params + 0 ) = ThePawn;
				*( Vector* )( params + 8 ) = Impulse;
				*( Vector* )( params + 20 ) = HitLocation;
				*( ScriptName* )( params + 32 ) = BoneName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateDeathGoreChunks( class UTPawn* ThePawn, ScriptClass* TheDamageType, void* &HitInfo, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.CreateDeathGoreChunks" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class UTPawn** )( params + 0 ) = ThePawn;
				*( ScriptClass** )( params + 4 ) = TheDamageType;
				*( void** )( params + 8 ) = HitInfo;
				*( Vector* )( params + 36 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HitInfo = *( void** )( params + 8 );
			}

			void SpawnExtraGibEffects( class UTGib* TheGib )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.SpawnExtraGibEffects" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTGib** )( params + 0 ) = TheGib;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawKillIcon( class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.DrawKillIcon" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( float* )( params + 4 ) = ScreenX;
				*( float* )( params + 8 ) = ScreenY;
				*( float* )( params + 12 ) = HUDScaleX;
				*( float* )( params + 16 ) = HUDScaleY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CalcDeathCamera( class UTPawn* P, float DeltaTime, Vector &CameraLocation, Rotator &CameraRotation, float &CameraFOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTDamageType.CalcDeathCamera" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class UTPawn** )( params + 0 ) = P;
				*( float* )( params + 4 ) = DeltaTime;
				*( Vector* )( params + 8 ) = CameraLocation;
				*( Rotator* )( params + 20 ) = CameraRotation;
				*( float* )( params + 32 ) = CameraFOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				CameraLocation = *( Vector* )( params + 8 );
				CameraRotation = *( Rotator* )( params + 20 );
				CameraFOV = *( float* )( params + 32 );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
