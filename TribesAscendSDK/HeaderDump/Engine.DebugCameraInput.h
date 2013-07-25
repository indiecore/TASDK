#pragma once
#include "Engine.PlayerInput.h"
namespace UnrealScript
{
	class DebugCameraInput : public PlayerInput
	{
	public:
		bool InputKey(int ControllerId, ScriptName Key, byte Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DebugCameraInput.InputKey");
			byte* params = (byte*)malloc(25);
			*(int*)params = ControllerId;
			*(ScriptName*)(params + 4) = Key;
			*(params + 12) = Event;
			*(float*)(params + 16) = AmountDepressed;
			*(bool*)(params + 20) = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
	};
}
