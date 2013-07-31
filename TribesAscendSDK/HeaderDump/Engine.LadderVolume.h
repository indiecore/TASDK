#pragma once
#include "Engine.PhysicsVolume.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
#include "Engine.Ladder.h"
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
	class LadderVolume : public PhysicsVolume
	{
	public:
		ADD_STRUCT(Vector, ClimbDir, 608)
		ADD_BOOL(bAllowLadderStrafing, 624, 0x4)
		ADD_OBJECT(Pawn, PendingClimber, 628)
		ADD_BOOL(bAutoPath, 624, 0x2)
		ADD_BOOL(bNoPhysicalLadder, 624, 0x1)
		ADD_OBJECT(Ladder, LadderList, 620)
		ADD_STRUCT(Vector, LookDir, 596)
		ADD_STRUCT(Rotator, WallDir, 584)
		bool InUse(class Pawn* Ignored)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(11896);
			byte params[8] = { NULL };
			*(class Pawn**)params = Ignored;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19140);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnEnteredVolume(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19146);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PawnLeavingVolume(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19151);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PhysicsChangedFor(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19154);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
