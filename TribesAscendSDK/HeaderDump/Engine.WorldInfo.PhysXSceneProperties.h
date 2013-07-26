#pragma once
#include "Engine.WorldInfo.PhysXSimulationProperties.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty WorldInfo.PhysXSceneProperties." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PhysXSceneProperties
	{
	public:
		ADD_STRUCT(::NonArithmeticProperty<PhysXSimulationProperties>, PrimaryScene, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PhysXSimulationProperties>, CompartmentRigidBody, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PhysXSimulationProperties>, CompartmentFluid, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PhysXSimulationProperties>, CompartmentCloth, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<PhysXSimulationProperties>, CompartmentSoftBody, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
