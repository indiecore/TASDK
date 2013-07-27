#pragma once
#include "Engine.SequenceAction.h"
#include "UTGame.UTVehicle.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_UseHoverboard : public SequenceAction
	{
	public:
		ADD_OBJECT(UTVehicle, Hoverboard, 232)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_UseHoverboard.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_OBJECT
