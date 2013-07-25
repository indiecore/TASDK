#pragma once
#include "Engine__ParticleModuleAttractorBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleAttractorPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleAttractorPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAttractorPoint : public ParticleModuleAttractorBase
	{
	public:
		ADD_VAR(::BoolProperty, bUseWorldSpacePosition, 0x8)
		ADD_VAR(::BoolProperty, bOverrideVelocity, 0x4)
		ADD_VAR(::BoolProperty, bAffectBaseVelocity, 0x2)
		ADD_VAR(::BoolProperty, StrengthByDistance, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Strength'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Range'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'Position'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
