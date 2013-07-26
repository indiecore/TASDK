#pragma once
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.Vector.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PhysXParticleSystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PhysXParticleSystem." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PhysXParticleSystem : public Object
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, PSys, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, CascadeScene, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionResponseCoefficient, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Viscosity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Stiffness, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, KernelRadiusMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RestDensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RestParticleDistance, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, ExternalAcceleration, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, Damping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxMotionDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsInGame, 0x40)
		ADD_VAR(::BoolProperty, bSyncFailed, 0x20)
		ADD_VAR(::BoolProperty, bDestroy, 0x10)
		ADD_VAR(::BoolProperty, bTwoWayCollision, 0x8)
		ADD_VAR(::BoolProperty, bStaticCollision, 0x4)
		ADD_VAR(::BoolProperty, bDisableGravity, 0x2)
		ADD_VAR(::BoolProperty, bDynamicCollision, 0x1)
		ADD_VAR(::FloatProperty, StaticFrictionWithDynamicShapes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StaticFrictionWithStaticShapes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FrictionWithDynamicShapes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FrictionWithStaticShapes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RestitutionWithDynamicShapes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RestitutionWithStaticShapes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CollisionDistance, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<RBCollisionChannelContainer>, RBCollideWithChannels, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PacketSizeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, SimulationMethod, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, RBChannel, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ParticleSpawnReserve, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxParticles, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
