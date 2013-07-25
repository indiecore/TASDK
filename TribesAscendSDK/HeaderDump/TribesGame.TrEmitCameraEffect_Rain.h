#pragma once
#include "TribesGame.TrEmitCameraEffect_Speed.h"
namespace UnrealScript
{
	class TrEmitCameraEffect_Rain : public TrEmitCameraEffect_Speed
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEmitCameraEffect_Rain.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
