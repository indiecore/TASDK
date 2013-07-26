#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleEmitter.ParticleBurst." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleBurst
	{
	public:
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CountLow, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Count, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
