#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrSeekingMissileManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrSeekingMissileManager." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrSeekingMissileManager." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrSeekingMissileManager : public Info
	{
	public:
			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AddSaberLauncher( class TrDevice_SaberLauncher* SaberLauncherToAdd, byte MissileLockValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.AddSaberLauncher" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class TrDevice_SaberLauncher** )params = SaberLauncherToAdd;
				*( byte* )( params + 4 ) = MissileLockValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveSaberLauncher( class TrDevice_SaberLauncher* SaberLauncherToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.RemoveSaberLauncher" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrDevice_SaberLauncher** )params = SaberLauncherToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetNumSaberLaunchersTargetingController( class TrPlayerController* Controller, bool bOnlyClientNotified )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.GetNumSaberLaunchersTargetingController" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrPlayerController** )params = Controller;
				*( bool* )( params + 4 ) = bOnlyClientNotified;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetNumSaberLaunchersTargetingVehicle( class TrVehicle* targetVehicle, bool bOnlyClientNotified )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.GetNumSaberLaunchersTargetingVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class TrVehicle** )params = targetVehicle;
				*( bool* )( params + 4 ) = bOnlyClientNotified;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void AddMissile( class TrProj_TrackingMissile* MissileToAdd )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.AddMissile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrProj_TrackingMissile** )params = MissileToAdd;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RemoveMissile( class TrProj_TrackingMissile* MissileToRemove )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.RemoveMissile" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrProj_TrackingMissile** )params = MissileToRemove;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetNumMissilesTrackingController( class TrPlayerController* Controller )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.GetNumMissilesTrackingController" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = Controller;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			int GetNumMissilesTrackingVehicle( class TrVehicle* targetVehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.GetNumMissilesTrackingVehicle" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrVehicle** )params = targetVehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void VictimControllerUpdated( class TrPlayerController* VictimController, byte MissileEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.VictimControllerUpdated" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class TrPlayerController** )params = VictimController;
				*( byte* )( params + 4 ) = MissileEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TargetVehicleUpdated( class TrVehicle* targetVehicle, byte MissileEvent )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.TargetVehicleUpdated" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class TrVehicle** )params = targetVehicle;
				*( byte* )( params + 4 ) = MissileEvent;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginSaberLauncherTargeting( class TrPlayerController* VictimController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.BeginSaberLauncherTargeting" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = VictimController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopSaberLauncherTargeting( class TrPlayerController* VictimController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.StopSaberLauncherTargeting" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = VictimController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginMissileTracking( class TrPlayerController* VictimController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.BeginMissileTracking" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = VictimController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopMissileTracking( class TrPlayerController* VictimController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.StopMissileTracking" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class TrPlayerController** )params = VictimController;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnLeftVehicle( class Pawn* LeavingPawn, class TrVehicle* Vehicle )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.PawnLeftVehicle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Pawn** )params = LeavingPawn;
				*( class TrVehicle** )( params + 4 ) = Vehicle;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PawnEnteredVehicle( class Pawn* EnteringPawn, class TrVehicle* Vehicle, int SeatIndex )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrSeekingMissileManager.PawnEnteredVehicle" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class Pawn** )params = EnteringPawn;
				*( class TrVehicle** )( params + 4 ) = Vehicle;
				*( int* )( params + 8 ) = SeatIndex;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ADD_VAR( ::IntProperty, RepCounter, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
