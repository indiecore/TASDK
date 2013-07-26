#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ReverbVolume.InteriorSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class InteriorSettings
	{
	public:
		ADD_VAR(::BoolProperty, bIsWorldInfo, 0x1)
		ADD_VAR(::FloatProperty, ExteriorVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExteriorTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExteriorLPF, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExteriorLPFTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteriorVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteriorTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteriorLPF, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteriorLPFTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
