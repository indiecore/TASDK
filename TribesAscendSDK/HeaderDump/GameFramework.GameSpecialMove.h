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
		ADD_STRUCT(Rotator, PreciseRotation, 112)
		ADD_STRUCT(float, PreciseRotationInterpolationTime, 108)
		ADD_STRUCT(Vector, PreciseDestRelOffset, 96)
		ADD_OBJECT(Actor, PreciseDestBase, 92)
		ADD_STRUCT(Vector, PreciseDestination, 80)
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31883);
			byte params[12] = { NULL };
			*(class GamePawn**)params = inPawn;
			*(ScriptName*)&params[4] = InHandle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitSpecialMoveFlags(int& out_Flags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31886);
			byte params[4] = { NULL };
			*(int*)params = out_Flags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Flags = *(int*)params;
		}
		void ExtractSpecialMoveFlags(int Flags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31888);
			byte params[4] = { NULL };
			*(int*)params = Flags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanChainMove(ScriptName NextMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31890);
			byte params[12] = { NULL };
			*(ScriptName*)params = NextMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CanOverrideMoveWith(ScriptName NewMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31893);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CanOverrideSpecialMove(ScriptName InMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31896);
			byte params[12] = { NULL };
			*(ScriptName*)params = InMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool CanDoSpecialMove(bool bForceCheck)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31899);
			byte params[8] = { NULL };
			*(bool*)params = bForceCheck;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool InternalCanDoSpecialMove()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31902);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SpecialMoveStarted(bool bForced, ScriptName PrevMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31904);
			byte params[12] = { NULL };
			*(bool*)params = bForced;
			*(ScriptName*)&params[4] = PrevMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialMoveEnded(ScriptName PrevMove, ScriptName NextMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31907);
			byte params[16] = { NULL };
			*(ScriptName*)params = PrevMove;
			*(ScriptName*)&params[8] = NextMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31910);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SpecialMoveFlagsUpdated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31912);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldReplicate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31913);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetReachPreciseDestination(Vector DestinationToReach, bool bCancel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31915);
			byte params[16] = { NULL };
			*(Vector*)params = DestinationToReach;
			*(bool*)&params[12] = bCancel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFacePreciseRotation(Rotator RotationToFace, float InterpolationTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31918);
			byte params[16] = { NULL };
			*(Rotator*)params = RotationToFace;
			*(float*)&params[12] = InterpolationTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReachedPrecisePosition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31921);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetFacePreciseRotation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31922);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MessageEvent(ScriptName EventName, class Object* Sender)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31923);
			byte params[16] = { NULL };
			*(ScriptName*)params = EventName;
			*(class Object**)&params[8] = Sender;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void ForcePawnRotation(class Pawn* P, Rotator NewRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31927);
			byte params[16] = { NULL };
			*(class Pawn**)params = P;
			*(Rotator*)&params[4] = NewRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Vector WorldToRelativeOffset(Rotator InRotation, Vector WorldSpaceOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31930);
			byte params[36] = { NULL };
			*(Rotator*)params = InRotation;
			*(Vector*)&params[12] = WorldSpaceOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
		Vector RelativeToWorldOffset(Rotator InRotation, Vector RelativeSpaceOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(31934);
			byte params[36] = { NULL };
			*(Rotator*)params = InRotation;
			*(Vector*)&params[12] = RelativeSpaceOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Vector*)&params[24];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
