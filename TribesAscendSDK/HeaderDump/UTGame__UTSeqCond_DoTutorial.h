#pragma once
#include "Engine__SequenceCondition.h"
namespace UnrealScript
{
	class UTSeqCond_DoTutorial : public SequenceCondition
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqCond_DoTutorial.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
