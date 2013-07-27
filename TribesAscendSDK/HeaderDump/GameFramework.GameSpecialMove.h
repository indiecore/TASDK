#pragma once
#include "GameFramework.GamePawn.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GameSpecialMove : public Object
	{
	public:
		ADD_STRUCT(Object::Rotator, PreciseRotation, 112)
		ADD_STRUCT(float, PreciseRotationInterpolationTime, 108)
		ADD_STRUCT(Object::Vector, PreciseDestRelOffset, 96)
		ADD_OBJECT(Actor, PreciseDestBase, 92)
		ADD_STRUCT(Object::Vector, PreciseDestination, 80)
		ADD_BOOL(bForcePrecisePosition, 76, 0x20)
		ADD_BOOL(bReachedPreciseRotation, 76, 0x10)
		ADD_BOOL(bReachPreciseRotation, 76, 0x8)
		ADD_BOOL(bReachedPreciseDestination, 76, 0x4)
		ADD_BOOL(bReachPreciseDestination, 76, 0x2)
		ADD_BOOL(bLastCanDoSpecialMove, 76, 0x1)
		ADD_STRUCT(float, LastCanDoSpecialMoveTime, 72)
		ADD_STRUCT(ScriptName, Handle, 64)
		ADD_OBJECT(GamePawn, PawnOwner, 60)
		void InitSpecialMove(class GamePawn* inPawn, ScriptName InHandle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.InitSpecialMove");
			byte params[12] = { NULL };
			*(class GamePawn**)&params[0] = inPawn;
			*(ScriptName*)&params[4] = InHandle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitSpecialMoveFlags(int& out_Flags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.InitSpecialMoveFlags");
			byte params[4] = { NULL };
			*(int*)&params[0] = out_Flags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Flags = *(int*)&params[0];
		}
		void ExtractSpecialMoveFlags(int Flags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ExtractSpecialMoveFlags");
			byte params[4] = { NULL };
			*(int*)&params[0] = Flags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanChainMove(ScriptName NextMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanChainMove");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = NextMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CanOverrideMoveWith(ScriptName NewMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanOverrideMoveWith");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = NewMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CanOverrideSpecialMove(ScriptName InMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanOverrideSpecialMove");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CanDoSpecialMove(bool bForceCheck)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.CanDoSpecialMove");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool InternalCanDoSpecialMove()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.InternalCanDoSpecialMove");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SpecialMoveStarted(bool bForced, ScriptName PrevMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SpecialMoveStarted");
			byte params[12] = { NULL };
			*(bool*)&params[0] = bForced;
			*(ScriptName*)&params[4] = PrevMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialMoveEnded(ScriptName PrevMove, ScriptName NextMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SpecialMoveEnded");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = PrevMove;
			*(ScriptName*)&params[8] = NextMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialMoveFlagsUpdated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SpecialMoveFlagsUpdated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldReplicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ShouldReplicate");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetReachPreciseDestination(Object::Vector DestinationToReach, bool bCancel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SetReachPreciseDestination");
			byte params[16] = { NULL };
			*(Object::Vector*)&params[0] = DestinationToReach;
			*(bool*)&params[12] = bCancel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFacePreciseRotation(Object::Rotator RotationToFace, float InterpolationTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.SetFacePreciseRotation");
			byte params[16] = { NULL };
			*(Object::Rotator*)&params[0] = RotationToFace;
			*(float*)&params[12] = InterpolationTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReachedPrecisePosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ReachedPrecisePosition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetFacePreciseRotation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ResetFacePreciseRotation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MessageEvent(ScriptName EventName, class Object* Sender)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.MessageEvent");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = EventName;
			*(class Object**)&params[8] = Sender;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void ForcePawnRotation(class Pawn* P, Object::Rotator NewRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.ForcePawnRotation");
			byte params[16] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(Object::Rotator*)&params[4] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Vector WorldToRelativeOffset(Object::Rotator InRotation, Object::Vector WorldSpaceOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.WorldToRelativeOffset");
			byte params[36] = { NULL };
			*(Object::Rotator*)&params[0] = InRotation;
			*(Object::Vector*)&params[12] = WorldSpaceOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
		Object::Vector RelativeToWorldOffset(Object::Rotator InRotation, Object::Vector RelativeSpaceOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.GameSpecialMove.RelativeToWorldOffset");
			byte params[36] = { NULL };
			*(Object::Rotator*)&params[0] = InRotation;
			*(Object::Vector*)&params[12] = RelativeSpaceOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Vector*)&params[24];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
