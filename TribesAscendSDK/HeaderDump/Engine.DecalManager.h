#pragma once
#include "Core.Object.h"
#include "Engine.Actor.h"
#include "Engine.MaterialInterface.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class DecalManager : public Actor
	{
	public:
		class ActiveDecalInfo
		{
		public:
			ADD_STRUCT(float, LifetimeRemaining, 4)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, PoolDecals, 480)
		ADD_STRUCT(ScriptArray<DecalManager::ActiveDecalInfo>, ActiveDecals, 512)
		ADD_STRUCT(Object::Vector2D, DecalBlendRange, 504)
		ADD_STRUCT(float, DecalDepthBias, 500)
		ADD_STRUCT(float, DecalLifeSpan, 496)
		ADD_STRUCT(int, MaxActiveDecals, 492)
		bool AreDynamicDecalsEnabled()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.AreDynamicDecalsEnabled");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void DecalFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* Decal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.DecalFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = Decal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanSpawnDecals()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.CanSpawnDecals");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetDecalParameters(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* TheDecal, class MaterialInterface* DecalMaterial, Object::Vector DecalLocation, Object::Rotator DecalOrientation, float Width, float Height, float Thickness, bool bNoClip, float DecalRotation, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, bool bProjectOnTerrain, bool bProjectOnSkeletalMeshes, ScriptName HitBone, int HitNodeIndex, int HitLevelIndex, int InFracturedStaticMeshComponentIndex, float DepthBias, Object::Vector2D BlendRange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.SetDecalParameters");
			byte params[96] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = TheDecal;
			*(class MaterialInterface**)&params[4] = DecalMaterial;
			*(Object::Vector*)&params[8] = DecalLocation;
			*(Object::Rotator*)&params[20] = DecalOrientation;
			*(float*)&params[32] = Width;
			*(float*)&params[36] = Height;
			*(float*)&params[40] = Thickness;
			*(bool*)&params[44] = bNoClip;
			*(float*)&params[48] = DecalRotation;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[52] = HitComponent;
			*(bool*)&params[56] = bProjectOnTerrain;
			*(bool*)&params[60] = bProjectOnSkeletalMeshes;
			*(ScriptName*)&params[64] = HitBone;
			*(int*)&params[72] = HitNodeIndex;
			*(int*)&params[76] = HitLevelIndex;
			*(int*)&params[80] = InFracturedStaticMeshComponentIndex;
			*(float*)&params[84] = DepthBias;
			*(Object::Vector2D*)&params[88] = BlendRange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetPooledComponent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.GetPooledComponent");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0];
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SpawnDecal(class MaterialInterface* DecalMaterial, Object::Vector DecalLocation, Object::Rotator DecalOrientation, float Width, float Height, float Thickness, bool bNoClip, float DecalRotation, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* HitComponent, bool bProjectOnTerrain, bool bProjectOnSkeletalMeshes, ScriptName HitBone, int HitNodeIndex, int HitLevelIndex, float InDecalLifeSpan, int InFracturedStaticMeshComponentIndex, float InDepthBias, Object::Vector2D InBlendRange)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.DecalManager.SpawnDecal");
			byte params[100] = { NULL };
			*(class MaterialInterface**)&params[0] = DecalMaterial;
			*(Object::Vector*)&params[4] = DecalLocation;
			*(Object::Rotator*)&params[16] = DecalOrientation;
			*(float*)&params[28] = Width;
			*(float*)&params[32] = Height;
			*(float*)&params[36] = Thickness;
			*(bool*)&params[40] = bNoClip;
			*(float*)&params[44] = DecalRotation;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[48] = HitComponent;
			*(bool*)&params[52] = bProjectOnTerrain;
			*(bool*)&params[56] = bProjectOnSkeletalMeshes;
			*(ScriptName*)&params[60] = HitBone;
			*(int*)&params[68] = HitNodeIndex;
			*(int*)&params[72] = HitLevelIndex;
			*(float*)&params[76] = InDecalLifeSpan;
			*(int*)&params[80] = InFracturedStaticMeshComponentIndex;
			*(float*)&params[84] = InDepthBias;
			*(Object::Vector2D*)&params[88] = InBlendRange;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[96];
		}
	};
}
#undef ADD_STRUCT
