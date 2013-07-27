#pragma once
#include "GameFramework.SeqEvent_MobileBase.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqEvent_MobileMotion : public SeqEvent_MobileBase
	{
	public:
		ADD_STRUCT(float, DeltaYaw, 276)
		ADD_STRUCT(float, DeltaPitch, 272)
		ADD_STRUCT(float, DeltaRoll, 268)
		ADD_STRUCT(float, Yaw, 264)
		ADD_STRUCT(float, Pitch, 260)
		ADD_STRUCT(float, Roll, 256)
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(33048);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
