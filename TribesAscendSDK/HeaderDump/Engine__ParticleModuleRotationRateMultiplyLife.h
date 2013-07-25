#pragma once
#include "Engine__ParticleModuleRotationRateBase.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleRotationRateMultiplyLife." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleRotationRateMultiplyLife : public ParticleModuleRotationRateBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'LifeMultiplier'!
	};
}
#undef ADD_STRUCT
