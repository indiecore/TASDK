#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModuleTypeDataBeam2.BeamTargetData." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BeamTargetData
	{
	public:
		ADD_VAR(::FloatProperty, TargetPercentage, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TargetName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
