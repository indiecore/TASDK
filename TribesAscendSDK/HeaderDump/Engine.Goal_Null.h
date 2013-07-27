#pragma once
#include "Engine.PathGoalEvaluator.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class Goal_Null : public PathGoalEvaluator
	{
	public:
		bool GoUntilBust(class Pawn* P, int InMaxPathVisits)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Goal_Null.GoUntilBust");
			byte params[12] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(int*)&params[4] = InMaxPathVisits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Goal_Null.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
