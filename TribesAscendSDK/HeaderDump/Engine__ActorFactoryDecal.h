#pragma once
#include "Engine__ActorFactory.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ActorFactoryDecal." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryDecal : public ActorFactory
	{
	public:
		ADD_OBJECT(MaterialInterface, DecalMaterial)
	};
}
#undef ADD_OBJECT
