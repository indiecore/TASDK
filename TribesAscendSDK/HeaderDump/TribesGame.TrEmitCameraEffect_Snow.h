#pragma once
#include "TribesGame.TrEmitCameraEffect_Speed.h"
namespace UnrealScript
{
	class TrEmitCameraEffect_Snow : public TrEmitCameraEffect_Speed
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEmitCameraEffect_Snow.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
