#pragma once
#include "Engine.AnimNode_MultiBlendPerBone.WeightNodeRule.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNode_MultiBlendPerBone.WeightRule." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WeightRule
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<WeightNodeRule>, SecondNode, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<WeightNodeRule>, FirstNode, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
