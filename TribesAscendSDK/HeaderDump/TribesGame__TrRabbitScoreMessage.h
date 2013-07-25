#pragma once
#include "Engine__PlayerController.h"
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Engine__SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrRabbitScoreMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrRabbitScoreMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrRabbitScoreMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundCue, m_sFlagReturnedToStand)
		ADD_OBJECT(SoundCue, m_sYouPickedUpFlag)
		ADD_OBJECT(SoundCue, m_sOtherIsNewLeadeCue)
		ADD_OBJECT(SoundCue, m_sYouAreNewLeadeCue)
		ADD_VAR(::StrProperty, GetToTheFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KillTheRabbit, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherDroppedFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouDroppedFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherIsNewLeader, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouAreNewLeader, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, OtherScoreFlagTouch, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouScoreFlagTouch, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
		// Here lies the not-yet-implemented method 'ClientReceive'
		// Here lies the not-yet-implemented method 'AnnouncementLevel'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
