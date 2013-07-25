#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeRepeat." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeRepeat : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::FloatProperty, RepeatMaxSize, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RepeatAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
