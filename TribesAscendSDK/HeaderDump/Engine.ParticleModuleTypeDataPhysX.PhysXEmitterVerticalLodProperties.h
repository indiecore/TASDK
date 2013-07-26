#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " ParticleModuleTypeDataPhysX.PhysXEmitterVerticalLodProperties." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class PhysXEmitterVerticalLodProperties
	{
	public:
		ADD_VAR(::FloatProperty, RelativeFadeoutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpawnLodRateVsLifeBias, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeightForSpawnLod, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, WeightForFifo, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
