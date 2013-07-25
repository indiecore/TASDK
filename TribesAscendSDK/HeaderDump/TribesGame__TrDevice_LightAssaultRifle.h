#pragma once
#include "TribesGame__TrDevice_AssaultRifle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_LightAssaultRifle." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_LightAssaultRifle : public TrDevice_AssaultRifle
	{
	public:
		ADD_VAR(::FloatProperty, m_fBurtShotRefireTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, m_bHoldingFire, 0x1)
		ADD_VAR(::IntProperty, m_nShotsSoFar, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nShotBurstCount, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
