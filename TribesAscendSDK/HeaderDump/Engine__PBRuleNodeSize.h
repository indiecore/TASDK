#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeSize." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeSize : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::BoolProperty, bUseTopLevelScopeSize, 0x1)
		ADD_VAR(::FloatProperty, DecisionSize, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SizeAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
