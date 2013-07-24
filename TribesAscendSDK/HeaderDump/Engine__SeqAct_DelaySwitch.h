#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_DelaySwitch." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_DelaySwitch : public SeqAct_Latent
	{
	public:
		ADD_VAR(::FloatProperty, NextLinkTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SwitchDelay, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentIdx, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LinkCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
