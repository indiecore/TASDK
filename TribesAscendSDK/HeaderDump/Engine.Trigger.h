#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.Projectile.h"
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
	class Trigger : public Actor
	{
	public:
		class CheckpointRecord
		{
		public:
			ADD_BOOL(bCollideActors, 0, 0x1)
		};
		ADD_BOOL(bRecentlyTriggered, 480, 0x1)
		ADD_STRUCT(float, AITriggerDelay, 484)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Object::Vector HitLocation, Object::Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.Touch");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = OtherComp;
			*(Object::Vector*)&params[8] = HitLocation;
			*(Object::Vector*)&params[20] = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTriggered()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.NotifyTriggered");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnTrigger()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.UnTrigger");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool StopsProjectile(class Projectile* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.StopsProjectile");
			byte params[8] = { NULL };
			*(class Projectile**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.ShouldSaveForCheckpoint");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void CreateCheckpointRecord(Trigger::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.CreateCheckpointRecord");
			byte params[4] = { NULL };
			*(Trigger::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(Trigger::CheckpointRecord*)&params[0];
		}
		void ApplyCheckpointRecord(Trigger::CheckpointRecord& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.ApplyCheckpointRecord");
			byte params[4] = { NULL };
			*(Trigger::CheckpointRecord*)&params[0] = Record;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Record = *(Trigger::CheckpointRecord*)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
