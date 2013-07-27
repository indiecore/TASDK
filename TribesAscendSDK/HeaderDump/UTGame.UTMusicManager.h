#pragma once
#include "Engine.Info.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.SoundCue.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class UTMusicManager : public Info
	{
	public:
		enum EMusicState : byte
		{
			MST_Ambient = 0,
			MST_Tension = 1,
			MST_Suspense = 2,
			MST_Action = 3,
			MST_Victory = 4,
			MST_MAX = 5,
		};
		ADD_STRUCT(float, MusicStartTime, 476)
		ADD_STRUCT(int, LastBeat, 480)
		ADD_STRUCT(UTMusicManager::EMusicState, CurrentState, 512)
		ADD_STRUCT(float, MusicVolume, 496)
		ADD_OBJECT(UTPlayerController, PlayerOwner, 492)
		ADD_STRUCT(float, CurrTempo, 484)
		ADD_STRUCT(float, CurrFadeFactor, 488)
		ADD_STRUCT(int, PendingEvent, 516)
		ADD_STRUCT(float, PendingEventPlayTime, 520)
		ADD_STRUCT(float, PendingEventDelay, 524)
		ADD_BOOL(bPendingAction, 504, 0x1)
		ADD_STRUCT(float, LastActionEventTime, 500)
		ADD_STRUCT(float, StingerVolumeMultiplier, 508)
		bool AlreadyInActionMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.AlreadyInActionMusic");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.StartMusic");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void IntroFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.IntroFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* CreateNewTrack(class SoundCue* MusicCue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.CreateNewTrack");
			byte params[8] = { NULL };
			*(class SoundCue**)&params[0] = MusicCue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[4];
		}
		void MusicEvent(int NewEventIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.MusicEvent");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewEventIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessMusicEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.ProcessMusicEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ChangeTrack(UTMusicManager::EMusicState NewState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.ChangeTrack");
			byte params[1] = { NULL };
			*(UTMusicManager::EMusicState*)&params[0] = NewState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
