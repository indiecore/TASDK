#pragma once
#include "Engine.AnimNodeBlendBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrAnimNodeBlendByGravCycleTilt : public AnimNodeBlendBase
	{
	public:
		ADD_STRUCT(float, m_fDeadZone, 260)
		ADD_STRUCT(ScriptName, m_RootBoneName, 252)
		ADD_STRUCT(float, m_fTiltScale, 248)
		ADD_STRUCT(float, m_fTiltAmount, 244)
	};
}
#undef ADD_STRUCT
