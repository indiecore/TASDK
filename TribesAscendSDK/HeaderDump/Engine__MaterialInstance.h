#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.MaterialInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.MaterialInstance." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.MaterialInstance." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class MaterialInstance : public MaterialInterface
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Guid' for the property named 'ParentLightingGuid'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Resources'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'StaticPermutationResources'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'StaticParameters'!
		ADD_VAR(::BoolProperty, bNeedsMaterialFlattening, 0x8)
		ADD_VAR(::BoolProperty, ReentrantFlag, 0x4)
		ADD_VAR(::BoolProperty, bStaticPermutationDirty, 0x2)
		ADD_VAR(::BoolProperty, bHasStaticPermutationResource, 0x1)
		ADD_OBJECT(PhysicalMaterial, WhitePhysicalMaterial)
		ADD_OBJECT(PhysicalMaterial, BlackPhysicalMaterial)
		ADD_VAR(::IntProperty, PhysMaterialMaskUVChannel, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, PhysMaterialMask)
		ADD_OBJECT(MaterialInterface, Parent)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
