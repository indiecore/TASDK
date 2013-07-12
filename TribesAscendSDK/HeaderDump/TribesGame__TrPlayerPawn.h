#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " TribesGame.TrPlayerPawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty TribesGame.TrPlayerPawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty TribesGame.TrPlayerPawn." #y ) ); \
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
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
