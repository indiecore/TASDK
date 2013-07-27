#pragma once
#include "Core.Object.h"
#include "Engine.ParticleModuleUberBase.h"
#include "Engine.ParticleModuleLocationPrimitiveCylinder.h"
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
namespace UnrealScript
{
	class ParticleModuleUberRainDrops : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(Object::Vector, StartLocationMax, 208)
		ADD_STRUCT(Object::Vector, StartLocationMin, 196)
		ADD_STRUCT(ParticleModuleLocationPrimitiveCylinder::CylinderHeightAxis, PC_HeightAxis, 192)
		ADD_STRUCT(float, PC_StartHeight, 188)
		ADD_STRUCT(float, PC_StartRadius, 184)
		ADD_STRUCT(Object::Vector, PC_StartLocation, 172)
		ADD_STRUCT(float, PC_VelocityScale, 168)
		ADD_BOOL(bRadialVelocity, 164, 0x200)
		ADD_BOOL(bVelocity, 164, 0x100)
		ADD_BOOL(bSurfaceOnly, 164, 0x80)
		ADD_BOOL(bNegative_Z, 164, 0x40)
		ADD_BOOL(bNegative_Y, 164, 0x20)
		ADD_BOOL(bNegative_X, 164, 0x10)
		ADD_BOOL(bPositive_Z, 164, 0x8)
		ADD_BOOL(bPositive_Y, 164, 0x4)
		ADD_BOOL(bPositive_X, 164, 0x2)
		ADD_BOOL(bIsUsingCylinder, 164, 0x1)
		ADD_STRUCT(float, AlphaOverLife, 160)
		ADD_STRUCT(Object::Vector, ColorOverLife, 148)
		ADD_STRUCT(float, StartVelocityRadialMax, 144)
		ADD_STRUCT(float, StartVelocityRadialMin, 140)
		ADD_STRUCT(Object::Vector, StartVelocityMax, 128)
		ADD_STRUCT(Object::Vector, StartVelocityMin, 116)
		ADD_STRUCT(Object::Vector, StartSizeMax, 104)
		ADD_STRUCT(Object::Vector, StartSizeMin, 92)
		ADD_STRUCT(float, LifetimeMax, 88)
		ADD_STRUCT(float, LifetimeMin, 84)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
