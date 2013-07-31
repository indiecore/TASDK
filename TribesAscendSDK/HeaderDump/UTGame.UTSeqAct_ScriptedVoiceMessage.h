#pragma once
#include "Engine.SequenceAction.h"
#include "Engine.SoundNodeWave.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTSeqAct_ScriptedVoiceMessage : public SequenceAction
	{
	public:
		ADD_STRUCT(ScriptString*, SpeakingCharacterName, 236)
		ADD_OBJECT(SoundNodeWave, VoiceToPlay, 232)
		void Activated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49127);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetObjClassVersion()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(49132);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
