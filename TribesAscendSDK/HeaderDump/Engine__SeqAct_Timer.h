#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Timer." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Timer : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, Time, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ActivationTime, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
