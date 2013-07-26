#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.WorldFractureSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class WorldFractureSettings
	{
	public:
		ADD_VAR(::FloatProperty, ChanceOfPhysicsChunkOverride, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bEnableChanceOfPhysicsChunkOverride, 0x1)
		ADD_VAR(::BoolProperty, bLimitExplosionChunkSize, 0x2)
		ADD_VAR(::FloatProperty, MaxExplosionChunkSize, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bLimitDamageChunkSize, 0x1)
		ADD_VAR(::FloatProperty, MaxDamageChunkSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxNumFacturedChunksToSpawnInAFrame, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FractureExplosionVelScale, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
