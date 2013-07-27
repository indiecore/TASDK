#pragma once
#include "TribesGame.TrDmgType_Explosive.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrDmgType_WhiteOut : public TrDmgType_Explosive
	{
	public:
		ADD_STRUCT(float, m_fWhiteoutInterpSpeed, 424)
		ADD_STRUCT(float, m_fWhiteoutTargetValue, 428)
	};
}
#undef ADD_STRUCT
