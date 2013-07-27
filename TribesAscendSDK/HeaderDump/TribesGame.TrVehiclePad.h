#pragma once
#include "Engine.SkeletalMeshActor.h"
#include "TribesGame.TrSkelControl_SpinControl.h"
#include "TribesGame.TrAnimNodeBlendList.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrVehiclePad : public SkeletalMeshActor
	{
	public:
		ADD_OBJECT(TrSkelControl_SpinControl, m_SpinControl, 540)
		ADD_OBJECT(TrAnimNodeBlendList, m_VehiclePadBlendNode, 536)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114967);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114970);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayIdleAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114972);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDeployAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114973);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCollapseAnim()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(114974);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
