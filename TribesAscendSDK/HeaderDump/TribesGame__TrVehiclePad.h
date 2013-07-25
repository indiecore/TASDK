#pragma once
#include "Engine__SkeletalMeshActor.h"
#include "TribesGame__TrSkelControl_SpinControl.h"
#include "TribesGame__TrAnimNodeBlendList.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrVehiclePad." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrVehiclePad : public SkeletalMeshActor
	{
	public:
		ADD_OBJECT(TrSkelControl_SpinControl, m_SpinControl)
		ADD_OBJECT(TrAnimNodeBlendList, m_VehiclePadBlendNode)
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'PostInitAnimTree'
		// Here lies the not-yet-implemented method 'PlayIdleAnim'
		// Here lies the not-yet-implemented method 'PlayDeployAnim'
		// Here lies the not-yet-implemented method 'PlayCollapseAnim'
	};
}
#undef ADD_OBJECT
