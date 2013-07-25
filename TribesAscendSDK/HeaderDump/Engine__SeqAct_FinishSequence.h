#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_FinishSequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_FinishSequence : public SequenceAction
	{
	public:
		ADD_VAR(::StrProperty, OutputLabel, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
