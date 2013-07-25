#pragma once
#include "Engine__Volume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrWeatherVolume." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrWeatherVolume : public Volume
	{
	public:
		ADD_VAR(::BoolProperty, m_DeactivatePawnCentricWeatherOnEnter, 0x1)
	};
}
#undef ADD_VAR
