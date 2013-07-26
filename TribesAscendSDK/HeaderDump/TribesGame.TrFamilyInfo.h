#pragma once
#include "Core.Object.Vector2D.h"
#include "UTGame.UTFamilyInfo.h"
#include "Engine.AnimTree.h"
#include "Engine.MorphTargetSet.h"
#include "Engine.AnimSet.h"
#include "TribesGame.TrObject.PaperDollInfo.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PhysicsAsset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrFamilyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrFamilyInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrFamilyInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrFamilyInfo : public UTFamilyInfo
	{
	public:
		ADD_VAR(::IntProperty, ClassId, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FriendlyName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_IconId, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, ClassType, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ClassDescription, 0xFFFFFFFF)
		ADD_OBJECT(AnimTree, m_3pAnimTreeTemplate)
		ADD_VAR(::FloatProperty, m_fFIMaxSkiSpeed, 0xFFFFFFFF)
		ADD_OBJECT(SkeletalMesh, m_FirstPersonBodyMesh)
		ADD_VAR(::FloatProperty, m_fCollisionRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCollisionHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxGroundSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMass, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIMaxJettingSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFITerminalJettingSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFITerminalSkiSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIMaxSpeedDecelerationRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIAirControl, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIAirSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIPeakSkiControlSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFISkiControlSigmaSquare, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIMaxSkiControlPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFISkiSlopeGravityBoost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIMaxJetpackBoostGroundspeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIMaxStoppingDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIFallVelocityTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIMaxJetpackThrustSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIAccelRateAtMaxThrustSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIForwardJettingPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_FIJumpZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIAirAccelCapSpeedThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFIAirAccelSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFISkiAccelCapSpeedThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFISkiAccelPct, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_nmHeadBone, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHeadHeightOffset, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHeadRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fMaxPowerPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_nMaxHealthPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPowerPoolRechargeRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSecondsBeforeAutoHeal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthPoolRechargeRate, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, m_vAirControlReductionRange, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2D>, m_vAirControlMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFlightAcceleration, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bMomentumDampingEnabled, 0x1)
		ADD_VAR(::FloatProperty, m_fMomentumDampingSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMomentumDampingPct, 0xFFFFFFFF)
		ADD_OBJECT(SkeletalMesh, m_GibMesh)
		ADD_OBJECT(PhysicsAsset, m_GibPhysicsAsset)
		ADD_OBJECT(ParticleSystem, m_GibMeshParticleTemplate)
		ADD_VAR(::FloatProperty, m_fPassengerMeshScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleSpeedInheritPercent, 0xFFFFFFFF)
		ADD_OBJECT(SkeletalMesh, m_FirstPersonHandsMesh)
		ADD_VAR(::FloatProperty, m_fLowHealthThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fJetpackInitTotalTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InfoBit, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, DefaultSkinClass)
		ADD_STRUCT(::NonArithmeticProperty<PaperDollInfo>, m_MainMenuPaperDollInfo, 0xFFFFFFFF)
		ADD_OBJECT(PhysicsAsset, m_PaperDollSidekickPhysics)
		ADD_OBJECT(AnimTree, m_PaperDollSidekickAnimTree)
		ADD_OBJECT(AnimSet, m_PaperDollSidekickAnimset)
		ADD_OBJECT(SkeletalMesh, m_PaperDollSidekickMesh)
		ADD_VAR(::FloatProperty, m_fPaperDollFOV, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_SkillNodeShortDescriptions, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_SkillNodeDescriptions, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_SkillNodeNames, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_IconColor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Stat_Durability, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Stat_Difficulty, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Stat_AntiArmor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Stat_Mobility, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Stat_Range, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Abbreviation, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, ShortDesc, 0xFFFFFFFF)
		ADD_OBJECT(MorphTargetSet, m_OverlayMorphTarget)
		ADD_OBJECT(ParticleSystem, m_fJetpackThrustTemplate)
		ADD_OBJECT(ParticleSystem, m_fJetpackRibbonTemplate)
		ADD_VAR(::FloatProperty, m_fJetpackInitialCost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fJetpackPowerPoolTickRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fJetpackPowerPoolCost, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fJetpackInitAccelMultiplier, 0xFFFFFFFF)
		ScriptClass* GetDeviceClassByEquipPoint(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFamilyInfo.GetDeviceClassByEquipPoint");
			byte* params = (byte*)malloc(5);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetContentDeviceClassStringByEquipPoint(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFamilyInfo.GetContentDeviceClassStringByEquipPoint");
			byte* params = (byte*)malloc(13);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
