#pragma once
#include "Engine__LensFlare.h"
#include "Engine__ActorFactory.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryLensFlare." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryLensFlare : public ActorFactory
	{
	public:
		ADD_OBJECT(LensFlare, LensFlareObject)
	};
}
#undef ADD_OBJECT
