#pragma once
#include "TribesGame__TrEmitCameraEffect_Speed.h"
namespace UnrealScript
{
	class TrEmitCameraEffect_Ashes : public TrEmitCameraEffect_Speed
	{
	public:
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEmitCameraEffect_Ashes.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
