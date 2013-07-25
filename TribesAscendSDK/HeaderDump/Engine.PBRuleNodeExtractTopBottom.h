#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeExtractTopBottom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeExtractTopBottom : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::FloatProperty, ExtractNotBottomZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExtractBottomZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExtractNotTopZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExtractTopZ, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
