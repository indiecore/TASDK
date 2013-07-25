#pragma once
#include "UTGame__UTDmgType_Burning.h"
#include "UTGame__UTPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTDmgType_ScorpionSelfDestruct." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTDmgType_ScorpionSelfDestruct : public UTDmgType_Burning
	{
	public:
		ADD_VAR(::IntProperty, DamageGivenForSelfDestruct, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'IncrementKills'
	};
}
#undef ADD_VAR
