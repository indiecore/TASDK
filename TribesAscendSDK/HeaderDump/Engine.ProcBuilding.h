#pragma once
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.Volume.h"
#include "Engine.ProcBuildingRuleset.h"
#include "Engine.StaticMeshActor.h"
#include "Core.Object.h"
#include "Engine.Actor.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ProcBuilding : public Volume
	{
	public:
		static const auto PROCBUILDING_VERSION = 1;
		static const float ROOF_MINZ;
		enum EScopeEdge : byte
		{
			EPSA_Top = 0,
			EPSA_Bottom = 1,
			EPSA_Left = 2,
			EPSA_Right = 3,
			EPSA_None = 4,
			EPSA_MAX = 5,
		};
		enum EBuildingStatsBrowserColumns : byte
		{
			BSBC_Name = 0,
			BSBC_Ruleset = 1,
			BSBC_NumStaticMeshComps = 2,
			BSBC_NumInstancedStaticMeshComps = 3,
			BSBC_NumInstancedTris = 4,
			BSBC_LightmapMemBytes = 5,
			BSBC_ShadowmapMemBytes = 6,
			BSBC_LODDiffuseMemBytes = 7,
			BSBC_LODLightingMemBytes = 8,
			BSBC_MAX = 9,
		};
		enum EPBCornerType : byte
		{
			EPBC_Default = 0,
			EPBC_Chamfer = 1,
			EPBC_Round = 2,
			EPBC_MAX = 3,
		};
		struct PBMaterialParam
		{
		public:
			ADD_STRUCT(ScriptName, ParamName, 0)
			ADD_STRUCT(Object::LinearColor, Color, 8)
		};
		struct PBFracMeshCompInfo
		{
		public:
			ADD_STRUCT(int, TopLevelScopeIndex, 4)
		};
		struct PBFaceUVInfo
		{
		public:
			ADD_STRUCT(Object::Vector2D, Offset, 0)
			ADD_STRUCT(Object::Vector2D, Size, 8)
		};
		struct PBMemUsageInfo
		{
		public:
			ADD_OBJECT(ProcBuilding, Building, 0)
			ADD_OBJECT(ProcBuildingRuleset, Ruleset, 4)
			ADD_STRUCT(int, NumStaticMeshComponent, 8)
			ADD_STRUCT(int, NumInstancedStaticMeshComponents, 12)
			ADD_STRUCT(int, NumInstancedTris, 16)
			ADD_STRUCT(int, LightmapMemBytes, 20)
			ADD_STRUCT(int, ShadowmapMemBytes, 24)
			ADD_STRUCT(int, LODDiffuseMemBytes, 28)
			ADD_STRUCT(int, LODLightingMemBytes, 32)
		};
		struct PBMeshCompInfo
		{
		public:
			ADD_STRUCT(int, TopLevelScopeIndex, 4)
		};
		struct PBScopeProcessInfo
		{
		public:
			ADD_OBJECT(ProcBuilding, OwningBuilding, 0)
			ADD_OBJECT(ProcBuildingRuleset, Ruleset, 4)
			ADD_STRUCT(ScriptName, RulesetVariation, 8)
			ADD_BOOL(bGenerateLODPoly, 16, 0x1)
			ADD_BOOL(bPartOfNonRect, 16, 0x2)
		};
		struct PBScope2D
		{
		public:
			ADD_STRUCT(Object::Matrix, ScopeFrame, 0)
			ADD_STRUCT(float, DimX, 64)
			ADD_STRUCT(float, DimZ, 68)
		};
		struct PBEdgeInfo
		{
		public:
			ADD_STRUCT(Vector, EdgeEnd, 0)
			ADD_STRUCT(Vector, EdgeStart, 12)
			ADD_STRUCT(int, ScopeAIndex, 24)
			ADD_STRUCT(ProcBuilding::EScopeEdge, ScopeAEdge, 28)
			ADD_STRUCT(int, ScopeBIndex, 32)
			ADD_STRUCT(ProcBuilding::EScopeEdge, ScopeBEdge, 36)
			ADD_STRUCT(float, EdgeAngle, 40)
		};
		ADD_OBJECT(ProcBuildingRuleset, Ruleset, 520)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBMeshCompInfo>, BuildingMeshCompInfos, 524)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBFracMeshCompInfo>, BuildingFracMeshCompInfos, 536)
		ADD_BOOL(bGenerateRoofMesh, 552, 0x1)
		ADD_BOOL(bGenerateFloorMesh, 552, 0x2)
		ADD_BOOL(bApplyRulesToRoof, 552, 0x4)
		ADD_BOOL(bApplyRulesToFloor, 552, 0x8)
		ADD_BOOL(bSplitWallsAtRoofLevels, 552, 0x10)
		ADD_BOOL(bSplitWallsAtWallEdges, 552, 0x20)
		ADD_BOOL(bQuickEdited, 552, 0x40)
		ADD_BOOL(bBuildingBrushCollision, 552, 0x80)
		ADD_BOOL(bDebugDrawEdgeInfo, 552, 0x100)
		ADD_BOOL(bDebugDrawScopes, 552, 0x200)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, LODMeshComps, 556)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBFaceUVInfo>, LODMeshUVInfos, 568)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBScope2D>, TopLevelScopes, 580)
		ADD_STRUCT(int, NumMeshedTopLevelScopes, 592)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBFaceUVInfo>, TopLevelScopeUVInfos, 596)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBScopeProcessInfo>, TopLevelScopeInfos, 608)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBEdgeInfo>, EdgeInfos, 620)
		ADD_STRUCT(float, MaxFacadeZ, 632)
		ADD_STRUCT(float, MinFacadeZ, 636)
		ADD_STRUCT(ScriptArray<class ProcBuilding*>, OverlappingBuildings, 640)
		ADD_STRUCT(float, SimpleMeshMassiveLODDistance, 652)
		ADD_STRUCT(float, RenderToTexturePullBackAmount, 656)
		ADD_STRUCT(int, RoofLightmapRes, 660)
		ADD_STRUCT(int, NonRectWallLightmapRes, 664)
		ADD_STRUCT(float, LODRenderToTextureScale, 668)
		ADD_STRUCT(ScriptName, ParamSwatchName, 672)
		ADD_STRUCT(ScriptArray<ProcBuilding::PBMaterialParam>, BuildingMaterialParams, 680)
		ADD_STRUCT(ScriptArray<class MaterialInstanceConstant*>, BuildingMatParamMICs, 692)
		ADD_OBJECT(StaticMeshActor, LowLODPersistentActor, 704)
		ADD_OBJECT(Actor, CurrentSimpleMeshActor, 712)
		ADD_STRUCT(ScriptArray<class ProcBuilding*>, AttachedBuildings, 716)
		ADD_STRUCT(int, BuildingInstanceVersion, 728)
		int FindEdgeForTopLevelScope(int TopLevelScopeIndex, ProcBuilding::EScopeEdge Edge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24086);
			byte params[9] = { NULL };
			*(int*)params = TopLevelScopeIndex;
			*(ProcBuilding::EScopeEdge*)&params[4] = Edge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void BreakFractureComponent(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Comp, Vector BoxMin, Vector BoxMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24087);
			byte params[28] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Comp;
			*(Vector*)&params[4] = BoxMin;
			*(Vector*)&params[16] = BoxMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetAllGroupedProcBuildings(ScriptArray<class ProcBuilding*>& OutSet)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24093);
			byte params[12] = { NULL };
			*(ScriptArray<class ProcBuilding*>*)params = OutSet;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutSet = *(ScriptArray<class ProcBuilding*>*)params;
		}
		class ProcBuilding* GetBaseMostBuilding()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24097);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class ProcBuilding**)params;
		}
		ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*> FindComponentsForTopLevelScope(int TopLevelScopeIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24100);
			byte params[16] = { NULL };
			*(int*)params = TopLevelScopeIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>*)&params[4];
		}
		void ClearBuildingMeshes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24102);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
	const float ProcBuilding::ROOF_MINZ = 0.7f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
