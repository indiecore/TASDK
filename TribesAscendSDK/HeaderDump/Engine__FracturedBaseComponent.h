#pragma once
#include "Engine__StaticMeshComponent.h"
#include "Engine__StaticMesh.h"
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
		// Here lies the not-yet-implemented method 'SetStaticMesh'
		// Here lies the not-yet-implemented method 'GetVisibleFragments'
		// Here lies the not-yet-implemented method 'IsFragmentVisible'
		// Here lies the not-yet-implemented method 'GetNumFragments'
		// Here lies the not-yet-implemented method 'GetNumVisibleFragments'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
