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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.ShouldProcessUIInput");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClearUIInputBlocks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.ClearUIInputBlocks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BlockUIInput(bool bBlock)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.BlockUIInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bBlock;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.NotifyGameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
