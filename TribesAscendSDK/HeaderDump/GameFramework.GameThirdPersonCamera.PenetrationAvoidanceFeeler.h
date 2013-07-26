#pragma once
#include "Core.Object.Vector.h"
#include "Core.Object.Rotator.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameThirdPersonCamera.PenetrationAvoidanceFeeler." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameThirdPersonCamera.PenetrationAvoidanceFeeler." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PenetrationAvoidanceFeeler
	{
	public:
		ADD_VAR(::IntProperty, FramesUntilNextTrace, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TraceInterval, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Extent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PawnWeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WorldWeight, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, AdjustmentRot, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
