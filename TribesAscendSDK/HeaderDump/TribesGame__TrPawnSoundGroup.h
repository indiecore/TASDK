#pragma once
#include "Engine__Pawn.h"
#include "UTGame__UTPawnSoundGroup.h"
#include "Engine__SoundCue.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrPawnSoundGroup." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrPawnSoundGroup : public UTPawnSoundGroup
	{
	public:
		ADD_OBJECT(SoundCue, m_RechargeHealthSound3p)
		ADD_OBJECT(SoundCue, m_ShieldPackLoopSound1p)
		ADD_OBJECT(SoundCue, m_ShieldPackLoopSound3p)
		ADD_OBJECT(SoundCue, m_StealthPackLoopSound1p)
		ADD_OBJECT(SoundCue, m_RageLoopSound1p)
		ADD_OBJECT(SoundCue, m_RageLoopSound3p)
		ADD_OBJECT(SoundCue, m_JammerPackLoopSound1p)
		ADD_OBJECT(SoundCue, m_JetpackLoopSound)
		ADD_OBJECT(SoundCue, m_LowHealthSound)
		ADD_OBJECT(SoundCue, m_RechargeHealthSound)
		ADD_OBJECT(SoundCue, m_BlinkPackSound3p)
		ADD_OBJECT(SoundCue, m_BlinkPackSound1p)
		ADD_OBJECT(SoundCue, m_RageDeactivateSound3p)
		ADD_OBJECT(SoundCue, m_RageDeactivateSound1p)
		ADD_OBJECT(SoundCue, m_RageActivateSound3p)
		ADD_OBJECT(SoundCue, m_RageActivateSound1p)
		ADD_OBJECT(SoundCue, m_JammerPackLoopSound3p)
		ADD_OBJECT(SoundCue, m_JammerPackDeactivateSound3p)
		ADD_OBJECT(SoundCue, m_JammerPackDeactivateSound1p)
		ADD_OBJECT(SoundCue, m_JammerPackActivateSound3p)
		ADD_OBJECT(SoundCue, m_JammerPackActivateSound1p)
		ADD_OBJECT(SoundCue, m_StealthPackLoopSound3p)
		ADD_OBJECT(SoundCue, m_StealthPackDeactivateSound3p)
		ADD_OBJECT(SoundCue, m_StealthPackDeactivateSound1p)
		ADD_OBJECT(SoundCue, m_StealthPackActivateSound3p)
		ADD_OBJECT(SoundCue, m_StealthPackActivateSound1p)
		ADD_OBJECT(SoundCue, m_ShieldPackDeactivateSound3p)
		ADD_OBJECT(SoundCue, m_ShieldPackDeactivateSound1p)
		ADD_OBJECT(SoundCue, m_ShieldPackActivateSound3p)
		ADD_OBJECT(SoundCue, m_ShieldPackActivateSound1p)
		ADD_OBJECT(SoundCue, m_JetpackCooldownSound)
		void PlayShieldPackActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayShieldPackActivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayShieldPackDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayShieldPackDeactivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayStealthPackActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayStealthPackActivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayStealthPackDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayStealthPackDeactivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayJammerPackActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayJammerPackActivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayJammerPackDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayJammerPackDeactivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRageActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayRageActivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRageDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayRageDeactivateSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayDyingSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayDyingSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayBlinkPackSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayBlinkPackSound");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_OBJECT
