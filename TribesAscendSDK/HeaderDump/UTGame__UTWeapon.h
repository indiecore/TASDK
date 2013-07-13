#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " UTGame.UTWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty UTGame.UTWeapon." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty UTGame.UTWeapon." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class UTWeapon : public UDKWeapon
	{
	public:
			ADD_VAR( ::ByteProperty, AmmoDisplayType, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, InventoryGroup, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, UseHintString, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bExportMenuData, 0x1 )
			ADD_VAR( ::BoolProperty, bAllowFiringWithoutController, 0x40000 )
			ADD_VAR( ::BoolProperty, bSmallWeapons, 0x8 )
			ADD_VAR( ::BoolProperty, bUseCustomCoordinates, 0x4 )
			ADD_VAR( ::FloatProperty, LastHitEnemyTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, InventoryWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, GroupWeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CrosshairScaling, 0xFFFFFFFF )
			ADD_OBJECT( Texture2D, CrosshairImage )
			ADD_VAR( ::BoolProperty, bWasLocked, 0x2 )
			ADD_VAR( ::FloatProperty, LockedStartTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentLockedScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, StartLockedScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LockedScaleTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, FinalLockedScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomedRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomedTargetFOV, 0xFFFFFFFF )
			ADD_OBJECT( AnimSet, ArmsAnimSet )
			ADD_OBJECT( ForceFeedbackWaveform, WeaponFireWaveForm )
			ADD_VAR( ::BoolProperty, bSuppressSounds, 0x40 )
			ADD_VAR( ::BoolProperty, bMuzzleFlashPSCLoops, 0x400 )
			ADD_VAR( ::NameProperty, MuzzleFlashSocket, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bShowAltMuzzlePSCWhenWeaponHidden, 0x200 )
			ADD_OBJECT( ParticleSystem, MuzzleFlashAltPSCTemplate )
			ADD_VAR( ::BoolProperty, bMuzzleFlashAttached, 0x800 )
			ADD_OBJECT( ParticleSystem, MuzzleFlashPSCTemplate )
			ADD_VAR( ::FloatProperty, MuzzleFlashDuration, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, WeaponPutDownAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ArmsPutDownAnim, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, WeaponPutDownSnd )
			ADD_VAR( ::NameProperty, WeaponEquipAnim, 0xFFFFFFFF )
			ADD_VAR( ::NameProperty, ArmsEquipAnim, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, WeaponEquipSnd )
			ADD_VAR( ::BoolProperty, bPendingShow, 0x100 )
			ADD_VAR( ::BoolProperty, bForceHidden, 0x200000 )
			ADD_STRUCT( ::VectorProperty, HiddenWeaponsOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PlayerViewOffset, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, SmallWeaponsOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WideScreenOffsetScaling, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, BobDamping, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, JumpDamping, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LastRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxYawLag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, MaxPitchLag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, LastRotUpdate, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, WidescreenRotationOffset, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, OldRotDiff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldLeadMag, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, OldMaxDiff, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, RotChgSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ReturnChgSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, CurrentRating, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, MaxAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSplashJump, 0x1000 )
			ADD_VAR( ::BoolProperty, bUsingAimingHelp, 0x20000 )
			ADD_VAR( ::FloatProperty, AimingHelpRadius, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, ZoomedFireModeNum, 0xFFFFFFFF )
			ADD_OBJECT( SoundCue, ZoomInSound )
			ADD_OBJECT( SoundCue, ZoomOutSound )
			ADD_VAR( ::FloatProperty, SwitchAbortTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ProjectileSpawnOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WeaponCanvasXPct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, WeaponCanvasYPct, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, bSuperWeapon, 0x10 )
			ADD_VAR( ::BoolProperty, bNeverForwardPendingFire, 0x20 )
			ADD_VAR( ::BoolProperty, bUsesOffhand, 0x80 )
			ADD_VAR( ::BoolProperty, bRecommendSplashDamage, 0x2000 )
			ADD_VAR( ::BoolProperty, bSniping, 0x4000 )
			ADD_VAR( ::BoolProperty, bFastRepeater, 0x8000 )
			ADD_VAR( ::BoolProperty, bLockedAimWhileFiring, 0x10000 )
			ADD_VAR( ::BoolProperty, bTargetFrictionEnabled, 0x80000 )
			ADD_VAR( ::BoolProperty, bTargetAdhesionEnabled, 0x100000 )
			ADD_VAR( ::BoolProperty, bHasLocationSpeech, 0x400000 )
			ADD_VAR( ::IntProperty, LockerAmmoCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconX, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconY, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconWidth, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, IconHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, DroppedPickupOffsetZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomFadeTime, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, PivotTranslation, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, LockerRotation, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, LockerOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, aimerror, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ZoomedTurnSpeedScalePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionDistanceMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionDistancePeak, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionDistanceMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionPeakRadiusScale, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionPeakHeightScale, 0xFFFFFFFF )
			ADD_STRUCT( ::VectorProperty, TargetFrictionOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetFrictionZoomedBoostValue, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionTimeMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionDistanceMax, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionAimDistY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionAimDistZ, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionScaleAmountMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionTargetVelocityMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionPlayerVelocityMin, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, TargetAdhesionZoomedBoostValue, 0xFFFFFFFF )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
