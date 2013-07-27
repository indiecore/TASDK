#pragma once
#include "Engine.EmitterPool.h"
#include "Engine.ParticleSystem.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
	class UDKEmitterPool : public EmitterPool
	{
	public:
		struct AttachedExplosionLight
		{
		public:
			ADD_STRUCT(Vector, RelativeLocation, 8)
			ADD_OBJECT(Actor, Base, 4)
		};
		ADD_STRUCT(ScriptArray<UDKEmitterPool::AttachedExplosionLight>, RelativeExplosionLights, 564)
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitter(class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Rotator SpawnRotation, class Actor* AttachToActor, bool bInheritScaleFromBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34795);
			byte params[40] = { NULL };
			*(class ParticleSystem**)params = EmitterTemplate;
			*(Vector*)&params[4] = SpawnLocation;
			*(Rotator*)&params[16] = SpawnRotation;
			*(class Actor**)&params[28] = AttachToActor;
			*(bool*)&params[32] = bInheritScaleFromBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[36];
		}
		void OnExplosionLightFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Light)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34805);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Light;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnExplosionLight(ScriptClass* LightClass, Vector SpawnLocation, class Actor* AttachToActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34808);
			byte params[24] = { NULL };
			*(ScriptClass**)params = LightClass;
			*(Vector*)&params[4] = SpawnLocation;
			*(class Actor**)&params[16] = AttachToActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
