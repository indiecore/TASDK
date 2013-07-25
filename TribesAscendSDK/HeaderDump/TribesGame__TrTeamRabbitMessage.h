#pragma once
#include "UTGame__UTLocalMessage.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTeamRabbitMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrTeamRabbitMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, LivesLeft, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, EnemyTeamHas, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YourTeamHas, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DroppedTheFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, KillBonus, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YourTeamHasTheFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, TheEnemyHasTheFlag, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, YouHaveTheFlag, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
