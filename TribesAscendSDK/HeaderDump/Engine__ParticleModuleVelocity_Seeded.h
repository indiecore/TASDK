#pragma once
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleVelocity_Seeded." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleVelocity_Seeded : public ParticleModuleVelocity
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct Engine.ParticleModule.ParticleRandomSeedInfo' for the property named 'RandomSeedInfo'!
	};
}
#undef ADD_STRUCT
