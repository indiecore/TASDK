#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrScoreboard.TrScoreboardState." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrScoreboardState
	{
	public:
		ADD_VAR(::IntProperty, DiamondSwordScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BloodEagleScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, RemainingTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
