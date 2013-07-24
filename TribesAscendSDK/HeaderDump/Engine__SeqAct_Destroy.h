#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_Destroy." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_Destroy : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bDestroyBasedActors, 0x1)
	};
}
#undef ADD_VAR
