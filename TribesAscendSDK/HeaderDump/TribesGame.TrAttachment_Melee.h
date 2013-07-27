#pragma once
#include "Engine.SoundCue.h"
#include "TribesGame.TrDeviceAttachment.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
namespace UnrealScript
{
	class TrAttachment_Melee : public TrDeviceAttachment
	{
	public:
		void PlayImpactSound(class Actor* HitActor, class SoundCue* SoundToPlay, Object::Vector FireDir, Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_Melee.PlayImpactSound");
			byte params[32] = { NULL };
			*(class Actor**)&params[0] = HitActor;
			*(class SoundCue**)&params[4] = SoundToPlay;
			*(Object::Vector*)&params[8] = FireDir;
			*(Object::Vector*)&params[20] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayImpactEffects(Object::Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAttachment_Melee.PlayImpactEffects");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
