#pragma once
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
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
