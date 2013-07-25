#pragma once
#include "TribesGame__TrGame.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrCaH." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrCaH : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_nPostCapturePointTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTicketCountTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_5PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_4PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_3PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRemainingTicketTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
