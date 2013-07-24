#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeAlternate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeAlternate : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::BoolProperty, bEqualSizeAB, 0x2)
		ADD_VAR(::BoolProperty, bInvertPatternOrder, 0x1)
		ADD_VAR(::FloatProperty, BMaxSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ASize, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RepeatAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
