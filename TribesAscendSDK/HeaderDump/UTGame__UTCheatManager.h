#pragma once
#include "Engine__CheatManager.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCheatManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCheatManager : public CheatManager
	{
	public:
		ADD_OBJECT(SpeechRecognition, RecogObject)
	};
}
#undef ADD_OBJECT
