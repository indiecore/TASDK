#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrAnimNodeTurnInPlace_Player.TIP_Transition." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TIP_Transition
	{
	public:
		ADD_VAR(::NameProperty, AnimName, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, TransName, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
