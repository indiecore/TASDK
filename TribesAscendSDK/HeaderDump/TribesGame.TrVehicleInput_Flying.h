#pragma once
#include "Engine.PlayerInput.h"
namespace UnrealScript
{
	class TrVehicleInput_Flying : public PlayerInput
	{
	public:
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114951);
			byte params[4] = { NULL };
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
