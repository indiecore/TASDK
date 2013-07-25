#pragma once
#include "Engine.Info.h"
#include "UTGame.UTPlayerController.h"
#include "Engine.SoundCue.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTMusicManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTMusicManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTMusicManager : public Info
	{
	public:
		ADD_VAR(::FloatProperty, MusicStartTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastBeat, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, CurrentState, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MusicVolume, 0xFFFFFFFF)
		ADD_OBJECT(UTPlayerController, PlayerOwner)
		ADD_VAR(::FloatProperty, CurrTempo, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrFadeFactor, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PendingEvent, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PendingEventPlayTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PendingEventDelay, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPendingAction, 0x1)
		ADD_VAR(::FloatProperty, LastActionEventTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StingerVolumeMultiplier, 0xFFFFFFFF)
		bool AlreadyInActionMusic()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.AlreadyInActionMusic");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* CreateNewTrack(class SoundCue* MusicCue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.CreateNewTrack");
			byte* params = (byte*)malloc(8);
			*(class SoundCue**)params = MusicCue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 4);
			free(params);
			return returnVal;
		}
		void MusicEvent(int NewEventIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.MusicEvent");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewEventIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessMusicEvent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.ProcessMusicEvent");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.Tick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangeTrack(byte NewState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTMusicManager.ChangeTrack");
			byte* params = (byte*)malloc(1);
			*params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
