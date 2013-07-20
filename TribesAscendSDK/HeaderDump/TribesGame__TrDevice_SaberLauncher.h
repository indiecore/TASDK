#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDevice_SaberLauncher." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDevice_SaberLauncher." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDevice_SaberLauncher." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDevice_SaberLauncher : public TrDevice
	{
	public:
			ADD_VAR( ::BoolProperty, r_bTargetLocked, 0x1 )
			ADD_OBJECT( TrPlayerController, m_TargetController )
			ADD_VAR( ::ByteProperty, r_nFired, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLockingTargetTimestamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeBeforeVictimKnowsMissileIsTargeting, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fGroundCheckDistance, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPotentialTargetLockOnDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fReticuleLockOnDist, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLockRetainSeconds, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRestoreAimHelpRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinCosineAcquireTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAcquireTargetMaxAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRetainTargetMaxAngle, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMinCosineRetainTarget, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bDebugMode, 0x4 )
			ADD_VAR( ::BoolProperty, m_bRestoreAimingHelp, 0x2 )
			ADD_OBJECT( Actor, m_Target )
			ADD_VAR( ::FloatProperty, m_fPreLockTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTargetSightTime, 0xFFFFFFFF )
			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResumeTargeting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.ResumeTargeting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SuspendTargeting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.SuspendTargeting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Destroyed(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.Destroyed" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool TargetInsideReticle( class Actor* Target, bool initialAcquire )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.TargetInsideReticle" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = Target;
				*( bool* )( params + 4 ) = initialAcquire;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool IsActorInLOS( class Actor* A )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.IsActorInLOS" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = A;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ValidateTrackingTarget( class Actor* Target, bool initialAcquire )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.ValidateTrackingTarget" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class Actor** )params = Target;
				*( bool* )( params + 4 ) = initialAcquire;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SetTargetActorMissileLockState( class Actor* Target, byte lockValue )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.SetTargetActorMissileLockState" );
				byte *params = ( byte* )( malloc( 5 ) );
				*( class Actor** )params = Target;
				*( byte* )( params + 4 ) = lockValue;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetNewTrackingTarget( class Actor* Target )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.SetNewTrackingTarget" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Actor** )params = Target;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void TargetLockAcquired(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.TargetLockAcquired" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void FireAmmunition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.FireAmmunition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PerformTargeting(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.PerformTargeting" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSwitchAwayFromWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.OnSwitchAwayFromWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnSwitchToWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.OnSwitchToWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HolderEnteredVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.HolderEnteredVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void HolderExitedVehicle(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.HolderExitedVehicle" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class Projectile* ProjectileFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.ProjectileFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Projectile** )( params + function->return_val_offset() );
			}

			void ServerTryNewPossibleTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.ServerTryNewPossibleTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.BeginFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrSeekingMissileManager* GetSeekingMissileManager(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDevice_SaberLauncher.GetSeekingMissileManager" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrSeekingMissileManager** )( params + function->return_val_offset() );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
