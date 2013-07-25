#pragma once
#include "TribesGame__TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_SniperRifle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_SniperRifle : public TrDevice
	{
	public:
		ADD_VAR(::FloatProperty, m_fDivCoeff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMultCoeff, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, r_fAimChargeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fAimChargeDeltaTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMaxAimedDamage, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
