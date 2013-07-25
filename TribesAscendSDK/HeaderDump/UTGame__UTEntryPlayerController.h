#pragma once
#include "UTGame__UTPlayerController.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTEntryPlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTEntryPlayerController : public UTPlayerController
	{
	public:
		ADD_OBJECT(LocalPlayer, OldPlayer)
		ADD_OBJECT(PostProcessChain, EntryPostProcessChain)
	};
}
#undef ADD_OBJECT
