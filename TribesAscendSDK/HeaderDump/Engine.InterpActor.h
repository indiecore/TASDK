#pragma once
#include "Engine.Actor.h"
#include "Engine.DynamicSMActor.h"
#include "Engine.SoundCue.h"
#include "Engine.NavigationPoint.h"
#include "Engine.SeqAct_Interp.h"
#include "Engine.InterpGroupInst.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InterpActor." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpActor : public DynamicSMActor
	{
	public:
		ADD_VAR(::BoolProperty, bMonitorMover, 0x2)
		ADD_OBJECT(NavigationPoint, MyMarker)
		ADD_OBJECT(SoundCue, ClosedSound)
		ADD_OBJECT(SoundCue, ClosingAmbientSound)
		ADD_OBJECT(SoundCue, CloseSound)
		ADD_OBJECT(SoundCue, OpenedSound)
		ADD_OBJECT(SoundCue, OpeningAmbientSound)
		ADD_OBJECT(SoundCue, OpenSound)
		ADD_VAR(::FloatProperty, StayOpenTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxZVelocity, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsLift, 0x80)
		ADD_VAR(::BoolProperty, bShouldShadowParentAllAttachedActors, 0x40)
		ADD_VAR(::BoolProperty, bStopOnEncroach, 0x20)
		ADD_VAR(::BoolProperty, bContinueOnEncroachPhysicsObject, 0x10)
		ADD_VAR(::BoolProperty, bDestroyProjectilesOnEncroach, 0x8)
		ADD_VAR(::BoolProperty, bMonitorZVelocity, 0x4)
		ADD_VAR(::BoolProperty, bShouldSaveForCheckpoint, 0x1)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetShadowParentOnAllAttachedComponents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.SetShadowParentOnAllAttachedComponents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool EncroachingOn(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.EncroachingOn");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RanInto(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.RanInto");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Attach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.Attach");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Detach(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.Detach");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Restart()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.Restart");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FinishedOpen()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.FinishedOpen");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayMovingSound(bool bClosing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.PlayMovingSound");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bClosing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InterpolationStarted(class SeqAct_Interp* InterpAction, class InterpGroupInst* GroupInst)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.InterpolationStarted");
			byte* params = (byte*)malloc(8);
			*(class SeqAct_Interp**)params = InterpAction;
			*(class InterpGroupInst**)(params + 4) = GroupInst;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InterpolationFinished(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.InterpolationFinished");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InterpolationChanged(class SeqAct_Interp* InterpAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.InterpolationChanged");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Interp**)params = InterpAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShutDown()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.ShutDown");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.ShouldSaveForCheckpoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.InterpActor.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.CreateCheckpointRecord");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.InterpActor.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.InterpActor.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.InterpActor.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InterpActor.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(32);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.InterpActor.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.InterpActor.CheckpointRecord'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
