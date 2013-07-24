#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_AddNamedBot." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_AddNamedBot." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_AddNamedBot : public SequenceAction
	{
	public:
		ADD_OBJECT(UTBot, SpawnedBot)
		ADD_OBJECT(NavigationPoint, StartSpot)
		ADD_VAR(::IntProperty, TeamIndex, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bForceTeam, 0x1)
		ADD_VAR(::StrProperty, BotName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
