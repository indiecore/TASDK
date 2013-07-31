#pragma once
#include "Engine.UIInteraction.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UDKGameInteraction : public UIInteraction
	{
	public:
		ADD_STRUCT(int, BlockUIInputSemaphore, 348)
		bool ShouldProcessUIInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34862);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClearUIInputBlocks()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34864);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BlockUIInput(bool bBlock)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34865);
			byte params[4] = { NULL };
			*(bool*)params = bBlock;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(34867);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
