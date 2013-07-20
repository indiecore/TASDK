#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrDeployable_Turret." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrDeployable_Turret." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrDeployable_Turret." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrDeployable_Turret : public TrDeployable
	{
	public:
			ADD_VAR( ::FloatProperty, m_fLastStallTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFireStallRestoreTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeToIgnoreInvulnerable, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeToAcquireTarget, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTargetAcquiredTime, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_TargetAcquiredSoundCue )
			ADD_VAR( ::FloatProperty, m_fDeltaFireInterval, 0xFFFFFFFF )
			ADD_OBJECT( ScriptClass, m_MuzzleFlashLightClass )
			ADD_VAR( ::BoolProperty, m_bCanTargetVehicles, 0x2 )
			ADD_VAR( ::BoolProperty, m_bEnabled, 0x1 )
			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void DeployComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.DeployComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void AcquireTarget(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.AcquireTarget" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float GetAcquireDelayTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.GetAcquireDelayTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void CleanupIgnoreList(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.CleanupIgnoreList" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CanTargetPawn( class Pawn* aPawn )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.CanTargetPawn" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Pawn** )params = aPawn;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Pawn* GetTargetPawn(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.GetTargetPawn" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Pawn** )( params + function->return_val_offset() );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateAim( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.UpdateAim" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireEffects( class Weapon* InWeapon, bool bViaReplication, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.PlayFireEffects" );
				byte *params = ( byte* )( malloc( 20 ) );
				*( class Weapon** )params = InWeapon;
				*( bool* )( params + 4 ) = bViaReplication;
				*( Vector* )( params + 8 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CauseMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.CauseMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MuzzleFlashTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.MuzzleFlashTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetMuzzleFlashParams( void* MuzzleFlashColor )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.SetMuzzleFlashParams" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( void** )( params + 4 ) = MuzzleFlashColor;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector GetWeaponStartTraceLocation( class Weapon* CurrentWeapon )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.GetWeaponStartTraceLocation" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class Weapon** )params = CurrentWeapon;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			class Texture2D* GetMarker(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.GetMarker" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Texture2D** )( params + function->return_val_offset() );
			}

			void AwardKillAssists(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrDeployable_Turret.AwardKillAssists" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
