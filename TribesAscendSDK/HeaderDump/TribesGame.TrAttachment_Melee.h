#pragma once
#include "Engine.SoundCue.h"
#include "TribesGame.TrDeviceAttachment.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrAttachment_Melee : public TrDeviceAttachment
	{
	public:
		void PlayImpactSound(class Actor* HitActor, class SoundCue* SoundToPlay, Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_Melee.PlayImpactSound");
			byte* params = (byte*)malloc(32);
			*(class Actor**)params = HitActor;
			*(class SoundCue**)(params + 4) = SoundToPlay;
			*(Vector*)(params + 8) = FireDir;
			*(Vector*)(params + 20) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayImpactEffects(Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_Melee.PlayImpactEffects");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
