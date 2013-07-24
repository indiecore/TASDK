#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SplineMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SplineMeshComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SplineMeshComponent : public StaticMeshComponent
	{
	public:
		ADD_VAR(::BoolProperty, bSmoothInterpRollScale, 0x1)
		ADD_STRUCT(::VectorProperty, SplineXDir, 0xFFFFFFFF
		// WARNING: Unknown structure type 'ScriptStruct Engine.SplineMeshComponent.SplineMeshParams' for the property named 'SplineParams'!
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
