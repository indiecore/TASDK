#pragma once
#include "Engine__SeqAct_SetSequenceVariable.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqAct_SetObject." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetObject : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_OBJECT(Object, Value)
		ADD_OBJECT(Object, DefaultValue)
	};
}
#undef ADD_OBJECT
