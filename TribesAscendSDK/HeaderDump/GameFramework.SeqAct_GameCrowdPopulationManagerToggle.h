#pragma once
#include "Engine.SequenceAction.h"
#include "GameFramework.GameCrowd_ListOfAgents.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class SeqAct_GameCrowdPopulationManagerToggle : public SequenceAction
	{
	public:
		ADD_STRUCT(float, WarmupPct, 232)
		ADD_BOOL(bClearOldArchetypes, 236, 0x2)
		ADD_OBJECT(GameCrowd_ListOfAgents, CrowdAgentList, 240)
		ADD_STRUCT(float, MaxSimulationDistance, 252)
		ADD_BOOL(bCastShadows, 236, 0x8)
		ADD_BOOL(bEnableCrowdLightEnvironment, 236, 0x4)
		ADD_STRUCT(float, SpawnRate, 248)
		ADD_STRUCT(int, MaxAgents, 244)
		ADD_BOOL(bKillAgentsInstantly, 236, 0x1)
		ADD_OBJECT(ScriptClass, PopulationManagerClass, 256)
		void FindPopMgrTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32910);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(32911);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
