#pragma once
#include "Engine__AnimNodeSequence.h"
#include "Engine__AnimNodeBlendList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AnimNodeRandom." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AnimNodeRandom." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimNodeRandom : public AnimNodeBlendList
	{
	public:
		ADD_VAR(::BoolProperty, bPickedPendingChildIndex, 0x1)
		ADD_VAR(::IntProperty, PendingChildIndex, 0xFFFFFFFF)
		ADD_OBJECT(AnimNodeSequence, PlayingSeqNode)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
