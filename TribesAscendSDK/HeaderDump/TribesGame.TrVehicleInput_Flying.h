#pragma once
#include "Engine.PlayerInput.h"
namespace UnrealScript
{
	class TrVehicleInput_Flying : public PlayerInput
	{
	public:
		void AdjustMouseSensitivity(float FOVScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehicleInput_Flying.AdjustMouseSensitivity");
			byte* params = (byte*)malloc(4);
			*(float*)params = FOVScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
