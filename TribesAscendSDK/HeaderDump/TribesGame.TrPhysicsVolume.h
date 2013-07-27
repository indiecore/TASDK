#pragma once
#include "Engine.PhysicsVolume.h"
#include "TribesGame.TrVGSCommandList.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrPhysicsVolume : public PhysicsVolume
	{
	public:
		ADD_STRUCT(TrVGSCommandList::EVGSContextLocation, m_ContextLocation, 584)
		ADD_STRUCT(byte, m_DefenderTeamIndex, 585)
	};
}
#undef ADD_STRUCT
