#pragma once
#include "TribesGame.TrDeployable.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByDeployableState : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrDeployable, m_TrDeployable, 292)
	};
}
#undef ADD_OBJECT
