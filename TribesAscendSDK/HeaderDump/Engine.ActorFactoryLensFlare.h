#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.LensFlare.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryLensFlare : public ActorFactory
	{
	public:
		ADD_OBJECT(LensFlare, LensFlareObject, 92)
	};
}
#undef ADD_OBJECT
