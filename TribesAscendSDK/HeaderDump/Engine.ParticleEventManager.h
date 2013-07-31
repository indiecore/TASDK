#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.ParticleModuleEventSendToGame.h"
namespace UnrealScript
{
	class ParticleEventManager : public Actor
	{
	public:
		void HandleParticleModuleEventSendToGame(class ParticleModuleEventSendToGame* InEvent, Vector& InCollideDirection, Vector& InHitLocation, Vector& InHitNormal, ScriptName& InBoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23084);
			byte params[48] = { NULL };
			*(class ParticleModuleEventSendToGame**)params = InEvent;
			*(Vector*)&params[4] = InCollideDirection;
			*(Vector*)&params[16] = InHitLocation;
			*(Vector*)&params[28] = InHitNormal;
			*(ScriptName*)&params[40] = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InCollideDirection = *(Vector*)&params[4];
			InHitLocation = *(Vector*)&params[16];
			InHitNormal = *(Vector*)&params[28];
			InBoneName = *(ScriptName*)&params[40];
		}
	};
}
