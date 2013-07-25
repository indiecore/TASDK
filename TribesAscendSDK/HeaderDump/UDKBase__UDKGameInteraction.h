#pragma once
#include "Engine__UIInteraction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UDKBase.UDKGameInteraction." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class UDKGameInteraction : public UIInteraction
	{
	public:
		ADD_VAR(::IntProperty, BlockUIInputSemaphore, 0xFFFFFFFF)
		bool ShouldProcessUIInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.ShouldProcessUIInput");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClearUIInputBlocks()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.ClearUIInputBlocks");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BlockUIInput(bool bBlock)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.BlockUIInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bBlock;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyGameSessionEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UDKBase.UDKGameInteraction.NotifyGameSessionEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
