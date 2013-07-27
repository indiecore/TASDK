#pragma once
#include "UTGame.UTTeamAI.h"
#include "Engine.Controller.h"
#include "UTGame.UTSquadAI.h"
#include "UTGame.UTCTFFlag.h"
#include "UTGame.UTGameObjective.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFTeamAI : public UTTeamAI
	{
	public:
		ADD_OBJECT(UTCTFFlag, FriendlyFlag, 668)
		ADD_OBJECT(UTCTFFlag, EnemyFlag, 672)
		ADD_STRUCT(float, LastGotFlag, 676)
		class UTSquadAI* AddSquadWithLeader(class Controller* C, class UTGameObjective* O)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46740);
			byte params[12] = { NULL };
			*(class Controller**)params = C;
			*(class UTGameObjective**)&params[4] = O;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTSquadAI**)&params[8];
		}
		class UTGameObjective* GetPriorityFreelanceObjectiveFor(class UTSquadAI* InFreelanceSquad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(46745);
			byte params[8] = { NULL };
			*(class UTSquadAI**)params = InFreelanceSquad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UTGameObjective**)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
