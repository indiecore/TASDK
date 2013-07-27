#pragma once
#include "Engine.K2NodeBase.h"
#include "Engine.AITree.h"
#include "Engine.DMC_Prototype.h"
#include "Engine.AIController.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class AICommandNodeBase : public K2NodeBase
	{
	public:
		ADD_OBJECT(DMC_Prototype, UtilityDMC, 96)
		ADD_OBJECT(ScriptClass, CommandClass, 92)
		class AICommandNodeBase* SelectBestChild(class AIController* InAI, AITree::AITreeHandle& Handle)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AICommandNodeBase.SelectBestChild");
			byte params[56] = { NULL };
			*(class AIController**)&params[0] = InAI;
			*(AITree::AITreeHandle*)&params[4] = Handle;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Handle = *(AITree::AITreeHandle*)&params[4];
			return *(class AICommandNodeBase**)&params[52];
		}
	};
}
#undef ADD_OBJECT
