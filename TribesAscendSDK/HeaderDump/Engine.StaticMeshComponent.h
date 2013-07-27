#pragma once
#include "Engine.Texture.h"
#include "Engine.MeshComponent.h"
#include "Core.Object.h"
#include "Engine.EngineTypes.h"
#include "Engine.StaticMesh.h"
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
	class StaticMeshComponent : public MeshComponent
	{
	public:
		enum ELightmapModificationFunction : byte
		{
			MLMF_Modulate = 0,
			MLMF_ModulateAlpha = 1,
			MLMF_MAX = 2,
		};
		class StaticMeshComponentLODInfo
		{
		public:
			ADD_STRUCT(ScriptArray<class ShadowMap2D*>, ShadowMaps, 0)
			ADD_STRUCT(ScriptArray<class Object*>, ShadowVertexBuffers, 12)
			ADD_STRUCT(ScriptArray<Object::Vector>, VertexColorPositions, 32)
			ADD_STRUCT(Object::Pointer, OverrideVertexColors, 28)
			ADD_STRUCT(Object::Pointer, LightMap, 24)
		};
		ADD_STRUCT(ScriptArray<Object::Guid>, IrrelevantLights, 552)
		ADD_STRUCT(ScriptArray<StaticMeshComponent::StaticMeshComponentLODInfo>, LODData, 564)
		ADD_STRUCT(EngineTypes::LightmassPrimitiveSettings, LightmassSettings, 580)
		ADD_STRUCT(int, VertexPositionVersionNumber, 576)
		ADD_BOOL(bNeverBecomeDynamic, 548, 0x1)
		ADD_STRUCT(StaticMeshComponent::ELightmapModificationFunction, SimpleLightmapModificationFunction, 544)
		ADD_STRUCT(int, ForcedLodModel, 500)
		ADD_OBJECT(Texture, SimpleLightmapModificationTexture, 540)
		ADD_BOOL(bUseSimpleLightmapModifications, 536, 0x8)
		ADD_BOOL(bCanHighlightSelectedSections, 536, 0x4)
		ADD_BOOL(bForceStaticDecals, 536, 0x2)
		ADD_BOOL(bUseSubDivisions, 536, 0x1)
		ADD_STRUCT(int, SubDivisionStepSize, 532)
		ADD_STRUCT(float, OverriddenLODMaxRange, 528)
		ADD_STRUCT(int, OverriddenLightMapRes, 524)
		ADD_STRUCT(int, OverriddenLightMapResolution, 520)
		ADD_BOOL(bOverrideLightMapRes, 516, 0x4)
		ADD_BOOL(bOverrideLightMapResolution, 516, 0x2)
		ADD_BOOL(bIgnoreInstanceForTextureStreaming, 516, 0x1)
		ADD_STRUCT(Object::Color, WireframeColor, 512)
		ADD_OBJECT(StaticMesh, StaticMesh, 508)
		ADD_STRUCT(int, PreviousLODLevel, 504)
		bool CanBecomeDynamic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshComponent.CanBecomeDynamic");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SetStaticMesh(class StaticMesh* NewMesh, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshComponent.SetStaticMesh");
			byte params[12] = { NULL };
			*(class StaticMesh**)&params[0] = NewMesh;
			*(bool*)&params[4] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DisableRBCollisionWithSMC(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* OtherSMC, bool bDisabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshComponent.DisableRBCollisionWithSMC");
			byte params[8] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = OtherSMC;
			*(bool*)&params[4] = bDisabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetForceStaticDecals(bool bInForceStaticDecals)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.StaticMeshComponent.SetForceStaticDecals");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bInForceStaticDecals;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
