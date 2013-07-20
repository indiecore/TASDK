#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTWeaponPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTWeaponPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTWeaponPawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTWeaponPawn : public UDKWeaponPawn
	{
	public:
			ScriptName GetVehicleDrivingStatName(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.GetVehicleDrivingStatName" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void DisplayDebug( class HUD* HUD, float &out_YL, float &out_YPos )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.DisplayDebug" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class HUD** )params = HUD;
				*( float* )( params + 4 ) = out_YL;
				*( float* )( params + 8 ) = out_YPos;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_YL = *( float* )( params + 4 );
				out_YPos = *( float* )( params + 8 );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.CalcCamera" );
				byte *params = ( byte* )( malloc( 32 ) );
				*( float* )params = fDeltaTime;
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

			void ProcessViewRotation( float DeltaTime, Rotator &out_ViewRotation, Rotator &out_DeltaRot )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.ProcessViewRotation" );
				byte *params = ( byte* )( malloc( 28 ) );
				*( float* )params = DeltaTime;
				*( Rotator* )( params + 4 ) = out_ViewRotation;
				*( Rotator* )( params + 16 ) = out_DeltaRot;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				out_ViewRotation = *( Rotator* )( params + 4 );
				out_DeltaRot = *( Rotator* )( params + 16 );
			}

			void SetFiringMode( class Weapon* Weap, byte FiringModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.SetFiringMode" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )params = Weap;
				*( byte* )( params + 4 ) = FiringModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void IncrementFlashCount( class Weapon* Who, byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.IncrementFlashCount" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Weapon** )params = Who;
				*( byte* )( params + 4 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashCount( class Weapon* Who )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.ClearFlashCount" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )params = Who;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetFlashLocation( class Weapon* Who, byte FireModeNum, Vector NewLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.SetFlashLocation" );
				byte *params = ( byte* )( malloc( 17 ) );
				*( class Weapon** )params = Who;
				*( byte* )( params + 4 ) = FireModeNum;
				*( Vector* )( params + 8 ) = NewLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearFlashLocation( class Weapon* Who )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.ClearFlashLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )params = Who;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PossessedBy( class Controller* C, bool bVehicleTransition )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.PossessedBy" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Controller** )params = C;
				*( bool* )( params + 4 ) = bVehicleTransition;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DriverLeft(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.DriverLeft" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerAdjacentSeat( int Direction, class Controller* C )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.ServerAdjacentSeat" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = Direction;
				*( class Controller** )( params + 4 ) = C;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ServerChangeSeat( int RequestedSeat )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.ServerChangeSeat" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = RequestedSeat;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AdjustCameraScale( bool bIn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.AdjustCameraScale" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bIn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool PlaceExitingDriver( class Pawn* ExitingDriver )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.PlaceExitingDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = ExitingDriver;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DropToGround(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.DropToGround" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddVelocity( Vector NewVelocity, Vector HitLocation, ScriptClass* DamageType, void* HitInfo )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.AddVelocity" );
				byte *params = ( byte* )( malloc( 56 ) );
				*( Vector* )params = NewVelocity;
				*( Vector* )( params + 12 ) = HitLocation;
				*( ScriptClass** )( params + 24 ) = DamageType;
				*( void** )( params + 28 ) = HitInfo;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void JumpOffPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.JumpOffPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BaseChange(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.BaseChange" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMovementPhysics(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.SetMovementPhysics" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DoJump( bool bUpdating )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.DoJump" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bUpdating;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float GetCollisionRadius(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.GetCollisionRadius" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void SetBaseEyeheight(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.SetBaseEyeheight" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AttachDriver( class Pawn* P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.AttachDriver" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HoldGameObject( class UDKCarriedObject* GameObj )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.HoldGameObject" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UDKCarriedObject** )params = GameObj;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FaceRotation( Rotator NewRotation, float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.FaceRotation" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )params = NewRotation;
				*( float* )( params + 12 ) = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool DriverLeave( bool bForceLeave )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.DriverLeave" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bForceLeave;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool Died( class Controller* Killer, ScriptClass* DamageType, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.Died" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Controller** )params = Killer;
				*( ScriptClass** )( params + 4 ) = DamageType;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool TooCloseToAttack( class Actor* Other )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.TooCloseToAttack" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Other;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void DisplayHud( class UTHUD* HUD, class Canvas* Canvas, void* HudPOS, int SIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.DisplayHud" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class UTHUD** )params = HUD;
				*( class Canvas** )( params + 4 ) = Canvas;
				*( void** )( params + 8 ) = HudPOS;
				*( int* )( params + 16 ) = SIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ApplyWeaponEffects( int OverlayFlags, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function UTGame.UTWeaponPawn.ApplyWeaponEffects" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( int* )params = OverlayFlags;
				*( int* )( params + 4 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
