#pragma once
#include "Engine.AnimNodeBlendBase.h"
#include "Engine.AnimNodeSlot.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNode_MultiBlendPerBone.WeightNodeRule." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AnimNode_MultiBlendPerBone.WeightNodeRule." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class WeightNodeRule
	{
	public:
		ADD_VAR(::IntProperty, ChildIndex, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, WeightCheck, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeSlot, CachedSlotNode)
		ADD_OBJECT(AnimNodeBlendBase, CachedNode)
		ADD_VAR(::NameProperty, NodeName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
