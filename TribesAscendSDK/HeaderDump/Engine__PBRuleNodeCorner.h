#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeCorner." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeCorner : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::FloatProperty, RoundCurvature, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoundTesselation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CornerShapeOffset, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CornerType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseAdjacentRulesetForRightGap, 0x2)
		ADD_VAR(::BoolProperty, bNoMeshForConcaveCorners, 0x1)
		ADD_VAR(::FloatProperty, FlatThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CornerSize, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
