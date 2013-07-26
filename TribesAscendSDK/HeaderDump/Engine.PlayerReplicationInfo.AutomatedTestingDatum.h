#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " PlayerReplicationInfo.AutomatedTestingDatum." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class AutomatedTestingDatum
	{
	public:
		ADD_VAR(::IntProperty, NumberOfMatchesPlayed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumMapListCyclesDone, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
