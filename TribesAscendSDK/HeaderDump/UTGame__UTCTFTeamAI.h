#pragma once
#include "UTGame__UTTeamAI.h"
#include "UTGame__UTCTFFlag.h"
#include "UTGame__UTSquadAI.h"
#include "Engine__Controller.h"
#include "UTGame__UTGameObjective.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFTeamAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFTeamAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFTeamAI : public UTTeamAI
	{
	public:
		ADD_OBJECT(UTCTFFlag, FriendlyFlag)
		ADD_OBJECT(UTCTFFlag, EnemyFlag)
		ADD_VAR(::FloatProperty, LastGotFlag, 0xFFFFFFFF)
		class UTSquadAI* AddSquadWithLeader(class Controller* C, class UTGameObjective* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFTeamAI.AddSquadWithLeader");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = C;
			*(class UTGameObjective**)(params + 4) = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTSquadAI**)(params + 8);
			free(params);
			return returnVal;
		}
		class UTGameObjective* GetPriorityFreelanceObjectiveFor(class UTSquadAI* InFreelanceSquad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFTeamAI.GetPriorityFreelanceObjectiveFor");
			byte* params = (byte*)malloc(8);
			*(class UTSquadAI**)params = InFreelanceSquad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UTGameObjective**)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
