#pragma once
#include "Engine__SkeletalMeshActor.h"
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
	};
}
#undef ADD_OBJECT
