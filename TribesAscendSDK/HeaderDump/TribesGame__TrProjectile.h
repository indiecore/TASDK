#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrProjectile." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrProjectile." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrProjectile : public UTProjectile
	{
	public:
		ADD_VAR(::BoolProperty, m_bTether, 0x40)
		ADD_VAR(::BoolProperty, m_bSimulateAutonomousProjectiles, 0x80)
		ADD_VAR(::ByteProperty, m_SpawnedEquipPoint, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, r_nTetherId, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bIsBullet, 0x100)
		ADD_STRUCT(::VectorProperty, r_vSpawnLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fInstigatorExtraZMomentum, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, SpawnedFromDevice)
		ADD_VAR(::FloatProperty, m_fAlwaysRelevantDistanceSquared, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMinLifespan, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxLifespan, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, m_vAccelDirection, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, m_fClientSimulatedSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTweenSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentTetherTweenAmount, 0xFFFFFFFF)
		ADD_OBJECT(TrProjectile, c_ChildTetheredProjectile)
		ADD_OBJECT(TrProjectile, c_ParentTetheredProjectile)
		ADD_VAR(::FloatProperty, m_fInstigatorMomentumTransferMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAmbientSoundFadeOut, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAmbientSoundFadeIn, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDirectHitMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fBounceDampingPercent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nPerPlayerMaxDeployed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxProjInheritPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fProjInheritVelocityPctZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fProjInheritVelocityPct, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fXYDamageRadius, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bAuthoritativeExploding, 0x20)
		ADD_VAR(::BoolProperty, m_bOrientToWall, 0x10)
		ADD_VAR(::BoolProperty, m_bHasBounced, 0x8)
		ADD_VAR(::BoolProperty, m_bFastProjectile, 0x4)
		ADD_VAR(::BoolProperty, m_bDebugProjectileRadius, 0x2)
		ADD_VAR(::BoolProperty, m_bLimitXYDamageCheck, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
