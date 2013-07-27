#pragma once
#include "Engine.SoundNodeWave.h"
#include "Engine.ActorComponent.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.ReverbVolume.h"
#include "Engine.SoundCue.h"
#include "Engine.SoundNode.h"
#include "Engine.PortalVolume.h"
#include "Engine.EngineTypes.h"
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
	class AudioComponent : public ActorComponent
	{
	public:
		class AudioComponentParam
		{
		public:
			ADD_OBJECT(SoundNodeWave, WaveParam, 12)
			ADD_STRUCT(float, FloatParam, 8)
			ADD_STRUCT(ScriptName, ParamName, 0)
		};
		ADD_BOOL(bUseOwnerLocation, 108, 0x1)
		ADD_STRUCT(Object::Vector, Location, 280)
		ADD_BOOL(bAllowSpatialization, 108, 0x100)
		ADD_STRUCT(float, VolumeMultiplier, 488)
		ADD_STRUCT(float, PitchMultiplier, 492)
		ADD_BOOL(bAutoDestroy, 108, 0x4)
		ADD_STRUCT(float, SubtitlePriority, 308)
		ADD_BOOL(bSuppressSubtitles, 108, 0x40)
		ADD_OBJECT(SoundCue, SoundCue, 88)
		ADD_STRUCT(ScriptArray<AudioComponent::AudioComponentParam>, InstanceParameters, 96)
		ADD_STRUCT(ScriptArray<Object::Pointer>, WaveInstances, 124)
		ADD_STRUCT(ScriptArray<byte>, SoundNodeData, 136)
		ADD_STRUCT(float, LastOcclusionCheckTime, 504)
		ADD_STRUCT(float, OcclusionCheckInterval, 500)
		ADD_STRUCT(float, HighFrequencyGainMultiplier, 496)
		ADD_STRUCT(int, LastReverbVolumeIndex, 484)
		ADD_STRUCT(ReverbVolume::InteriorSettings, LastInteriorSettings, 448)
		ADD_STRUCT(Object::Vector, LastLocation, 436)
		ADD_STRUCT(float, CurrentInteriorLPF, 432)
		ADD_STRUCT(float, CurrentInteriorVolume, 428)
		ADD_STRUCT(float, SourceInteriorLPF, 424)
		ADD_STRUCT(float, SourceInteriorVolume, 420)
		ADD_STRUCT(Object::Double, LastUpdateTime, 412)
		ADD_STRUCT(float, CurrentRadioFilterVolumeThreshold, 408)
		ADD_STRUCT(float, CurrentRadioFilterVolume, 404)
		ADD_STRUCT(float, CurrentVoiceCenterChannelVolume, 400)
		ADD_STRUCT(float, CurrentHighFrequencyGainMultiplier, 396)
		ADD_STRUCT(float, CurrentPitchMultiplier, 392)
		ADD_STRUCT(float, CurrentVolumeMultiplier, 388)
		ADD_STRUCT(int, CurrentNotifyOnLoop, 384)
		ADD_STRUCT(int, CurrentUseSpatialization, 380)
		ADD_STRUCT(float, CurrentHighFrequencyGain, 376)
		ADD_STRUCT(float, CurrentPitch, 372)
		ADD_STRUCT(float, CurrentVolume, 368)
		ADD_STRUCT(Object::Vector, CurrentLocation, 356)
		ADD_OBJECT(SoundNode, CurrentNotifyBufferFinishedHook, 352)
		ADD_STRUCT(float, CurrAdjustVolumeTargetVolume, 348)
		ADD_STRUCT(float, AdjustVolumeTargetVolume, 344)
		ADD_STRUCT(float, AdjustVolumeStopTime, 340)
		ADD_STRUCT(float, AdjustVolumeStartTime, 336)
		ADD_STRUCT(float, FadeOutTargetVolume, 332)
		ADD_STRUCT(float, FadeOutStopTime, 328)
		ADD_STRUCT(float, FadeOutStartTime, 324)
		ADD_STRUCT(float, FadeInTargetVolume, 320)
		ADD_STRUCT(float, FadeInStopTime, 316)
		ADD_STRUCT(float, FadeInStartTime, 312)
		ADD_OBJECT(Actor, LastOwner, 304)
		ADD_STRUCT(Object::Vector, ComponentLocation, 292)
		ADD_OBJECT(PortalVolume, PortalVolume, 276)
		ADD_STRUCT(float, PlaybackTime, 272)
		ADD_STRUCT(Object::Pointer, Listener, 268)
		ADD_STRUCT(Object::MultiMap_Mirror, SoundNodeResetWaveMap, 208)
		ADD_BOOL(bBassBoost, 120, 0x40)
		ADD_BOOL(bCenterChannelOnly, 120, 0x20)
		ADD_BOOL(bReverb, 120, 0x10)
		ADD_BOOL(bIsMusic, 120, 0x8)
		ADD_BOOL(bIsUISound, 120, 0x4)
		ADD_BOOL(bAlwaysPlay, 120, 0x2)
		ADD_BOOL(bEQFilterApplied, 120, 0x1)
		ADD_STRUCT(float, LFEBleed, 116)
		ADD_STRUCT(float, StereoBleed, 112)
		ADD_BOOL(bIgnoreForFlushing, 108, 0x800)
		ADD_BOOL(bPreviewComponent, 108, 0x400)
		ADD_BOOL(bFinished, 108, 0x200)
		ADD_BOOL(bWasPlaying, 108, 0x80)
		ADD_BOOL(bWasOccluded, 108, 0x20)
		ADD_BOOL(bShouldRemainActiveIfDropped, 108, 0x10)
		ADD_BOOL(bStopWhenOwnerDestroyed, 108, 0x8)
		ADD_BOOL(bAutoPlay, 108, 0x2)
		ADD_OBJECT(SoundNode, CueFirstNode, 92)
		void ResetToDefaults()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.ResetToDefaults");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Play()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.Play");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FadeIn(float FadeInDuration, float FadeVolumeLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.FadeIn");
			byte params[8] = { NULL };
			*(float*)&params[0] = FadeInDuration;
			*(float*)&params[4] = FadeVolumeLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FadeOut(float FadeOutDuration, float FadeVolumeLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.FadeOut");
			byte params[8] = { NULL };
			*(float*)&params[0] = FadeOutDuration;
			*(float*)&params[4] = FadeVolumeLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnQueueSubtitles(ScriptArray<EngineTypes::SubtitleCue> Subtitles, float CueDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.OnQueueSubtitles");
			byte params[16] = { NULL };
			*(ScriptArray<EngineTypes::SubtitleCue>*)&params[0] = Subtitles;
			*(float*)&params[12] = CueDuration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.OnAudioFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Stop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.Stop");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPlaying()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.IsPlaying");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void AdjustVolume(float AdjustVolumeDuration, float AdjustVolumeLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.AdjustVolume");
			byte params[8] = { NULL };
			*(float*)&params[0] = AdjustVolumeDuration;
			*(float*)&params[4] = AdjustVolumeLevel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFloatParameter(ScriptName InName, float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.SetFloatParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InName;
			*(float*)&params[8] = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWaveParameter(ScriptName InName, class SoundNodeWave* InWave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.SetWaveParameter");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = InName;
			*(class SoundNodeWave**)&params[8] = InWave;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OcclusionChanged(bool bNowOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.OcclusionChanged");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
