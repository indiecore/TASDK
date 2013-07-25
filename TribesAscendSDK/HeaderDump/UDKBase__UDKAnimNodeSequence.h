#pragma once
#include "Engine__AnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimNodeSequence." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSequence : public AnimNodeSequence
	{
	public:
		ADD_VAR(::BoolProperty, bLoopLastSequence, 0x2)
		ADD_VAR(::BoolProperty, bAutoStart, 0x1)
		void PlayAnimation(ScriptName Sequence, float SeqRate, bool bSeqLoop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequence.PlayAnimation");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = Sequence;
			*(float*)(params + 8) = SeqRate;
			*(bool*)(params + 12) = bSeqLoop;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayAnimationSet(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Sequences, float SeqRate, bool bLoopLast)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequence.PlayAnimationSet");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Sequences;
			*(float*)(params + 12) = SeqRate;
			*(bool*)(params + 16) = bLoopLast;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnInit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKAnimNodeSequence.OnInit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
