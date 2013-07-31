#pragma once
#include "Engine.Actor.h"
#include "Engine.MaterialInstanceTimeVarying.h"
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
	class TrCallIn_OpenDeliveryPod : public Actor
	{
	public:
		ADD_OBJECT(MaterialInstanceTimeVarying, PodFadeMaterial, 484)
		ADD_STRUCT(float, TimeToFade, 480)
		ADD_STRUCT(float, TimeToDelete, 476)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74062);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemovePod()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74064);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
