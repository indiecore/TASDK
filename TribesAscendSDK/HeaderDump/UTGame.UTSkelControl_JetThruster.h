#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTSkelControl_JetThruster : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(float, DesiredStrength, 244)
		ADD_STRUCT(float, BlendRate, 240)
		ADD_STRUCT(float, MaxForwardVelocity, 236)
		void TickSkelControl(float DeltaTime, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49352);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
