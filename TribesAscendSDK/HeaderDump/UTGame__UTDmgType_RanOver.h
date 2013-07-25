#pragma once
#include "UTGame__UTDamageType.h"
#include "UTGame__UTPlayerController.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDmgType_RanOver." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTDmgType_RanOver : public UTDamageType
	{
	public:
		ADD_VAR(::IntProperty, NumMessages, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IncrementKills'
		// Here lies the not-yet-implemented method 'SmallReward'
		// Here lies the not-yet-implemented method 'SpawnHitEffect'
	};
}
#undef ADD_VAR
