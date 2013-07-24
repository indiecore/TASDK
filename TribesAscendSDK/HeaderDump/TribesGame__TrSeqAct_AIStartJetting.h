#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrSeqAct_AIStartJetting." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrSeqAct_AIStartJetting." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrSeqAct_AIStartJetting : public SequenceAction
	{
	public:
		ADD_VAR(::BoolProperty, m_bResetVelocity, 0x1)
		ADD_STRUCT(::VectorProperty, Direction, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, Magnitude, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
