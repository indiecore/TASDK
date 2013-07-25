#pragma once
#include "Engine.FracturedBaseComponent.h"
#include "Engine.MaterialInterface.h"
#include "Engine.PhysicalMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FracturedStaticMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FracturedStaticMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FracturedStaticMeshComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FracturedStaticMeshComponent : public FracturedBaseComponent
	{
	public:
		ADD_VAR(::FloatProperty, FragmentBoundsMinZ, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FragmentBoundsMaxZ, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, LoseChunkOutsideMaterialOverride)
		ADD_VAR(::FloatProperty, TopBottomFragmentDistThreshold, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBottomFragmentsRootNonDestroyable, 0x8)
		ADD_VAR(::BoolProperty, bTopFragmentsRootNonDestroyable, 0x4)
		ADD_VAR(::BoolProperty, bUseVisibleVertsForBounds, 0x2)
		ADD_VAR(::BoolProperty, bUseSkinnedRendering, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box' for the property named 'VisibleBox'!
		void SetVisibleFragments(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* VisibilityFactors)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.SetVisibleFragments");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = VisibilityFactors;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsFragmentDestroyable(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.IsFragmentDestroyable");
			byte* params = (byte*)malloc(8);
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsRootFragment(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.IsRootFragment");
			byte* params = (byte*)malloc(8);
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsNoPhysFragment(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.IsNoPhysFragment");
			byte* params = (byte*)malloc(8);
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box'!
void* GetFragmentBox(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFragmentBox");
			byte* params = (byte*)malloc(32);
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Box'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		Vector GetFragmentAverageExteriorNormal(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFragmentAverageExteriorNormal");
			byte* params = (byte*)malloc(16);
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Vector*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetCoreFragmentIndex()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetCoreFragmentIndex");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetFragmentGroups(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* IgnoreFragments, float MinConnectionArea)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFragmentGroups");
			byte* params = (byte*)malloc(28);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = IgnoreFragments;
			*(float*)(params + 12) = MinConnectionArea;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetBoundaryHiddenFragments(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* AdditionalVisibleFragments)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetBoundaryHiddenFragments");
			byte* params = (byte*)malloc(24);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = AdditionalVisibleFragments;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			free(params);
			return returnVal;
		}
		void RecreatePhysState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.RecreatePhysState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PhysicalMaterial* GetFracturedMeshPhysMaterial()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedStaticMeshComponent.GetFracturedMeshPhysMaterial");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PhysicalMaterial**)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
