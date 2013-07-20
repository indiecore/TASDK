#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrPlayerPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrPlayerPawn." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrPlayerPawn." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrPlayerPawn : public TrPawn
	{
	public:
			ADD_VAR( ::ByteProperty, r_nFlashReloadPrimaryWeapon, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_nFlashReloadSecondaryWeapon, 0xFFFFFFFF )
			ADD_OBJECT( TrAnimNodeBlendBy3pDevice, m_3pDeviceAnimNode )
			ADD_OBJECT( TrAnimNodeBlendBy3pDevice, m_1pBodyMeshDeviceAnimNode )
			ADD_VAR( ::FloatProperty, BobGroundSpeedMultiplier2, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobGroundSpeedMultiplier1, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobTimeMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_WeaponBobMultiplier2, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_WeaponBobMultiplier1, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_BobFootstepMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_JumpBob5, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_JumpBob4, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_JumpBob3, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_JumpBob2, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_JumpBob1, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingSkiingMultiplier2, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingSkiingMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingSpeedSqThresholdSkiing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingSpeedSqThreshold, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingMultiplier5, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingMultiplier4, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingMultiplier3, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingMultiplier2, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingMultiplier1, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandingMinSmoothing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandRecoveryMultiplier2, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandRecoveryMultiplier1, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandRecoveryMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightLandRecoveryMinSmoothing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightWalkingMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_EyeHeightWalkingMinSmoothing, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_Cam3pZoomInSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_Cam3pZoomOutSpeed, 0xFFFFFFFF )
			ADD_OBJECT( Actor, m_DeathCamFocus )
			ADD_STRUCT( ::RotatorProperty, m_CamRotOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRibbonZVelocity, 0xFFFFFFFF )
			ADD_OBJECT( ParticleSystem, m_SonicPunchEffect3p )
			ADD_OBJECT( ParticleSystem, m_SonicPunchEffect1p )
			ADD_OBJECT( SoundCue, m_SonicPunch3p )
			ADD_OBJECT( SoundCue, m_SonicPunch1p )
			ADD_OBJECT( ParticleSystem, m_DefaultSkiJetParticle )
			ADD_VAR( ::FloatProperty, m_fJetpackSoundFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingJetpackSoundFadeOutTime, 0xFFFFFFFF )
			void SetCharacterClassFromInfo( ScriptClass* Info, bool bForce )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.SetCharacterClassFromInfo" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptClass** )params = Info;
				*( bool* )( params + 4 ) = bForce;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateEyeHeight( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.UpdateEyeHeight" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			ScriptName GetMaterialBelowFeetByLoc( Vector TestLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.GetMaterialBelowFeetByLoc" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = TestLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			ScriptName GetMaterialBelowFeet(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.GetMaterialBelowFeet" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( ScriptName* )( params + function->return_val_offset() );
			}

			void ActuallyPlayFootstepSound( int FootDown )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.ActuallyPlayFootstepSound" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( int* )params = FootDown;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			Vector WeaponBob( float BobDamping, float JumpDamping )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.WeaponBob" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( float* )params = BobDamping;
				*( float* )( params + 4 ) = JumpDamping;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
				return *( Vector* )( params + function->return_val_offset() );
			}

			void ReplicatedEvent( ScriptName VarName )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.ReplicatedEvent" );
				byte *params = ( byte* )( malloc( 8 ) );
				*( ScriptName* )params = VarName;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PostInitAnimTree(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.PostInitAnimTree" );
				byte *params = ( byte* )( malloc( 4 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayHardLandingEffect( Vector HitLocation )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.PlayHardLandingEffect" );
				byte *params = ( byte* )( malloc( 12 ) );
				*( Vector* )params = HitLocation;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlaySonicPunchEffect(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.PlaySonicPunchEffect" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateSkiParticleEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.CreateSkiParticleEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearSkiParticleEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.ClearSkiParticleEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlaySkiEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.PlaySkiEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopSkiEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.StopSkiEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CreateJetpackParticleEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.CreateJetpackParticleEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void ClearJetpackParticleEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.ClearJetpackParticleEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayJetpackEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.PlayJetpackEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void UpdateJetpackEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.UpdateJetpackEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void StopJetpackEffects(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.StopJetpackEffects" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void PlayReload( byte EquipPoint )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.PlayReload" );
				byte *params = ( byte* )( malloc( 1 ) );
				*( byte* )params = EquipPoint;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void Tick( float DeltaTime )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.Tick" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( float* )params = DeltaTime;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CalcCamera( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.CalcCamera" );
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

			void SetThirdPersonCamera( bool bNewBehindView )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.SetThirdPersonCamera" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bNewBehindView;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			bool CalcThirdPersonCam( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.CalcThirdPersonCam" );
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

			bool CalcOtherWatchingCam( float fDeltaTime, Vector &out_CamLoc, Rotator &out_CamRot, float &out_FOV, class TrPlayerController* WatcherController )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.CalcOtherWatchingCam" );
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

			void ClearMeshAnimSeqNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.ClearMeshAnimSeqNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void CacheMeshAnimSeqNodes(  )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.CacheMeshAnimSeqNodes" );
				byte *params = ( byte* )( malloc( 0 ) );
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

			void SuppressAnimNotifies( bool bSuppress )
			{
				static ScriptFunction *function = ScriptObject::Find< ScriptFunction >( "Function TribesGame.TrPlayerPawn.SuppressAnimNotifies" );
				byte *params = ( byte* )( malloc( 4 ) );
				*( bool* )params = bSuppress;
				ScriptObject *object = ( ScriptObject* )( this );
				object->ProcessEvent( function, params, NULL );
			}

	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
