#pragma once
#include "Engine__ParticleModuleTypeDataMesh.h"
#include "Engine__PhysXParticleSystem.h"
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties' for the property named 'VerticalLod'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'RenderInstance'!
		ADD_VAR(::FloatProperty, FluidRotationCoefficient, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, PhysXRotationMethod, 0xFFFFFFFF)
		ADD_OBJECT(PhysXParticleSystem, PhysXParSys)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
