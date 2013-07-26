#pragma once
#include "Engine.ParticleModuleUberBase.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleUberRainDrops." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleUberRainDrops." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleUberRainDrops : public ParticleModuleUberBase
	{
	public:
		ADD_STRUCT(::VectorProperty, StartLocationMax, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartLocationMin, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PC_HeightAxis, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PC_StartHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PC_StartRadius, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, PC_StartLocation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PC_VelocityScale, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bRadialVelocity, 0x200)
		ADD_VAR(::BoolProperty, bVelocity, 0x100)
		ADD_VAR(::BoolProperty, bSurfaceOnly, 0x80)
		ADD_VAR(::BoolProperty, bNegative_Z, 0x40)
		ADD_VAR(::BoolProperty, bNegative_Y, 0x20)
		ADD_VAR(::BoolProperty, bNegative_X, 0x10)
		ADD_VAR(::BoolProperty, bPositive_Z, 0x8)
		ADD_VAR(::BoolProperty, bPositive_Y, 0x4)
		ADD_VAR(::BoolProperty, bPositive_X, 0x2)
		ADD_VAR(::BoolProperty, bIsUsingCylinder, 0x1)
		ADD_VAR(::FloatProperty, AlphaOverLife, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ColorOverLife, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartVelocityRadialMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StartVelocityRadialMin, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartVelocityMax, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartVelocityMin, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartSizeMax, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, StartSizeMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LifetimeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LifetimeMin, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
