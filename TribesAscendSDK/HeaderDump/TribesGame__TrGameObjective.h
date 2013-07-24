#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrGameObjective." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameObjective." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameObjective : public UTGameObjective
	{
	public:
		ADD_VAR(::FloatProperty, fUpgradeAssistTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMarker2DDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DESTROY_ASSIST_PERCENTAGE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, REPAIR_ASSIST_PERCENTAGE, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInstigatorNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fObjectiveHealthBarPlacementX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_MarkerMIC)
		ADD_OBJECT(MaterialInstanceConstant, m_HealthBarMIC)
		ADD_VAR(::FloatProperty, m_fRepairBoost, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, m_UpgradeTemplate)
		ADD_VAR(::IntProperty, r_nUpgradeLevel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPromptMessageSwitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPromptMessageTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fRemainingSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, m_rPotentialSeekingTargetHUDRotation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fRemainingPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_MissileLockStatus, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, r_bReset, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, DestroyedTemplate)
		ADD_VAR(::FloatProperty, m_fLifeAfterDeathSecs, 0xFFFFFFFF)
		ADD_OBJECT(Controller, m_LastDamager)
		ADD_OBJECT(SoundCue, m_ExplosionSound)
		ADD_VAR(::BoolProperty, m_bAlwaysRelevantToSameTeam, 0x8000)
		ADD_VAR(::BoolProperty, m_bHurtByFriendlyFire, 0x4000)
		ADD_VAR(::BoolProperty, m_bDestroyable, 0x2000)
		ADD_VAR(::BoolProperty, m_bShowObjectivesForcesMarker, 0x1000)
		ADD_VAR(::BoolProperty, m_bIsRepairable, 0x800)
		ADD_VAR(::BoolProperty, m_bIsUpgradeable, 0x400)
		ADD_VAR(::BoolProperty, m_bHasPromptText, 0x200)
		ADD_VAR(::BoolProperty, r_bInDestroyedState, 0x100)
		ADD_VAR(::BoolProperty, m_bIsRepairableAfterDeath, 0x80)
		ADD_VAR(::BoolProperty, m_bPostRenderForEnemy, 0x40)
		ADD_VAR(::BoolProperty, m_bVisibilityRequiredForEnemy, 0x20)
		ADD_VAR(::BoolProperty, m_bForceShowHUD, 0x10)
		ADD_VAR(::BoolProperty, m_bReceivesPowerFromGenerator, 0x8)
		ADD_VAR(::BoolProperty, r_bIsPowered, 0x4)
		ADD_VAR(::BoolProperty, m_bInstantOnlineSound, 0x2)
		ADD_VAR(::BoolProperty, m_bAutoPlayOnlineSound, 0x1)
		ADD_OBJECT(PhysicsAsset, m_OfflinePhysicsAsset)
		ADD_OBJECT(PhysicsAsset, m_OnlinePhysicsAsset)
		ADD_VAR(::StrProperty, m_sScreenName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOuterExplosionShakeRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInnerExplosionShakeRadius, 0xFFFFFFFF)
		ADD_OBJECT(CameraAnim, m_ExplosionShake)
		ADD_OBJECT(ParticleSystem, m_ExplosionTemplate)
		ADD_VAR(::FloatProperty, m_fShieldHitRemainingTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShieldHitTargetTimeLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fShieldHitTargetScale, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldMIC)
		ADD_VAR(::FloatProperty, ShowHeaderUntil, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MarkerOffset, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, m_ShieldNormalMap)
		ADD_OBJECT(Material, m_ShieldMaterial)
		ADD_VAR(::FloatProperty, m_fShieldHealthPercentage, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nRepairHealthThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCriticalHealthThreshold, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, r_vReplicatedHitInfo, 0xFFFFFFFF
		ADD_VAR(::IntProperty, m_nHealthRegenRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_MaxHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_Health, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ObjectiveMIC)
		ADD_STRUCT(::VectorProperty, CallInPosition, 0xFFFFFFFF
		ADD_STRUCT(::RotatorProperty, CallInRotation, 0xFFFFFFFF
		ADD_OBJECT(TrStatsInterface, Stats)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
