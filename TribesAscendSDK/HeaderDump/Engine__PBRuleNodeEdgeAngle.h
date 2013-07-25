#pragma once
#include "Engine__PBRuleNodeBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PBRuleNodeEdgeAngle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PBRuleNodeEdgeAngle : public PBRuleNodeBase
	{
	public:
		ADD_VAR(::ByteProperty, Edge, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
