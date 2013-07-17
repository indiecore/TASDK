#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTVehicle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTVehicle : public UDKVehicle
	{
	public:
			ADD_VAR( ::BoolProperty, bCanCarryFlag, 0x2 )
			ADD_VAR( ::BoolProperty, bRequestedEntryWithFlag, 0x200000 )
			bool TryToDrive( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TryToDrive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bHasCustomEntryRadius, 0x10 )
			bool InCustomEntryRadius( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.InCustomEntryRadius" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( UTVehicle, NextVehicle )
			ADD_VAR( ::FloatProperty, DefaultFOV, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDropDetailWhenDriving, 0x10000 )
			ADD_VAR( ::BoolProperty, bSpectatedView, 0x200 )
			ADD_VAR( ::FloatProperty, LastEnemyWarningTime, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, ReferenceMovementMesh )
			ADD_OBJECT( ParticleSystem, DisabledTemplate )
			ADD_VAR( ::FloatProperty, TimeLastDisabled, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DisabledTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, OldCameraPosition, 0xFFFFFFFF )
			ADD_OBJECT( UTGib, DeathCameraGib )
			ADD_VAR( ::FloatProperty, MinCameraDistSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookForwardDist, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CameraOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraLag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraSmoothingFactor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldCamPosZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, SeatCameraScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastCollisionDamageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CollisionDamageMult, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, BurnOutMaterial )
			ADD_VAR( ::FloatProperty, SpawnInTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, SpawnMaterialParameterName, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, HudIcons )
			ADD_STRUCT( ::VectorProperty, PassengerTeamBeaconOffset, 0xFFFFFFFF )
			ADD_OBJECT( PlayerReplicationInfo, PassengerPRI )
			ADD_STRUCT( ::VectorProperty, TeamBeaconOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HealthPulseTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, LastHealth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapSize, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, FlagBone, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, FlagRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, FlagOffset, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, BoostPadSound )
			ADD_OBJECT( SoundCue, SpawnOutSound )
			ADD_OBJECT( SoundCue, SpawnInSound )
			ADD_VAR( ::FloatProperty, SpawnRadius, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BurnTimeParameterName, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, ExplosionSound )
			ADD_VAR( ::FloatProperty, TurretExplosiveForce, 0xFFFFFFFF )
			ADD_OBJECT( StaticMesh, DestroyedTurretTemplate )
			ADD_OBJECT( UTVehicleDeathPiece, DestroyedTurret )
			ADD_STRUCT( ::VectorProperty, TurretOffset, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TurretSocketName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TurretScaleControlName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OuterExplosionShakeRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InnerExplosionShakeRadius, 0xFFFFFFFF )
			ADD_OBJECT( CameraAnim, DeathExplosionShake )
			ADD_VAR( ::FloatProperty, ExplosionInAirAngVel, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExplosionMomentum, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExplosionRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExplosionDamage, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DelayedBurnoutCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeadVehicleLifeSpan, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BurnOutTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BigExplosionSocket, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, SecondaryExplosion )
			ADD_OBJECT( ParticleSystem, ExplosionTemplate )
			ADD_VAR( ::FloatProperty, MaxFireEffectDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxImpactEffectDistance, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, ExplosionDamageType )
			ADD_VAR( ::FloatProperty, DamageSmokeThreshold, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, VehiclePieceClass )
			ADD_VAR( ::IntProperty, ClientHealth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeTilSecondaryVehicleExplosion, 0xFFFFFFFF )
			ADD_OBJECT( Emitter, DeathExplosion )
			ADD_VAR( ::FloatProperty, MaxExplosionLightDistance, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, ExplosionLightClass )
			ADD_OBJECT( ScriptClass, VehicleDrowningDamType )
			ADD_VAR( ::FloatProperty, HUDExtent, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, VehicleNameString, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, VehiclePositionString, 0xFFFFFFFF )
			ADD_OBJECT( UTBot, Reservation )
			ADD_OBJECT( UTVehicleFactory, ParentFactory )
			ADD_OBJECT( SoundCue, StolenSound )
			ADD_VAR( ::IntProperty, StolenAnnouncementIndex, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, RanOverSound )
			ADD_OBJECT( ScriptClass, RanOverDamageType )
			ADD_OBJECT( SoundCue, LockedOnSound )
			ADD_VAR( ::FloatProperty, ConsoleSteerScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookSteerDeadZone, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookSteerDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LookSteerSensitivity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LeftStickDirDeadZone, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, HornIndex, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastHornTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HornAIRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxDesireability, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, LinkedEndSound )
			ADD_OBJECT( SoundCue, LinkedToCue )
			ADD_VAR( ::FloatProperty, LinkHealMult, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InitialSpawnDelay, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RespawnTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, PlayerStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VehicleLostTime, 0xFFFFFFFF )
			ADD_OBJECT( PhysicalMaterial, DefaultPhysicalMaterial )
			ADD_OBJECT( PhysicalMaterial, DrivingPhysicalMaterial )
			ADD_VAR( ::FloatProperty, DeflectionReverseThresh, 0xFFFFFFFF )
			ADD_OBJECT( Actor, NoPassengerObjective )
			ADD_VAR( ::ByteProperty, LinkedToCount, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, AIPurpose, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDriverHoldsFlag, 0x1 )
			ADD_OBJECT( SoundCue, VehicleLockedSound )
			ADD_VAR( ::BoolProperty, bIsNecrisVehicle, 0x100 )
			ADD_VAR( ::BoolProperty, bHasEnemyVehicleSound, 0x80 )
			ADD_VAR( ::BoolProperty, bStealthVehicle, 0x40 )
			ADD_VAR( ::BoolProperty, bShowDamageDebug, 0x20 )
			ADD_VAR( ::BoolProperty, bAcceptTurretJump, 0x10 )
			ADD_VAR( ::BoolProperty, bIsConsoleTurning, 0x8 )
			ADD_VAR( ::BoolProperty, bStopDeathCamera, 0x4 )
			ADD_VAR( ::BoolProperty, bCameraNeverHidesVehicle, 0x2 )
			ADD_VAR( ::BoolProperty, bFixedCamZ, 0x1 )
			ADD_VAR( ::BoolProperty, bNoFollowJumpZ, 0x80000000 )
			ADD_VAR( ::BoolProperty, bLimitCameraZLookingUp, 0x40000000 )
			ADD_VAR( ::BoolProperty, bNoZSmoothing, 0x20000000 )
			ADD_VAR( ::BoolProperty, bRotateCameraUnderVehicle, 0x10000000 )
			ADD_VAR( ::BoolProperty, bReducedFallingCollisionDamage, 0x8000000 )
			ADD_VAR( ::BoolProperty, bPlayingSpawnEffect, 0x4000000 )
			ADD_VAR( ::BoolProperty, bPostRenderTraceSucceeded, 0x2000000 )
			ADD_VAR( ::BoolProperty, bHasTurretExplosion, 0x1000000 )
			ADD_VAR( ::BoolProperty, bRagdollDriverOnDarkwalkerHorn, 0x800000 )
			ADD_VAR( ::BoolProperty, bInitializedVehicleEffects, 0x400000 )
			ADD_VAR( ::BoolProperty, bFindGroundExit, 0x100000 )
			ADD_VAR( ::BoolProperty, bUsingLookSteer, 0x80000 )
			ADD_VAR( ::BoolProperty, bLookSteerOnSimpleControls, 0x40000 )
			ADD_VAR( ::BoolProperty, bLookSteerOnNormalControls, 0x20000 )
			ADD_VAR( ::BoolProperty, bHasBeenDriven, 0x8000 )
			ADD_VAR( ::BoolProperty, bDriverCastsShadow, 0x4000 )
			ADD_VAR( ::BoolProperty, bDrawHealthOnHUD, 0x2000 )
			ADD_VAR( ::BoolProperty, bShouldLeaveForCombat, 0x1000 )
			ADD_VAR( ::BoolProperty, bNeverReset, 0x800 )
			ADD_VAR( ::BoolProperty, bHasWeaponBar, 0x400 )
			ADD_VAR( ::BoolProperty, bShouldAutoCenterViewPitch, 0x200 )
			ADD_VAR( ::BoolProperty, bStickDeflectionThrottle, 0x100 )
			ADD_VAR( ::BoolProperty, bOverrideAVRiLLocks, 0x80 )
			ADD_VAR( ::BoolProperty, bMustBeUpright, 0x40 )
			ADD_VAR( ::BoolProperty, bKeyVehicle, 0x20 )
			ADD_VAR( ::BoolProperty, bEnteringUnlocks, 0x8 )
			ADD_VAR( ::BoolProperty, bValidLinkTarget, 0x4 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateShadowSettings( bool bWantShadow )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.UpdateShadowSettings" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bWantShadow;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReattachMesh(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ReattachMesh" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateDamageMaterialInstance(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CreateDamageMaterialInstance" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateLookSteerStatus(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.UpdateLookSteerStatus" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetInputs( float InForward, float InStrafe, float InUp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetInputs" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = InForward;
				*( float* )( params + 4 ) = InStrafe;
				*( float* )( params + 8 ) = InUp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FellOutOfWorld( ScriptClass* dmgType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.FellOutOfWorld" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )( params + 0 ) = dmgType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetChargePower(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetChargePower" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PlaySpawnEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PlaySpawnEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopSpawnEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.StopSpawnEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EjectSeat( int SeatIdx )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.EjectSeat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIdx;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptClass* GetRanOverDamageType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetRanOverDamageType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void DisplayWeaponBar( class Canvas* Canvas, class UTHUD* HUD )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DisplayWeaponBar" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( class UTHUD** )( params + 4 ) = HUD;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawKillIcon( class Canvas* Canvas, float ScreenX, float ScreenY, float HUDScaleX, float HUDScaleY )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DrawKillIcon" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Canvas** )( params + 0 ) = Canvas;
				*( float* )( params + 4 ) = ScreenX;
				*( float* )( params + 8 ) = ScreenY;
				*( float* )( params + 12 ) = HUDScaleX;
				*( float* )( params + 16 ) = HUDScaleY;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RenderMapIcon( class UTMapInfo* MP, class Canvas* Canvas, class UTPlayerController* PlayerOwner, void* FinalColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.RenderMapIcon" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class UTMapInfo** )( params + 0 ) = MP;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( class UTPlayerController** )( params + 8 ) = PlayerOwner;
				*( void** )( params + 12 ) = FinalColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float AdjustedStrength(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.AdjustedStrength" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool ContinueOnFoot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ContinueOnFoot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsDriverSeat( class Vehicle* TestSeatPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.IsDriverSeat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Vehicle** )( params + 0 ) = TestSeatPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RecommendCharge( class UTBot* B, class Pawn* Enemy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.RecommendCharge" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTBot** )( params + 0 ) = B;
				*( class Pawn** )( params + 4 ) = Enemy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CriticalChargeAttack( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CriticalChargeAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void CreateVehicleEffect( int EffectIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CreateVehicleEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = EffectIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.InitializeEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetVehicleEffectParms( ScriptName TriggerName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetVehicleEffectParms" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptName* )( params + 0 ) = TriggerName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TriggerVehicleEffect( ScriptName EventTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TriggerVehicleEffect" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = EventTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayVehicleSound( ScriptName SoundTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PlayVehicleSound" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = SoundTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayVehicleAnimation( ScriptName EventTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PlayVehicleAnimation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = EventTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleEvent( ScriptName EventTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = EventTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EntryAnnouncement( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.EntryAnnouncement" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Rotator ExitRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ExitRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool FindAutoExit( class Pawn* ExitingDriver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.FindAutoExit" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = ExitingDriver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RanInto( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.RanInto" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PancakeOther( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PancakeOther" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeWaterDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TakeWaterDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverRadiusDamage( float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DriverRadiusDamage" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( float* )( params + 0 ) = DamageAmount;
				*( float* )( params + 4 ) = DamageRadius;
				*( class Controller** )( params + 8 ) = EventInstigator;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( float* )( params + 16 ) = Momentum;
				*( Vector* )( params + 20 ) = HitLocation;
				*( class Actor** )( params + 32 ) = DamageCauser;
				*( float* )( params + 36 ) = DamageFalloffExponent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTexturesToBeResident( bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetTexturesToBeResident" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DisableVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DisableVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void EnableVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.EnableVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeFireDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TakeFireDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetSeatIndexFromPrefix( ScriptArray< wchar_t > Prefix )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetSeatIndexFromPrefix" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( ScriptArray< wchar_t >* )( params + 0 ) = Prefix;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void ServerSetConsoleTurning( bool bNewConsoleTurning )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ServerSetConsoleTurning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bNewConsoleTurning;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ProcessViewRotation( float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( Rotator* )( params + 4 ) = out_ViewRotation;
				*( Rotator* )( params + 16 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 4 );
				out_DeltaRot = *( Rotator* )( params + 16 );
			}

			Rotator GetClampedViewRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetClampedViewRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool ShouldClamp(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ShouldClamp" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Rotator GetViewRotation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetViewRotation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void WeaponRotationChanged( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.WeaponRotationChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetKeyVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetKeyVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrivingStatusChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DrivingStatusChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnAnimEnd( class AnimNodeSequence* SeqNode, float PlayedTime, float ExcessTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.OnAnimEnd" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class AnimNodeSequence** )( params + 0 ) = SeqNode;
				*( float* )( params + 4 ) = PlayedTime;
				*( float* )( params + 8 ) = ExcessTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool SeatAvailable( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SeatAvailable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AnySeatAvailable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.AnySeatAvailable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetSeatIndexForController( class Controller* ControllerToMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetSeatIndexForController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = ControllerToMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class Controller* GetControllerForSeatIndex( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetControllerForSeatIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			void ServerAdjacentSeat( int Direction, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ServerAdjacentSeat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = Direction;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerChangeSeat( int RequestedSeat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ServerChangeSeat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = RequestedSeat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HasPriority( class Controller* first, class Controller* Second )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.HasPriority" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = first;
				*( class Controller** )( params + 4 ) = Second;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ChangeSeat( class Controller* ControllerToMove, int RequestedSeat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ChangeSeat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = ControllerToMove;
				*( int* )( params + 4 ) = RequestedSeat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void TornOff(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TornOff" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Controller* GetCollisionDamageInstigator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetCollisionDamageInstigator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			bool Died( class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )( params + 0 ) = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void BlowupVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.BlowupVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class PlayerReplicationInfo* GetSeatPRI( int SeatNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetSeatPRI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerReplicationInfo** )( params + function->return_val_offset() );
			}

			bool CanEnterVehicle( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CanEnterVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool KickOutBot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.KickOutBot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void VehicleLocked( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleLocked" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldShowUseable( class PlayerController* PC, float Dist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ShouldShowUseable" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( float* )( params + 4 ) = Dist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetDisplayedHealth(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetDisplayedHealth" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void RenderPassengerBeacons( class PlayerController* PC, class Canvas* Canvas, void* TeamColor, void* TextColor, class UTWeapon* Weap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.RenderPassengerBeacons" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( void** )( params + 8 ) = TeamColor;
				*( void** )( params + 24 ) = TextColor;
				*( class UTWeapon** )( params + 28 ) = Weap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostRenderPassengerBeacon( class PlayerController* PC, class Canvas* Canvas, void* TeamColor, void* TextColor, class UTWeapon* Weap, class PlayerReplicationInfo* InPassengerPRI, Vector InPassengerTeamBeaconOffset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PostRenderPassengerBeacon" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( void** )( params + 8 ) = TeamColor;
				*( void** )( params + 24 ) = TextColor;
				*( class UTWeapon** )( params + 28 ) = Weap;
				*( class PlayerReplicationInfo** )( params + 32 ) = InPassengerPRI;
				*( Vector* )( params + 36 ) = InPassengerTeamBeaconOffset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetTeamNum( byte T )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetTeamNum" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = T;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TeamChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeamChanged_VehicleEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TeamChanged_VehicleEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Dodge( byte DoubleClickMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.Dodge" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = DoubleClickMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void IncomingMissile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.IncomingMissile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShootMissile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ShootMissile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendLockOnMessage( int Switch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SendLockOnMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Switch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void LockOnWarning( class UDKProjectile* IncomingMissile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.LockOnWarning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKProjectile** )( params + 0 ) = IncomingMissile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TooCloseToAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TooCloseToAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheckTurretPitchLimit( int NeededPitch, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CheckTurretPitchLimit" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = NeededPitch;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PlayHorn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PlayHorn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DriverLeave( bool bForceLeave )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DriverLeave" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bForceLeave;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UpdateControllerOnPossess( bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.UpdateControllerOnPossess" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int NumPassengers(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.NumPassengers" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			class UTVehicle* GetMoveTargetFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetMoveTargetFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTVehicle** )( params + function->return_val_offset() );
			}

			void HandleEnteringFlag( class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.HandleEnteringFlag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )( params + 0 ) = EnteringPRI;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DriverEnter( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DriverEnter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void HoldGameObject( class UDKCarriedObject* GameObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.HoldGameObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKCarriedObject** )( params + 0 ) = GameObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachFlag( class UTCarriedObject* FlagActor, class Pawn* NewDriver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.AttachFlag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTCarriedObject** )( params + 0 ) = FlagActor;
				*( class Pawn** )( params + 4 ) = NewDriver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverLeft(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DriverLeft" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetFirstAvailableSeat( bool bSeatMustAllowFlag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetFirstAvailableSeat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bSeatMustAllowFlag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool PassengerEnter( class Pawn* P, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PassengerEnter" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )( params + 0 ) = P;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PassengerLeave( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PassengerLeave" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CheckReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Occupied(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.Occupied" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool OpenPositionFor( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.OpenPositionFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float BotDesireability( class UTSquadAI* S, int TeamIndex, class Actor* Objective )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.BotDesireability" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class UTSquadAI** )( params + 0 ) = S;
				*( int* )( params + 4 ) = TeamIndex;
				*( class Actor** )( params + 8 ) = Objective;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			float ReservationCostMultiplier( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ReservationCostMultiplier" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool SpokenFor( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SpokenFor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool StopsProjectile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.StopsProjectile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetReservation( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetReservation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )( params + 0 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TeamLink( int TeamNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TeamLink" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = TeamNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AllowLinkThroughOwnedActor( class Actor* OwnedActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.AllowLinkThroughOwnedActor" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = OwnedActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool HealDamage( int Amount, class Controller* Healer, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.HealDamage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = Amount;
				*( class Controller** )( params + 4 ) = Healer;
				*( ScriptClass** )( params + 8 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void IncrementLinkedToCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.IncrementLinkedToCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DecrementLinkedToCount(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DecrementLinkedToCount" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartLinkedEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.StartLinkedEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopLinkedEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.StopLinkedEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayHit( float Damage, class Controller* InstigatedBy, Vector HitLocation, ScriptClass* DamageType, Vector Momentum, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PlayHit" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( float* )( params + 0 ) = Damage;
				*( class Controller** )( params + 4 ) = InstigatedBy;
				*( Vector* )( params + 8 ) = HitLocation;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				*( void** )( params + 36 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayTakeHitEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PlayTakeHitEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyTakeHit( class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.NotifyTakeHit" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )( params + 0 ) = InstigatedBy;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = Damage;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )( params + 0 ) = Damage;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* GetHomingTarget( class UTProjectile* Seeker, class Controller* InstigatedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetHomingTarget" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTProjectile** )( params + 0 ) = Seeker;
				*( class Controller** )( params + 4 ) = InstigatedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			bool ImportantVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ImportantVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void InitializeSeats(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.InitializeSeats" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PreCacheSeatNames(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PreCacheSeatNames" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeTurrets(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.InitializeTurrets" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PossessedBy( class Controller* C, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.PossessedBy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )( params + 0 ) = C;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFiringMode( class Weapon* Weap, byte FiringModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetFiringMode" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )( params + 0 ) = Weap;
				*( byte* )( params + 4 ) = FiringModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashCount( class Weapon* Who )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ClearFlashCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = Who;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementFlashCount( class Weapon* Who, byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.IncrementFlashCount" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )( params + 0 ) = Who;
				*( byte* )( params + 4 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlashLocation( class Weapon* Who, byte FireModeNum, Vector NewLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetFlashLocation" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Weapon** )( params + 0 ) = Who;
				*( byte* )( params + 4 ) = FireModeNum;
				*( Vector* )( params + 8 ) = NewLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashLocation( class Weapon* Who )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ClearFlashLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )( params + 0 ) = Who;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetBarrelLocationAndRotation( int SeatIndex, Vector &SocketLocation, Rotator &SocketRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetBarrelLocationAndRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( int* )( params + 0 ) = SeatIndex;
				*( Vector* )( params + 4 ) = SocketLocation;
				*( Rotator* )( params + 16 ) = SocketRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				SocketLocation = *( Vector* )( params + 4 );
				SocketRotation = *( Rotator* )( params + 16 );
			}

			Vector GetEffectLocation( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetEffectLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetPhysicalFireStartLoc( class UTWeapon* ForWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetPhysicalFireStartLoc" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTWeapon** )( params + 0 ) = ForWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Rotator GetWeaponAim( class UTVehicleWeapon* VWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetWeaponAim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTVehicleWeapon** )( params + 0 ) = VWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			bool OverrideBeginFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.OverrideBeginFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool OverrideEndFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.OverrideEndFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void GetWeaponViewAxes( class UTWeapon* WhichWeapon, Vector &XAxis, Vector &YAxis, Vector &ZAxis )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetWeaponViewAxes" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( class UTWeapon** )( params + 0 ) = WhichWeapon;
				*( Vector* )( params + 4 ) = XAxis;
				*( Vector* )( params + 16 ) = YAxis;
				*( Vector* )( params + 28 ) = ZAxis;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				XAxis = *( Vector* )( params + 4 );
				YAxis = *( Vector* )( params + 16 );
				ZAxis = *( Vector* )( params + 28 );
			}

			void CauseMuzzleFlashLight( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CauseMuzzleFlashLight" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponFired( class Weapon* InWeapon, bool bViaReplication, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.WeaponFired" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleWeaponFired( bool bViaReplication, Vector HitLocation, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleWeaponFired" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( bool* )( params + 0 ) = bViaReplication;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void WeaponStoppedFiring( class Weapon* InWeapon, bool bViaReplication )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.WeaponStoppedFiring" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Weapon** )( params + 0 ) = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleWeaponStoppedFiring( bool bViaReplication, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleWeaponStoppedFiring" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )( params + 0 ) = bViaReplication;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleWeaponFireEffects( Vector HitLocation, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleWeaponFireEffects" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( int* )( params + 12 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Actor* FindWeaponHitNormal( Vector &HitLocation, Vector &HitNormal, Vector End, Vector Start, void* &HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.FindWeaponHitNormal" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				*( Vector* )( params + 24 ) = End;
				*( Vector* )( params + 36 ) = Start;
				*( void** )( params + 48 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				HitLocation = *( Vector* )( params + 0 );
				HitNormal = *( Vector* )( params + 12 );
				HitInfo = *( void** )( params + 48 );
				return *( class Actor** )( params + function->return_val_offset() );
			}

			void VehicleWeaponImpactEffects( Vector HitLocation, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleWeaponImpactEffects" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( int* )( params + 12 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnImpactEmitter( Vector HitLocation, Vector HitNormal, void* &ImpactEffect, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SpawnImpactEmitter" );
				byte *params = ( byte* )( malloc( 76 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				*( void** )( params + 24 ) = ImpactEffect;
				*( int* )( params + 72 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				ImpactEffect = *( void** )( params + 24 );
			}

			void VehicleAdjustFlashCount( int SeatIndex, byte FireModeNum, bool bClear )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleAdjustFlashCount" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( int* )( params + 0 ) = SeatIndex;
				*( byte* )( params + 4 ) = FireModeNum;
				*( bool* )( params + 8 ) = bClear;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleAdjustFlashLocation( int SeatIndex, byte FireModeNum, Vector NewLocation, bool bClear )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleAdjustFlashLocation" );
				byte *params = ( byte* )( malloc( 21 ) );
				*( int* )( params + 0 ) = SeatIndex;
				*( byte* )( params + 4 ) = FireModeNum;
				*( Vector* )( params + 8 ) = NewLocation;
				*( bool* )( params + 20 ) = bClear;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FindGoodEndView( class PlayerController* PC, Rotator &GoodRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.FindGoodEndView" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class PlayerController** )( params + 0 ) = PC;
				*( Rotator* )( params + 4 ) = GoodRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				GoodRotation = *( Rotator* )( params + 4 );
			}

			bool CalcCamera( float DeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CalcCamera" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
				return *( bool* )( params + function->return_val_offset() );
			}

			Vector GetCameraFocus( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetCameraFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			Vector GetCameraStart( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetCameraStart" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			float LimitCameraZ( float CurrentCamZ, float OriginalCamZ, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.LimitCameraZ" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )( params + 0 ) = CurrentCamZ;
				*( float* )( params + 4 ) = OriginalCamZ;
				*( int* )( params + 8 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void VehicleCalcCamera( float DeltaTime, int SeatIndex, Vector &out_CamLoc, Rotator &out_CamRot, Vector &CamStart, bool bPivotOnly )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.VehicleCalcCamera" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( float* )( params + 0 ) = DeltaTime;
				*( int* )( params + 4 ) = SeatIndex;
				*( Vector* )( params + 8 ) = out_CamLoc;
				*( Rotator* )( params + 20 ) = out_CamRot;
				*( Vector* )( params + 32 ) = CamStart;
				*( bool* )( params + 44 ) = bPivotOnly;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 8 );
				out_CamRot = *( Rotator* )( params + 20 );
				CamStart = *( Vector* )( params + 32 );
			}

			void AdjustCameraScale( bool bMoveCameraIn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.AdjustCameraScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = bMoveCameraIn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartBurnOut(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.StartBurnOut" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TurnOffShadows(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TurnOffShadows" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableDamageSmoke(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DisableDamageSmoke" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisableCollision(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DisableCollision" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBurnOut(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetBurnOut" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldSpawnExplosionLight( Vector HitLocation, Vector HitNormal )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ShouldSpawnExplosionLight" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( Vector* )( params + 12 ) = HitNormal;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void RBPenetrationDestroy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.RBPenetrationDestroy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RigidBodyCollision( void* &Collision, int ContactIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.RigidBodyCollision" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 8 ) = Collision;
				*( int* )( params + 44 ) = ContactIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Collision = *( void** )( params + 8 );
			}

			void TurretExplosion(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.TurretExplosion" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopVehicleSounds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.StopVehicleSounds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckDamageSmoke(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CheckDamageSmoke" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachDriver( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.AttachDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SitDriver( class UTPawn* UTP, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SitDriver" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPawn** )( params + 0 ) = UTP;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnDriverPhysicsAssetChanged( class UTPawn* UTP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.OnDriverPhysicsAssetChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPawn** )( params + 0 ) = UTP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptArray< wchar_t > GetHumanReadableName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetHumanReadableName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void OnPropertyChange( ScriptName PropName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.OnPropertyChange" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )( params + 0 ) = PropName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetHealth( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetHealth" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			float GetCollisionDamageModifier(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetCollisionDamageModifier" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void InitializeMorphs(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.InitializeMorphs" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceivedHealthChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ReceivedHealthChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyMorphHeal( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ApplyMorphHeal" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyRandomMorphDamage( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ApplyRandomMorphDamage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class UTGib* SpawnGibVehicle( Vector SpawnLocation, Rotator SpawnRotation, class StaticMesh* TheMesh, Vector HitLocation, bool bSpinGib, Vector ImpulseDirection, class ParticleSystem* PS_OnBreak, class ParticleSystem* PS_Trail )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SpawnGibVehicle" );
				byte *params = ( byte* )( malloc( 64 ) );
				*( Vector* )( params + 0 ) = SpawnLocation;
				*( Rotator* )( params + 12 ) = SpawnRotation;
				*( class StaticMesh** )( params + 24 ) = TheMesh;
				*( Vector* )( params + 28 ) = HitLocation;
				*( bool* )( params + 40 ) = bSpinGib;
				*( Vector* )( params + 44 ) = ImpulseDirection;
				*( class ParticleSystem** )( params + 56 ) = PS_OnBreak;
				*( class ParticleSystem** )( params + 60 ) = PS_Trail;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class UTGib** )( params + function->return_val_offset() );
			}

			void GetSVehicleDebug(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetSVehicleDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnExitVehicle( class UTSeqAct_ExitVehicle* Action )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.OnExitVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTSeqAct_ExitVehicle** )( params + 0 ) = Action;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetShieldActive( int SeatIndex, bool bActive )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetShieldActive" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SeatIndex;
				*( bool* )( params + 4 ) = bActive;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetSeatStoragePawn( int SeatIndex, class Pawn* PawnToSit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetSeatStoragePawn" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SeatIndex;
				*( class Pawn** )( params + 4 ) = PawnToSit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMovementEffect( int SeatIndex, bool bSetActive, class UTPawn* UTP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.SetMovementEffect" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )( params + 0 ) = SeatIndex;
				*( bool* )( params + 4 ) = bSetActive;
				*( class UTPawn** )( params + 8 ) = UTP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachDriver( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DetachDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )( params + 0 ) = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.CanAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )( params + 0 ) = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ScriptName GetVehicleKillStatName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetVehicleKillStatName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void DisplayHud( class UTHUD* HUD, class Canvas* Canvas, void* HudPOS, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DisplayHud" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class UTHUD** )( params + 0 ) = HUD;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( void** )( params + 8 ) = HudPOS;
				*( int* )( params + 16 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrawBarGraph( float X, float Y, float Width, float MaxWidth, float Height, class Canvas* DrawCanvas )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DrawBarGraph" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( float* )( params + 0 ) = X;
				*( float* )( params + 4 ) = Y;
				*( float* )( params + 8 ) = Width;
				*( float* )( params + 12 ) = MaxWidth;
				*( float* )( params + 16 ) = Height;
				*( class Canvas** )( params + 20 ) = DrawCanvas;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayExtraHud( class UTHUD* HUD, class Canvas* Canvas, void* pos, float Width, float Height, int SIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DisplayExtraHud" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class UTHUD** )( params + 0 ) = HUD;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( void** )( params + 8 ) = pos;
				*( float* )( params + 16 ) = Width;
				*( float* )( params + 20 ) = Height;
				*( int* )( params + 24 ) = SIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplaySeats( class UTHUD* HUD, class Canvas* Canvas, float PosX, float PosY, float Width, float Height, int SIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.DisplaySeats" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( class UTHUD** )( params + 0 ) = HUD;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( float* )( params + 8 ) = PosX;
				*( float* )( params + 12 ) = PosY;
				*( float* )( params + 16 ) = Width;
				*( float* )( params + 20 ) = Height;
				*( int* )( params + 24 ) = SIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void* GetSeatColor( int SeatIndex, bool bIsPlayersSeat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.GetSeatColor" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = SeatIndex;
				*( bool* )( params + 4 ) = bIsPlayersSeat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( void** )( params + function->return_val_offset() );
			}

			void ApplyWeaponEffects( int OverlayFlags, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ApplyWeaponEffects" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )( params + 0 ) = OverlayFlags;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldLeaveForCombat( class UTBot* B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTVehicle.ShouldLeaveForCombat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTBot** )( params + 0 ) = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
