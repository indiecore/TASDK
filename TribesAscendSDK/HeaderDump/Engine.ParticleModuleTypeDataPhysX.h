#pragma once
#include "Engine.ParticleModuleTypeDataBase.h"
#include "Engine.ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties.h"
#include "Engine.PhysXParticleSystem.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleTypeDataPhysX." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ParticleModuleTypeDataPhysX." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ParticleModuleTypeDataPhysX : public ParticleModuleTypeDataBase
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<PhysXEmitterVerticalLodProperties>, VerticalLod, 0xFFFFFFFF)
		ADD_OBJECT(PhysXParticleSystem, PhysXParSys)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
