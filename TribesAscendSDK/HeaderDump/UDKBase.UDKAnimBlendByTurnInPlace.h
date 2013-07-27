#pragma once
#include "UDKBase.UDKPawn.h"
#include "UDKBase.UDKAnimBlendBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByTurnInPlace : public UDKAnimBlendBase
	{
	public:
		ADD_OBJECT(UDKPawn, OwnerUTP, 304)
		ADD_STRUCT(float, TurnInPlaceBlendSpeed, 300)
		ADD_STRUCT(float, RootYawSpeedThresh, 296)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
