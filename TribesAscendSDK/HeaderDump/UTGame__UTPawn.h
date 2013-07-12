#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( #x " UTGame.UTPawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "StructProperty UTGame.UTPawn." #y ) ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ( ScriptProperty* )( ScriptObject::Find( "ObjectProperty UTGame.UTPawn." #y ) ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTPawn : public UDKPawn
	{
	public:
			ADD_VAR( ::FloatProperty, CurrentCameraScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, WalkBob, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, VestArmor, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShieldBeltArmor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bIsInvulnerable, 0x40 )
			ADD_VAR( ::BoolProperty, bFixedView, 0x1 )
			ADD_STRUCT( ::VectorProperty, FixedViewLoc, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, FixedViewRot, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LandBob, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bJustLanded, 0x400 )
			ADD_VAR( ::BoolProperty, bLandRecovery, 0x800 )
			ADD_VAR( ::BoolProperty, bArmsAttached, 0x20000 )
			ADD_VAR( ::BoolProperty, bStopDeathCamera, 0x2000 )
			ADD_VAR( ::FloatProperty, LastPainSound, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MapSize, 0xFFFFFFFF )
			ADD_OBJECT( UTWeaponAttachment, CurrentWeaponAttachment )
			ADD_VAR( ::FloatProperty, DefaultMeshScale, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bReceivedValidTeam, 0x200000 )
			ADD_OBJECT( AnimNodeBlend, FeignDeathBlend )
			ADD_OBJECT( AnimNodeSlot, FullBodyAnimSlot )
			ADD_OBJECT( AnimNodeSlot, TopHalfAnimSlot )
			ADD_OBJECT( UTAnimBlendByDriving, DrivingNode )
			ADD_OBJECT( UTAnimBlendByVehicle, VehicleNode )
			ADD_OBJECT( UTAnimBlendByHoverboarding, HoverboardingNode )
			ADD_VAR( ::BoolProperty, bWeaponBob, 0x200 )
			ADD_VAR( ::FloatProperty, JumpBob, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, TauntNames, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, bobtime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, Bob, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AppliedBob, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWeaponAttachmentVisible, 0x40000 )
			ADD_VAR( ::BoolProperty, bSpawnDone, 0x2 )
			ADD_VAR( ::BoolProperty, bSpawnIn, 0x4 )
			ADD_OBJECT( SoundCue, SpawnSound )
			ADD_OBJECT( SoundCue, TeleportSound )
			ADD_OBJECT( CameraAnim, TransCameraAnim )
			ADD_OBJECT( UTClientSideWeaponPawn, ClientSideWeaponPawn )
			ADD_VAR( ::FloatProperty, ThighpadArmor, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShieldAbsorb, 0x8 )
			ADD_OBJECT( SoundCue, ArmorHitSound )
			ADD_VAR( ::BoolProperty, bJustDroppedOrb, 0x80 )
			ADD_VAR( ::FloatProperty, MaxFootstepDistSq, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxJumpSoundDistSq, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHeadGibbed, 0x10000 )
			ADD_VAR( ::BoolProperty, bGibbed, 0x8000 )
			ADD_VAR( ::FloatProperty, DeathTime, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bForcedFeignDeath, 0x100 )
			ADD_VAR( ::BoolProperty, bHideOnListenServer, 0x80000 )
			ADD_VAR( ::FloatProperty, DeathHipLinSpring, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeathHipLinDamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeathHipAngSpring, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DeathHipAngDamp, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StartDeathAnimTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TimeLastTookDeathAnimDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraZOffset, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bWinnerCam, 0x4000 )
			ADD_VAR( ::IntProperty, HeroCameraPitch, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeroCameraScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, CamOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DodgeSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DodgeSpeedZ, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bDodging, 0x10 )
			ADD_VAR( ::IntProperty, JumpBootCharge, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, CurrentDir, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleJumpEyeHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DoubleJumpThreshold, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bStopOnDoubleLanding, 0x20 )
			ADD_VAR( ::FloatProperty, DefaultAirControl, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInterface, ShieldBeltTeamMaterialInstances )
			ADD_OBJECT( MaterialInterface, ShieldBeltMaterialInstance )
			ADD_VAR( ::FloatProperty, FeignDeathStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FeignDeathBodyAtRestSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, UnfeignFailedCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FeignDeathRecoveryStartTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, HeadBone, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bKillsAffectHead, 0x400000 )
			ADD_OBJECT( UTProjectile, AttachedProj )
			ADD_VAR( ::FloatProperty, AccumulationTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, AccumulateDamage, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bHasHoverboard, 0x1000 )
			ADD_VAR( ::FloatProperty, LastHoverboardTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MinHoverboardInterval, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeadHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeadRadius, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraScaleMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CameraScaleMax, 0xFFFFFFFF )
			ADD_OBJECT( ForceFeedbackWaveform, FallingDamageWaveForm )
			ADD_STRUCT( ::VectorProperty, OldCameraPosition, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bKilledByBio, 0x800000 )
			ADD_VAR( ::FloatProperty, BioBurnAwayTime, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, BioEffectName, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RagdollLifespan, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bPostRenderTraceSucceeded, 0x100000 )
			ADD_VAR( ::IntProperty, SuperHealthMax, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, WeaponSocket, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, WeaponSocket2, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, PawnEffectSockets, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, HeadOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TeamBeaconPlayerInfoMaxDist, 0xFFFFFFFF )
			ADD_OBJECT( Texture, SpeakingBeaconTexture )
			ADD_VAR( ::FloatProperty, DesiredMeshScale, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
