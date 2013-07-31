#pragma once
#include "Engine.LocalPlayer.h"
#include "Engine.UIDataProvider.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UIDataProvider_OnlinePlayerDataBase : public UIDataProvider
	{
	public:
		ADD_STRUCT(int, PlayerControllerId, 88)
		void OnRegister(class LocalPlayer* InPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28152);
			byte params[4] = { NULL };
			*(class LocalPlayer**)params = InPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregister()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(28154);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
