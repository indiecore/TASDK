#pragma once
#include "Engine.SequenceEvent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileRawInput : public SequenceEvent
	{
	public:
		ADD_STRUCT(float, TimeStamp, 268)
		ADD_STRUCT(float, TouchLocationY, 264)
		ADD_STRUCT(float, TouchLocationX, 260)
		ADD_STRUCT(int, TouchIndex, 256)
		void RegisterEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_MobileRawInput.RegisterEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
