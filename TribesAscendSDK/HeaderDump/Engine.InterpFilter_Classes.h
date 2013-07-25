#pragma once
#include "Engine.InterpFilter.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InterpFilter_Classes." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InterpFilter_Classes : public InterpFilter
	{
	public:
		ADD_OBJECT(ScriptClass, ClassToFilterBy)
	};
}
#undef ADD_OBJECT
