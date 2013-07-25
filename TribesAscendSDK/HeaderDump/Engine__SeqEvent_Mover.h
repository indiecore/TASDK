#pragma once
#include "Engine__SequenceEvent.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqEvent_Mover." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_Mover : public SequenceEvent
	{
	public:
		ADD_VAR(::FloatProperty, StayOpenTime, 0xFFFFFFFF)
		void RegisterEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Mover.RegisterEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyEncroachingOn(class Actor* Hit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Mover.NotifyEncroachingOn");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Hit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyAttached(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Mover.NotifyAttached");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyDetached(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Mover.NotifyDetached");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyFinishedOpen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Mover.NotifyFinishedOpen");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
