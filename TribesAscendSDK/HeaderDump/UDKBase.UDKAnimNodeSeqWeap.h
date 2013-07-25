#pragma once
#include "UDKBase.UDKAnimNodeSequence.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKAnimNodeSeqWeap." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSeqWeap : public UDKAnimNodeSequence
	{
	public:
		ADD_VAR(::NameProperty, StingerAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, ShoulderRocketAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, SinglePistolAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DualPistolAnim, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DefaultAnim, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
