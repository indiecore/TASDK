#pragma once
#include "GameFramework.SeqEvent_MobileBase.h"
#include "GameFramework.MobilePlayerInput.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileZoneBase : public SeqEvent_MobileBase
	{
	public:
		ADD_STRUCT(ScriptString*, TargetZoneName, 256)
		void AddToMobileInput(class MobilePlayerInput* MPI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GameFramework.SeqEvent_MobileZoneBase.AddToMobileInput");
			byte params[4] = { NULL };
			*(class MobilePlayerInput**)&params[0] = MPI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
