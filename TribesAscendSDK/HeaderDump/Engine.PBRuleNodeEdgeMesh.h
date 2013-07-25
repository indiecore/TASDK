#pragma once
#include "Engine.PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeEdgeMesh." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeEdgeMesh : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::FloatProperty, MainXPullIn, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlatThreshold, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
