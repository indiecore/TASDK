#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.ParticleModuleSpawnPerUnit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.ParticleModuleSpawnPerUnit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ParticleModuleSpawnPerUnit : public ParticleModuleSpawnBase
	{
	public:
		ADD_VAR(::FloatProperty, MovementTolerance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIgnoreMovementAlongZ, 0x8)
		ADD_VAR(::BoolProperty, bIgnoreMovementAlongY, 0x4)
		ADD_VAR(::BoolProperty, bIgnoreMovementAlongX, 0x2)
		ADD_VAR(::BoolProperty, bIgnoreSpawnRateWhenMoving, 0x1)
		// WARNING: Unknown structure type 'ScriptStruct Core.DistributionFloat.RawDistributionFloat' for the property named 'SpawnPerUnit'!
		ADD_VAR(::FloatProperty, UnitScalar, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
