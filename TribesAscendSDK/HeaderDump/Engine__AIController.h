#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AIController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AIController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AIController : public Controller
	{
	public:
		ADD_OBJECT(Actor, ScriptedFocus)
		ADD_VAR(::IntProperty, ScriptedRouteIndex, 0xFFFFFFFF)
		ADD_OBJECT(Route, ScriptedRoute)
		ADD_OBJECT(Actor, ScriptedMoveTarget)
		ADD_VAR(::FloatProperty, Skill, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bReverseScriptedRoute, 0x2)
		ADD_VAR(::BoolProperty, bAdjustFromWalls, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
