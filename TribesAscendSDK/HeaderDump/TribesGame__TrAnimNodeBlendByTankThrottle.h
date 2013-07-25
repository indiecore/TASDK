#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrVehicle.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByTankThrottle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByTankThrottle : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrVehicle, m_TrVehicle)
	};
}
#undef ADD_OBJECT
