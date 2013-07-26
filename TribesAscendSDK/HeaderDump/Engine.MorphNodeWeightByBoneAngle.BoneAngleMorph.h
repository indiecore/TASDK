#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " MorphNodeWeightByBoneAngle.BoneAngleMorph." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class BoneAngleMorph
	{
	public:
		ADD_VAR(::FloatProperty, TargetWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Angle, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
