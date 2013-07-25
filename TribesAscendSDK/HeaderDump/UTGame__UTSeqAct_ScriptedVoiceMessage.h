#pragma once
#include "Engine__SequenceAction.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTSeqAct_ScriptedVoiceMessage." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTSeqAct_ScriptedVoiceMessage." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_ScriptedVoiceMessage : public SequenceAction
	{
	public:
		ADD_VAR(::StrProperty, SpeakingCharacterName, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, VoiceToPlay)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
