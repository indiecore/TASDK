#pragma once
#include "Engine__PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeSplit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeSplit : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::ByteProperty, SplitAxis, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
