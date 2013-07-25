#pragma once
#include "Engine__SequenceAction.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrSeqAct_GiveAccolade." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrSeqAct_GiveAccolade : public SequenceAction
	{
	public:
		ADD_OBJECT(ScriptClass, AccoladeType)
	};
}
#undef ADD_OBJECT
