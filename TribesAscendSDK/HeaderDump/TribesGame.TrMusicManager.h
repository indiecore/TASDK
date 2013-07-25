#pragma once
#include "Engine.Info.h"
#include "Engine.SoundCue.h"
#include "TribesGame.TrPlayerController.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrMusicManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrMusicManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrMusicManager : public Info
	{
	public:
		ADD_OBJECT(TrPlayerController, m_PlayerOwner)
		ADD_VAR(::FloatProperty, m_fMusicVolume, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_CurrentState, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, m_PendingState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fStingerVolumeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_CTFTeamScores, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* CreateNewTrack(class SoundCue* MusicCue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.CreateNewTrack");
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = MusicCue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void StartMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.StartMusic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetStateBasedOnGameState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.SetStateBasedOnGameState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MusicEvent(int NewEventIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.MusicEvent");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewEventIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPendingState(byte NewState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.SetPendingState");
			byte* params = (byte*)malloc(1);
			*params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCurrentState(byte NewState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.SetCurrentState");
			byte* params = (byte*)malloc(1);
			*params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerScoredFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrMusicManager.PlayerScoredFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
