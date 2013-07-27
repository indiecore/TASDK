#pragma once
#include "Engine.SequenceOp.h"
#include "Engine.SequenceObject.h"
#include "Engine.SequenceEvent.h"
#include "Core.Object.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Sequence : public SequenceOp
	{
	public:
		class ActivateOp
		{
		public:
			ADD_STRUCT(float, RemainingDelay, 12)
			ADD_STRUCT(int, InputIdx, 8)
			ADD_OBJECT(SequenceOp, Op, 4)
			ADD_OBJECT(SequenceOp, ActivatorOp, 0)
		};
		class QueuedActivationInfo
		{
		public:
			ADD_STRUCT(ScriptArray<int>, ActivateIndices, 12)
			ADD_BOOL(bPushTop, 24, 0x1)
			ADD_OBJECT(Actor, InInstigator, 8)
			ADD_OBJECT(Actor, InOriginator, 4)
			ADD_OBJECT(SequenceEvent, ActivatedEvent, 0)
		};
		ADD_STRUCT(ScriptArray<class SequenceObject*>, SequenceObjects, 212)
		ADD_STRUCT(ScriptArray<class SequenceOp*>, ActiveSequenceOps, 224)
		ADD_STRUCT(ScriptArray<class Sequence*>, NestedSequences, 236)
		ADD_STRUCT(ScriptArray<class SequenceEvent*>, UnregisteredEvents, 248)
		ADD_STRUCT(ScriptArray<Sequence::ActivateOp>, DelayedActivatedOps, 260)
		ADD_STRUCT(ScriptArray<Sequence::QueuedActivationInfo>, QueuedActivations, 276)
		ADD_STRUCT(float, DefaultViewZoom, 296)
		ADD_STRUCT(int, DefaultViewY, 292)
		ADD_STRUCT(int, DefaultViewX, 288)
		ADD_BOOL(bEnabled, 272, 0x1)
		ADD_STRUCT(Object::Pointer, LogFile, 208)
		void FindSeqObjectsByClass(ScriptClass* DesiredClass, bool bRecursive, ScriptArray<class SequenceObject*>& OutputObjects)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.FindSeqObjectsByClass");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = DesiredClass;
			*(bool*)&params[4] = bRecursive;
			*(ScriptArray<class SequenceObject*>*)&params[8] = OutputObjects;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutputObjects = *(ScriptArray<class SequenceObject*>*)&params[8];
		}
		void FindSeqObjectsByName(ScriptString* SeqObjName, bool bCheckComment, ScriptArray<class SequenceObject*>& OutputObjects, bool bRecursive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.FindSeqObjectsByName");
			byte params[32] = { NULL };
			*(ScriptString**)&params[0] = SeqObjName;
			*(bool*)&params[12] = bCheckComment;
			*(ScriptArray<class SequenceObject*>*)&params[16] = OutputObjects;
			*(bool*)&params[28] = bRecursive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutputObjects = *(ScriptArray<class SequenceObject*>*)&params[16];
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEnabled(bool bInEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Sequence.SetEnabled");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
