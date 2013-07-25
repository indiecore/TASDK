#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrWarningMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrWarningMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, RequiresPowerToFire, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, RequiresCreditsToFire, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SuicidePenalty, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MissileIntercepted, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MissileTargetingYou, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, MissileLockedOnToYou, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SaberLauncherNeedsTargetToFire, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, FumbledFlag, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
	};
}
#undef ADD_VAR
