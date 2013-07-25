#pragma once
#include "Engine__ParticleModuleUberBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleUberRainSplashA." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleUberRainSplashA." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberRainSplashA : public ParticleModuleUberBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'AlphaOverLife'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'ColorOverLife'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'LifeMultiplier'!
		ADD_VAR(::BoolProperty, MultiplyZ, 0x8)
		ADD_VAR(::BoolProperty, MultiplyY, 0x4)
		ADD_VAR(::BoolProperty, MultiplyX, 0x2)
		ADD_VAR(::BoolProperty, bInheritParent, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'StartRotation'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionVector.RawDistributionVector' for the property named 'StartSize'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Lifetime'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
