#pragma once
#include "Engine.SeqAct_SetSequenceVariable.h"
#include "Core.Object.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_SetObject : public SeqAct_SetSequenceVariable
	{
	public:
		ADD_OBJECT(Object, Value, 236)
		ADD_OBJECT(Object, DefaultValue, 232)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqAct_SetObject.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_OBJECT
