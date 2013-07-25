#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeRandom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeRandom : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::IntProperty, MaxNumExecuted, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinNumExecuted, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumOutputs, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
