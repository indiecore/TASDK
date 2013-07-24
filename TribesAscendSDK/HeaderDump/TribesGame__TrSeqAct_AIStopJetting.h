#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSeqAct_AIStopJetting." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSeqAct_AIStopJetting : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, m_bResetVelocity, 0x1)
	};
}
#undef ADD_VAR
