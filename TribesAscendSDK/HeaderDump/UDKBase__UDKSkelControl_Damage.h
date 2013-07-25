#pragma once
#include "Engine__SkelControlSingleBone.h"
#include "Engine__ParticleSystem.h"
#include "Engine__StaticMesh.h"
#include "UDKBase__UDKVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKSkelControl_Damage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UDKBase.UDKSkelControl_Damage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UDKBase.UDKSkelControl_Damage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UDKSkelControl_Damage : public SkelControlSingleBone
	{
	public:
		ADD_OBJECT(ParticleSystem, PS_DeathTrail)
		ADD_OBJECT(ParticleSystem, PS_DeathOnBreak)
		ADD_STRUCT(::VectorProperty, DeathScale, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DeathImpulseDir, 0xFFFFFFFF
		ADD_OBJECT(StaticMesh, DeathStaticMesh)
		ADD_VAR(::FloatProperty, DeathBoneScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeathPercentToActuallySpawn, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, BreakSpeed, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, OwnerVehicleMaxHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BreakTimer, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, BrokenBone, 0xFFFFFFFF)
		ADD_OBJECT(ParticleSystem, PS_DamageTrail)
		ADD_OBJECT(ParticleSystem, PS_DamageOnBreak)
		ADD_STRUCT(::VectorProperty, DamageScale, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, DefaultBreakDir, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, BreakTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, BreakThreshold, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, BreakMesh)
		ADD_VAR(::FloatProperty, ActivationThreshold, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DamageMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DamageBoneScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HealthPerc, 0xFFFFFFFF)
		ADD_OBJECT(UDKVehicle, OwnerVehicle)
		ADD_VAR(::BoolProperty, bOnDeathUseForSecondaryExplosion, 0x80)
		ADD_VAR(::BoolProperty, bOnDeathActive, 0x40)
		ADD_VAR(::BoolProperty, bDeathCamFollows, 0x20)
		ADD_VAR(::BoolProperty, bIsBreaking, 0x10)
		ADD_VAR(::BoolProperty, bIsBroken, 0x8)
		ADD_VAR(::BoolProperty, bControlStrFollowsHealth, 0x4)
		ADD_VAR(::BoolProperty, bOnDamageActive, 0x2)
		ADD_VAR(::BoolProperty, bInitialized, 0x1)
		// Here lies the not-yet-implemented method 'BreakApart'
		// Here lies the not-yet-implemented method 'BreakApartOnDeath'
		// Here lies the not-yet-implemented method 'RestorePart'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
