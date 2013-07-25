#pragma once
#include "UTGame__UTLocalMessage.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTVictoryMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTVictoryMessage : public UTLocalMessage
	{
	public:
		ADD_OBJECT(SoundNodeWave, VictorySounds)
	};
}
#undef ADD_OBJECT
