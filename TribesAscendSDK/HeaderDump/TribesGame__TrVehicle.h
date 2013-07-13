#pragma once
#define ADD_VAR( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( #x " TribesGame.TrVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_STRUCT( x, y, z ) ( ##x ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "StructProperty TribesGame.TrVehicle." #y ); \
	return ( ##x( this, script_property->offset, z ) ); \
}
#define ADD_OBJECT( x, y ) ( class x* ) var_##y() \
{ \
	static ScriptProperty *script_property = ScriptObject::Find< ScriptProperty >( "ObjectProperty TribesGame.TrVehicle." #y ); \
	return *( x** )( this + script_property->offset ); \
}
namespace UnrealScript
{
	class TrVehicle : public UTVehicle
	{
	public:
			ADD_VAR( ::FloatProperty, m_fCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_sName, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nIconIndex, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bClientPhysDirty, 0x100 )
			ADD_VAR( ::BoolProperty, m_bServerCorrectionForce, 0x200 )
			ADD_VAR( ::BoolProperty, m_bImprovedLagSupport, 0x4 )
			ADD_VAR( ::ByteProperty, m_VehicleType, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, m_bUsesArmoredMultiplier, 0x80 )
			ADD_VAR( ::StrProperty, m_sWeapon1Name, 0xFFFFFFFF )
			ADD_VAR( ::StrProperty, m_sWeapon2Name, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fMaxPawnLeaveSpeed, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nDetectedByEnemyScannerCount, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, m_nServerTickCount, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fClientPhysDeltaTime, 0xFFFFFFFF )
			ADD_OBJECT( TrStatsInterface, Stats )
			ADD_STRUCT( ::VectorProperty, m_vDeathCamStartOffset, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarHeight, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarWidth, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarPlacementY, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleHealthBarPlacementX, 0xFFFFFFFF )
			ADD_OBJECT( MaterialInstanceConstant, m_MarkerMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger4HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger3HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger2HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_Passenger1HealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_DriverHealthBarMIC )
			ADD_OBJECT( MaterialInstanceConstant, m_HealthBarMIC )
			ADD_VAR( ::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_STRUCT( ::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fContrailSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostFadeOutTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostFadeInTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fDivingMaxSpeedMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::IntProperty, r_nBaseMaxSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallDamageTickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastWallDamageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMaxDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMinDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMinDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fWallMaxDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleDamageTickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fLastVehicleDamageTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMaxDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMinDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMinDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fVehicleMaxDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnDamageTickTime, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnMaxDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnMinDamage, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnMaxDamageSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPawnPushSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fFlagPushSpeed, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_CrashDamageSeverity, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPowerPoolTickRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fPowerPoolRechargeRate, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, r_fCurrentPowerPool, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostReactivatePct, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostEnergyPerSec, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fBoostMultiplier, 0xFFFFFFFF )
			ADD_VAR( ::FloatProperty, m_fTimeToReset, 0xFFFFFFFF )
			ADD_OBJECT( TrVehicleStation, m_OwnerStation )
			ADD_VAR( ::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF )
			ADD_VAR( ::ByteProperty, r_MissileLock, 0xFFFFFFFF )
			ADD_VAR( ::BoolProperty, r_bDetectedByEnemyScanner, 0x400 )
			ADD_VAR( ::BoolProperty, r_LevelFlightEnabled, 0x40 )
			ADD_VAR( ::BoolProperty, m_bLowPowerPool, 0x20 )
			ADD_VAR( ::BoolProperty, r_BoostersEnabled, 0x10 )
			ADD_VAR( ::BoolProperty, r_bIsInvulnerable, 0x8 )
			ADD_VAR( ::BoolProperty, m_bBoostRequiresThrust, 0x2 )
			ADD_VAR( ::BoolProperty, m_bPostSpawnLocked, 0x1 )
			ADD_OBJECT( TrPawn, m_PawnToTeleport )
			ADD_OBJECT( Pawn, Passenger )
	};
}

#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
