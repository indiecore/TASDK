#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrValueModifier." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrValueModifier : public Object
	{
	public:
		ADD_VAR(::FloatProperty, m_fWeaponSwitchPctBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPrimaryWeaponReloadBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSecondaryWeaponReloadBuffPct, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPrimaryWeaponIncreasedClipSizeBuff, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nSecondaryWeaponIncreasedClipSizeBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fUpgradeCostBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPrimaryWeaponArmorPenetrationBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSecondaryWeaponArmorPenetrationBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOffhandArmorPenetrationBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeployableHealthBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeployableRangeBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTurretAcquireTargetBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAcquireTimeByEnemyTurretPctBuff, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nExtraOffhandAmmo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nExtraGrenadesFromPickupBuff, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nExtraPrimaryAmmo, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nExtraSecondaryAmmo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxJettingSpeedBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTerminalJettingSpeedBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxSkiSpeedBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTerminalSkiSpeedBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPeakSkiControlSpeedBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiControlSigmaSquareBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxSkiControlBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fGroundSpeedPctBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxStoppingDistancePctBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMassPctBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fExtraEnergyBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fEnergyRegenRateBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTimeToRegenHealthBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSplatDamageBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStealthPackPulseTimeBuffPct, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bHasDetermination, 0x10)
		ADD_VAR(::FloatProperty, m_fHealthRegenRateBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShieldPackEffectivenessBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fReceiveMeleeDamageBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSelfDamagePct, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIgnoreGrenadeSecondaryOnSelf, 0x2000)
		ADD_VAR(::FloatProperty, m_fEnergyDrainPctBuff, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bPotentialEnergy, 0x100)
		ADD_VAR(::BoolProperty, m_bPotentialEnergyFallDamage, 0x200)
		ADD_VAR(::FloatProperty, m_fPotentialEnergyDamageTransferPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fWhiteOutInterpSpeedPctBuff, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bStickyHands, 0x1)
		ADD_VAR(::BoolProperty, m_bRadarLink, 0x400)
		ADD_VAR(::FloatProperty, m_fIgnorePulseTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bRage, 0x8000)
		ADD_VAR(::FloatProperty, m_fRageEnergyRegenBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRageHealthRestorationPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRageMassPctBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRageLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fJammerPackRadiusPctBuff, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bClothesline, 0x80)
		ADD_VAR(::BoolProperty, m_bFlagReach, 0x800)
		ADD_VAR(::IntProperty, m_nFlagReachTier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nExtraCreditsFromBeltKills, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCreditsFromKillsBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleCostBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSensorDistancePctBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPackEnergyCostBuffPct, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nExtraDeployablesOutBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFasterThrowBeltBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOffhandDamageRadiusBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBlinkPackPotencyBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBuildupBuffPct, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bSonicPunch, 0x4000)
		ADD_VAR(::FloatProperty, m_fSonicPunchDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSonicPunchKnockback, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBackstabMeleeDamagePctBuff, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bVictimDropFlagOnMelee, 0x20)
		ADD_VAR(::BoolProperty, m_bCanDamageRepairEnemyObjectives, 0x8)
		ADD_VAR(::FloatProperty, m_fRepairRateBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPrimaryWeaponRangeBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSecondaryWeaponRangeBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAmmoFromPickupBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthFromPickupBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fEnergyFromPickupBuffPct, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bAmmoPickupReach, 0x1000)
		ADD_VAR(::IntProperty, m_nExtraMinesOutBuff, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bCanDetectTraps, 0x4)
		ADD_VAR(::FloatProperty, m_fRepairDeployableRateBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPrimaryWeaponEnergyCostPctBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDeployedTurretArmorPenetrationBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMultiCrewedVehicleDamageProtectionPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleRunOverDamageProtectionPct, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bEjectionSeat, 0x40)
		ADD_VAR(::BoolProperty, m_bCanCallInSupplyDrop, 0x2)
		ADD_VAR(::FloatProperty, m_fTimeToRegenEnergyBuff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleExtraEnergyBuffPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleExtraHealthBuffPct, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DatabaseItemId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, IconId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Description, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyName, 0xFFFFFFFF)
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrValueModifier.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Merge(class TrValueModifier* ModifierToMerge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrValueModifier.Merge");
			byte* params = (byte*)malloc(4);
			*(class TrValueModifier**)params = ModifierToMerge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MergeClass(ScriptClass* ModifierClassToMerge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrValueModifier.MergeClass");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = ModifierClassToMerge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MergeModification(int ModType, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrValueModifier.MergeModification");
			byte* params = (byte*)malloc(8);
			*(int*)params = ModType;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogModifiedValues()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrValueModifier.LogModifiedValues");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
