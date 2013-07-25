#pragma once
#include "TribesGame__TrFlagBase.h"
#include "Engine__Controller.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrFlagCTF." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrFlagCTF : public TrFlagBase
	{
	public:
		ADD_VAR(::FloatProperty, m_YouHaveTheFlagReminderTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_ReturnedTimeLimit, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_LastReturnedTime, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'LogTaken'
		// Here lies the not-yet-implemented method 'LogDropped'
		// Here lies the not-yet-implemented method 'ClearHolder'
		// Here lies the not-yet-implemented method 'SendHome'
		// Here lies the not-yet-implemented method 'RemindPlayerAboutFlagTimer'
		// Here lies the not-yet-implemented method 'BroadcastTakenFromBaseMessage'
		// Here lies the not-yet-implemented method 'BroadcastTakenDroppedMessage'
		// Here lies the not-yet-implemented method 'BroadcastCapturedMessage'
		// Here lies the not-yet-implemented method 'BroadcastReturnedMessage'
		// Here lies the not-yet-implemented method 'BroadcastDroppedMessage'
	};
}
#undef ADD_VAR
