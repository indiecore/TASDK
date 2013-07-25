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
		class AICommandNodeBase* SelectBestChild(class AIController* InAI, 
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void*& Handle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AICommandNodeBase.SelectBestChild");
			byte* params = (byte*)malloc(56);
			*(class AIController**)params = InAI;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void**)(params + 4) = Handle;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Handle = *(
// WARNING: Unknown structure type 'ScriptStruct Engine.AITree.AITreeHandle'!
void**)(params + 4);
			auto returnVal = *(class AICommandNodeBase**)(params + 52);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
