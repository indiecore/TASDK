#pragma once
#include "Engine.PhysXParticleSystem.h"
#include "Engine.ParticleModuleTypeDataMesh.h"
#include "Engine.ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties.h"
#include "Core.Object.Pointer.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleTypeDataMeshPhysX." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleTypeDataMeshPhysX." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ParticleModuleTypeDataMeshPhysX." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleTypeDataMeshPhysX : public ParticleModuleTypeDataMesh
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<PhysXEmitterVerticalLodProperties>, VerticalLod, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, RenderInstance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidRotationCoefficient, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PhysXRotationMethod, 0xFFFFFFFF)
		ADD_OBJECT(PhysXParticleSystem, PhysXParSys)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
