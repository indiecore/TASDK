#pragma once
#include "UTGame__UTPlayerReplicationInfo.h"
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
		ADD_VAR(::IntProperty, m_nRabbitRank, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPlayerIconIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_bSkinId, 0xFFFFFFFF)
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
		ADD_VAR(::IntProperty, m_PendingLoadout, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_CurrentLoadout, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
