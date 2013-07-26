#pragma once
#include "Engine.StaticMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PBRuleNodeMesh.BuildingMeshInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty PBRuleNodeMesh.BuildingMeshInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class BuildingMeshInfo
	{
	public:
		ADD_VAR(::IntProperty, OverriddenMeshLightMapRes, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOverrideMeshLightMapRes, 0x2)
		ADD_VAR(::BoolProperty, bMeshScaleTranslation, 0x1)
		ADD_VAR(::FloatProperty, Chance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DimZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DimX, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, Mesh)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
