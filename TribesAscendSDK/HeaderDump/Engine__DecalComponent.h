#pragma once
#include "Engine__PrimitiveComponent.h"
#include "Engine__MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DecalComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DecalComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.DecalComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class DecalComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(::VectorProperty, OriginalParentRelativeOrientationVec, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, OriginalParentRelativeLocation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, ParentRelativeOrientation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ParentRelativeLocation, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, FilterMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DecalTransform, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'BlendRange'!
		ADD_VAR(::FloatProperty, BackfaceAngle, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SortOrder, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlopeScaleDepthBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DepthBias, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ReleaseResourcesFence'!
		ADD_VAR(::IntProperty, FracturedStaticMeshComponentIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HitLevelIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, HitNodeIndex, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, HitBone, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasBeenAttached, 0x800)
		ADD_VAR(::BoolProperty, bMovableDecal, 0x400)
		ADD_VAR(::BoolProperty, bFlipBackfaceDirection, 0x200)
		ADD_VAR(::BoolProperty, bProjectOnTerrain, 0x100)
		ADD_VAR(::BoolProperty, bProjectOnSkeletalMeshes, 0x80)
		ADD_VAR(::BoolProperty, bProjectOnStaticMeshes, 0x40)
		ADD_VAR(::BoolProperty, bProjectOnBSP, 0x20)
		ADD_VAR(::BoolProperty, bProjectOnHidden, 0x10)
		ADD_VAR(::BoolProperty, bProjectOnBackfaces, 0x8)
		ADD_VAR(::BoolProperty, m_bGameplayRequired, 0x4)
		ADD_VAR(::BoolProperty, bStaticDecal, 0x2)
		ADD_VAR(::BoolProperty, bNoClip, 0x1)
		ADD_STRUCT(::VectorProperty, HitBinormal, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HitTangent, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HitNormal, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, HitLocation, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, Orientation, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FarPlane, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NearPlane, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FieldOfView, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffsetY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OffsetX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TileY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TileX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Height, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Width, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, DecalMaterial)
		void ResetToDefaults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.ResetToDefaults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetDecalMaterial(class MaterialInterface* NewDecalMaterial)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.SetDecalMaterial");
			byte* params = (byte*)malloc(4);
			*(class MaterialInterface**)params = NewDecalMaterial;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class MaterialInterface* GetDecalMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.GetDecalMaterial");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class MaterialInterface**)params;
			free(params);
			return returnVal;
		}
		void SetGameplayRequired(bool bIsGameplayRelevant)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalComponent.SetGameplayRequired");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsGameplayRelevant;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
