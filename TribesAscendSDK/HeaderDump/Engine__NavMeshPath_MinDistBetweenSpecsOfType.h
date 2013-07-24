#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NavMeshPath_MinDistBetweenSpecsOfType." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NavMeshPath_MinDistBetweenSpecsOfType : public NavMeshPathConstraint
	{
	public:
		ADD_VAR(::ByteProperty, EdgeType, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, InitLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, MinDistBetweenEdgeTypes, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
