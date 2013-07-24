#pragma once
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
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
