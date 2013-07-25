#pragma once
#include "Engine__SequenceCondition.h"
namespace UnrealScript
{
	class UTSeqCond_IsConsole : public SequenceCondition
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqCond_IsConsole.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
