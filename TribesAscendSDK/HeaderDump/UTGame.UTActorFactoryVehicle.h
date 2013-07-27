#pragma once
#include "Engine.ActorFactoryVehicle.h"
#include "Engine.Actor.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTActorFactoryVehicle : public ActorFactoryVehicle
	{
	public:
		ADD_STRUCT(byte, TeamNum, 100)
		ADD_BOOL(bKeyVehicle, 96, 0x2)
		ADD_BOOL(bTeamLocked, 96, 0x1)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39175);
			byte params[4] = { NULL };
			*(class Actor**)params = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
