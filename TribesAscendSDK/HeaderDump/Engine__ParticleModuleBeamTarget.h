#pragma once
#include "Engine__ParticleModuleBeamBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleBeamTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleBeamTarget." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleBeamTarget : public ParticleModuleBeamBase
	{
	public:
		ADD_VAR(::FloatProperty, LockRadius, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'TargetStrength'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'TargetTangent'!
		ADD_VAR(::BoolProperty, bLockTargetStength, 0x8)
		ADD_VAR(::BoolProperty, bLockTargetTangent, 0x4)
		ADD_VAR(::BoolProperty, bLockTarget, 0x2)
		ADD_VAR(::BoolProperty, bTargetAbsolute, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'Target'!
		ADD_VAR(::NameProperty, TargetName, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TargetTangentMethod, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TargetMethod, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
