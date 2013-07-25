#pragma once
#include "TribesGame__TrAnimNodeBlendList.h"
#include "TribesGame__TrPawn.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAnimNodeBlendByVehicle." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAnimNodeBlendByVehicle : public TrAnimNodeBlendList
	{
	public:
		ADD_OBJECT(TrPawn, m_TrPawn)
		// Here lies the not-yet-implemented method 'PlayNoVehicleAnim'
		// Here lies the not-yet-implemented method 'PlayDrivingAnim'
		// Here lies the not-yet-implemented method 'PlayEnterAnim'
		// Here lies the not-yet-implemented method 'PlayExitAnim'
		// Here lies the not-yet-implemented method 'PlayChangeSeatAnim'
	};
}
#undef ADD_OBJECT
