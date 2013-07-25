#pragma once
#include "Engine.SequenceEvent.h"
#include "GFxUI.GFxFSCmdHandler_Kismet.h"
#include "GFxUI.SwfMovie.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GFxUI.GFxEvent_FSCommand." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GFxUI.GFxEvent_FSCommand." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxEvent_FSCommand : public SequenceEvent
	{
	public:
		ADD_OBJECT(GFxFSCmdHandler_Kismet, Handler)
		ADD_VAR(::StrProperty, FSCommand, 0xFFFFFFFF)
		ADD_OBJECT(SwfMovie, Movie)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
