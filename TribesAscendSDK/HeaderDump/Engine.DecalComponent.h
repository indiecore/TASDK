#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.MaterialInterface.h"
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
	class DecalComponent : public PrimitiveComponent
	{
	public:
		enum EFilterMode : byte
		{
			FM_None = 0,
			FM_Ignore = 1,
			FM_Affect = 2,
			FM_MAX = 3,
		};
		enum EDecalTransform : byte
		{
			DecalTransform_OwnerAbsolute = 0,
			DecalTransform_OwnerRelative = 1,
			DecalTransform_SpawnRelative = 2,
			DecalTransform_MAX = 3,
		};
		class DecalReceiver
		{
		public:
			ADD_STRUCT(Object::Pointer, RenderData, 4)
		};
		ADD_STRUCT(ScriptArray<int>, HitNodeIndices, 632)
		ADD_STRUCT(ScriptArray<DecalComponent::DecalReceiver>, DecalReceivers, 644)
		ADD_STRUCT(ScriptArray<Object::Pointer>, StaticReceivers, 656)
		ADD_STRUCT(ScriptArray<Object::Plane>, Planes, 672)
		ADD_STRUCT(ScriptArray<class Actor*>, Filter, 712)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, ReceiverImages, 724)
		ADD_STRUCT(Object::Vector, OriginalParentRelativeOrientationVec, 772)
		ADD_STRUCT(Object::Vector, OriginalParentRelativeLocation, 760)
		ADD_STRUCT(Object::Rotator, ParentRelativeOrientation, 748)
		ADD_STRUCT(Object::Vector, ParentRelativeLocation, 736)
		ADD_STRUCT(DecalComponent::EFilterMode, FilterMode, 709)
		ADD_STRUCT(DecalComponent::EDecalTransform, DecalTransform, 708)
		ADD_STRUCT(Object::Vector2D, BlendRange, 700)
		ADD_STRUCT(float, BackfaceAngle, 696)
		ADD_STRUCT(int, SortOrder, 692)
		ADD_STRUCT(float, SlopeScaleDepthBias, 688)
		ADD_STRUCT(float, DepthBias, 684)
		ADD_STRUCT(Object::Pointer, ReleaseResourcesFence, 668)
		ADD_STRUCT(int, FracturedStaticMeshComponentIndex, 628)
		ADD_STRUCT(int, HitLevelIndex, 624)
		ADD_STRUCT(int, HitNodeIndex, 620)
		ADD_STRUCT(ScriptName, HitBone, 612)
		ADD_BOOL(bHasBeenAttached, 604, 0x800)
		ADD_BOOL(bMovableDecal, 604, 0x400)
		ADD_BOOL(bFlipBackfaceDirection, 604, 0x200)
		ADD_BOOL(bProjectOnTerrain, 604, 0x100)
		ADD_BOOL(bProjectOnSkeletalMeshes, 604, 0x80)
		ADD_BOOL(bProjectOnStaticMeshes, 604, 0x40)
		ADD_BOOL(bProjectOnBSP, 604, 0x20)
		ADD_BOOL(bProjectOnHidden, 604, 0x10)
		ADD_BOOL(bProjectOnBackfaces, 604, 0x8)
		ADD_BOOL(m_bGameplayRequired, 604, 0x4)
		ADD_BOOL(bStaticDecal, 604, 0x2)
		ADD_BOOL(bNoClip, 604, 0x1)
		ADD_STRUCT(Object::Vector, HitBinormal, 592)
		ADD_STRUCT(Object::Vector, HitTangent, 580)
		ADD_STRUCT(Object::Vector, HitNormal, 568)
		ADD_STRUCT(Object::Vector, HitLocation, 556)
		ADD_STRUCT(Object::Rotator, Orientation, 544)
		ADD_STRUCT(Object::Vector, Location, 532)
		ADD_STRUCT(float, FarPlane, 528)
		ADD_STRUCT(float, NearPlane, 524)
		ADD_STRUCT(float, FieldOfView, 520)
		ADD_STRUCT(float, DecalRotation, 516)
		ADD_STRUCT(float, OffsetY, 512)
		ADD_STRUCT(float, OffsetX, 508)
		ADD_STRUCT(float, TileY, 504)
		ADD_STRUCT(float, TileX, 500)
		ADD_STRUCT(float, Height, 496)
		ADD_STRUCT(float, Width, 492)
		ADD_OBJECT(MaterialInterface, DecalMaterial, 488)
		void ResetToDefaults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.ResetToDefaults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDecalMaterial(class MaterialInterface* NewDecalMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.SetDecalMaterial");
			byte params[4] = { NULL };
			*(class MaterialInterface**)&params[0] = NewDecalMaterial;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class MaterialInterface* GetDecalMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.GetDecalMaterial");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class MaterialInterface**)&params[0];
		}
		void SetGameplayRequired(bool bIsGameplayRelevant)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.SetGameplayRequired");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsGameplayRelevant;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
