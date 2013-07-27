#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_Toggle.h"
namespace UnrealScript
{
	class NxForceFieldSpawnable : public Actor
	{
	public:
		void OnToggle(class SeqAct_Toggle* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21236);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
