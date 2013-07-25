#pragma once
#include "Engine__Info.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrServerSettingsInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrServerSettingsInfo : public Info
	{
	public:
		ADD_VAR(::BoolProperty, bObjectiveUpgrades, 0x4)
		ADD_VAR(::BoolProperty, bPreplacedObjectives, 0x20)
		ADD_VAR(::BoolProperty, bFriendlyFireDeployables, 0x100)
		ADD_VAR(::BoolProperty, bPoweredDeployables, 0x8)
		ADD_VAR(::BoolProperty, bFriendlyFireBaseAssets, 0x80)
		ADD_VAR(::IntProperty, BaseDestructionLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxSpeedWithFlagLight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxSpeedWithFlagMedium, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxSpeedWithFlagHeavy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DecelerationRateWithFlag, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSupplyDropAmmoOnly, 0x200)
		ADD_VAR(::FloatProperty, fEnergyMultiplier, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTeamCredits, 0x800)
		ADD_VAR(::IntProperty, RespawnTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TeamAssignType, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VehiclePrices, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FFKillLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FFDamageLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CallinPrices, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CallinBuildups, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CallinCooldowns, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, OvertimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, WarmupTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoBalanceInGame, 0x2)
		ADD_VAR(::FloatProperty, fFriendlyFireDamageMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ArenaRounds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GameScores, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCTFBlitzAllFlagsMove, 0x2000)
		ADD_VAR(::BoolProperty, bFriendlyFire, 0x1)
		ADD_VAR(::BoolProperty, bPoweredCallins, 0x400)
		ADD_VAR(::BoolProperty, bSkiEnabled, 0x1000)
		ADD_VAR(::IntProperty, SpawnType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bGeneratorAutoRegen, 0x10)
		ADD_VAR(::BoolProperty, bGenDestroyable, 0x40)
		ADD_VAR(::FloatProperty, fAoEDamageMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fAoESizeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, fVehicleHealthMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CallinsDenied, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, VehicleLimits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ClassCounts, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPlayers, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ScoreLimit, 0xFFFFFFFF)
		int GetClassCount(byte ClassType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.GetClassCount");
			byte* params = (byte*)malloc(5);
			*params = ClassType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsCallinAllowed(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.IsCallinAllowed");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsClassAllowed(byte ClassType, int CurrentCount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.IsClassAllowed");
			byte* params = (byte*)malloc(9);
			*params = ClassType;
			*(int*)(params + 4) = CurrentCount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetPropAsFloat(int PropId, float& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.GetPropAsFloat");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropId;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(float*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetPropAsInt(int PropId, int& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.GetPropAsInt");
			byte* params = (byte*)malloc(12);
			*(int*)params = PropId;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(int*)(params + 4);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetPropAsString(int PropId, ScriptArray<wchar_t>& Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.GetPropAsString");
			byte* params = (byte*)malloc(20);
			*(int*)params = PropId;
			*(ScriptArray<wchar_t>*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Value = *(ScriptArray<wchar_t>*)(params + 4);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.LoadServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetVehicleLimit(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrServerSettingsInfo.GetVehicleLimit");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
