#pragma once
#include "Engine.ActorComponent.h"
#include "Engine.Texture2D.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ImageReflectionComponent : public ActorComponent
	{
	public:
		ADD_OBJECT(Texture2D, ReflectionTexture, 88)
	};
}
#undef ADD_OBJECT
