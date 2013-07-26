#pragma once
#include "Engine.ProcBuilding.h"
#include "Engine.ProcBuildingRuleset.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ProcBuilding.PBMemUsageInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty ProcBuilding.PBMemUsageInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PBMemUsageInfo
	{
	public:
		ADD_OBJECT(ProcBuilding, Building)
		ADD_OBJECT(ProcBuildingRuleset, Ruleset)
		ADD_VAR(::IntProperty, NumStaticMeshComponent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumInstancedStaticMeshComponents, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumInstancedTris, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LightmapMemBytes, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ShadowmapMemBytes, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LODDiffuseMemBytes, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LODLightingMemBytes, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
