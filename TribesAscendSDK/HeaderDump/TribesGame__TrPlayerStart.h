#pragma once
#include "UDKBase__UDKTeamPlayerStart.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPlayerStart." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPlayerStart : public UDKTeamPlayerStart
	{
	public:
		ADD_OBJECT(TrCaHCapturePoint, CaHCapturePoint)
	};
}
#undef ADD_OBJECT
