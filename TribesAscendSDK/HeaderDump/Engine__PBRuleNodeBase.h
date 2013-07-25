#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeBase." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeBase : public Object
	{
	public:
		ADD_VAR(::IntProperty, DrawHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DrawWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, InDrawY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RulePosY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RulePosX, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, Comment, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
