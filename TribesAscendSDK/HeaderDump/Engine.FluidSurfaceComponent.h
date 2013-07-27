#pragma once
#include "Engine.PrimitiveComponent.h"
#include "Engine.MaterialInterface.h"
#include "Engine.EngineTypes.h"
#include "Engine.ShadowMap2D.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
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
	class FluidSurfaceComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(float, ForceImpact, 568)
		ADD_STRUCT(ScriptArray<byte>, ClampMap, 692)
		ADD_STRUCT(ScriptArray<class ShadowMap2D*>, ShadowMaps, 704)
		ADD_STRUCT(Object::Pointer, FluidSimulation, 720)
		ADD_STRUCT(EngineTypes::LightMapRef, LightMap, 716)
		ADD_STRUCT(Object::Vector, EditorViewPosition, 680)
		ADD_STRUCT(Object::Vector, DetailPosition, 668)
		ADD_STRUCT(Object::Vector, SimulationPosition, 656)
		ADD_STRUCT(float, ViewDistance, 652)
		ADD_STRUCT(float, DeactivationTimer, 648)
		ADD_STRUCT(float, TestRippleAngle, 644)
		ADD_STRUCT(float, TestRippleTime, 640)
		ADD_STRUCT(float, FluidHeight, 636)
		ADD_STRUCT(float, FluidWidth, 632)
		ADD_STRUCT(float, TestRippleRadius, 628)
		ADD_STRUCT(float, TestRippleFrequency, 624)
		ADD_STRUCT(float, TestRippleSpeed, 620)
		ADD_STRUCT(float, NormalLength, 616)
		ADD_STRUCT(float, DetailUpdateRate, 612)
		ADD_STRUCT(float, DetailHeightScale, 608)
		ADD_STRUCT(float, DetailTransfer, 604)
		ADD_STRUCT(float, DetailTravelSpeed, 600)
		ADD_STRUCT(float, DetailDamping, 596)
		ADD_STRUCT(float, DetailSize, 592)
		ADD_STRUCT(int, DetailResolution, 588)
		ADD_STRUCT(float, DeactivationDistance, 584)
		ADD_OBJECT(Actor, TargetDetail, 580)
		ADD_STRUCT(float, LightingContrast, 576)
		ADD_STRUCT(float, ForceContinuous, 572)
		ADD_STRUCT(float, FluidUpdateRate, 564)
		ADD_STRUCT(float, FluidHeightScale, 560)
		ADD_STRUCT(float, FluidTravelSpeed, 556)
		ADD_STRUCT(float, FluidDamping, 552)
		ADD_STRUCT(float, GPUTessellationFactor, 548)
		ADD_OBJECT(Actor, TargetSimulation, 544)
		ADD_STRUCT(float, GridSpacingLowRes, 540)
		ADD_STRUCT(float, GridSpacing, 536)
		ADD_STRUCT(int, SimulationQuadsY, 532)
		ADD_STRUCT(int, SimulationQuadsX, 528)
		ADD_BOOL(bTestRippleCenterOnDetail, 524, 0x400)
		ADD_BOOL(bTestRipple, 524, 0x200)
		ADD_BOOL(bShowFluidDetail, 524, 0x100)
		ADD_BOOL(bShowFluidSimulation, 524, 0x80)
		ADD_BOOL(bShowDetailPosition, 524, 0x40)
		ADD_BOOL(bShowDetailNormals, 524, 0x20)
		ADD_BOOL(bShowSimulationPosition, 524, 0x10)
		ADD_BOOL(bShowSimulationNormals, 524, 0x8)
		ADD_BOOL(bPause, 524, 0x4)
		ADD_BOOL(EnableDetail, 524, 0x2)
		ADD_BOOL(EnableSimulation, 524, 0x1)
		ADD_STRUCT(EngineTypes::LightmassPrimitiveSettings, LightmassSettings, 496)
		ADD_STRUCT(int, LightMapResolution, 492)
		ADD_OBJECT(MaterialInterface, FluidMaterial, 488)
		void ApplyForce(Object::Vector WorldPos, float Strength, float Radius, bool bImpulse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FluidSurfaceComponent.ApplyForce");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = WorldPos;
			*(float*)&params[12] = Strength;
			*(float*)&params[16] = Radius;
			*(bool*)&params[20] = bImpulse;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDetailPosition(Object::Vector WorldPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FluidSurfaceComponent.SetDetailPosition");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = WorldPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSimulationPosition(Object::Vector WorldPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FluidSurfaceComponent.SetSimulationPosition");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = WorldPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
