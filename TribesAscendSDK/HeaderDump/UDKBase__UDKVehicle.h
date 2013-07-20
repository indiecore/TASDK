#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UDKBase.UDKVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UDKBase.UDKVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UDKBase.UDKVehicle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UDKVehicle : public UDKVehicleBase
	{
	public:
			bool OnTouchForcedDirVolume( class UDKForcedDirectionVolume* Vol )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.OnTouchForcedDirVolume" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKForcedDirectionVolume** )params = Vol;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, bAllowedExit, 0x8000 )
			ADD_VAR( ::BoolProperty, bEjectKilledBodies, 0x1 )
			ScriptClass* GetRanOverDamageType(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.GetRanOverDamageType" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			ADD_STRUCT( ::VectorProperty, HUDLocation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShowLockedMaxDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastPostRenderTraceTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TeamBeaconMaxDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinRunOverWarningAim, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastRunOverWarningTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinRunOverSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ResetTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExtraReachDownThreshold, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, Team, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ObjectiveGetOutDist, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ContrailColorParameterName, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, WaterEffectType, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastJumpOutCheck, 0xFFFFFFFF )
			ADD_OBJECT( Controller, KillerController )
			ADD_VAR( ::FloatProperty, LastTakeHitTimeout, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, DamageMaterialInstance )
			ADD_VAR( ::FloatProperty, CustomGravityScaling, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, SmallChunkImpactSound )
			ADD_OBJECT( SoundCue, MediumChunkImpactSound )
			ADD_OBJECT( SoundCue, LargeChunkImpactSound )
			ADD_VAR( ::FloatProperty, LastDeathImpactTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeInDestroyablePenetration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DestroyOnPenetrationDuration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DestroyOnPenetrationThreshold, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, DrivingAnim, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, SeatMask, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, WeaponRotation, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, WaterGroundEffect )
			ADD_VAR( ::NameProperty, GroundEffectDistParameterName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxGroundEffectDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccumulatedWaterDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WaterDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OccupiedUpsideDownDamagePerSec, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, UpsideDownDamagePerSec, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccruedFireDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FireDamagePerSec, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FireDamageThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FlippedCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastCheckUpsideDownTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxWheelEffectDistSq, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, CurrentTireMaterial, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RemainingBurn, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForceSpinWarmup, 0x800000 )
			ADD_VAR( ::BoolProperty, bGrab2, 0x400000 )
			ADD_VAR( ::BoolProperty, bGrab1, 0x200000 )
			ADD_VAR( ::BoolProperty, bTrickJumping, 0x100000 )
			ADD_VAR( ::BoolProperty, bDisableRepulsorsAtMaxFallSpeed, 0x80000 )
			ADD_VAR( ::BoolProperty, bTeamLocked, 0x40000 )
			ADD_VAR( ::BoolProperty, bShowLocked, 0x20000 )
			ADD_VAR( ::BoolProperty, bUseAlternatePaths, 0x10000 )
			ADD_VAR( ::BoolProperty, bFloatWhenDriven, 0x4000 )
			ADD_VAR( ::BoolProperty, bJostleWhileDriving, 0x2000 )
			ADD_VAR( ::BoolProperty, bDeadVehicle, 0x1000 )
			ADD_VAR( ::BoolProperty, bIsInDestroyablePenetration, 0x800 )
			ADD_VAR( ::BoolProperty, bTakeWaterDamageWhileDriving, 0x400 )
			ADD_VAR( ::BoolProperty, bIsScraping, 0x200 )
			ADD_VAR( ::BoolProperty, bEjectPassengersWhenFlipped, 0x100 )
			ADD_VAR( ::BoolProperty, bIsBurning, 0x80 )
			ADD_VAR( ::BoolProperty, bIsDisabled, 0x40 )
			ADD_VAR( ::BoolProperty, bNoZDamping, 0x20 )
			ADD_VAR( ::BoolProperty, bNoZDampingInAir, 0x10 )
			ADD_VAR( ::BoolProperty, bFrontalCollisionWithFixed, 0x8 )
			ADD_VAR( ::BoolProperty, bFrontalCollision, 0x4 )
			ADD_VAR( ::BoolProperty, bHomingTarget, 0x2 )
			Rotator SeatWeaponRotation( int SeatIndex, Rotator NewRot, bool bReadValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.SeatWeaponRotation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = SeatIndex;
				*( Rotator* )( params + 4 ) = NewRot;
				*( bool* )( params + 16 ) = bReadValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Vector SeatFlashLocation( int SeatIndex, Vector NewLoc, bool bReadValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.SeatFlashLocation" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( int* )params = SeatIndex;
				*( Vector* )( params + 4 ) = NewLoc;
				*( bool* )( params + 16 ) = bReadValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			byte SeatFlashCount( int SeatIndex, byte NewCount, bool bReadValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.SeatFlashCount" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( int* )params = SeatIndex;
				*( byte* )( params + 4 ) = NewCount;
				*( bool* )( params + 8 ) = bReadValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			byte SeatFiringMode( int SeatIndex, byte NewFireMode, bool bReadValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.SeatFiringMode" );
				byte *params = ( byte* )( malloc( 9 ) );
				*( int* )params = SeatIndex;
				*( byte* )( params + 4 ) = NewFireMode;
				*( bool* )( params + 8 ) = bReadValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void ForceWeaponRotation( int SeatIndex, Rotator NewRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.ForceWeaponRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( int* )params = SeatIndex;
				*( Rotator* )( params + 4 ) = NewRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetSeatPivotPoint( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.GetSeatPivotPoint" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			int GetBarrelIndex( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.GetBarrelIndex" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool IsSeatControllerReplicationViewer( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.IsSeatControllerReplicationViewer" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsLocalOnVehicle( class Pawn* InP )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.IsLocalOnVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = InP;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void LockOnWarning( class UDKProjectile* IncomingMissile )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.LockOnWarning" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKProjectile** )params = IncomingMissile;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnPropertyChange( ScriptName PropName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.OnPropertyChange" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = PropName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetGravityZ(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.GetGravityZ" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PlayTakeHitEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.PlayTakeHitEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReceivedHealthChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.ReceivedHealthChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void JumpOutCheck(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.JumpOutCheck" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetMaxRiseForce(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.GetMaxRiseForce" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool CheckAutoDestruct( class TeamInfo* InstigatorTeam, float CheckRadius )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.CheckAutoDestruct" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TeamInfo** )params = InstigatorTeam;
				*( float* )( params + 4 ) = CheckRadius;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SelfDestruct( class Actor* ImpactedActor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.SelfDestruct" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = ImpactedActor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			byte GetTeamNum(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.GetTeamNum" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( byte* )( params + function->return_val_offset() );
			}

			void NativePostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.NativePostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool InUseableRange( class UDKPlayerController* PC, float Dist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.InUseableRange" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UDKPlayerController** )params = PC;
				*( float* )( params + 4 ) = Dist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetHUDLocation( Vector NewHUDLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.SetHUDLocation" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = NewHUDLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitDamageSkel(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.InitDamageSkel" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateDamageMaterial(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.UpdateDamageMaterial" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyMorphDamage( Vector HitLocation, int Damage, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.ApplyMorphDamage" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = HitLocation;
				*( int* )( params + 12 ) = Damage;
				*( Vector* )( params + 16 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MorphTargetDestroyed( int MorphNodeIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.MorphTargetDestroyed" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = MorphNodeIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RBPenetrationDestroy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.RBPenetrationDestroy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeWaterDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.TakeWaterDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.CheckReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeFireDamage(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.TakeFireDamage" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitRigidBody(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.PostInitRigidBody" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateHoverboardDustEffect( float DustHeight )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UDKBase.UDKVehicle.UpdateHoverboardDustEffect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DustHeight;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
