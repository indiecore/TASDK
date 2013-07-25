#pragma once
#include "Engine__ParticleSystem.h"
#include "Engine__Actor.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "TribesGame__TrValueModifier.h"
#include "Engine__SkeletalMesh.h"
#include "TribesGame__TrInventoryHelper.h"
#include "TribesGame__TrStatsInterface.h"
#include "Engine__TeamInfo.h"
#include "UTGame__UTCarriedObject.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrPlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrPlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPlayerReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerReplicationInfo : public UTPlayerReplicationInfo
	{
	public:
		ADD_VAR(::IntProperty, m_nCreditsEarned, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nKills, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nAssists, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nArenaSpawnsLeft, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, r_bIsCrossedOffArenaList, 0x8)
		ADD_OBJECT(Actor, m_LockedTarget)
		ADD_VAR(::BoolProperty, c_bIsBuddyToLocalPlayer, 0x2)
		ADD_VAR(::BoolProperty, c_bIsMutualBuddiesWithLocalPlayer, 0x4)
		ADD_VAR(::BoolProperty, r_bIsLastManStanding, 0x10)
		ADD_VAR(::IntProperty, m_nFreeCredits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCurrentCredits, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, r_VoiceClass)
		ADD_VAR(::IntProperty, m_nRabbitRank, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPlayerIconIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_bSkinId, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, c_Cached1PSkin)
		ADD_OBJECT(ScriptClass, c_Cached3PSkin)
		ADD_OBJECT(TrValueModifier, m_ValueModifier)
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.TrPlayerReplicationInfo.EquipLevel' for the property named 'r_EquipLevels'!
		ADD_VAR(::FloatProperty, c_fRedFlagTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, c_fRedFlagPingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, c_fRedFlagPingThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, c_fCurrentPingMS, 0xFFFFFFFF)
		ADD_OBJECT(TrInventoryHelper, InvHelper)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_VAR(::ByteProperty, m_ArmorType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDevUpgrades, 0x1)
		ADD_VAR(::IntProperty, m_nPlayerClassId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nBaseXP, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nBaseGP, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRankIconIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRankNum, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, m_PendingBaseClass)
		ADD_OBJECT(ScriptClass, m_CurrentBaseClass)
		ADD_OBJECT(ScriptClass, m_Rank)
		ADD_VAR(::IntProperty, m_PendingLoadout, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_CurrentLoadout, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetPlayerRank'
		// Here lies the not-yet-implemented method 'GetCurrentClass'
		// Here lies the not-yet-implemented method 'GetEquipDevice'
		// Here lies the not-yet-implemented method 'GetRankIcon'
		// Here lies the not-yet-implemented method 'GetCurrentValueModifier'
		// Here lies the not-yet-implemented method 'GetEquipPointByWeaponId'
		// Here lies the not-yet-implemented method 'GetArmorType'
		// Here lies the not-yet-implemented method 'GetCurrentSkinClass'
		// Here lies the not-yet-implemented method 'GetGibMesh'
		// Here lies the not-yet-implemented method 'Get3PSkin'
		// Here lies the not-yet-implemented method 'GetBodyMesh'
		// Here lies the not-yet-implemented method 'GetHandsMesh'
		// Here lies the not-yet-implemented method 'GetSkiThrust'
		// Here lies the not-yet-implemented method 'GetJetpackSocketCount'
		// Here lies the not-yet-implemented method 'GetJetpackThrust'
		// Here lies the not-yet-implemented method 'GetJetpackSocket'
		// Here lies the not-yet-implemented method 'GetJetpackTrail'
		// Here lies the not-yet-implemented method 'RequestLoadoutChange'
		// Here lies the not-yet-implemented method 'VerifyCharacter'
		// Here lies the not-yet-implemented method 'GetCharacterEquip'
		// Here lies the not-yet-implemented method 'GetCharacterEquipLocal'
		// Here lies the not-yet-implemented method 'GetUpgradeLevel'
		// Here lies the not-yet-implemented method 'GetUpgradeLevelLocal'
		// Here lies the not-yet-implemented method 'UpdatePing'
		// Here lies the not-yet-implemented method 'RegisterBuddy'
		// Here lies the not-yet-implemented method 'Load1PData'
		// Here lies the not-yet-implemented method 'ReplicatedEvent'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'RegisterPlayerWithSession'
		// Here lies the not-yet-implemented method 'UpdateValueModifier'
		// Here lies the not-yet-implemented method 'Reset'
		// Here lies the not-yet-implemented method 'SetPlayerTeam'
		// Here lies the not-yet-implemented method 'SwapToPendingCharClass'
		// Here lies the not-yet-implemented method 'VerifyAndLoadCharacter'
		// Here lies the not-yet-implemented method 'GetSelectedLoadout'
		// Here lies the not-yet-implemented method 'ShouldVisitStation'
		// Here lies the not-yet-implemented method 'ResolveDefaultEquip'
		// Here lies the not-yet-implemented method 'SetActiveEquip'
		// Here lies the not-yet-implemented method 'IncrementKills'
		// Here lies the not-yet-implemented method 'CheckMultiKill'
		// Here lies the not-yet-implemented method 'GetPlayerClassId'
		// Here lies the not-yet-implemented method 'GetPendingClass'
		// Here lies the not-yet-implemented method 'GetCurrentClassAbb'
		// Here lies the not-yet-implemented method 'GetPlayerRankNum'
		// Here lies the not-yet-implemented method 'GetBaseGP'
		// Here lies the not-yet-implemented method 'GetBaseXP'
		// Here lies the not-yet-implemented method 'SetPlayerGP'
		// Here lies the not-yet-implemented method 'SetPlayerXP'
		// Here lies the not-yet-implemented method 'GetRankFromXP'
		// Here lies the not-yet-implemented method 'GetPerkFromId'
		// Here lies the not-yet-implemented method 'SetFlag'
		// Here lies the not-yet-implemented method 'Duplicate'
		// Here lies the not-yet-implemented method 'CopyProperties'
		// Here lies the not-yet-implemented method 'SetCached3PSkin'
		// Here lies the not-yet-implemented method 'GetCurrentVoiceClass'
		// Here lies the not-yet-implemented method 'UpdateCachedSkin'
		// Here lies the not-yet-implemented method 'On3PSkinContentLoaded'
		// Here lies the not-yet-implemented method 'On1PSkinContentLoaded'
		// Here lies the not-yet-implemented method 'Update1PMesh'
		// Here lies the not-yet-implemented method 'OnPingRedFlagged'
		// Here lies the not-yet-implemented method 'ServerPingRedFlag'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
