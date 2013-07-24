#pragma once
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
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties' for the property named 'VerticalLod'!
		ADD_OBJECT(PhysXParticleSystem, PhysXParSys)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
