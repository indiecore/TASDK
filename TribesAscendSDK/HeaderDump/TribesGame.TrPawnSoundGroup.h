#pragma once
#include "UTGame.UTPawnSoundGroup.h"
#include "Engine.SoundCue.h"
#include "Engine.Pawn.h"
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
	class TrPawnSoundGroup : public UTPawnSoundGroup
	{
	public:
		ADD_OBJECT(SoundCue, m_RechargeHealthSound3p, 184)
		ADD_OBJECT(SoundCue, m_ShieldPackLoopSound1p, 204)
		ADD_OBJECT(SoundCue, m_ShieldPackLoopSound3p, 208)
		ADD_OBJECT(SoundCue, m_StealthPackLoopSound1p, 228)
		ADD_OBJECT(SoundCue, m_RageLoopSound1p, 276)
		ADD_OBJECT(SoundCue, m_RageLoopSound3p, 280)
		ADD_OBJECT(SoundCue, m_JammerPackLoopSound1p, 252)
		ADD_OBJECT(SoundCue, m_JetpackLoopSound, 168)
		ADD_OBJECT(SoundCue, m_LowHealthSound, 176)
		ADD_OBJECT(SoundCue, m_RechargeHealthSound, 180)
		ADD_STRUCT(ScriptArray<class SoundCue*>, m_DyingSounds, 284)
		ADD_OBJECT(SoundCue, m_BlinkPackSound3p, 300)
		ADD_OBJECT(SoundCue, m_BlinkPackSound1p, 296)
		ADD_OBJECT(SoundCue, m_RageDeactivateSound3p, 272)
		ADD_OBJECT(SoundCue, m_RageDeactivateSound1p, 268)
		ADD_OBJECT(SoundCue, m_RageActivateSound3p, 264)
		ADD_OBJECT(SoundCue, m_RageActivateSound1p, 260)
		ADD_OBJECT(SoundCue, m_JammerPackLoopSound3p, 256)
		ADD_OBJECT(SoundCue, m_JammerPackDeactivateSound3p, 248)
		ADD_OBJECT(SoundCue, m_JammerPackDeactivateSound1p, 244)
		ADD_OBJECT(SoundCue, m_JammerPackActivateSound3p, 240)
		ADD_OBJECT(SoundCue, m_JammerPackActivateSound1p, 236)
		ADD_OBJECT(SoundCue, m_StealthPackLoopSound3p, 232)
		ADD_OBJECT(SoundCue, m_StealthPackDeactivateSound3p, 224)
		ADD_OBJECT(SoundCue, m_StealthPackDeactivateSound1p, 220)
		ADD_OBJECT(SoundCue, m_StealthPackActivateSound3p, 216)
		ADD_OBJECT(SoundCue, m_StealthPackActivateSound1p, 212)
		ADD_OBJECT(SoundCue, m_ShieldPackDeactivateSound3p, 200)
		ADD_OBJECT(SoundCue, m_ShieldPackDeactivateSound1p, 196)
		ADD_OBJECT(SoundCue, m_ShieldPackActivateSound3p, 192)
		ADD_OBJECT(SoundCue, m_ShieldPackActivateSound1p, 188)
		ADD_OBJECT(SoundCue, m_JetpackCooldownSound, 172)
		void PlayShieldPackActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayShieldPackActivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayShieldPackDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayShieldPackDeactivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayStealthPackActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayStealthPackActivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayStealthPackDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayStealthPackDeactivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayJammerPackActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayJammerPackActivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayJammerPackDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayJammerPackDeactivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRageActivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayRageActivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRageDeactivateSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayRageDeactivateSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayDyingSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayDyingSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayBlinkPackSound(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrPawnSoundGroup.PlayBlinkPackSound");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
