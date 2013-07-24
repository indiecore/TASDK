#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_MITV_Activate." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_MITV_Activate : public SequenceAction
	{
	public:
		ADD_VAR(::FloatProperty, DurationOfMITV, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
