#pragma once
#include "Engine__ActorComponent.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.ImageReflectionComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class ImageReflectionComponent : public ActorComponent
	{
	public:
		ADD_OBJECT(Texture2D, ReflectionTexture)
	};
}
#undef ADD_OBJECT
