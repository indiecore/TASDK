#pragma once
#include "Core.Object.h"
#include "Engine.Emitter.h"
#include "Engine.ParticleSystem.h"
#include "UDKBase.UDKPawn.h"
#include "Engine.WorldInfo.h"
namespace UnrealScript
{
	class UTEmitter : public Emitter
	{
	public:
		class ParticleSystem* GetTemplateForDistance(ScriptArray<UDKPawn::DistanceBasedParticleTemplate>& TemplateList, Object::Vector SpawnLocation, class WorldInfo* WI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmitter.GetTemplateForDistance");
			byte params[32] = { NULL };
			*(ScriptArray<UDKPawn::DistanceBasedParticleTemplate>*)&params[0] = TemplateList;
			*(Object::Vector*)&params[12] = SpawnLocation;
			*(class WorldInfo**)&params[24] = WI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			TemplateList = *(ScriptArray<UDKPawn::DistanceBasedParticleTemplate>*)&params[0];
			return *(class ParticleSystem**)&params[28];
		}
		void SetTemplate(class ParticleSystem* NewTemplate, bool bDestroyOnFinish)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmitter.SetTemplate");
			byte params[8] = { NULL };
			*(class ParticleSystem**)&params[0] = NewTemplate;
			*(bool*)&params[4] = bDestroyOnFinish;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetLightEnvironment(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Light)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTEmitter.SetLightEnvironment");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Light;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
