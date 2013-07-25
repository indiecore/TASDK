#pragma once
#include "Engine__Actor.h"
#include "Engine__Projectile.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Trigger." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Trigger : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bRecentlyTriggered, 0x1)
		ADD_VAR(::FloatProperty, AITriggerDelay, 0xFFFFFFFF)
		void Touch(class Actor* Other, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherComp, Vector HitLocation, Vector HitNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.Touch");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = Other;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4) = OtherComp;
			*(Vector*)(params + 8) = HitLocation;
			*(Vector*)(params + 20) = HitNormal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(8);
			*(class Projectile**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShouldSaveForCheckpoint()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.ShouldSaveForCheckpoint");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void CreateCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.Trigger.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.CreateCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Trigger.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Trigger.CheckpointRecord'!
void**)params;
			free(params);
		}
		void ApplyCheckpointRecord(
// WARNING: Unknown structure type 'ScriptStruct Engine.Trigger.CheckpointRecord'!
void*& Record)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Trigger.ApplyCheckpointRecord");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.Trigger.CheckpointRecord'!
void**)params = Record;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Record = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.Trigger.CheckpointRecord'!
void**)params;
			free(params);
		}
	};
}
#undef ADD_VAR
