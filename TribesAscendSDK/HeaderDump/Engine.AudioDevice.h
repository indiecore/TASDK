#pragma once
#include "Core.Subsystem.h"
#include "Engine.SoundClass.h"
#include "Core.Object.h"
#include "Engine.ReverbVolume.h"
#include "Engine.SoundMode.h"
#include "Engine.SoundNodeWave.h"
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
	class AudioDevice : public Subsystem
	{
	public:
		enum EDebugState : byte
		{
			DEBUGSTATE_None = 0,
			DEBUGSTATE_IsolateDryAudio = 1,
			DEBUGSTATE_IsolateReverb = 2,
			DEBUGSTATE_TestLPF = 3,
			DEBUGSTATE_TestStereoBleed = 4,
			DEBUGSTATE_TestLFEBleed = 5,
			DEBUGSTATE_DisableLPF = 6,
			DEBUGSTATE_DisableRadio = 7,
			DEBUGSTATE_MAX = 8,
		};
		enum ESoundClassName : byte
		{
			World_Props = 0,
			WeaponFoley = 1,
			WeaponFire = 2,
			WeaponExplosion = 3,
			Weapon = 4,
			VoxRadio = 5,
			VoxIngame = 6,
			VoxHelp = 7,
			VoxExceptions = 8,
			VoxAnnouncer = 9,
			Vox2 = 10,
			VOX = 11,
			Vehicle = 12,
			UI = 13,
			Tutorial_VOX_Reverb = 14,
			Tutorial_SFX_Reverb = 15,
			SFXExceptions = 16,
			SFX = 17,
			Music = 18,
			Master = 19,
			Concussion = 20,
			Character = 21,
			Ambient = 22,
			ESoundClassName_MAX = 23,
		};
		enum ETTSSpeaker : byte
		{
			TTSSPEAKER_Paul = 0,
			TTSSPEAKER_Harry = 1,
			TTSSPEAKER_Frank = 2,
			TTSSPEAKER_Dennis = 3,
			TTSSPEAKER_Kit = 4,
			TTSSPEAKER_Betty = 5,
			TTSSPEAKER_Ursula = 6,
			TTSSPEAKER_Rita = 7,
			TTSSPEAKER_Wendy = 8,
			TTSSPEAKER_MAX = 9,
		};
		struct Listener
		{
		public:
			ADD_STRUCT(Vector, Front, 40)
			ADD_STRUCT(Vector, Right, 28)
			ADD_STRUCT(Vector, Up, 16)
			ADD_STRUCT(Vector, Location, 4)
			ADD_OBJECT(PortalVolume, PortalVolume, 0)
		};
		struct AudioClassInfo
		{
		public:
			ADD_STRUCT(int, SizeRealTime, 12)
			ADD_STRUCT(int, NumRealTime, 8)
			ADD_STRUCT(int, SizeResident, 4)
			ADD_STRUCT(int, NumResident, 0)
		};
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, AudioComponents, 128)
		ADD_STRUCT(ScriptArray<Object::Pointer>, Sources, 140)
		ADD_STRUCT(ScriptArray<Object::Pointer>, FreeSources, 152)
		ADD_STRUCT(ScriptArray<AudioDevice::Listener>, Listeners, 224)
		ADD_STRUCT(float, LastUpdateTime, 704)
		ADD_STRUCT(float, TransientMasterVolume, 700)
		ADD_STRUCT(AudioDevice::EDebugState, DebugState, 696)
		ADD_STRUCT(Object::Pointer, TextToSpeech, 692)
		ADD_STRUCT(float, ExteriorLPFInterp, 684)
		ADD_STRUCT(float, ExteriorVolumeInterp, 680)
		ADD_STRUCT(float, InteriorLPFInterp, 676)
		ADD_STRUCT(float, InteriorVolumeInterp, 672)
		ADD_STRUCT(Object::Double, ExteriorLPFEndTime, 664)
		ADD_STRUCT(Object::Double, InteriorLPFEndTime, 656)
		ADD_STRUCT(Object::Double, ExteriorEndTime, 648)
		ADD_STRUCT(Object::Double, InteriorEndTime, 640)
		ADD_STRUCT(Object::Double, InteriorStartTime, 632)
		ADD_STRUCT(ReverbVolume::InteriorSettings, ListenerInteriorSettings, 596)
		ADD_STRUCT(int, ListenerVolumeIndex, 592)
		ADD_STRUCT(Object::Double, SoundModeEndTime, 584)
		ADD_STRUCT(Object::Double, SoundModeFadeInEndTime, 576)
		ADD_STRUCT(Object::Double, SoundModeFadeInStartTime, 568)
		ADD_STRUCT(Object::Double, SoundModeStartTime, 560)
		ADD_OBJECT(SoundMode, CurrentMode, 556)
		ADD_STRUCT(ScriptName, BaseSoundModeName, 548)
		ADD_STRUCT(Object::Pointer, Effects, 544)
		ADD_STRUCT(QWord, CurrentTick, 236)
		ADD_STRUCT(int, CommonAudioPoolFreeBytes, 124)
		ADD_STRUCT(Object::Pointer, CommonAudioPool, 120)
		ADD_BOOL(bGameWasTicking, 116, 0x2)
		ADD_BOOL(m_bEnableBassBoost, 116, 0x1)
		ADD_OBJECT(SoundNodeWave, ChirpOutSoundNodeWave, 112)
		ADD_STRUCT(ScriptString*, ChirpOutSoundNodeWaveName, 100)
		ADD_OBJECT(SoundNodeWave, ChirpInSoundNodeWave, 96)
		ADD_STRUCT(ScriptString*, ChirpInSoundNodeWaveName, 84)
		ADD_STRUCT(float, MinCompressedDurationGame, 80)
		ADD_STRUCT(float, MinCompressedDurationEditor, 76)
		ADD_STRUCT(float, LowPassFilterResonance, 72)
		ADD_STRUCT(int, CommonAudioPoolSize, 68)
		ADD_STRUCT(int, MaxChannels, 64)
		bool SetSoundMode(ScriptName NewMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9511);
			byte params[12] = { NULL };
			*(ScriptName*)params = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		class SoundClass* FindSoundClass(ScriptName SoundClassName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10363);
			byte params[12] = { NULL };
			*(ScriptName*)params = SoundClassName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundClass**)&params[8];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
