#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModuleOrbit.OrbitOptions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OrbitOptions
	{
	public:
		ADD_VAR(::BoolProperty, bUseEmitterTime, 0x4)
		ADD_VAR(::BoolProperty, bProcessDuringUpdate, 0x2)
		ADD_VAR(::BoolProperty, bProcessDuringSpawn, 0x1)
	};
}
#undef ADD_VAR
