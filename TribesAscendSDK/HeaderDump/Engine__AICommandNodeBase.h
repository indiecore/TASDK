#pragma once
#include "Engine__AIController.h"
#include "Engine__K2NodeBase.h"
#include "Engine__DMC_Prototype.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AICommandNodeBase." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AICommandNodeBase : public K2NodeBase
	{
	public:
		ADD_OBJECT(DMC_Prototype, UtilityDMC)
		ADD_OBJECT(ScriptClass, CommandClass)
		// Here lies the not-yet-implemented method 'SelectBestChild'
	};
}
#undef ADD_OBJECT
