#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleCollisionBase.h"
#include "Core.DistributionVector.RawDistributionVector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleCollision." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleCollision." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleCollision : public ParticleModuleCollisionBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, DelayAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, VerticalFudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirScalar, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, ParticleMass, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bDropDetail, 0x8)
		ADD_VAR(::BoolProperty, bOnlyVerticalNormalsDecrementCount, 0x4)
		ADD_VAR(::BoolProperty, bPawnsDoNotDecrementCount, 0x2)
		ADD_VAR(::BoolProperty, bApplyPhysics, 0x1)
		ADD_VAR(::ByteProperty, CollisionCompletionOption, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, MaxCollisions, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, DampingFactorRotation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionVector>, DampingFactor, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
