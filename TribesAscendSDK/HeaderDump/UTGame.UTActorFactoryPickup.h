#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.Actor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTActorFactoryPickup : public ActorFactory
	{
	public:
		ADD_OBJECT(ScriptClass, InventoryClass, 92)
		void PostCreateActor(class Actor* NewActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTActorFactoryPickup.PostCreateActor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = NewActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_OBJECT
