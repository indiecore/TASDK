#pragma once
#include "TribesGame.TrCallIn.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrCallIn_Support : public TrCallIn
	{
	public:
		ADD_STRUCT(int, MaxDeployedLimit, 548)
		ADD_OBJECT(ScriptClass, ItemInDeliveryPod, 544)
		bool FireCompletedCallIn(int CallInOffs, Vector TargetLocation, Vector TargetNormal)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74115);
			byte params[32] = { NULL };
			*(int*)params = CallInOffs;
			*(Vector*)&params[4] = TargetLocation;
			*(Vector*)&params[16] = TargetNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void DestroyOverLimit()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74121);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
