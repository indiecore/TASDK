#pragma once
#include "Engine.Volume.h"
#include "Engine.ProcBuildingRuleset.h"
#include "Engine.StaticMeshActor.h"
#include "Engine.Actor.h"
#include "Core.Object.Vector.h"
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
		int FindEdgeForTopLevelScope(int TopLevelScopeIndex, byte Edge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ProcBuilding.FindEdgeForTopLevelScope");
			byte* params = (byte*)malloc(9);
			*(int*)params = TopLevelScopeIndex;
			*(params + 4) = Edge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void BreakFractureComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Comp, Vector BoxMin, Vector BoxMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ProcBuilding.BreakFractureComponent");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Comp;
			*(Vector*)(params + 4) = BoxMin;
			*(Vector*)(params + 16) = BoxMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetAllGroupedProcBuildings(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutSet)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ProcBuilding.GetAllGroupedProcBuildings");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = OutSet;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutSet = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		class ProcBuilding* GetBaseMostBuilding()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ProcBuilding.GetBaseMostBuilding");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class ProcBuilding**)params;
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* FindComponentsForTopLevelScope(int TopLevelScopeIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ProcBuilding.FindComponentsForTopLevelScope");
			byte* params = (byte*)malloc(16);
			*(int*)params = TopLevelScopeIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void ClearBuildingMeshes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.ProcBuilding.ClearBuildingMeshes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
