#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_IsInObjectList." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_IsInObjectList : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, bObjectFound, 0x2)
		ADD_VAR(::BoolProperty, bCheckForAllObjects, 0x1)
	};
}
#undef ADD_VAR
