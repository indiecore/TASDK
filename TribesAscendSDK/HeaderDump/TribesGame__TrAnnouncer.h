#pragma once
#include "Engine__SoundCue.h"
#include "Engine__Info.h"
#include "TribesGame__TrPlayerController.h"
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
		// Here lies the not-yet-implemented method 'Destroyed'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PlayAnnouncement'
		// Here lies the not-yet-implemented method 'AnnouncementFinished'
	};
}
#undef ADD_OBJECT
