#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeVariation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeVariation : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::BoolProperty, bVariationOfScopeOnLeft, 0x1)
	};
}
#undef ADD_VAR
