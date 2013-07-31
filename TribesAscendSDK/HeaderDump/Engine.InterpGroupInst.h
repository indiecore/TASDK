#pragma once
#include "Engine.Actor.h"
#include "Engine.InterpTrackInst.h"
#include "Core.Object.h"
#include "Engine.InterpGroup.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class InterpGroupInst : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<class InterpTrackInst*>, TrackInst, 68)
		ADD_OBJECT(Actor, GroupActor, 64)
		ADD_OBJECT(InterpGroup, Group, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
