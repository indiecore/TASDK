#pragma once
#include "Engine.AnimNodeBlendBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAnimNodeBlendByGravCycleTilt." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrAnimNodeBlendByGravCycleTilt : public AnimNodeBlendBase
	{
	public:
		ADD_VAR(::FloatProperty, m_fDeadZone, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, m_RootBoneName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTiltScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fTiltAmount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
