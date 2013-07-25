#pragma once
#include "Engine__ActorFactory.h"
#include "Engine__Actor.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTActorFactoryPickup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTActorFactoryPickup : public ActorFactory
	{
	public:
		ADD_OBJECT(ScriptClass, InventoryClass)
		// Here lies the not-yet-implemented method 'PostCreateActor'
	};
}
#undef ADD_OBJECT
