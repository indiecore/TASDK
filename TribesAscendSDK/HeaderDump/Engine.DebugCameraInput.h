#pragma once
#include "Engine.PlayerInput.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class DebugCameraInput : public PlayerInput
	{
	public:
		bool InputKey(int ControllerId, ScriptName Key, Object::EInputEvent Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraInput.InputKey");
			byte params[25] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object::EInputEvent*)&params[12] = Event;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
	};
}
