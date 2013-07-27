#pragma once
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class PBRuleNodeBase : public Object
	{
	public:
		class PBRuleLink
		{
		public:
			ADD_STRUCT(int, DrawY, 12)
			ADD_STRUCT(ScriptName, LinkName, 4)
			ADD_OBJECT(PBRuleNodeBase, NextRule, 0)
		};
		ADD_STRUCT(ScriptArray<PBRuleNodeBase::PBRuleLink>, NextRules, 60)
		ADD_STRUCT(int, DrawHeight, 100)
		ADD_STRUCT(int, DrawWidth, 96)
		ADD_STRUCT(int, InDrawY, 92)
		ADD_STRUCT(int, RulePosY, 88)
		ADD_STRUCT(int, RulePosX, 84)
		ADD_STRUCT(ScriptString*, Comment, 72)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
