#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.FluidSurfaceActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FluidInfluenceComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FluidInfluenceComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FluidInfluenceComponent : public PrimitiveComponent
	{
	public:
		ADD_OBJECT(FluidSurfaceActor, CurrentFluidActor)
		ADD_VAR(::FloatProperty, CurrentTimer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SphereStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SphereInnerRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SphereOuterRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlowFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlowStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlowWaveRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlowSideMotionRadius, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FlowNumRipples, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FlowSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RaindropRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RaindropStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RaindropRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RaindropAreaRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WaveRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WavePhase, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WaveFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WaveStrength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDistance, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, InfluenceType, 0xFFFFFFFF)
		ADD_OBJECT(FluidSurfaceActor, FluidActor)
		ADD_VAR(::BoolProperty, bIsToggleTriggered, 0x4)
		ADD_VAR(::BoolProperty, RaindropFillEntireFluid, 0x2)
		ADD_VAR(::BoolProperty, bActive, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
