#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PBRuleNodeBase.PBRuleLink." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PBRuleNodeBase.PBRuleLink." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PBRuleLink
	{
	public:
		ADD_VAR(::IntProperty, DrawY, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, LinkName, 0xFFFFFFFF)
		ADD_OBJECT(PBRuleNodeBase, NextRule)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
