#pragma once
#include "Engine.PhysXParticleSystem.h"
#include "Engine.ParticleModuleTypeDataMesh.h"
#include "Engine.ParticleModuleTypeDataPhysX.h"
#include "Core.Object.h"
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
	class ParticleModuleTypeDataMeshPhysX : public ParticleModuleTypeDataMesh
	{
	public:
		enum EPhysXMeshRotationMethod : byte
		{
			PMRM_Disabled = 0,
			PMRM_Spherical = 1,
			PMRM_Box = 2,
			PMRM_LongBox = 3,
			PMRM_FlatBox = 4,
			PMRM_Velocity = 5,
			PMRM_MAX = 6,
		};
		ADD_STRUCT(ParticleModuleTypeDataPhysX::PhysXEmitterVerticalLodProperties, VerticalLod, 112)
		ADD_STRUCT(Object::Pointer, RenderInstance, 108)
		ADD_STRUCT(float, FluidRotationCoefficient, 104)
		ADD_STRUCT(ParticleModuleTypeDataMeshPhysX::EPhysXMeshRotationMethod, PhysXRotationMethod, 100)
		ADD_OBJECT(PhysXParticleSystem, PhysXParSys, 96)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
