#pragma once
#include "Engine.Info.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrPlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnnouncer." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnnouncer : public Info
	{
	public:
		ADD_OBJECT(TrPlayerController, m_PlayerOwner)
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnnouncer.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnnouncer.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayAnnouncement(class SoundCue* AnnouncementCue, bool bPlayRightNow)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnnouncer.PlayAnnouncement");
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = AnnouncementCue;
			*(bool*)(params + 4) = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AnnouncementFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAnnouncer.AnnouncementFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
