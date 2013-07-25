#pragma once
#include "Engine.Actor.h"
#include "Engine.MaterialInterface.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.DecalManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.DecalManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class DecalManager : public Actor
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D' for the property named 'DecalBlendRange'!
		ADD_VAR(::FloatProperty, DecalDepthBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DecalLifeSpan, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxActiveDecals, 0xFFFFFFFF)
		bool AreDynamicDecalsEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.AreDynamicDecalsEnabled");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void DecalFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Decal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.DecalFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = Decal;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanSpawnDecals()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.CanSpawnDecals");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetDecalParameters(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* TheDecal, class MaterialInterface* DecalMaterial, Vector DecalLocation, Rotator DecalOrientation, float Width, float Height, float Thickness, bool bNoClip, float DecalRotation, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, bool bProjectOnTerrain, bool bProjectOnSkeletalMeshes, ScriptName HitBone, int HitNodeIndex, int HitLevelIndex, int InFracturedStaticMeshComponentIndex, float DepthBias, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* BlendRange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.SetDecalParameters");
			byte* params = (byte*)malloc(96);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = TheDecal;
			*(class MaterialInterface**)(params + 4) = DecalMaterial;
			*(Vector*)(params + 8) = DecalLocation;
			*(Rotator*)(params + 20) = DecalOrientation;
			*(float*)(params + 32) = Width;
			*(float*)(params + 36) = Height;
			*(float*)(params + 40) = Thickness;
			*(bool*)(params + 44) = bNoClip;
			*(float*)(params + 48) = DecalRotation;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 52) = HitComponent;
			*(bool*)(params + 56) = bProjectOnTerrain;
			*(bool*)(params + 60) = bProjectOnSkeletalMeshes;
			*(ScriptName*)(params + 64) = HitBone;
			*(int*)(params + 72) = HitNodeIndex;
			*(int*)(params + 76) = HitLevelIndex;
			*(int*)(params + 80) = InFracturedStaticMeshComponentIndex;
			*(float*)(params + 84) = DepthBias;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 88) = BlendRange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetPooledComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.GetPooledComponent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnDecal(class MaterialInterface* DecalMaterial, Vector DecalLocation, Rotator DecalOrientation, float Width, float Height, float Thickness, bool bNoClip, float DecalRotation, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, bool bProjectOnTerrain, bool bProjectOnSkeletalMeshes, ScriptName HitBone, int HitNodeIndex, int HitLevelIndex, float InDecalLifeSpan, int InFracturedStaticMeshComponentIndex, float InDepthBias, 
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void* InBlendRange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.SpawnDecal");
			byte* params = (byte*)malloc(100);
			*(class MaterialInterface**)params = DecalMaterial;
			*(Vector*)(params + 4) = DecalLocation;
			*(Rotator*)(params + 16) = DecalOrientation;
			*(float*)(params + 28) = Width;
			*(float*)(params + 32) = Height;
			*(float*)(params + 36) = Thickness;
			*(bool*)(params + 40) = bNoClip;
			*(float*)(params + 44) = DecalRotation;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 48) = HitComponent;
			*(bool*)(params + 52) = bProjectOnTerrain;
			*(bool*)(params + 56) = bProjectOnSkeletalMeshes;
			*(ScriptName*)(params + 60) = HitBone;
			*(int*)(params + 68) = HitNodeIndex;
			*(int*)(params + 72) = HitLevelIndex;
			*(float*)(params + 76) = InDecalLifeSpan;
			*(int*)(params + 80) = InFracturedStaticMeshComponentIndex;
			*(float*)(params + 84) = InDepthBias;
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Vector2D'!
void**)(params + 88) = InBlendRange;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 96);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
