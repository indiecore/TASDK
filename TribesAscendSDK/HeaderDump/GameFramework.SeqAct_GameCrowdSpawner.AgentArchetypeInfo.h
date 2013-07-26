#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " SeqAct_GameCrowdSpawner.AgentArchetypeInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty SeqAct_GameCrowdSpawner.AgentArchetypeInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AgentArchetypeInfo
	{
	public:
		ADD_VAR(::IntProperty, CurrSpawned, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxAllowed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FrequencyModifier, 0xFFFFFFFF)
		ADD_OBJECT(Object, AgentArchetype)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
