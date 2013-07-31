#pragma once
#include "Engine.ActorFactory.h"
#include "Engine.SpeedTree.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SpeedTreeActorFactory : public ActorFactory
	{
	public:
		ADD_OBJECT(SpeedTree, SpeedTree, 92)
	};
}
#undef ADD_OBJECT
