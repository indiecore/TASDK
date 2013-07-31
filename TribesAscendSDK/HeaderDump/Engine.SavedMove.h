#pragma once
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.SkeletalMeshComponent.h"
#include "Engine.Pawn.h"
#include "Engine.PlayerController.h"
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
	class SavedMove : public Object
	{
	public:
		ADD_STRUCT(float, TimeStamp, 64)
		ADD_OBJECT(SavedMove, NextMove, 60)
		ADD_STRUCT(Vector, Acceleration, 176)
		ADD_OBJECT(Actor, EndBase, 204)
		ADD_STRUCT(Vector, SavedRelativeLocation, 152)
		ADD_STRUCT(Vector, SavedLocation, 128)
		ADD_STRUCT(Vector, SavedVelocity, 140)
		ADD_BOOL(bForceRMVelocity, 72, 0x20)
		ADD_STRUCT(float, Delta, 68)
		ADD_STRUCT(Actor::EDoubleClickDir, DoubleClickMove, 76)
		ADD_STRUCT(Vector, StartVelocity, 104)
		ADD_OBJECT(Actor, StartBase, 200)
		ADD_STRUCT(Vector, StartFloor, 116)
		ADD_STRUCT(Rotator, Rotation, 188)
		ADD_STRUCT(Vector, RootMotionInterpCurveLastValue, 220)
		ADD_STRUCT(float, RootMotionInterpCurrentTime, 216)
		ADD_STRUCT(float, AccelDotThreshold, 212)
		ADD_STRUCT(float, CustomTimeDilation, 208)
		ADD_STRUCT(Vector, RMVelocity, 164)
		ADD_STRUCT(Vector, StartRelativeLocation, 92)
		ADD_STRUCT(Vector, StartLocation, 80)
		ADD_STRUCT(SkeletalMeshComponent::ERootMotionMode, RootMotionMode, 78)
		ADD_STRUCT(Actor::EPhysics, SavedPhysics, 77)
		ADD_BOOL(bRootMotionFromInterpCurve, 72, 0x80)
		ADD_BOOL(bForceMaxAccel, 72, 0x40)
		ADD_BOOL(bPreciseDestination, 72, 0x10)
		ADD_BOOL(bDoubleJump, 72, 0x8)
		ADD_BOOL(bPressedJump, 72, 0x4)
		ADD_BOOL(bDuck, 72, 0x2)
		ADD_BOOL(bRun, 72, 0x1)
		Actor::EDoubleClickDir SetFlags(byte Flags, class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8150);
			byte params[6] = { NULL };
			*params = Flags;
			*(class PlayerController**)&params[4] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::EDoubleClickDir*)&params[8];
		}
		byte CompressedFlags()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8248);
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *params;
		}
		bool IsImportantMove(Vector CompareAccel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8269);
			byte params[16] = { NULL };
			*(Vector*)params = CompareAccel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CanCombineWith(class SavedMove* NewMove, class Pawn* inPawn, float MaxDelta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8272);
			byte params[16] = { NULL };
			*(class SavedMove**)params = NewMove;
			*(class Pawn**)&params[4] = inPawn;
			*(float*)&params[8] = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		Vector GetStartLocation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8274);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)params;
		}
		void Clear()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25395);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostUpdate(class PlayerController* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25396);
			byte params[4] = { NULL };
			*(class PlayerController**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInitialPosition(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25400);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMoveFor(class PlayerController* P, float DeltaTime, Vector newAccel, Actor::EDoubleClickDir InDoubleClick)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25405);
			byte params[21] = { NULL };
			*(class PlayerController**)params = P;
			*(float*)&params[4] = DeltaTime;
			*(Vector*)&params[8] = newAccel;
			*(Actor::EDoubleClickDir*)&params[20] = InDoubleClick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrepMoveFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25410);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetMoveFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25412);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDebugString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(25417);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
