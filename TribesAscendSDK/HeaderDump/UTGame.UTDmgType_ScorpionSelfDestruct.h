#pragma once
#include "UTGame.UTDmgType_Burning.h"
#include "UTGame.UTPlayerReplicationInfo.h"
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
		int IncrementKills(class UTPlayerReplicationInfo* KillerPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDmgType_ScorpionSelfDestruct.IncrementKills");
			byte* params = (byte*)malloc(8);
			*(class UTPlayerReplicationInfo**)params = KillerPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
