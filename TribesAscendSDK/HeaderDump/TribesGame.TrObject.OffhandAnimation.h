#pragma once
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TrObject.OffhandAnimation." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OffhandAnimation
	{
	public:
		ADD_VAR(::NameProperty, m_OffhandUseType, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_AnimName, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bFullBody, 0x1)
	};
}
#undef ADD_VAR
