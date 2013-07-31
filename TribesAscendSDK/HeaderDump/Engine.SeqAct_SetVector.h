#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqAct_SetVector : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_STRUCT(Vector, DefaultValue, 232)
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25937);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
