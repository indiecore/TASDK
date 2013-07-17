#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVehicleWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVehicleWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVehicleWeapon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicleWeapon : public UTVehicleWeapon
	{
	public:
			bool HasReticuleCharge(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.HasReticuleCharge" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			float CalculateReloadPercentRemaining(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.CalculateReloadPercentRemaining" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::IntProperty, m_nReticuleIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bShowAmmoIndicator, 0x20 )
			ADD_VAR( ::FloatProperty, m_fReloadTimeRemaining, 0xFFFFFFFF )
			float GetAccuracy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.GetAccuracy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			bool CanClientRequestReloadNow(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.CanClientRequestReloadNow" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, m_bEndZoomOnReload, 0x100 )
			bool CanViewZoom(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.CanViewZoom" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			ADD_VAR( ::BoolProperty, r_bIsReloading, 0x40 )
			ADD_VAR( ::NameProperty, m_WeaponSpinControl, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bSpawnTracers, 0x1 )
			ADD_VAR( ::ByteProperty, m_TracerType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bSpawnTracerBeams, 0x2 )
			ADD_OBJECT( ParticleSystem, m_TracerBeamTemplate )
			ADD_VAR( ::FloatProperty, m_fShowTracerDistance, 0xFFFFFFFF )
			ADD_OBJECT( CameraShake, m_FireCameraShake )
			ADD_OBJECT( MaterialInstanceConstant, m_ZoomOverlayMaterial )
			ADD_VAR( ::NameProperty, m_nmZoomMaterialEffectName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nCarriedAmmoCount, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, m_DryFireSoundCue )
			ADD_OBJECT( SoundCue, m_ReloadAmmoSoundCue )
			ADD_VAR( ::FloatProperty, m_fPctTimeBeforeReload, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fReloadTime, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nCarriedAmmo, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nLowAmmoWarning, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nTracerInterval, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bCanZoom, 0x80 )
			ADD_VAR( ::BoolProperty, m_bPendingReload, 0x10 )
			ADD_VAR( ::BoolProperty, m_bReloadSingles, 0x8 )
			ADD_VAR( ::BoolProperty, m_bLowAmmoOn, 0x4 )
			ADD_VAR( ::FloatProperty, m_fAccuracyCorrectionRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAimingModeAccuracyBonus, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossOnShot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossOnWeaponSwitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fAccuracyLossOnJump, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDefaultAccuracy, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fCachedFiringCone, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nFiringConeWidthDegrees, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_ShotsFired, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nAltReticuleIndex, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, DBWeaponId, 0xFFFFFFFF )
			float GetTargetAccuracy(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.GetTargetAccuracy" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void RestoreAccuracy( float fTimeStep )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.RestoreAccuracy" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )( params + 0 ) = fTimeStep;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void InitVehicleGun(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.InitVehicleGun" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			float CalculateReloadTime(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.CalculateReloadTime" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( float* )( params + function->return_val_offset() );
			}

			void PostBeginPlay(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.PostBeginPlay" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.StartFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool IsWeaponInFiringCone(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.IsWeaponInFiringCone" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			class Projectile* ProjectileFire(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.ProjectileFire" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class Projectile** )( params + function->return_val_offset() );
			}

			ScriptClass* GetProjectileClass(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.GetProjectileClass" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptClass** )( params + function->return_val_offset() );
			}

			void UpdateShotsFired( bool Reset )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.UpdateShotsFired" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )( params + 0 ) = Reset;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int GetNumRoundsCurrentlyInClip(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.GetNumRoundsCurrentlyInClip" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			Vector GetEffectLocation(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.GetEffectLocation" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void AttachMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.AttachMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void MuzzleFlashTimer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.MuzzleFlashTimer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CauseMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.CauseMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopMuzzleFlash(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.StopMuzzleFlash" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayFireEffects( byte FireModeNum, Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.PlayFireEffects" );
				byte *params = ( byte* )( malloc( 13 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				*( Vector* )( params + 4 ) = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ShakeView(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.ShakeView" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool ShouldFireTracer(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.ShouldFireTracer" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			bool ShouldFireTracerBeam(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.ShouldFireTracerBeam" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( bool* )( params + function->return_val_offset() );
			}

			void SpawnTracerBeam( Vector Start, Vector End )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.SpawnTracerBeam" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = Start;
				*( Vector* )( params + 12 ) = End;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrProj_Tracer* SpawnTracerEffect( Vector HitLocation, float HitDistance )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.SpawnTracerEffect" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Vector* )( params + 0 ) = HitLocation;
				*( float* )( params + 12 ) = HitDistance;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProj_Tracer** )( params + function->return_val_offset() );
			}

			void WeaponPlaySoundLocal( class SoundCue* Sound, float NoiseLoudness, bool bStopWhenOwnerDestroyed )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.WeaponPlaySoundLocal" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( class SoundCue** )( params + 0 ) = Sound;
				*( float* )( params + 4 ) = NoiseLoudness;
				*( bool* )( params + 8 ) = bStopWhenOwnerDestroyed;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			class TrProj_Tracer* GetTracer( Vector SpawnLocation, Rotator SpawnRotation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.GetTracer" );
				byte *params = ( byte* )( malloc( 24 ) );
				*( Vector* )( params + 0 ) = SpawnLocation;
				*( Rotator* )( params + 12 ) = SpawnRotation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( class TrProj_Tracer** )( params + function->return_val_offset() );
			}

			void PayAccuracyForShot(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.PayAccuracyForShot" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Rotator AddSpreadWithAccuracy( Rotator BaseAim, float fAccuracy )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.AddSpreadWithAccuracy" );
				byte *params = ( byte* )( malloc( 16 ) );
				*( Rotator* )( params + 0 ) = BaseAim;
				*( float* )( params + 12 ) = fAccuracy;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator GetAdjustedAim( Vector StartFireLoc )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.GetAdjustedAim" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )( params + 0 ) = StartFireLoc;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			Rotator AddSpread( Rotator BaseAim )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.AddSpread" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Rotator* )( params + 0 ) = BaseAim;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Rotator* )( params + function->return_val_offset() );
			}

			void FireAmmunition(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.FireAmmunition" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginFire( byte FireModeNum )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.BeginFire" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )( params + 0 ) = FireModeNum;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PutDownWeapon(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.PutDownWeapon" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void RequestReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.RequestReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnClientReloaded(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.OnClientReloaded" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClientFinishedReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.ClientFinishedReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void OnReloadComplete(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.OnReloadComplete" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void BeginAReload(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.BeginAReload" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			int AddCarriedAmmo( int Amount )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.AddCarriedAmmo" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )( params + 0 ) = Amount;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( int* )( params + function->return_val_offset() );
			}

			void UpdateReplicatedCarriedAmmo(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.UpdateReplicatedCarriedAmmo" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StartZoom( class UTPlayerController* PC )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.StartZoom" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void EndZoom( class UTPlayerController* PC, bool bReturningTo3P )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.EndZoom" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( class UTPlayerController** )( params + 0 ) = PC;
				*( bool* )( params + 4 ) = bReturningTo3P;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SetAltReticule(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.SetAltReticule" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ResetAltReticule(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrVehicleWeapon.ResetAltReticule" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
