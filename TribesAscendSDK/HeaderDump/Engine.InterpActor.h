#pragma once
#include "Engine.Actor.h"
#include "Engine.DynamicSMActor.h"
#include "Engine.SoundCue.h"
#include "Engine.NavigationPoint.h"
#include "Engine.SeqAct_Interp.h"
#include "Engine.InterpGroupInst.h"
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
	class InterpActor : public DynamicSMActor
	{
	public:
		struct CheckpointRecord
		{
		public:
			ADD_BOOL(bNeedsPositionReplication, 28, 0x4)
			ADD_BOOL(bIsShutdown, 28, 0x2)
			ADD_BOOL(bHidden, 28, 0x1)
			ADD_STRUCT(Actor::ECollisionType, CollisionType, 24)
			ADD_STRUCT(Rotator, Rotation, 12)
			ADD_STRUCT(Vector, Location, 0)
		};
		ADD_BOOL(bMonitorMover, 532, 0x2)
		ADD_OBJECT(NavigationPoint, MyMarker, 536)
		ADD_OBJECT(SoundCue, ClosedSound, 568)
		ADD_OBJECT(SoundCue, ClosingAmbientSound, 564)
		ADD_OBJECT(SoundCue, CloseSound, 560)
		ADD_OBJECT(SoundCue, OpenedSound, 556)
		ADD_OBJECT(SoundCue, OpeningAmbientSound, 552)
		ADD_OBJECT(SoundCue, OpenSound, 548)
		ADD_STRUCT(float, StayOpenTime, 544)
		ADD_STRUCT(float, MaxZVelocity, 540)
		ADD_BOOL(bIsLift, 532, 0x80)
		ADD_BOOL(bShouldShadowParentAllAttachedActors, 532, 0x40)
		ADD_BOOL(bStopOnEncroach, 532, 0x20)
		ADD_BOOL(bContinueOnEncroachPhysicsObject, 532, 0x10)
		ADD_BOOL(bDestroyProjectilesOnEncroach, 532, 0x8)
		ADD_BOOL(bMonitorZVelocity, 532, 0x4)
		ADD_BOOL(bShouldSaveForCheckpoint, 532, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18379);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetShadowParentOnAllAttachedComponents()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18380);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18381);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18395);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Attach(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18399);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Detach(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18403);
			byte params[4] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Restart()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18407);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FinishedOpen()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18409);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayMovingSound(bool bClosing)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18412);
			byte params[4] = { NULL };
			*(bool*)params = bClosing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18416);
			byte params[8] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			*(class InterpGroupInst**)&params[4] = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18420);
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InterpolationChanged(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18427);
			byte params[4] = { NULL };
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShutDown()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18429);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18430);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void CreateCheckpointRecord(InterpActor::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18432);
			byte params[32] = { NULL };
			*(InterpActor::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(InterpActor::CheckpointRecord*)params;
		}
		void ApplyCheckpointRecord(InterpActor::CheckpointRecord& Record)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18434);
			byte params[32] = { NULL };
			*(InterpActor::CheckpointRecord*)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(InterpActor::CheckpointRecord*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
