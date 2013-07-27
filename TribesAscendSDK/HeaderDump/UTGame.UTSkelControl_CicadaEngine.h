#pragma once
#include "Engine.SkelControlSingleBone.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTSkelControl_CicadaEngine : public SkelControlSingleBone
	{
	public:
		ADD_STRUCT(int, DesiredPitch, 268)
		ADD_STRUCT(float, LastThrust, 264)
		ADD_STRUCT(float, PitchTime, 260)
		ADD_STRUCT(float, MaxVelocityPitchRateMultiplier, 256)
		ADD_STRUCT(float, MinVelocity, 252)
		ADD_STRUCT(float, MaxVelocity, 248)
		ADD_STRUCT(float, PitchRate, 244)
		ADD_STRUCT(float, BackPitch, 240)
		ADD_STRUCT(float, ForwardPitch, 236)
		void TickSkelControl(float DeltaTime, 
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* SkelComp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTSkelControl_CicadaEngine.TickSkelControl");
			byte params[8] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4] = SkelComp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
