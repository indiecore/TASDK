#pragma once
#include "Engine.AnimNotify.h"
#include "Engine.Actor.h"
#include "Engine.AnimNodeSequence.h"
namespace UnrealScript
{
	class AnimNotify_Scripted : public AnimNotify
	{
	public:
		void Notify(class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11144);
			byte params[8] = { NULL };
			*(class Actor**)params = Owner;
			*(class AnimNodeSequence**)&params[4] = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyEnd(class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11147);
			byte params[8] = { NULL };
			*(class Actor**)params = Owner;
			*(class AnimNodeSequence**)&params[4] = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
