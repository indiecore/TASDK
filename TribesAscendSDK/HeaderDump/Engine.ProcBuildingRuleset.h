#pragma once
#include "Core.Object.h"
#include "Engine.PBRuleNodeBase.h"
#include "Engine.MaterialInterface.h"
#include "Engine.PBRuleNodeComment.h"
#include "Engine.Texture.h"
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
	class ProcBuildingRuleset : public Object
	{
	public:
		enum EProcBuildingAxis : byte
		{
			EPBAxis_X = 0,
			EPBAxis_Z = 1,
			EPBAxis_MAX = 2,
		};
		struct PBParamSwatch
		{
		public:
			ADD_STRUCT(ScriptName, SwatchName, 0)
			ADD_STRUCT(ScriptArray<ProcBuilding::PBMaterialParam>, Params, 8)
		};
		struct PBVariationInfo
		{
		public:
			ADD_STRUCT(ScriptName, VariationName, 0)
			ADD_BOOL(bMeshOnTopOfFacePoly, 8, 0x1)
		};
		ADD_OBJECT(PBRuleNodeBase, RootRule, 60)
		ADD_BOOL(bBeingEdited, 64, 0x1)
		ADD_BOOL(bEnableInteriorTexture, 64, 0x2)
		ADD_BOOL(bLODOnlyRoof, 64, 0x4)
		ADD_BOOL(bPickRandomSwatch, 64, 0x8)
		ADD_OBJECT(MaterialInterface, DefaultRoofMaterial, 68)
		ADD_OBJECT(MaterialInterface, DefaultFloorMaterial, 72)
		ADD_OBJECT(MaterialInterface, DefaultNonRectWallMaterial, 76)
		ADD_STRUCT(float, RoofZOffset, 80)
		ADD_STRUCT(float, NotRoofZOffset, 84)
		ADD_STRUCT(float, FloorZOffset, 88)
		ADD_STRUCT(float, NotFloorZOffset, 92)
		ADD_STRUCT(float, RoofPolyInset, 96)
		ADD_STRUCT(float, FloorPolyInset, 100)
		ADD_STRUCT(float, BuildingLODSpecular, 104)
		ADD_STRUCT(float, RoofEdgeScopeRaise, 108)
		ADD_OBJECT(Texture, LODCubemap, 112)
		ADD_OBJECT(Texture, InteriorTexture, 116)
		ADD_STRUCT(ScriptArray<ProcBuildingRuleset::PBVariationInfo>, Variations, 120)
		ADD_STRUCT(ScriptArray<ProcBuildingRuleset::PBParamSwatch>, ParamSwatches, 132)
		ADD_STRUCT(ScriptArray<class PBRuleNodeComment*>, Comments, 144)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
