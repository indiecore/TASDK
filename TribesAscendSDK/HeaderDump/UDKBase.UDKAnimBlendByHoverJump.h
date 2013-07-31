#pragma once
#include "Engine.Pawn.h"
#include "UDKBase.UDKAnimBlendByFall.h"
#include "UDKBase.UDKVehicle.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UDKAnimBlendByHoverJump : public UDKAnimBlendByFall
	{
	public:
		ADD_OBJECT(UDKVehicle, OwnerHV, 328)
		ADD_OBJECT(Pawn, OwnerP, 324)
	};
}
#undef ADD_OBJECT
