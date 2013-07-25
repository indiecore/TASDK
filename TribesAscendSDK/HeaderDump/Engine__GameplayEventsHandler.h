#pragma once
#include "Core__Object.h"
#include "Engine__GameplayEventsReader.h"
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
		// Here lies the not-yet-implemented method 'SetReader'
		// Here lies the not-yet-implemented method 'PreProcessStream'
		// Here lies the not-yet-implemented method 'PostProcessStream'
		// Here lies the not-yet-implemented method 'ResolveGroupFilters'
		// Here lies the not-yet-implemented method 'AddFilter'
		// Here lies the not-yet-implemented method 'RemoveFilter'
		// Here lies the not-yet-implemented method 'IsEventFiltered'
	};
}
#undef ADD_OBJECT
