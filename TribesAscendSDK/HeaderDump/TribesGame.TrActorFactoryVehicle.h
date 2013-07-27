#pragma once
#include "Engine.ActorFactoryVehicle.h"
#include "Engine.Actor.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrActorFactoryVehicle : public ActorFactoryVehicle
	{
	public:
		ADD_STRUCT(byte, TeamNum, 96)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(66298);
			byte params[4] = { NULL };
			*(class Actor**)params = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
