#pragma once
#include "Engine.Emitter.h"
#include "Engine.ParticleSystem.h"
#include "Core.Object.Vector.h"
#include "Engine.WorldInfo.h"
namespace UnrealScript
{
	class UTEmitter : public Emitter
	{
	public:
		class ParticleSystem* GetTemplateForDistance(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& TemplateList, Vector SpawnLocation, class WorldInfo* WI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmitter.GetTemplateForDistance");
			byte* params = (byte*)malloc(32);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = TemplateList;
			*(Vector*)(params + 12) = SpawnLocation;
			*(class WorldInfo**)(params + 24) = WI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			TemplateList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(class ParticleSystem**)(params + 28);
			free(params);
			return returnVal;
		}
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmitter.SetTemplate");
			byte* params = (byte*)malloc(8);
			*(class ParticleSystem**)params = NewTemplate;
			*(bool*)(params + 4) = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetLightEnvironment(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Light)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmitter.SetLightEnvironment");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Light;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
