#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVehicle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicle : public UTVehicle
	{
	public:
			ADD_VAR( ::FloatProperty, m_fCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_sName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nIconIndex, 0xFFFFFFFF )
			bool IsEmpty(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.IsEmpty" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool RidingPawnLeave( int SeatIndex, bool bForceLeave )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.RidingPawnLeave" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = SeatIndex;
				*( bool* )( params + 4 ) = bForceLeave;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bClientPhysDirty, 0x100 )
			ADD_VAR( ::BoolProperty, m_bServerCorrectionForce, 0x200 )
			ADD_VAR( ::BoolProperty, m_bImprovedLagSupport, 0x4 )
			int GetSeatIndexForController( class Controller* ControllerToMove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetSeatIndexForController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = ControllerToMove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::ByteProperty, m_VehicleType, 0xFFFFFFFF )
			bool CalcOtherWatchingCam( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV, class TrPlayerController* WatcherController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.CalcOtherWatchingCam" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( float* )params = fDeltaTime;
				*( Vector* )( params + 4 ) = out_CamLoc;
				*( Rotator* )( params + 16 ) = out_CamRot;
				*( float* )( params + 28 ) = out_FOV;
				*( class TrPlayerController** )( params + 32 ) = WatcherController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_CamLoc = *( Vector* )( params + 4 );
				out_CamRot = *( Rotator* )( params + 16 );
				out_FOV = *( float* )( params + 28 );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SetScannerDetect( bool detected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SetScannerDetect" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = detected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bUsesArmoredMultiplier, 0x80 )
			ADD_VAR( ::StrProperty, m_sWeapon1Name, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_sWeapon2Name, 0xFFFFFFFF )
			bool StopsProjectile( class Projectile* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.StopsProjectile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Projectile** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::FloatProperty, m_fMaxPawnLeaveSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nDetectedByEnemyScannerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nServerTickCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClientPhysDeltaTime, 0xFFFFFFFF )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_STRUCT( ::VectorProperty, m_vDeathCamStartOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarWidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarPlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarPlacementX, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger4HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger3HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger2HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger1HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_DriverHealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_HealthBarMIC )
			ADD_VAR( ::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fContrailSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostFadeInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDivingMaxSpeedMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nBaseMaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallDamageTickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastWallDamageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMaxDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMinDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMinDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMaxDamageSpeed, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, WallCollisionDamageType )
			ADD_VAR( ::FloatProperty, m_fVehicleDamageTickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastVehicleDamageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMaxDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMinDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMinDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMaxDamageSpeed, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, VehicleCollisionDamageType )
			ADD_VAR( ::FloatProperty, m_fPawnDamageTickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnMaxDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnMinDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnMaxDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnPushSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFlagPushSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_CrashDamageSeverity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPowerPoolTickRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPowerPoolRechargeRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostReactivatePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostEnergyPerSec, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeToReset, 0xFFFFFFFF )
			ADD_OBJECT( TrVehicleStation, m_OwnerStation )
			ADD_VAR( ::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_MissileLock, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bDetectedByEnemyScanner, 0x400 )
			ADD_VAR( ::BoolProperty, r_LevelFlightEnabled, 0x40 )
			ADD_VAR( ::BoolProperty, m_bLowPowerPool, 0x20 )
			ADD_VAR( ::BoolProperty, r_BoostersEnabled, 0x10 )
			ADD_VAR( ::BoolProperty, r_bIsInvulnerable, 0x8 )
			ADD_VAR( ::BoolProperty, m_bBoostRequiresThrust, 0x2 )
			ADD_VAR( ::BoolProperty, m_bPostSpawnLocked, 0x1 )
			ADD_OBJECT( TrPawn, m_PawnToTeleport )
			ADD_OBJECT( Pawn, Passenger )
			void NativePostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.NativePostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConsumePowerPool( float fAmount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ConsumePowerPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = fAmount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetPowerPoolPercent(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetPowerPoolPercent" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void RegainPowerPool( float fDeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.RegainPowerPool" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = fDeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SyncClientCurrentPowerPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SyncClientCurrentPowerPool" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetDetectedByEnemyScanner( bool detected )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SetDetectedByEnemyScanner" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = detected;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool GetDetectedByEnemyScanner(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetDetectedByEnemyScanner" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PancakeOther( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PancakeOther" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Controller* GetCollisionDamageInstigator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetCollisionDamageInstigator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			float GetDamageAmountForCollision( float Speed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetDamageAmountForCollision" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = Speed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void RigidBodyCollision( void* &Collision, int ContactIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.RigidBodyCollision" );
				byte *params = ( byte* )( malloc( 48 ) );
				*( void** )( params + 8 ) = Collision;
				*( int* )( params + 44 ) = ContactIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Collision = *( void** )( params + 8 );
			}

			void RanInto( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.RanInto" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SitDriver( class UTPawn* UTP, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SitDriver" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPawn** )params = UTP;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachDriver( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.DetachDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPawnToTeleport( class TrPawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SetPawnToTeleport" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetPostSpawnLocked( bool bLocked )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SetPostSpawnLocked" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bLocked;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SendLockOnMessage( int Switch )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SendLockOnMessage" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = Switch;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Died( class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )params = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void KillControllerForTeamChange( class Controller* ControllerToKill )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.KillControllerForTeamChange" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = ControllerToKill;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TeleportDriverToSeat(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.TeleportDriverToSeat" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanArmorDriveVehicle( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.CanArmorDriveVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CanArmorEnterVehicle( ScriptClass* FamilyInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.CanArmorEnterVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = FamilyInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			int GetFirstAvailableSeat( bool bSeatMustAllowFlag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetFirstAvailableSeat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bSeatMustAllowFlag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool TryToDrive( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.TryToDrive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DriverLeft(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.DriverLeft" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PassengerLeave( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PassengerLeave" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckReset(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.CheckReset" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetResetTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ResetResetTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandleMomentum( Vector Momentum, Vector HitLocation, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.HandleMomentum" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( Vector* )params = Momentum;
				*( Vector* )( params + 12 ) = HitLocation;
				*( ScriptClass** )( params + 24 ) = DamageType;
				*( void** )( params + 28 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ToggleBoosters( bool bEnabled, bool ToggleTimer )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ToggleBoosters" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bEnabled;
				*( bool* )( params + 4 ) = ToggleTimer;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ConsumeBoostPowerPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ConsumeBoostPowerPool" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanActivateBoosters(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.CanActivateBoosters" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldRechargePowerPool(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ShouldRechargePowerPool" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void ServerToggleLevelFlight( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ServerToggleLevelFlight" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BoostSoundFinished(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.BoostSoundFinished" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayBoosterEffects( bool bEnabled )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PlayBoosterEffects" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bEnabled;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayMissileLockSounds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PlayMissileLockSounds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Occupied(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.Occupied" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PostRenderFor( class PlayerController* PC, class Canvas* Canvas, Vector CameraPosition, Vector CameraDir )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PostRenderFor" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( class PlayerController** )params = PC;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( Vector* )( params + 8 ) = CameraPosition;
				*( Vector* )( params + 20 ) = CameraDir;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool RenderDriverPassengerMarker( class Canvas* Canvas, bool friendly, class TrHUD* HUD, class TrPlayerController* TrPC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.RenderDriverPassengerMarker" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( class Canvas** )params = Canvas;
				*( bool* )( params + 4 ) = friendly;
				*( class TrHUD** )( params + 8 ) = HUD;
				*( class TrPlayerController** )( params + 12 ) = TrPC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetSeatStoragePawn( int SeatIndex, class Pawn* PawnToSit )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SetSeatStoragePawn" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = SeatIndex;
				*( class Pawn** )( params + 4 ) = PawnToSit;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GetSVehicleDebug(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetSVehicleDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitializeSeats(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.InitializeSeats" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PassengerEnter( class Pawn* P, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PassengerEnter" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void AttachDriver( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.AttachDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachRidingPawn( class TrPawn* PawnToSit, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.AttachRidingPawn" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPawn** )params = PawnToSit;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachRidingPawn( class TrPawn* PawnLeft )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.DetachRidingPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPawn** )params = PawnLeft;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateSeatAnimations( class TrPawn* PawnToSit, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.UpdateSeatAnimations" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPawn** )params = PawnToSit;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HoldGameObject( class UDKCarriedObject* GameObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.HoldGameObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKCarriedObject** )params = GameObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HandleEnteringFlag( class UTPlayerReplicationInfo* EnteringPRI, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.HandleEnteringFlag" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerReplicationInfo** )params = EnteringPRI;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DriverEnter( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.DriverEnter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class PlayerReplicationInfo* GetSeatPRI( int SeatNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetSeatPRI" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class PlayerReplicationInfo** )( params + function->return_val_offset() );
			}

			void ServerChangeSeat( int RequestedSeat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ServerChangeSeat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = RequestedSeat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SwitchSeat( int RequestedSeat, class Controller* ControllerRequestingSeatChange )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SwitchSeat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = RequestedSeat;
				*( class Controller** )( params + 4 ) = ControllerRequestingSeatChange;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ChangeSeat( class Controller* ControllerToMove, int RequestedSeat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ChangeSeat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = ControllerToMove;
				*( int* )( params + 4 ) = RequestedSeat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SwitchWeapon( byte NewGroup )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SwitchWeapon" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = NewGroup;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetSeatIndexForStoragePawn( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetSeatIndexForStoragePawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			bool PlaceExitingDriver( class Pawn* ExitingDriver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PlaceExitingDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = ExitingDriver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TryExitPos( class Pawn* ExitingDriver, Vector ExitPos, bool bMustFindGround )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.TryExitPos" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = ExitingDriver;
				*( Vector* )( params + 4 ) = ExitPos;
				*( bool* )( params + 16 ) = bMustFindGround;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool SeatAvailable( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SeatAvailable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AnySeatAvailable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.AnySeatAvailable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Rotator GetWeaponAim( class UTVehicleWeapon* VWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetWeaponAim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTVehicleWeapon** )params = VWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void WeaponRotationChanged( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.WeaponRotationChanged" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool HealDamage( int Amount, class Controller* Healer, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.HealDamage" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( int* )params = Amount;
				*( class Controller** )( params + 4 ) = Healer;
				*( ScriptClass** )( params + 8 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DoRepairs( int HealAmount, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.DoRepairs" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )params = HealAmount;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverRadiusDamage( float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.DriverRadiusDamage" );
				byte *params = ( byte* )( malloc( 40 ) );
				*( float* )params = DamageAmount;
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

			void Suicide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.Suicide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeRadiusDamage( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.TakeRadiusDamage" );
				byte *params = ( byte* )( malloc( 44 ) );
				*( class Controller** )params = InstigatedBy;
				*( float* )( params + 4 ) = BaseDamage;
				*( float* )( params + 8 ) = DamageRadius;
				*( ScriptClass** )( params + 12 ) = DamageType;
				*( float* )( params + 16 ) = Momentum;
				*( Vector* )( params + 20 ) = HurtOrigin;
				*( bool* )( params + 32 ) = bFullDamage;
				*( class Actor** )( params + 36 ) = DamageCauser;
				*( float* )( params + 40 ) = DamageFalloffExponent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.TakeDamage" );
				byte *params = ( byte* )( malloc( 68 ) );
				*( int* )params = Damage;
				*( class Controller** )( params + 4 ) = EventInstigator;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				*( void** )( params + 36 ) = HitInfo;
				*( class Actor** )( params + 64 ) = DamageCauser;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CheckDamageSmoke(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.CheckDamageSmoke" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BlowupVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.BlowupVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleWeaponFireEffects( Vector HitLocation, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.VehicleWeaponFireEffects" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitLocation;
				*( int* )( params + 12 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleWeaponStoppedFiring( bool bViaReplication, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.VehicleWeaponStoppedFiring" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( bool* )params = bViaReplication;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ThirdPersonFireEffects( Vector HitLocation, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ThirdPersonFireEffects" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )params = HitLocation;
				*( int* )( params + 12 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SpawnTracerBeam( Vector Start, Vector End, class ParticleSystem* TracerBeamTemplate )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SpawnTracerBeam" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( Vector* )params = Start;
				*( Vector* )( params + 12 ) = End;
				*( class ParticleSystem** )( params + 24 ) = TracerBeamTemplate;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrProj_Tracer* SpawnTracerEffect( byte TracerType, Vector EffectLocation, Vector HitLocation, float HitDistance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SpawnTracerEffect" );
				byte *params = ( byte* )( malloc( 29 ) );
				*( byte* )params = TracerType;
				*( Vector* )( params + 4 ) = EffectLocation;
				*( Vector* )( params + 16 ) = HitLocation;
				*( float* )( params + 28 ) = HitDistance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProj_Tracer** )( params + function->return_val_offset() );
			}

			void ProcessViewRotation( float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = DeltaTime;
				*( Rotator* )( params + 4 ) = out_ViewRotation;
				*( Rotator* )( params + 16 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 4 );
				out_DeltaRot = *( Rotator* )( params + 16 );
			}

			void ProcessViewRotationBasedOnSeat( int SeatIndex, float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ProcessViewRotationBasedOnSeat" );
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

			bool ShouldShowUseable( class PlayerController* PC, float Dist )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ShouldShowUseable" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class PlayerController** )params = PC;
				*( float* )( params + 4 ) = Dist;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetDriving( bool bNewDriving )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.SetDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewDriving;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayVehicleEvent( ScriptName EventTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PlayVehicleEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = EventTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void VehicleEvent( ScriptName EventTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.VehicleEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = EventTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayClientVehicleSound( ScriptName SoundTag )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PlayClientVehicleSound" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = SoundTag;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MigrateVehicleSounds( class Pawn* P, bool bIsRiding )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.MigrateVehicleSounds" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = P;
				*( bool* )( params + 4 ) = bIsRiding;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopVehicleSounds(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.StopVehicleSounds" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetCameraFocus( int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetCameraFocus" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			ScriptArray< wchar_t > GetSpectatorName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GetSpectatorName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptArray< wchar_t >* )( params + function->return_val_offset() );
			}

			void PlayHorn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.PlayHorn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void GoInvulnerable( float InvulnerableTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.GoInvulnerable" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = InvulnerableTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearInvulnerability(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicle.ClearInvulnerability" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
