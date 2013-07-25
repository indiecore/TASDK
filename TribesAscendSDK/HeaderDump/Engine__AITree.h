#pragma once
#include "Engine__K2GraphBase.h"
#include "Engine__AIController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AITree." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AITree : public K2GraphBase
	{
	public:
		ADD_OBJECT(K2GraphBase, GatherList)
		// Here lies the not-yet-implemented method 'SetActiveRoot'
		// Here lies the not-yet-implemented method 'EvaluateTree'
	};
}
#undef ADD_OBJECT
