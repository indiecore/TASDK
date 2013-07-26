#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.ApexModuleDestructibleSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class ApexModuleDestructibleSettings
	{
	public:
		ADD_VAR(::IntProperty, MaxChunkIslandCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxRrbActorCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxChunkSeparationLOD, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOverrideMaxChunkSeparationLOD, 0x1)
	};
}
#undef ADD_VAR
