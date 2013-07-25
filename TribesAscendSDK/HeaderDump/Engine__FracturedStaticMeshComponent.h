#pragma once
#include "Engine__FracturedBaseComponent.h"
#include "Engine__MaterialInterface.h"
#include "Engine__PhysicalMaterial.h"
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
		// Here lies the not-yet-implemented method 'SetVisibleFragments'
		// Here lies the not-yet-implemented method 'IsFragmentDestroyable'
		// Here lies the not-yet-implemented method 'IsRootFragment'
		// Here lies the not-yet-implemented method 'IsNoPhysFragment'
		// Here lies the not-yet-implemented method 'GetFragmentBox'
		// Here lies the not-yet-implemented method 'GetFragmentAverageExteriorNormal'
		// Here lies the not-yet-implemented method 'GetCoreFragmentIndex'
		// Here lies the not-yet-implemented method 'GetFragmentGroups'
		// Here lies the not-yet-implemented method 'GetBoundaryHiddenFragments'
		// Here lies the not-yet-implemented method 'RecreatePhysState'
		// Here lies the not-yet-implemented method 'GetFracturedMeshPhysMaterial'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
