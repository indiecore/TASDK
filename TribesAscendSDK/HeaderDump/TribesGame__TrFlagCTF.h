#pragma once
#include "TribesGame__TrFlagBase.h"
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
	};
}
#undef ADD_VAR
