#pragma once
#include "Engine.AnimNodeSequence.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSequence : public AnimNodeSequence
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, SeqStack, 324)
		ADD_BOOL(bLoopLastSequence, 320, 0x2)
		ADD_BOOL(bAutoStart, 320, 0x1)
		void PlayAnimation(ScriptName Sequence, float SeqRate, bool bSeqLoop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequence.PlayAnimation");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = Sequence;
			*(float*)&params[8] = SeqRate;
			*(bool*)&params[12] = bSeqLoop;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayAnimationSet(ScriptArray<ScriptName> Sequences, float SeqRate, bool bLoopLast)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequence.PlayAnimationSet");
			byte params[20] = { NULL };
			*(ScriptArray<ScriptName>*)&params[0] = Sequences;
			*(float*)&params[12] = SeqRate;
			*(bool*)&params[16] = bLoopLast;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequence.OnInit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
