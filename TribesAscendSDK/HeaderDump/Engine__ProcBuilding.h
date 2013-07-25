#pragma once
#include "Engine__Volume.h"
#include "Engine__ProcBuildingRuleset.h"
#include "Engine__StaticMeshActor.h"
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ProcBuilding." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ProcBuilding." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ProcBuilding : public Volume
	{
	public:
		ADD_OBJECT(ProcBuildingRuleset, Ruleset)
		ADD_VAR(::BoolProperty, bGenerateRoofMesh, 0x1)
		ADD_VAR(::BoolProperty, bGenerateFloorMesh, 0x2)
		ADD_VAR(::BoolProperty, bApplyRulesToRoof, 0x4)
		ADD_VAR(::BoolProperty, bApplyRulesToFloor, 0x8)
		ADD_VAR(::BoolProperty, bSplitWallsAtRoofLevels, 0x10)
		ADD_VAR(::BoolProperty, bSplitWallsAtWallEdges, 0x20)
		ADD_VAR(::BoolProperty, bQuickEdited, 0x40)
		ADD_VAR(::BoolProperty, bBuildingBrushCollision, 0x80)
		ADD_VAR(::BoolProperty, bDebugDrawEdgeInfo, 0x100)
		ADD_VAR(::BoolProperty, bDebugDrawScopes, 0x200)
		ADD_VAR(::IntProperty, NumMeshedTopLevelScopes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxFacadeZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinFacadeZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SimpleMeshMassiveLODDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RenderToTexturePullBackAmount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RoofLightmapRes, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NonRectWallLightmapRes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LODRenderToTextureScale, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ParamSwatchName, 0xFFFFFFFF)
		ADD_OBJECT(StaticMeshActor, LowLODPersistentActor)
		ADD_OBJECT(Actor, CurrentSimpleMeshActor)
		ADD_VAR(::IntProperty, BuildingInstanceVersion, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'FindEdgeForTopLevelScope'
		// Here lies the not-yet-implemented method 'BreakFractureComponent'
		// Here lies the not-yet-implemented method 'GetAllGroupedProcBuildings'
		// Here lies the not-yet-implemented method 'GetBaseMostBuilding'
		// Here lies the not-yet-implemented method 'FindComponentsForTopLevelScope'
		// Here lies the not-yet-implemented method 'ClearBuildingMeshes'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
