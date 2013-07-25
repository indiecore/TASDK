#pragma once
#include "UTGame__UTLocalMessage.h"
#include "Core__Object.h"
#include "Engine__PlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDeployableMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDeployableMessage : public UTLocalMessage
	{
	public:
		ADD_VAR(::StrProperty, DeployableAmmoDepleted, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableAmmoRemaining, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramInvalidDeploySpot, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramOnlyOutside, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramTooCloseToAnotherDeployable, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, DeployableHologramTooCloseToEnemyBase, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetString'
	};
}
#undef ADD_VAR
