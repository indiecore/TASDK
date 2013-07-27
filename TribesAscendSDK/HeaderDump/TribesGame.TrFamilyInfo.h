#pragma once
#include "UTGame.UTFamilyInfo.h"
#include "TribesGame.TrObject.h"
#include "Engine.AnimTree.h"
#include "Core.Object.h"
#include "Engine.MorphTargetSet.h"
#include "Engine.AnimSet.h"
#include "Engine.SkeletalMesh.h"
#include "Engine.ParticleSystem.h"
#include "Engine.PhysicsAsset.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrFamilyInfo : public UTFamilyInfo
	{
	public:
		static const auto TR_MAX_FACTION_NBR = 3;
		class DeviceSelectionList
		{
		public:
			ADD_OBJECT(ScriptClass, DeviceClass, 4)
			ADD_STRUCT(TrObject::TR_EQUIP_POINT, EquipPoint, 0)
			ADD_STRUCT(ScriptString*, ContentDeviceClassString, 8)
		};
		class SkillNode
		{
		public:
			ADD_STRUCT(int, Cost, 24)
			ADD_STRUCT(int, ParentIndex, 20)
			ADD_STRUCT(int, IconId, 16)
			ADD_STRUCT(int, IconPosY, 12)
			ADD_STRUCT(int, IconPosX, 8)
			ADD_STRUCT(float, Value, 4)
			ADD_OBJECT(TrValueModifier, ValueModifier, 0)
		};
		ADD_STRUCT(int, ClassId, 636)
		ADD_STRUCT(ScriptString*, FriendlyName, 624)
		ADD_STRUCT(int, m_IconId, 784)
		ADD_STRUCT(TrObject::TrClassType, ClassType, 644)
		ADD_STRUCT(ScriptString*, ClassDescription, 660)
		ADD_STRUCT(ScriptArray<ScriptClass*>, VehicleSelectionList, 424)
		ADD_OBJECT(AnimTree, m_3pAnimTreeTemplate, 620)
		ADD_STRUCT(float, m_fFIMaxSkiSpeed, 760)
		ADD_OBJECT(SkeletalMesh, m_FirstPersonBodyMesh, 596)
		ADD_STRUCT(float, m_fCollisionRadius, 572)
		ADD_STRUCT(float, m_fCollisionHeight, 568)
		ADD_STRUCT(float, m_fMaxGroundSpeed, 556)
		ADD_STRUCT(float, m_fMass, 704)
		ADD_STRUCT(float, m_fFIMaxJettingSpeed, 720)
		ADD_STRUCT(float, m_fFITerminalJettingSpeed, 724)
		ADD_STRUCT(float, m_fFITerminalSkiSpeed, 764)
		ADD_STRUCT(float, m_fFIMaxSpeedDecelerationRate, 792)
		ADD_STRUCT(float, m_fFIAirControl, 728)
		ADD_STRUCT(float, m_fFIAirSpeed, 732)
		ADD_STRUCT(float, m_fFIPeakSkiControlSpeed, 768)
		ADD_STRUCT(float, m_fFISkiControlSigmaSquare, 772)
		ADD_STRUCT(float, m_fFIMaxSkiControlPct, 776)
		ADD_STRUCT(float, m_fFISkiSlopeGravityBoost, 780)
		ADD_STRUCT(float, m_fFIMaxJetpackBoostGroundspeed, 736)
		ADD_STRUCT(float, m_fFIMaxStoppingDistance, 740)
		ADD_STRUCT(float, m_fFIFallVelocityTransfer, 744)
		ADD_STRUCT(float, m_fFIMaxJetpackThrustSpeed, 748)
		ADD_STRUCT(float, m_fFIAccelRateAtMaxThrustSpeed, 752)
		ADD_STRUCT(float, m_fFIForwardJettingPct, 756)
		ADD_STRUCT(float, m_FIJumpZ, 1728)
		ADD_STRUCT(float, m_fFIAirAccelCapSpeedThreshold, 1732)
		ADD_STRUCT(float, m_fFIAirAccelSpeed, 1736)
		ADD_STRUCT(float, m_fFISkiAccelCapSpeedThreshold, 1740)
		ADD_STRUCT(float, m_fFISkiAccelPct, 1744)
		ADD_STRUCT(ScriptName, m_nmHeadBone, 584)
		ADD_STRUCT(float, m_fHeadHeightOffset, 580)
		ADD_STRUCT(float, m_fHeadRadius, 576)
		ADD_STRUCT(float, r_fMaxPowerPool, 536)
		ADD_STRUCT(float, m_nMaxHealthPool, 560)
		ADD_STRUCT(float, m_fPowerPoolRechargeRate, 540)
		ADD_STRUCT(float, m_fSecondsBeforeAutoHeal, 548)
		ADD_STRUCT(float, m_fHealthPoolRechargeRate, 544)
		ADD_STRUCT(Object::Vector2D, m_vAirControlReductionRange, 452)
		ADD_STRUCT(Object::Vector2D, m_vAirControlMultiplier, 460)
		ADD_STRUCT(float, m_fFlightAcceleration, 468)
		ADD_BOOL(m_bMomentumDampingEnabled, 708, 0x1)
		ADD_STRUCT(float, m_fMomentumDampingSpeed, 712)
		ADD_STRUCT(float, m_fMomentumDampingPct, 716)
		ADD_OBJECT(SkeletalMesh, m_GibMesh, 604)
		ADD_OBJECT(PhysicsAsset, m_GibPhysicsAsset, 608)
		ADD_OBJECT(ParticleSystem, m_GibMeshParticleTemplate, 612)
		ADD_STRUCT(float, m_fPassengerMeshScale, 592)
		ADD_STRUCT(float, m_fVehicleSpeedInheritPercent, 564)
		ADD_OBJECT(SkeletalMesh, m_FirstPersonHandsMesh, 600)
		ADD_STRUCT(ScriptArray<ScriptName>, m_nmFootstepEffectSockets, 524)
		ADD_STRUCT(ScriptArray<ScriptName>, m_nmSkiThrusterEffectSockets, 512)
		ADD_STRUCT(float, m_fLowHealthThreshold, 552)
		ADD_STRUCT(float, m_fJetpackInitTotalTime, 476)
		ADD_STRUCT(int, InfoBit, 640)
		ADD_STRUCT(ScriptArray<TrFamilyInfo::DeviceSelectionList>, DevSelectionList, 412)
		ADD_OBJECT(ScriptClass, DefaultSkinClass, 448)
		ADD_STRUCT(ScriptArray<ScriptClass*>, PassengerSelectionList, 436)
		ADD_STRUCT(ScriptArray<ScriptName>, m_nmJetpackThrustEffectSockets, 500)
		ADD_STRUCT(ScriptArray<TrFamilyInfo::SkillNode>, m_SkillGrid, 796)
		ADD_STRUCT(TrObject::PaperDollInfo, m_MainMenuPaperDollInfo, 1748)
		ADD_OBJECT(PhysicsAsset, m_PaperDollSidekickPhysics, 1724)
		ADD_OBJECT(AnimTree, m_PaperDollSidekickAnimTree, 1720)
		ADD_OBJECT(AnimSet, m_PaperDollSidekickAnimset, 1716)
		ADD_OBJECT(SkeletalMesh, m_PaperDollSidekickMesh, 1712)
		ADD_STRUCT(float, m_fPaperDollFOV, 1708)
		ADD_STRUCT(ScriptString*, m_SkillNodeShortDescriptions, 1408)
		ADD_STRUCT(ScriptString*, m_SkillNodeDescriptions, 1108)
		ADD_STRUCT(ScriptString*, m_SkillNodeNames, 808)
		ADD_STRUCT(int, m_IconColor, 788)
		ADD_STRUCT(float, Stat_Durability, 700)
		ADD_STRUCT(float, Stat_Difficulty, 696)
		ADD_STRUCT(float, Stat_AntiArmor, 692)
		ADD_STRUCT(float, Stat_Mobility, 688)
		ADD_STRUCT(float, Stat_Range, 684)
		ADD_STRUCT(ScriptString*, Abbreviation, 672)
		ADD_STRUCT(ScriptString*, ShortDesc, 648)
		ADD_OBJECT(MorphTargetSet, m_OverlayMorphTarget, 616)
		ADD_OBJECT(ParticleSystem, m_fJetpackThrustTemplate, 496)
		ADD_OBJECT(ParticleSystem, m_fJetpackRibbonTemplate, 492)
		ADD_STRUCT(float, m_fJetpackInitialCost, 488)
		ADD_STRUCT(float, m_fJetpackPowerPoolTickRate, 484)
		ADD_STRUCT(float, m_fJetpackPowerPoolCost, 480)
		ADD_STRUCT(float, m_fJetpackInitAccelMultiplier, 472)
		ScriptClass* GetDeviceClassByEquipPoint(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFamilyInfo.GetDeviceClassByEquipPoint");
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[4];
		}
		ScriptString* GetContentDeviceClassStringByEquipPoint(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrFamilyInfo.GetContentDeviceClassStringByEquipPoint");
			byte params[13] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)&params[0] = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
