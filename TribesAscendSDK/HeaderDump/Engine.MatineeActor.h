#pragma once
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#include "Engine.SeqAct_Interp.h"
#include "Engine.InterpGroupInstAI.h"
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
	class MatineeActor : public Actor
	{
	public:
		static const auto MAX_AIGROUP_NUMBER = 10;
		ADD_STRUCT(float, ClientSidePositionErrorTolerance, 652)
		ADD_STRUCT(int, AIGroupInitStage, 612)
		ADD_OBJECT(Pawn, AIGroupPawns, 572)
		ADD_STRUCT(ScriptName, AIGroupNames, 492)
		ADD_STRUCT(float, Position, 488)
		ADD_STRUCT(float, PlayRate, 484)
		ADD_BOOL(AllAIGroupsInitialized, 480, 0x8)
		ADD_BOOL(bPaused, 480, 0x4)
		ADD_BOOL(bReversePlayback, 480, 0x2)
		ADD_BOOL(bIsPlaying, 480, 0x1)
		ADD_OBJECT(SeqAct_Interp, InterpAction, 476)
		void AddAIGroupActor(class InterpGroupInstAI* AIGroupInst)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19930);
			byte params[4] = { NULL };
			*(class InterpGroupInstAI**)params = AIGroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Update()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19932);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckPriorityRefresh()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19940);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
