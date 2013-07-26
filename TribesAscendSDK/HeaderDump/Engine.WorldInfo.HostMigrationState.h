#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " WorldInfo.HostMigrationState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class HostMigrationState
	{
	public:
		ADD_VAR(::BoolProperty, bHostMigrationEnabled, 0x1)
		ADD_VAR(::StrProperty, HostMigrationTravelURL, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HostMigrationTravelCountdown, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HostMigrationElapsedTime, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, HostMigrationProgress, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
