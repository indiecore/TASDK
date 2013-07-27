#pragma once
#include "Engine.SequenceEvent.h"
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
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
	class SeqEvent_Touch : public SequenceEvent
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptClass*>, ClassProximityTypes, 256)
		ADD_STRUCT(ScriptArray<ScriptClass*>, IgnoredClassProximityTypes, 268)
		ADD_STRUCT(ScriptArray<class Actor*>, TouchedList, 284)
		ADD_BOOL(bAllowDeadPawns, 280, 0x4)
		ADD_BOOL(bUseInstigator, 280, 0x2)
		ADD_BOOL(bForceOverlapping, 280, 0x1)
		bool CheckTouchActivate(class Actor* InOriginator, class Actor* InInstigator, bool bTest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.CheckTouchActivate");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = InOriginator;
			*(class Actor**)&params[4] = InInstigator;
			*(bool*)&params[8] = bTest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CheckUnTouchActivate(class Actor* InOriginator, class Actor* InInstigator, bool bTest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.CheckUnTouchActivate");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = InOriginator;
			*(class Actor**)&params[4] = InInstigator;
			*(bool*)&params[8] = bTest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void Toggled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.Toggled");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyTouchingPawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.NotifyTouchingPawnDied");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqEvent_Touch.GetObjClassVersion");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
