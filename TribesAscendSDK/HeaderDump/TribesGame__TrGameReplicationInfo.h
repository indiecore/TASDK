#pragma once
#include "Engine__Actor.h"
#include "TribesGame__TrDaDCore.h"
#include "UTGame__UTGameReplicationInfo.h"
#include "TribesGame__TrServerSettingsInfo.h"
#include "TribesGame__TrPlayerReplicationInfo.h"
#include "TribesGame__TrObjectPool.h"
#include "TribesGame__TrFlagBase.h"
#include "Engine__PlayerReplicationInfo.h"
#include "TribesGame__TrDaDCapacitor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameReplicationInfo : public UTGameReplicationInfo
	{
	public:
		ADD_OBJECT(TrServerSettingsInfo, r_ServerConfig)
		ADD_OBJECT(TrPlayerReplicationInfo, r_BEPlayerList)
		ADD_OBJECT(TrPlayerReplicationInfo, r_DSPlayerList)
		ADD_VAR(::IntProperty, r_nRoundScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nCurrentRound, 0xFFFFFFFF)
		ADD_OBJECT(TrObjectPool, m_TrObjectPool)
		ADD_VAR(::ByteProperty, r_PhysType, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentSensorBlipOpacity, 0xFFFFFFFF)
		ADD_OBJECT(TrFlagBase, m_Flags)
		ADD_VAR(::BoolProperty, r_bSkiEnabled, 0x10)
		ADD_VAR(::IntProperty, r_nNumCapturePointsHeld, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GeneratorPower, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bPoweredCallins, 0x2)
		ADD_OBJECT(PlayerReplicationInfo, m_CurrentRabbitPRI)
		ADD_OBJECT(TrDaDCore, r_DaDCore)
		ADD_OBJECT(TrDaDCapacitor, r_DaDCapacitorBE)
		ADD_OBJECT(TrDaDCapacitor, r_DaDCapacitorDS)
		ADD_VAR(::IntProperty, FlagReturnTime, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, m_RabbitLeaderBoard)
		ADD_VAR(::IntProperty, r_CarrierCoreHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_CarrierShieldHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalMaxJetpackThrustSpeedMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalAirSpeedMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalAccelerationMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fGlobalSpeedCapMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSensorBlipFadeSpeed, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nBlip, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_nPhase0SeigeEnded, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_ResetGame, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGivePerfBonus, 0x8)
		ADD_VAR(::BoolProperty, bGivePrivateXP, 0x4)
		ADD_VAR(::BoolProperty, r_bCanPlaceDeployables, 0x1)
		ADD_VAR(::IntProperty, GeneratorDowntime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IsClassAllowed'
		// Here lies the not-yet-implemented method 'GetTeamSize'
		// Here lies the not-yet-implemented method 'CanJoinTeam'
		// Here lies the not-yet-implemented method 'GetGlobalSpeedCapMultiplier'
		// Here lies the not-yet-implemented method 'GetGlobalAccelerationMultiplier'
		// Here lies the not-yet-implemented method 'GetGlobalAirSpeedMultiplier'
		// Here lies the not-yet-implemented method 'GetGlobalMaxJetpackThrustSpeedMultiplier'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PreBeginPlay'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'ApplyServerSettings'
		// Here lies the not-yet-implemented method 'CanPlaceDeployables'
		// Here lies the not-yet-implemented method 'OnPhase0SiegeEnded'
		// Here lies the not-yet-implemented method 'OnResetGame'
		// Here lies the not-yet-implemented method 'Timer'
		// Here lies the not-yet-implemented method 'OnSameTeam'
		// Here lies the not-yet-implemented method 'Blip'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'ChangePhysicsType'
		// Here lies the not-yet-implemented method 'IsValidTeamPlayer'
		// Here lies the not-yet-implemented method 'SetWarmingUp'
		// Here lies the not-yet-implemented method 'AddPRI'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
