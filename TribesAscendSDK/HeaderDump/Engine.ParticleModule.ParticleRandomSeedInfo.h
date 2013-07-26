#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModule.ParticleRandomSeedInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleRandomSeedInfo
	{
	public:
		ADD_VAR(::BoolProperty, bResetSeedOnEmitterLooping, 0x4)
		ADD_VAR(::BoolProperty, bInstanceSeedIsIndex, 0x2)
		ADD_VAR(::BoolProperty, bGetSeedFromInstance, 0x1)
		ADD_VAR(::NameProperty, ParameterName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
