#pragma once
#include "TribesGame__TrGame.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrArena." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrArena : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_nGoalWonRounds, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_bHasTeamBenchedAPlayer, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNumEnemiesAliveAtLastManStanding, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
