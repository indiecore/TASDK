#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.SeqAct_ModifyCover." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class SeqAct_ModifyCover : public SequenceAction
	{
	public:
		ADD_VAR(::ByteProperty, ManualCoverType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bManualAdjustPlayersOnly, 0x1)
	};
}
#undef ADD_VAR
