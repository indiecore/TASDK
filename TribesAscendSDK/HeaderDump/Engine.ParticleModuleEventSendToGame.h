#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class ParticleModuleEventSendToGame : public Object
	{
	public:
		void DoEvent(Object::Vector& InCollideDirection, Object::Vector& InHitLocation, Object::Vector& InHitNormal, ScriptName& InBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleModuleEventSendToGame.DoEvent");
			byte params[44] = { NULL };
			*(Object::Vector*)&params[0] = InCollideDirection;
			*(Object::Vector*)&params[12] = InHitLocation;
			*(Object::Vector*)&params[24] = InHitNormal;
			*(ScriptName*)&params[36] = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InCollideDirection = *(Object::Vector*)&params[0];
			InHitLocation = *(Object::Vector*)&params[12];
			InHitNormal = *(Object::Vector*)&params[24];
			InBoneName = *(ScriptName*)&params[36];
		}
	};
}
