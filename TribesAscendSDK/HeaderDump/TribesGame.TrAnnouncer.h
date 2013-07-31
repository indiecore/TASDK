#pragma once
#include "Engine.Info.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.SoundCue.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrAnnouncer : public Info
	{
	public:
		ADD_STRUCT(ScriptArray<class SoundCue*>, m_QueuedAnnouncements, 476)
		ADD_OBJECT(TrPlayerController, m_PlayerOwner, 492)
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66546);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66547);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayAnnouncement(class SoundCue* AnnouncementCue, bool bPlayRightNow)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66548);
			byte params[8] = { NULL };
			*(class SoundCue**)params = AnnouncementCue;
			*(bool*)&params[4] = bPlayRightNow;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AnnouncementFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66551);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
