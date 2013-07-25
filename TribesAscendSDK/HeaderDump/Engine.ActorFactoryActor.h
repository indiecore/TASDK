#pragma once
#include "Engine.ActorFactory.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryActor." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryActor : public ActorFactory
	{
	public:
		ADD_OBJECT(ScriptClass, ActorClass)
	};
}
#undef ADD_OBJECT
