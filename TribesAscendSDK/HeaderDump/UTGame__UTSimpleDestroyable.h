#pragma once
#include "Engine__DynamicSMActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSimpleDestroyable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty UTGame.UTSimpleDestroyable." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSimpleDestroyable." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSimpleDestroyable : public DynamicSMActor
	{
	public:
		ADD_VAR(::FloatProperty, TimeToRespawn, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, RespawnStaticMesh)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SpawnPhysMeshAngularVel, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, SpawnPhysMeshLinearVel, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, SpawnPhysMeshLifeSpan, 0xFFFFFFFF)
		ADD_OBJECT(StaticMesh, SpawnPhysMesh)
		ADD_OBJECT(ParticleSystem, ParticlesOnDestroy)
		ADD_OBJECT(SoundCue, SoundOnDestroy)
		ADD_OBJECT(StaticMesh, MeshOnDestroy)
		ADD_VAR(::BoolProperty, bDestroyed, 0x8)
		ADD_VAR(::BoolProperty, bDestroyOnVehicleTouch, 0x4)
		ADD_VAR(::BoolProperty, bDestroyOnPlayerTouch, 0x2)
		ADD_VAR(::BoolProperty, bDestroyOnDamage, 0x1)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
