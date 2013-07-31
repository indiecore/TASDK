#pragma once
#include "Core.Object.h"
#include "GameFramework.SeqAct_GameCrowdSpawner.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class GameCrowd_ListOfAgents : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<SeqAct_GameCrowdSpawner::AgentArchetypeInfo>, ListOfAgents, 60)
	};
}
#undef ADD_STRUCT
