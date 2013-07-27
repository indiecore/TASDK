#pragma once
#include "UTGame.UTDmgType_Burning.h"
#include "UTGame.UTPlayerReplicationInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTDmgType_ScorpionSelfDestruct : public UTDmgType_Burning
	{
	public:
		ADD_STRUCT(int, DamageGivenForSelfDestruct, 300)
		int IncrementKills(class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_ScorpionSelfDestruct.IncrementKills");
			byte params[8] = { NULL };
			*(class UTPlayerReplicationInfo**)&params[0] = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
	};
}
#undef ADD_STRUCT
