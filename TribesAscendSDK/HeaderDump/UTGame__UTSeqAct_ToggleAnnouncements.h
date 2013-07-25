#pragma once
#include "Engine__SequenceAction.h"
namespace UnrealScript
{
	class UTSeqAct_ToggleAnnouncements : public SequenceAction
	{
	public:
		void Activated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSeqAct_ToggleAnnouncements.Activated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
