#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModuleEventGenerator.ParticleEvent_GenerateInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleEvent_GenerateInfo
	{
	public:
		ADD_VAR(::NameProperty, CustomName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, UseReflectedImpactVector, 0x4)
		ADD_VAR(::BoolProperty, LastTimeOnly, 0x2)
		ADD_VAR(::BoolProperty, FirstTimeOnly, 0x1)
		ADD_VAR(::IntProperty, ParticleFrequency, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LowFreq, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Frequency, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Type, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
