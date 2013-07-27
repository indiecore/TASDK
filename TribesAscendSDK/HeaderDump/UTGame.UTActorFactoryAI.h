#pragma once
#include "Engine.ActorFactoryAI.h"
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
namespace UnrealScript
{
	class UTActorFactoryAI : public ActorFactoryAI
	{
	public:
		ADD_BOOL(bUseCompartment, 132, 0x2)
		ADD_BOOL(bForceDeathmatchAI, 132, 0x1)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTActorFactoryAI.PostCreateActor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
