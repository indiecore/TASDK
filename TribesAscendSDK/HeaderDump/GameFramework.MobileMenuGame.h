#pragma once
#include "Engine.GameInfo.h"
#include "Engine.PlayerController.h"
#include "Engine.Controller.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class MobileMenuGame : public GameInfo
	{
	public:
		ADD_OBJECT(ScriptClass, InitialSceneToDisplayClass, 884)
		void PostLogin(class PlayerController* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32635);
			byte params[4] = { NULL };
			*(class PlayerController**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartMatch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32640);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32641);
			byte params[4] = { NULL };
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
