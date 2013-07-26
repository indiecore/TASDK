#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " EngineTypes.SwarmDebugOptions." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SwarmDebugOptions
	{
	public:
		ADD_VAR(::BoolProperty, bInitialized, 0x4)
		ADD_VAR(::BoolProperty, bForceContentExport, 0x2)
		ADD_VAR(::BoolProperty, bDistributionEnabled, 0x1)
	};
}
#undef ADD_VAR
