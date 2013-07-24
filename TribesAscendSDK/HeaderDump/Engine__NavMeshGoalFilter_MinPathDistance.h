#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshGoalFilter_MinPathDistance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshGoalFilter_MinPathDistance : public NavMeshGoal_Filter
	{
	public:
		ADD_VAR(::IntProperty, MinDistancePathShouldBe, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
