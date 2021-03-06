#pragma once
#include "Engine.Actor.h"
#include "Engine.InterpTrackInst.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class InterpTrackInstDirector : public InterpTrackInst
	{
	public:
		ADD_OBJECT(Actor, OldViewTarget, 60)
	};
}
#undef ADD_OBJECT
