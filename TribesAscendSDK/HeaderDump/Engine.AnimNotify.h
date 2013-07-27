#pragma once
#include "Engine.AnimSequence.h"
#include "Core.Object.h"
#include "Engine.AnimNodeSequence.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class AnimNotify : public Object
	{
	public:
		ADD_STRUCT(Object::Color, NotifyColor, 60)
		bool FindNextNotifyOfClass(class AnimNodeSequence* AnimSeqInstigator, ScriptClass* NotifyClass, AnimSequence::AnimNotifyEvent& OutEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AnimNotify.FindNextNotifyOfClass");
			byte params[32] = { NULL };
			*(class AnimNodeSequence**)&params[0] = AnimSeqInstigator;
			*(ScriptClass**)&params[4] = NotifyClass;
			*(AnimSequence::AnimNotifyEvent*)&params[8] = OutEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutEvent = *(AnimSequence::AnimNotifyEvent*)&params[8];
			return *(bool*)&params[28];
		}
	};
}
#undef ADD_STRUCT
