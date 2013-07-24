#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSeqAct_TrainingMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSeqAct_TrainingMessage : public SequenceAction
	{
	public:
		ADD_VAR(::ByteProperty, m_MessageType, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
