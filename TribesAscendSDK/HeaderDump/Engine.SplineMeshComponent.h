#pragma once
#include "Engine.StaticMeshComponent.h"
#include "Engine.SplineMeshComponent.SplineMeshParams.h"
#include "Core.Object.Vector.h"
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
		ADD_STRUCT(::VectorProperty, SplineXDir, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<SplineMeshParams>, SplineParams, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
