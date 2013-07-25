#pragma once
#include "Engine__GameplayEvents.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameplayEventsWriter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameplayEventsWriter : public GameplayEvents
	{
	public:
		ADD_OBJECT(GameInfo, Game)
	};
}
#undef ADD_OBJECT
