#pragma once
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrAudioSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrAudioSettings." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrAudioSettings : public GFxObject
	{
	public:
		ADD_VAR(::IntProperty, m_nVolumeMaster, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeMusic, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeVoice, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeVGS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nVolumeEffects, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, m_SettingsList)
		ADD_VAR(::IntProperty, m_SettingsCount, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'GetCurrentSettingValue'
		// Here lies the not-yet-implemented method 'FlushSettings'
		// Here lies the not-yet-implemented method 'StoreSetting'
		// Here lies the not-yet-implemented method 'ReadSetting'
		// Here lies the not-yet-implemented method 'ReadSettings'
		// Here lies the not-yet-implemented method 'InitializeAudioVolumes'
		// Here lies the not-yet-implemented method 'LoadAudioSettings'
		// Here lies the not-yet-implemented method 'ApplyAudioSetting'
		// Here lies the not-yet-implemented method 'AddSettingToList'
		// Here lies the not-yet-implemented method 'SetMasterVolume'
		// Here lies the not-yet-implemented method 'SetEffectsVolume'
		// Here lies the not-yet-implemented method 'SetMusicVolume'
		// Here lies the not-yet-implemented method 'SetVGSVolume'
		// Here lies the not-yet-implemented method 'SetVoiceVolume'
		// Here lies the not-yet-implemented method 'GetBassBoost'
		// Here lies the not-yet-implemented method 'SetBassBoost'
		// Here lies the not-yet-implemented method 'GetSettingNameFromType'
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
