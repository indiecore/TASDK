#pragma once
#include "Engine.SequenceAction.h"
#include "GameFramework.GameCrowd_ListOfAgents.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqAct_GameCrowdPopulationManagerToggle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqAct_GameCrowdPopulationManagerToggle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqAct_GameCrowdPopulationManagerToggle : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, WarmupPct, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bClearOldArchetypes, 0x2)
		ADD_OBJECT(GameCrowd_ListOfAgents, CrowdAgentList)
		ADD_VAR(::FloatProperty, MaxSimulationDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCastShadows, 0x8)
		ADD_VAR(::BoolProperty, bEnableCrowdLightEnvironment, 0x4)
		ADD_VAR(::FloatProperty, SpawnRate, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxAgents, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bKillAgentsInstantly, 0x1)
		ADD_OBJECT(ScriptClass, PopulationManagerClass)
		void FindPopMgrTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.FindPopMgrTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqAct_GameCrowdPopulationManagerToggle.GetObjClassVersion");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
