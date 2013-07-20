#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " Engine.Vehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty Engine.Vehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty Engine.Vehicle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class Vehicle : public Pawn
	{
	public:
			bool DriverLeave( bool bForceLeave )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DriverLeave" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceLeave;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TryToDrive( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.TryToDrive" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_OBJECT( Pawn, Driver )
			ADD_VAR( ::FloatProperty, TurnTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VehicleMovingTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AIMoveCheckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldThrottle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OnlySteeringStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldSteering, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StuckTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ThrottleTime, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, StuckCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ForceCrushPenetration, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinCrushSpeed, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, CrushedDamageType )
			ADD_VAR( ::FloatProperty, MomentumMult, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DriverDamageMult, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetLocationAdjustment, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Rise, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Throttle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Steering, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, ExitOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ExitRadius, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDoExtraNetRelevancyTraces, 0x1000 )
			ADD_VAR( ::BoolProperty, bIgnoreStallZ, 0x800 )
			ADD_VAR( ::BoolProperty, bRetryPathfindingWithDriver, 0x400 )
			ADD_VAR( ::BoolProperty, bAvoidReversing, 0x200 )
			ADD_VAR( ::BoolProperty, bDuckObstacles, 0x100 )
			ADD_VAR( ::BoolProperty, bScriptedRise, 0x80 )
			ADD_VAR( ::BoolProperty, bHasHandbrake, 0x40 )
			ADD_VAR( ::BoolProperty, bFollowLookDir, 0x20 )
			ADD_VAR( ::BoolProperty, bSeparateTurretFocus, 0x10 )
			ADD_VAR( ::BoolProperty, bTurnInPlace, 0x8 )
			ADD_VAR( ::BoolProperty, bAttachDriver, 0x4 )
			ADD_VAR( ::BoolProperty, bDriverIsVisible, 0x2 )
			ADD_VAR( ::BoolProperty, bDriving, 0x1 )
			void NotifyTeamChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.NotifyTeamChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void Suicide(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.Suicide" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetMaxRiseForce(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.GetMaxRiseForce" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			Vector GetTargetLocation( class Actor* RequestedBy, bool bRequestAlternateLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.GetTargetLocation" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = RequestedBy;
				*( bool* )( params + 4 ) = bRequestAlternateLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void TakeRadiusDamage( class Controller* InstigatedBy, float BaseDamage, float DamageRadius, ScriptClass* DamageType, float Momentum, Vector HurtOrigin, bool bFullDamage, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.TakeRadiusDamage" );
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

			void DriverRadiusDamage( float DamageAmount, float DamageRadius, class Controller* EventInstigator, ScriptClass* DamageType, float Momentum, Vector HitLocation, class Actor* DamageCauser, float DamageFalloffExponent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DriverRadiusDamage" );
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

			void PlayerChangedTeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.PlayerChangedTeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetBaseEyeheight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.SetBaseEyeheight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CheatWalk(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.CheatWalk" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheatGhost(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.CheatGhost" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool CheatFly(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.CheatFly" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed_HandleDriver(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.Destroyed_HandleDriver" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanEnterVehicle( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.CanEnterVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool AnySeatAvailable(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.AnySeatAvailable" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool DriverEnter( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DriverEnter" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PossessedBy( class Controller* C, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.PossessedBy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = C;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EntryAnnouncement( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.EntryAnnouncement" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachDriver( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.AttachDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DetachDriver( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DetachDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ContinueOnFoot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.ContinueOnFoot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			Rotator GetExitRotation( class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.GetExitRotation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Controller** )params = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void SetInputs( float InForward, float InStrafe, float InUp )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.SetInputs" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( float* )params = InForward;
				*( float* )( params + 4 ) = InStrafe;
				*( float* )( params + 8 ) = InUp;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverLeft(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DriverLeft" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PlaceExitingDriver( class Pawn* ExitingDriver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.PlaceExitingDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = ExitingDriver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool FindAutoExit( class Pawn* ExitingDriver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.FindAutoExit" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = ExitingDriver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TryExitPos( class Pawn* ExitingDriver, Vector ExitPos, bool bMustFindGround )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.TryExitPos" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Pawn** )params = ExitingDriver;
				*( Vector* )( params + 4 ) = ExitPos;
				*( bool* )( params + 16 ) = bMustFindGround;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void UnPossessed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.UnPossessed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Controller* SetKillInstigator( class Controller* InstigatedBy, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.SetKillInstigator" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = InstigatedBy;
				*( ScriptClass** )( params + 4 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			void TakeDamage( int Damage, class Controller* EventInstigator, Vector HitLocation, Vector Momentum, ScriptClass* DamageType, void* HitInfo, class Actor* DamageCauser )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.TakeDamage" );
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

			void AdjustDriverDamage( int &Damage, class Controller* InstigatedBy, Vector HitLocation, Vector &Momentum, ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.AdjustDriverDamage" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( int* )params = Damage;
				*( class Controller** )( params + 4 ) = InstigatedBy;
				*( Vector* )( params + 8 ) = HitLocation;
				*( Vector* )( params + 20 ) = Momentum;
				*( ScriptClass** )( params + 32 ) = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				Damage = *( int* )params;
				Momentum = *( Vector* )( params + 20 );
			}

			void ThrowActiveWeapon( bool bDestroyWeap )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.ThrowActiveWeapon" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bDestroyWeap;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool Died( class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )params = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DriverDied( ScriptClass* DamageType )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DriverDied" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( ScriptClass** )params = DamageType;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayDying( ScriptClass* DamageType, Vector HitLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.PlayDying" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( ScriptClass** )params = DamageType;
				*( Vector* )( params + 4 ) = HitLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetDefaultCameraMode( class PlayerController* RequestedBy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.GetDefaultCameraMode" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class PlayerController** )params = RequestedBy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void FaceRotation( Rotator NewRotation, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.FaceRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )params = NewRotation;
				*( float* )( params + 12 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EncroachedBy( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.EncroachedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Controller* GetCollisionDamageInstigator(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.GetCollisionDamageInstigator" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Controller** )( params + function->return_val_offset() );
			}

			bool EncroachingOn( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.EncroachingOn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void PancakeOther( class Pawn* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.PancakeOther" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CrushedBy( class Pawn* OtherPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.CrushedBy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = OtherPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetEntryLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.GetEntryLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void SetDriving( bool B )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.SetDriving" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = B;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DrivingStatusChanged(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.DrivingStatusChanged" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void NotifyDriverTakeHit( class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.NotifyDriverTakeHit" );
				byte *params = ( byte* )( malloc( 36 ) );
				*( class Controller** )params = InstigatedBy;
				*( Vector* )( params + 4 ) = HitLocation;
				*( int* )( params + 16 ) = Damage;
				*( ScriptClass** )( params + 20 ) = DamageType;
				*( Vector* )( params + 24 ) = Momentum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ZeroMovementVariables(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function Engine.Vehicle.ZeroMovementVariables" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
