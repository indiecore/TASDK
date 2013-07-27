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
		bool FireCompletedCallIn(int CallInOffs, Object::Vector TargetLocation, Object::Vector TargetNormal)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_Support.FireCompletedCallIn");
			byte params[32] = { NULL };
			*(int*)&params[0] = CallInOffs;
			*(Object::Vector*)&params[4] = TargetLocation;
			*(Object::Vector*)&params[16] = TargetNormal;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[28];
		}
		void DestroyOverLimit()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrCallIn_Support.DestroyOverLimit");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
