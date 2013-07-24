#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FracturedSkinnedMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FracturedSkinnedMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class FracturedSkinnedMeshComponent : public FracturedBaseComponent
	{
	public:
		ADD_VAR(::BoolProperty, bFragmentTransformsChanged, 0x2)
		ADD_VAR(::BoolProperty, bBecameVisible, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'ComponentSkinResources'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
