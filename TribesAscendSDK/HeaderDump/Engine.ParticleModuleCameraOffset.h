#pragma once
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.ParticleModuleCameraBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleCameraOffset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleCameraOffset." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleCameraOffset : public ParticleModuleCameraBase
	{
	public:
		ADD_VAR(::ByteProperty, UpdateMethod, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RawDistributionFloat>, CameraOffset, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSpawnTimeOnly, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
