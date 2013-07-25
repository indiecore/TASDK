#pragma once
#include "Core__Object.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameplayEventsHandler." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameplayEventsHandler : public Object
	{
	public:
		ADD_OBJECT(GameplayEventsReader, Reader)
	};
}
#undef ADD_OBJECT
