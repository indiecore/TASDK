#pragma once
#include "Engine__NxForceField.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NxGenericForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.NxGenericForceField." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class NxGenericForceField : public NxForceField
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'LinearKernel'!
		ADD_VAR(::FloatProperty, TorusRadius, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FalloffQuadratic, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, FalloffLinear, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Noise, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityTarget, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityMultiplierZ, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityMultiplierY, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, VelocityMultiplierX, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionTarget, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionMultiplierZ, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionMultiplierY, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PositionMultiplierX, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Constant, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Coordinates, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
