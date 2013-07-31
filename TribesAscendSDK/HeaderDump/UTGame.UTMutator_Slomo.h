#pragma once
#include "UTGame.UTMutator.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTMutator_Slomo : public UTMutator
	{
	public:
		ADD_STRUCT(float, GameSpeed, 496)
		void InitMutator(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48611);
			byte params[24] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
	};
}
#undef ADD_STRUCT
