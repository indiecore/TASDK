#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNode_MultiBlendPerBone.PerBoneMaskInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PerBoneMaskInfo
	{
	public:
		ADD_VAR(::IntProperty, TransformReqBoneIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPendingBlend, 0x4)
		ADD_VAR(::BoolProperty, bDisableForNonLocalHumanPlayers, 0x2)
		ADD_VAR(::BoolProperty, bWeightBasedOnNodeRules, 0x1)
		ADD_VAR(::FloatProperty, BlendTimeToGo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredWeight, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
