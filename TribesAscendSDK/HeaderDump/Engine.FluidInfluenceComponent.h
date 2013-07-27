#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.FluidSurfaceActor.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class FluidInfluenceComponent : public PrimitiveComponent
	{
	public:
		enum EInfluenceType : byte
		{
			Fluid_Flow = 0,
			Fluid_Raindrops = 1,
			Fluid_Wave = 2,
			Fluid_Sphere = 3,
			Fluid_MAX = 4,
		};
		ADD_OBJECT(FluidSurfaceActor, CurrentFluidActor, 580)
		ADD_STRUCT(float, CurrentTimer, 576)
		ADD_STRUCT(float, CurrentAngle, 572)
		ADD_STRUCT(float, SphereStrength, 568)
		ADD_STRUCT(float, SphereInnerRadius, 564)
		ADD_STRUCT(float, SphereOuterRadius, 560)
		ADD_STRUCT(float, FlowFrequency, 556)
		ADD_STRUCT(float, FlowStrength, 552)
		ADD_STRUCT(float, FlowWaveRadius, 548)
		ADD_STRUCT(float, FlowSideMotionRadius, 544)
		ADD_STRUCT(int, FlowNumRipples, 540)
		ADD_STRUCT(float, FlowSpeed, 536)
		ADD_STRUCT(float, RaindropRate, 532)
		ADD_STRUCT(float, RaindropStrength, 528)
		ADD_STRUCT(float, RaindropRadius, 524)
		ADD_STRUCT(float, RaindropAreaRadius, 520)
		ADD_STRUCT(float, WaveRadius, 516)
		ADD_STRUCT(float, WavePhase, 512)
		ADD_STRUCT(float, WaveFrequency, 508)
		ADD_STRUCT(float, WaveStrength, 504)
		ADD_STRUCT(float, MaxDistance, 500)
		ADD_STRUCT(FluidInfluenceComponent::EInfluenceType, InfluenceType, 496)
		ADD_OBJECT(FluidSurfaceActor, FluidActor, 492)
		ADD_BOOL(bIsToggleTriggered, 488, 0x4)
		ADD_BOOL(RaindropFillEntireFluid, 488, 0x2)
		ADD_BOOL(bActive, 488, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
