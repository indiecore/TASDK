#pragma once
#include "Core.Object.h"
namespace UnrealScript
{
	class ParticleModuleEventSendToGame : public Object
	{
	public:
		void DoEvent(Vector& InCollideDirection, Vector& InHitLocation, Vector& InHitNormal, ScriptName& InBoneName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23311);
			byte params[44] = { NULL };
			*(Vector*)params = InCollideDirection;
			*(Vector*)&params[12] = InHitLocation;
			*(Vector*)&params[24] = InHitNormal;
			*(ScriptName*)&params[36] = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InCollideDirection = *(Vector*)params;
			InHitLocation = *(Vector*)&params[12];
			InHitNormal = *(Vector*)&params[24];
			InBoneName = *(ScriptName*)&params[36];
		}
	};
}
