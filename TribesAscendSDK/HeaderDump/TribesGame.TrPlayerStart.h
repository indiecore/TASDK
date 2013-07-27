#pragma once
#include "TribesGame.TrCaHCapturePoint.h"
#include "UDKBase.UDKTeamPlayerStart.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerStart : public UDKTeamPlayerStart
	{
	public:
		ADD_OBJECT(TrCaHCapturePoint, CaHCapturePoint, 716)
	};
}
#undef ADD_OBJECT
