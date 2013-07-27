#pragma once
#include "Engine.SequenceEvent.h"
#include "GFxUI.GFxFSCmdHandler_Kismet.h"
#include "GFxUI.SwfMovie.h"
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
	class GFxEvent_FSCommand : public SequenceEvent
	{
	public:
		ADD_OBJECT(GFxFSCmdHandler_Kismet, Handler, 272)
		ADD_STRUCT(ScriptString*, FSCommand, 260)
		ADD_OBJECT(SwfMovie, Movie, 256)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
