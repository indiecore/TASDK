#pragma once
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Player : public Object
	{
	public:
		ADD_STRUCT(int, CurrentNetSpeed, 68)
		ADD_OBJECT(PlayerController, Actor, 64)
		ADD_STRUCT(float, PP_ShadowsMultiplier, 92)
		ADD_STRUCT(float, PP_MidTonesMultiplier, 88)
		ADD_STRUCT(float, PP_HighlightsMultiplier, 84)
		ADD_STRUCT(float, PP_DesaturationMultiplier, 80)
		ADD_STRUCT(int, ConfiguredLanSpeed, 76)
		ADD_STRUCT(int, ConfiguredInternetSpeed, 72)
		ADD_STRUCT(Object::Pointer, VfTable_FExec, 60)
		void SwitchController(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19471);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
