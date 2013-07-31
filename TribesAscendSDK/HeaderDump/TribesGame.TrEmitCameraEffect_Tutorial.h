#pragma once
#include "TribesGame.TrEmitCameraEffect_Speed.h"
namespace UnrealScript
{
	class TrEmitCameraEffect_Tutorial : public TrEmitCameraEffect_Speed
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87273);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
