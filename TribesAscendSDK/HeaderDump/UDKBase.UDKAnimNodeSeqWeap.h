#pragma once
#include "UDKBase.UDKAnimNodeSequence.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimNodeSeqWeap : public UDKAnimNodeSequence
	{
	public:
		ADD_STRUCT(ScriptName, StingerAnim, 368)
		ADD_STRUCT(ScriptName, ShoulderRocketAnim, 360)
		ADD_STRUCT(ScriptName, SinglePistolAnim, 352)
		ADD_STRUCT(ScriptName, DualPistolAnim, 344)
		ADD_STRUCT(ScriptName, DefaultAnim, 336)
	};
}
#undef ADD_STRUCT
