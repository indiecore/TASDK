#pragma once
#include "Engine.Texture2D.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.SpeedTree.h"
#include "Engine.MaterialInterface.h"
#include "Engine.EngineTypes.h"
#include "Core.Object.h"
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
	class SpeedTreeComponent : public PrimitiveComponent
	{
	public:
		enum ESpeedTreeMeshType : byte
		{
			STMT_MinMinusOne = 0,
			STMT_Branches1 = 1,
			STMT_Branches2 = 2,
			STMT_Fronds = 3,
			STMT_LeafCards = 4,
			STMT_LeafMeshes = 5,
			STMT_Billboards = 6,
			STMT_Max = 7,
		};
		class SpeedTreeStaticLight
		{
		public:
			ADD_OBJECT(ShadowMap1D, BillboardShadowMap, 32)
			ADD_OBJECT(ShadowMap1D, LeafCardShadowMap, 28)
			ADD_OBJECT(ShadowMap1D, LeafMeshShadowMap, 24)
			ADD_OBJECT(ShadowMap1D, FrondShadowMap, 20)
			ADD_OBJECT(ShadowMap1D, BranchShadowMap, 16)
			ADD_STRUCT(Object::Guid, Guid, 0)
		};
		ADD_STRUCT(ScriptArray<SpeedTreeComponent::SpeedTreeStaticLight>, StaticLights, 544)
		ADD_STRUCT(EngineTypes::LightmassPrimitiveSettings, LightmassSettings, 640)
		ADD_STRUCT(Object::Matrix, RotationOnlyMatrix, 576)
		ADD_STRUCT(EngineTypes::LightMapRef, BillboardLightMap, 572)
		ADD_STRUCT(EngineTypes::LightMapRef, LeafCardLightMap, 568)
		ADD_STRUCT(EngineTypes::LightMapRef, LeafMeshLightMap, 564)
		ADD_STRUCT(EngineTypes::LightMapRef, FrondLightMap, 560)
		ADD_STRUCT(EngineTypes::LightMapRef, BranchLightMap, 556)
		ADD_OBJECT(Texture2D, SpeedTreeIcon, 540)
		ADD_OBJECT(MaterialInterface, BillboardMaterial, 536)
		ADD_OBJECT(MaterialInterface, LeafMeshMaterial, 532)
		ADD_OBJECT(MaterialInterface, LeafCardMaterial, 528)
		ADD_OBJECT(MaterialInterface, FrondMaterial, 524)
		ADD_OBJECT(MaterialInterface, Branch2Material, 520)
		ADD_OBJECT(MaterialInterface, Branch1Material, 516)
		ADD_STRUCT(float, LodLevelOverride, 512)
		ADD_STRUCT(float, LodBillboardEnd, 508)
		ADD_STRUCT(float, LodBillboardStart, 504)
		ADD_STRUCT(float, Lod3DEnd, 500)
		ADD_STRUCT(float, Lod3DStart, 496)
		ADD_BOOL(bUseBillboards, 492, 0x10)
		ADD_BOOL(bUseFronds, 492, 0x8)
		ADD_BOOL(bUseBranches, 492, 0x4)
		ADD_BOOL(bUseLeafMeshes, 492, 0x2)
		ADD_BOOL(bUseLeafCards, 492, 0x1)
		ADD_OBJECT(SpeedTree, SpeedTree, 488)
		class MaterialInterface* GetMaterial(SpeedTreeComponent::ESpeedTreeMeshType MeshType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpeedTreeComponent.GetMaterial");
			byte params[5] = { NULL };
			*(SpeedTreeComponent::ESpeedTreeMeshType*)&params[0] = MeshType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[4];
		}
		void SetMaterial(SpeedTreeComponent::ESpeedTreeMeshType MeshType, class MaterialInterface* Material)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SpeedTreeComponent.SetMaterial");
			byte params[5] = { NULL };
			*(SpeedTreeComponent::ESpeedTreeMeshType*)&params[0] = MeshType;
			*(class MaterialInterface**)&params[4] = Material;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
