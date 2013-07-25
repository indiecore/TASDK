#pragma once
#include "Engine__ParticleModuleKillBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleKillHeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleKillHeight." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleKillHeight : public ParticleModuleKillBase
	{
	public:
		ADD_VAR(::BoolProperty, bApplyPSysScale, 0x4)
		ADD_VAR(::BoolProperty, bFloor, 0x2)
		ADD_VAR(::BoolProperty, bAbsolute, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'Height'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
