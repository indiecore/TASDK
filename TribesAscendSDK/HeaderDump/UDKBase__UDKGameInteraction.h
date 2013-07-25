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
		// Here lies the not-yet-implemented method 'ShouldProcessUIInput'
		// Here lies the not-yet-implemented method 'ClearUIInputBlocks'
		// Here lies the not-yet-implemented method 'BlockUIInput'
		// Here lies the not-yet-implemented method 'NotifyGameSessionEnded'
	};
}
#undef ADD_VAR
