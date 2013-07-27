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
		void PlayImpactSound(class Actor* HitActor, class SoundCue* SoundToPlay, Vector FireDir, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68481);
			byte params[32] = { NULL };
			*(class Actor**)params = HitActor;
			*(class SoundCue**)&params[4] = SoundToPlay;
			*(Vector*)&params[8] = FireDir;
			*(Vector*)&params[20] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayImpactEffects(Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68488);
			byte params[12] = { NULL };
			*(Vector*)params = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
