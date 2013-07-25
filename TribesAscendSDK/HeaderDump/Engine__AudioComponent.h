#pragma once
#include "Engine__ActorComponent.h"
#include "Engine__SoundCue.h"
#include "Engine__SoundNodeWave.h"
#include "Engine__SoundNode.h"
#include "Engine__Actor.h"
#include "Engine__PortalVolume.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AudioComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AudioComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AudioComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AudioComponent : public ActorComponent
	{
	public:
		ADD_VAR(::BoolProperty, bUseOwnerLocation, 0x1)
		ADD_STRUCT(::VectorProperty, Location, 0xFFFFFFFF
		ADD_VAR(::BoolProperty, bAllowSpatialization, 0x100)
		ADD_VAR(::FloatProperty, VolumeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, PitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAutoDestroy, 0x4)
		ADD_VAR(::FloatProperty, SubtitlePriority, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSuppressSubtitles, 0x40)
		ADD_OBJECT(SoundCue, SoundCue)
		ADD_VAR(::FloatProperty, LastOcclusionCheckTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OcclusionCheckInterval, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, HighFrequencyGainMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastReverbVolumeIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Engine.ReverbVolume.InteriorSettings' for the property named 'LastInteriorSettings'!
		ADD_STRUCT(::VectorProperty, LastLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, CurrentInteriorLPF, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentInteriorVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SourceInteriorLPF, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SourceInteriorVolume, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'LastUpdateTime'!
		ADD_VAR(::FloatProperty, CurrentRadioFilterVolumeThreshold, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentRadioFilterVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentVoiceCenterChannelVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentHighFrequencyGainMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentPitchMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentVolumeMultiplier, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentNotifyOnLoop, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CurrentUseSpatialization, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentHighFrequencyGain, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentPitch, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentVolume, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, CurrentLocation, 0xFFFFFFFF
		ADD_OBJECT(SoundNode, CurrentNotifyBufferFinishedHook)
		ADD_VAR(::FloatProperty, CurrAdjustVolumeTargetVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AdjustVolumeTargetVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AdjustVolumeStopTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AdjustVolumeStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutTargetVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutStopTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeOutStartTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInTargetVolume, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInStopTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FadeInStartTime, 0xFFFFFFFF)
		ADD_OBJECT(Actor, LastOwner)
		ADD_STRUCT(::VectorProperty, ComponentLocation, 0xFFFFFFFF
		ADD_OBJECT(PortalVolume, PortalVolume)
		ADD_VAR(::FloatProperty, PlaybackTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Listener'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.MultiMap_Mirror' for the property named 'SoundNodeResetWaveMap'!
		ADD_VAR(::BoolProperty, bBassBoost, 0x40)
		ADD_VAR(::BoolProperty, bCenterChannelOnly, 0x20)
		ADD_VAR(::BoolProperty, bReverb, 0x10)
		ADD_VAR(::BoolProperty, bIsMusic, 0x8)
		ADD_VAR(::BoolProperty, bIsUISound, 0x4)
		ADD_VAR(::BoolProperty, bAlwaysPlay, 0x2)
		ADD_VAR(::BoolProperty, bEQFilterApplied, 0x1)
		ADD_VAR(::FloatProperty, LFEBleed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, StereoBleed, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIgnoreForFlushing, 0x800)
		ADD_VAR(::BoolProperty, bPreviewComponent, 0x400)
		ADD_VAR(::BoolProperty, bFinished, 0x200)
		ADD_VAR(::BoolProperty, bWasPlaying, 0x80)
		ADD_VAR(::BoolProperty, bWasOccluded, 0x20)
		ADD_VAR(::BoolProperty, bShouldRemainActiveIfDropped, 0x10)
		ADD_VAR(::BoolProperty, bStopWhenOwnerDestroyed, 0x8)
		ADD_VAR(::BoolProperty, bAutoPlay, 0x2)
		ADD_OBJECT(SoundNode, CueFirstNode)
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
			byte* params = (byte*)malloc(8);
			*(float*)params = FadeInDuration;
			*(float*)(params + 4) = FadeVolumeLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FadeOut(float FadeOutDuration, float FadeVolumeLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.FadeOut");
			byte* params = (byte*)malloc(8);
			*(float*)params = FadeOutDuration;
			*(float*)(params + 4) = FadeVolumeLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnQueueSubtitles(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void* Subtitles, float CueDuration)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.OnQueueSubtitles");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Subtitles;
			*(float*)(params + 12) = CueDuration;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnAudioFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.OnAudioFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Stop()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.Stop");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPlaying()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.IsPlaying");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void AdjustVolume(float AdjustVolumeDuration, float AdjustVolumeLevel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.AdjustVolume");
			byte* params = (byte*)malloc(8);
			*(float*)params = AdjustVolumeDuration;
			*(float*)(params + 4) = AdjustVolumeLevel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetFloatParameter(ScriptName InName, float InFloat)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.SetFloatParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InName;
			*(float*)(params + 8) = InFloat;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWaveParameter(ScriptName InName, class SoundNodeWave* InWave)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.SetWaveParameter");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = InName;
			*(class SoundNodeWave**)(params + 8) = InWave;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OcclusionChanged(bool bNowOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioComponent.OcclusionChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowOccluded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
