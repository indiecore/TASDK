#pragma once
#include "UDKBase.UDKAnimBlendBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKAnimBlendByHoverboarding : public UDKAnimBlendBase
	{
	public:
		ADD_STRUCT(float, FallTimeBeforeAnim, 304)
		ADD_STRUCT(float, BoardLeanAmount, 300)
		ADD_STRUCT(int, LastActiveChildIndex, 296)
	};
}
#undef ADD_STRUCT
