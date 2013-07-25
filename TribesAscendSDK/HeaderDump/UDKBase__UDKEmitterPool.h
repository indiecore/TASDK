#pragma once
#include "Engine__EmitterPool.h"
#include "Engine__Actor.h"
#include "Engine__ParticleSystem.h"
namespace UnrealScript
{
	class UDKEmitterPool : public EmitterPool
	{
	public:
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnEmitter(class ParticleSystem* EmitterTemplate, Vector SpawnLocation, Rotator SpawnRotation, class Actor* AttachToActor, bool bInheritScaleFromBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitterPool.SpawnEmitter");
			byte* params = (byte*)malloc(40);
			*(class ParticleSystem**)params = EmitterTemplate;
			*(Vector*)(params + 4) = SpawnLocation;
			*(Rotator*)(params + 16) = SpawnRotation;
			*(class Actor**)(params + 28) = AttachToActor;
			*(bool*)(params + 32) = bInheritScaleFromBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 36);
			free(params);
			return returnVal;
		}
		void OnExplosionLightFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Light)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitterPool.OnExplosionLightFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Light;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnExplosionLight(ScriptClass* LightClass, Vector SpawnLocation, class Actor* AttachToActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKEmitterPool.SpawnExplosionLight");
			byte* params = (byte*)malloc(24);
			*(ScriptClass**)params = LightClass;
			*(Vector*)(params + 4) = SpawnLocation;
			*(class Actor**)(params + 16) = AttachToActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
