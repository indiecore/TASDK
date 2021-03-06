#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.MaterialInterface.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryDecal : public ActorFactory
	{
	public:
		ADD_OBJECT(MaterialInterface, DecalMaterial, 92)
	};
}
#undef ADD_OBJECT
