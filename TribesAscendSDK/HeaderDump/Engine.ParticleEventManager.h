#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.ParticleModuleEventSendToGame.h"
namespace UnrealScript
{
	class ParticleEventManager : public Actor
	{
	public:
		void HandleParticleModuleEventSendToGame(class ParticleModuleEventSendToGame* InEvent, Object::Vector& InCollideDirection, Object::Vector& InHitLocation, Object::Vector& InHitNormal, ScriptName& InBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleEventManager.HandleParticleModuleEventSendToGame");
			byte params[48] = { NULL };
			*(class ParticleModuleEventSendToGame**)&params[0] = InEvent;
			*(Object::Vector*)&params[4] = InCollideDirection;
			*(Object::Vector*)&params[16] = InHitLocation;
			*(Object::Vector*)&params[28] = InHitNormal;
			*(ScriptName*)&params[40] = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InCollideDirection = *(Object::Vector*)&params[4];
			InHitLocation = *(Object::Vector*)&params[16];
			InHitNormal = *(Object::Vector*)&params[28];
			InBoneName = *(ScriptName*)&params[40];
		}
	};
}
