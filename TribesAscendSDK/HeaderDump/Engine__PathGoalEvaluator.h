#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PathGoalEvaluator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PathGoalEvaluator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PathGoalEvaluator : public Object
	{
	public:
		ADD_VAR(::IntProperty, CacheIdx, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxPathVisits, 0xFFFFFFFF)
		ADD_OBJECT(NavigationPoint, GeneratedGoal)
		ADD_OBJECT(PathGoalEvaluator, NextEvaluator)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
