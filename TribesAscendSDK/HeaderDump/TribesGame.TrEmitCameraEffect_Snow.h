#pragma once
#include "TribesGame.TrEmitCameraEffect_Speed.h"
namespace UnrealScript
{
	class TrEmitCameraEffect_Snow : public TrEmitCameraEffect_Speed
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87269);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
