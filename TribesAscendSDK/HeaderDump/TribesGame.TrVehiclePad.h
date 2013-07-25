#pragma once
#include "Engine.SkeletalMeshActor.h"
#include "TribesGame.TrSkelControl_SpinControl.h"
#include "TribesGame.TrAnimNodeBlendList.h"
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
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehiclePad.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostInitAnimTree(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehiclePad.PostInitAnimTree");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayIdleAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehiclePad.PlayIdleAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayDeployAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehiclePad.PlayDeployAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCollapseAnim()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrVehiclePad.PlayCollapseAnim");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_OBJECT
