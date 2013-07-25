#pragma once
#include "Core__Subsystem.h"
#include "Engine__SoundNodeWave.h"
#include "Engine__SoundMode.h"
#include "Engine__SoundClass.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.AudioDevice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.AudioDevice." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.AudioDevice." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class AudioDevice : public Subsystem
	{
	public:
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TransientMasterVolume, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, DebugState, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'TextToSpeech'!
		ADD_VAR(::FloatProperty, ExteriorLPFInterp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExteriorVolumeInterp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteriorLPFInterp, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, InteriorVolumeInterp, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'ExteriorLPFEndTime'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'InteriorLPFEndTime'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'ExteriorEndTime'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'InteriorEndTime'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'InteriorStartTime'!
		// WARNING: Unknown structure type 'ScriptStruct Engine.ReverbVolume.InteriorSettings' for the property named 'ListenerInteriorSettings'!
		ADD_VAR(::IntProperty, ListenerVolumeIndex, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'SoundModeEndTime'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'SoundModeFadeInEndTime'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'SoundModeFadeInStartTime'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Double' for the property named 'SoundModeStartTime'!
		ADD_OBJECT(SoundMode, CurrentMode)
		ADD_VAR(::NameProperty, BaseSoundModeName, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'Effects'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.QWord' for the property named 'CurrentTick'!
		ADD_VAR(::IntProperty, CommonAudioPoolFreeBytes, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer' for the property named 'CommonAudioPool'!
		ADD_VAR(::BoolProperty, bGameWasTicking, 0x2)
		ADD_VAR(::BoolProperty, m_bEnableBassBoost, 0x1)
		ADD_OBJECT(SoundNodeWave, ChirpOutSoundNodeWave)
		ADD_VAR(::StrProperty, ChirpOutSoundNodeWaveName, 0xFFFFFFFF)
		ADD_OBJECT(SoundNodeWave, ChirpInSoundNodeWave)
		ADD_VAR(::StrProperty, ChirpInSoundNodeWaveName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinCompressedDurationGame, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MinCompressedDurationEditor, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LowPassFilterResonance, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CommonAudioPoolSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxChannels, 0xFFFFFFFF)
		bool SetSoundMode(ScriptName NewMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioDevice.SetSoundMode");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		class SoundClass* FindSoundClass(ScriptName SoundClassName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.AudioDevice.FindSoundClass");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SoundClassName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundClass**)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
