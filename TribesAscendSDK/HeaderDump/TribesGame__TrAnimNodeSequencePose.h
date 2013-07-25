#pragma once
#include "TribesGame__TrPawn.h"
#include "Engine__AnimNodeSequence.h"
namespace UnrealScript
{
	class TrAnimNodeSequencePose : public AnimNodeSequence
	{
	public:
		void FillWithPose(class TrPawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnimNodeSequencePose.FillWithPose");
			byte* params = (byte*)malloc(4);
			*(class TrPawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
