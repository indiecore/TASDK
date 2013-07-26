#pragma once
#include "Core.Object.h"
#include "Core.Object.Vector.h"
namespace UnrealScript
{
	class ParticleModuleEventSendToGame : public Object
	{
	public:
		void DoEvent(Vector& InCollideDirection, Vector& InHitLocation, Vector& InHitNormal, ScriptName& InBoneName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ParticleModuleEventSendToGame.DoEvent");
			byte* params = (byte*)malloc(44);
			*(Vector*)params = InCollideDirection;
			*(Vector*)(params + 12) = InHitLocation;
			*(Vector*)(params + 24) = InHitNormal;
			*(ScriptName*)(params + 36) = InBoneName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InCollideDirection = *(Vector*)params;
			InHitLocation = *(Vector*)(params + 12);
			InHitNormal = *(Vector*)(params + 24);
			InBoneName = *(ScriptName*)(params + 36);
			free(params);
		}
	};
}
