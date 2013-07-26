#pragma once
#include "Engine.AnimSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " AnimNodeSequenceBlendBase.AnimInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty AnimNodeSequenceBlendBase.AnimInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AnimInfo
	{
	public:
		ADD_VAR(::IntProperty, AnimLinkupIndex, 0xFFFFFFFF)
		ADD_OBJECT(AnimSequence, AnimSeq)
		ADD_VAR(::NameProperty, AnimSeqName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
