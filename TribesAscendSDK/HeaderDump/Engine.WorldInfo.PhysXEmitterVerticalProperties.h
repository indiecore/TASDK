#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.PhysXEmitterVerticalProperties." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PhysXEmitterVerticalProperties
	{
	public:
		ADD_VAR(::BoolProperty, bDisableLod, 0x1)
		ADD_VAR(::IntProperty, ParticlesLodMin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ParticlesLodMax, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PacketsPerPhysXParticleSystemMax, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bApplyCylindricalPacketCulling, 0x1)
		ADD_VAR(::FloatProperty, SpawnLodVsFifoBias, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
