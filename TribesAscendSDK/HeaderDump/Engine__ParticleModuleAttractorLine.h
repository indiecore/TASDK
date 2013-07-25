#pragma once
#include "Engine__ParticleModuleAttractorBase.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleAttractorLine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleAttractorLine : public ParticleModuleAttractorBase
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Strength'!
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Range'!
		ADD_STRUCT(::VectorProperty, EndPoint1, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EndPoint0, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
