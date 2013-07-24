#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.GameCrowdBehavior_RunFromPanic." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.GameCrowdBehavior_RunFromPanic." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameCrowdBehavior_RunFromPanic : public GameCrowdAgentBehavior
	{
	public:
		ADD_VAR(::FloatProperty, TimeToStopPanic, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DurationOfPanic, 0xFFFFFFFF)
		ADD_OBJECT(Actor, PanicFocus)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
