#pragma once
#include "Engine.ParticleModuleCollisionBase.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'DelayAmount'!
		ADD_VAR(::FloatProperty, VerticalFudgeFactor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DirScalar, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'ParticleMass'!
		ADD_VAR(::BoolProperty, bDropDetail, 0x8)
		ADD_VAR(::BoolProperty, bOnlyVerticalNormalsDecrementCount, 0x4)
		ADD_VAR(::BoolProperty, bPawnsDoNotDecrementCount, 0x2)
		ADD_VAR(::BoolProperty, bApplyPhysics, 0x1)
		ADD_VAR(::ByteProperty, CollisionCompletionOption, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'MaxCollisions'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'DampingFactorRotation'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'DampingFactor'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
