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
		ADD_STRUCT(Object::Vector, Acceleration, 176)
		ADD_OBJECT(Actor, EndBase, 204)
		ADD_STRUCT(Object::Vector, SavedRelativeLocation, 152)
		ADD_STRUCT(Object::Vector, SavedLocation, 128)
		ADD_STRUCT(Object::Vector, SavedVelocity, 140)
		ADD_BOOL(bForceRMVelocity, 72, 0x20)
		ADD_STRUCT(float, Delta, 68)
		ADD_STRUCT(Actor::EDoubleClickDir, DoubleClickMove, 76)
		ADD_STRUCT(Object::Vector, StartVelocity, 104)
		ADD_OBJECT(Actor, StartBase, 200)
		ADD_STRUCT(Object::Vector, StartFloor, 116)
		ADD_STRUCT(Object::Rotator, Rotation, 188)
		ADD_STRUCT(Object::Vector, RootMotionInterpCurveLastValue, 220)
		ADD_STRUCT(float, RootMotionInterpCurrentTime, 216)
		ADD_STRUCT(float, AccelDotThreshold, 212)
		ADD_STRUCT(float, CustomTimeDilation, 208)
		ADD_STRUCT(Object::Vector, RMVelocity, 164)
		ADD_STRUCT(Object::Vector, StartRelativeLocation, 92)
		ADD_STRUCT(Object::Vector, StartLocation, 80)
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.SetFlags");
			byte params[6] = { NULL };
			params[0] = Flags;
			*(class PlayerController**)&params[4] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Actor::EDoubleClickDir*)&params[8];
		}
		byte CompressedFlags()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.CompressedFlags");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		bool IsImportantMove(Object::Vector CompareAccel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.IsImportantMove");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = CompareAccel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool CanCombineWith(class SavedMove* NewMove, class Pawn* inPawn, float MaxDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.CanCombineWith");
			byte params[16] = { NULL };
			*(class SavedMove**)&params[0] = NewMove;
			*(class Pawn**)&params[4] = inPawn;
			*(float*)&params[8] = MaxDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		Object::Vector GetStartLocation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.GetStartLocation");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[0];
		}
		void Clear()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.Clear");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostUpdate(class PlayerController* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.PostUpdate");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInitialPosition(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.SetInitialPosition");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMoveFor(class PlayerController* P, float DeltaTime, Object::Vector newAccel, Actor::EDoubleClickDir InDoubleClick)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.SetMoveFor");
			byte params[21] = { NULL };
			*(class PlayerController**)&params[0] = P;
			*(float*)&params[4] = DeltaTime;
			*(Object::Vector*)&params[8] = newAccel;
			*(Actor::EDoubleClickDir*)&params[20] = InDoubleClick;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrepMoveFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.PrepMoveFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetMoveFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.ResetMoveFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDebugString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SavedMove.GetDebugString");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
