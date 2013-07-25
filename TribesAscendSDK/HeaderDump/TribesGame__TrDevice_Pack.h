#pragma once
#include "TribesGame__TrDevice.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrDevice_Pack." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrDevice_Pack : public TrDevice
	{
	public:
		ADD_VAR(::FloatProperty, m_CachedPowerPoolCostPerSec, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fDefaultPowerPoolCostPerSec, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
