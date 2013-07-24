#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMutator_SlowTimeKills." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UTMutator_SlowTimeKills : public UTMutator
	{
	public:
		ADD_VAR(::FloatProperty, SlowSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RampUpTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SlowTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
