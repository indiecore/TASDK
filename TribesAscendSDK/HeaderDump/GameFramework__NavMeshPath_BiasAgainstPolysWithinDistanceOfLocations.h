#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_BiasAgainstPolysWithinDistanceOfLocations : public NavMeshPathConstraint
	{
	public:
		ADD_VAR(::FloatProperty, DistanceToCheck, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Rotation, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
