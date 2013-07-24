#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleTrailSpawn." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleTrailSpawn : public ParticleModuleTrailBase
	{
	public:
		ADD_VAR(::FloatProperty, MinSpawnVelocity, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
