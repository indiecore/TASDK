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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18187);
			byte params[12] = { NULL };
			*(class Pawn**)params = P;
			*(int*)&params[4] = InMaxPathVisits;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18192);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
