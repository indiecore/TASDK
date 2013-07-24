#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEffect." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrEffect : public Object
	{
	public:
		ADD_VAR(::FloatProperty, m_fValue, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bRemovable, 0x1)
		ADD_VAR(::ByteProperty, m_eCalcMethodCode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nEffectInstanceId, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
