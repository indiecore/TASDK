#pragma once
#include "UTGame.UTPlayerReplicationInfo.h"
#include "TribesGame.TrStatsInterface.h"
#include "Engine.Actor.h"
#include "TribesGame.TrValueModifier.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.TeamInfo.h"
#include "TribesGame.TrInventoryHelper.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.ParticleSystem.h"
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
		ScriptClass* GetPlayerRank()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPlayerRank");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetCurrentClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetEquipDevice(ScriptClass* FamilyInfo, byte equipSlot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetEquipDevice");
			byte* params = (byte*)malloc(9);
			*(ScriptClass**)params = FamilyInfo;
			*(params + 4) = equipSlot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 8);
			free(params);
			return returnVal;
		}
		int GetRankIcon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetRankIcon");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		class TrValueModifier* GetCurrentValueModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentValueModifier");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrValueModifier**)params;
			free(params);
			return returnVal;
		}
		byte GetEquipPointByWeaponId(int WeaponId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetEquipPointByWeaponId");
			byte* params = (byte*)malloc(5);
			*(int*)params = WeaponId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		byte GetArmorType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetArmorType");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetCurrentSkinClass(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentSkinClass");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		class SkeletalMesh* GetGibMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetGibMesh");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMesh**)(params + 4);
			free(params);
			return returnVal;
		}
		class SkeletalMesh* Get3PSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Get3PSkin");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMesh**)params;
			free(params);
			return returnVal;
		}
		class SkeletalMesh* GetBodyMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetBodyMesh");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMesh**)params;
			free(params);
			return returnVal;
		}
		class SkeletalMesh* GetHandsMesh()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetHandsMesh");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SkeletalMesh**)params;
			free(params);
			return returnVal;
		}
		class ParticleSystem* GetSkiThrust(ScriptClass* FamilyInfo, class ParticleSystem* DefaultSystem)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetSkiThrust");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = FamilyInfo;
			*(class ParticleSystem**)(params + 4) = DefaultSystem;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ParticleSystem**)(params + 8);
			free(params);
			return returnVal;
		}
		int GetJetpackSocketCount(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackSocketCount");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		class ParticleSystem* GetJetpackThrust(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackThrust");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ParticleSystem**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptName GetJetpackSocket(ScriptClass* FamilyInfo, int Socket)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackSocket");
			byte* params = (byte*)malloc(16);
			*(ScriptClass**)params = FamilyInfo;
			*(int*)(params + 4) = Socket;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)(params + 8);
			free(params);
			return returnVal;
		}
		class ParticleSystem* GetJetpackTrail(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetJetpackTrail");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ParticleSystem**)(params + 4);
			free(params);
			return returnVal;
		}
		bool RequestLoadoutChange(ScriptClass* FamilyInfo, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.RequestLoadoutChange");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = FamilyInfo;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool VerifyCharacter(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.VerifyCharacter");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GetCharacterEquip(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquip");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetCharacterEquipLocal(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCharacterEquipLocal");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetUpgradeLevel(int ClassId, int Type, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* UpgradeList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetUpgradeLevel");
			byte* params = (byte*)malloc(24);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = UpgradeList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 20);
			free(params);
			return returnVal;
		}
		int GetUpgradeLevelLocal(int ClassId, int Type, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* UpgradeList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetUpgradeLevelLocal");
			byte* params = (byte*)malloc(24);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = UpgradeList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 20);
			free(params);
			return returnVal;
		}
		void UpdatePing(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.UpdatePing");
			byte* params = (byte*)malloc(4);
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RegisterBuddy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.RegisterBuddy");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptClass* Load1PData(ScriptArray<wchar_t> ContentPath)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Load1PData");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = ContentPath;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 12);
			free(params);
			return returnVal;
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterPlayerWithSession()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.RegisterPlayerWithSession");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateValueModifier()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.UpdateValueModifier");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetPlayerTeam(class TeamInfo* NewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetPlayerTeam");
			byte* params = (byte*)malloc(4);
			*(class TeamInfo**)params = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwapToPendingCharClass(bool bIsRespawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SwapToPendingCharClass");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsRespawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool VerifyAndLoadCharacter(ScriptClass* FamilyInfo, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.VerifyAndLoadCharacter");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = FamilyInfo;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetSelectedLoadout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetSelectedLoadout");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool ShouldVisitStation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ShouldVisitStation");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ResolveDefaultEquip(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ResolveDefaultEquip");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetActiveEquip(byte EquipId, int ItemId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetActiveEquip");
			byte* params = (byte*)malloc(5);
			*params = EquipId;
			*(int*)(params + 4) = ItemId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementKills(bool bEnemyKill)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.IncrementKills");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnemyKill;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckMultiKill()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.CheckMultiKill");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetPlayerClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPlayerClassId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptClass* GetPendingClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPendingClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetCurrentClassAbb()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentClassAbb");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		int GetPlayerRankNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPlayerRankNum");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetBaseGP()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetBaseGP");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetBaseXP()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetBaseXP");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void SetPlayerGP(int GP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetPlayerGP");
			byte* params = (byte*)malloc(4);
			*(int*)params = GP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerXP(int XP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetPlayerXP");
			byte* params = (byte*)malloc(4);
			*(int*)params = XP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptClass* GetRankFromXP(int XP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetRankFromXP");
			byte* params = (byte*)malloc(8);
			*(int*)params = XP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptClass* GetPerkFromId(int PerkId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetPerkFromId");
			byte* params = (byte*)malloc(8);
			*(int*)params = PerkId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		void SetFlag(class UTCarriedObject* NewFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetFlag");
			byte* params = (byte*)malloc(4);
			*(class UTCarriedObject**)params = NewFlag;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class PlayerReplicationInfo* Duplicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Duplicate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerReplicationInfo**)params;
			free(params);
			return returnVal;
		}
		void CopyProperties(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.CopyProperties");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCached3PSkin(ScriptClass* NewCachedSkin)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.SetCached3PSkin");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = NewCachedSkin;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptClass* GetCurrentVoiceClass(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.GetCurrentVoiceClass");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		void UpdateCachedSkin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.UpdateCachedSkin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void On3PSkinContentLoaded(ScriptClass* Skin3PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.On3PSkinContentLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Skin3PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void On1PSkinContentLoaded(ScriptClass* Skin1PDataClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.On1PSkinContentLoaded");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = Skin1PDataClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Update1PMesh(ScriptClass* FamilyInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.Update1PMesh");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = FamilyInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPingRedFlagged()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.OnPingRedFlagged");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPingRedFlag(float CurrentPingMS)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPlayerReplicationInfo.ServerPingRedFlag");
			byte* params = (byte*)malloc(4);
			*(float*)params = CurrentPingMS;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
