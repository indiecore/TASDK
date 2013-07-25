#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Engine.StaticMesh.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FracturedBaseComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FracturedBaseComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FracturedBaseComponent : public StaticMeshComponent
	{
	public:
		ADD_VAR(::IntProperty, bResetStaticMesh, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumResourceIndices, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUseDynamicIBWithHiddenFragments, 0x10)
		ADD_VAR(::BoolProperty, bUseDynamicIndexBuffer, 0x8)
		ADD_VAR(::BoolProperty, bInitialVisibilityValue, 0x4)
		ADD_VAR(::BoolProperty, bVisibilityReset, 0x2)
		ADD_VAR(::BoolProperty, bVisibilityHasChanged, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.RenderCommandFence_Mirror' for the property named 'ReleaseResourcesFence'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ComponentBaseResources'!
		bool SetStaticMesh(class StaticMesh* NewMesh, bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.SetStaticMesh");
			byte* params = (byte*)malloc(12);
			*(class StaticMesh**)params = NewMesh;
			*(bool*)(params + 4) = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* GetVisibleFragments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.GetVisibleFragments");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
			return returnVal;
		}
		bool IsFragmentVisible(int FragmentIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.IsFragmentVisible");
			byte* params = (byte*)malloc(8);
			*(int*)params = FragmentIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetNumFragments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.GetNumFragments");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetNumVisibleFragments()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FracturedBaseComponent.GetNumVisibleFragments");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
