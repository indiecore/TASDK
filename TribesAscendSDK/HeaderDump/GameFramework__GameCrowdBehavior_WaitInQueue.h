#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdBehavior_WaitInQueue." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdBehavior_WaitInQueue." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdBehavior_WaitInQueue : public GameCrowdAgentBehavior
	{
	public:
		ADD_OBJECT(GameCrowdDestinationQueuePoint, QueuePosition)
		ADD_VAR(::BoolProperty, bStoppingBehavior, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
