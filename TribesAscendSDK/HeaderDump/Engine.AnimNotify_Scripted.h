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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify_Scripted.Notify");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Owner;
			*(class AnimNodeSequence**)(params + 4) = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyEnd(class Actor* Owner, class AnimNodeSequence* AnimSeqInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify_Scripted.NotifyEnd");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Owner;
			*(class AnimNodeSequence**)(params + 4) = AnimSeqInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
