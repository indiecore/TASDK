#pragma once
#include "GFxUI.GFxObject.h"
#include "TribesGame.TrObject.h"
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
	class TrAudioSettings : public GFxObject
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, MasterSoundClassNames, 148)
		ADD_STRUCT(ScriptArray<ScriptString*>, EffectsSoundClassNames, 160)
		ADD_STRUCT(ScriptArray<ScriptString*>, MusicSoundClassNames, 172)
		ADD_STRUCT(ScriptArray<ScriptString*>, VGSSoundClassNames, 184)
		ADD_STRUCT(ScriptArray<ScriptString*>, VoiceSoundClassNames, 196)
		ADD_STRUCT(int, m_nVolumeMaster, 144)
		ADD_STRUCT(int, m_nVolumeMusic, 140)
		ADD_STRUCT(int, m_nVolumeVoice, 136)
		ADD_STRUCT(int, m_nVolumeVGS, 132)
		ADD_STRUCT(int, m_nVolumeEffects, 128)
		ADD_OBJECT(GFxObject, m_SettingsList, 124)
		ADD_STRUCT(int, m_SettingsCount, 120)
		int GetCurrentSettingValue(TrObject::ESettingsList Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.GetCurrentSettingValue");
			byte params[5] = { NULL };
			*(TrObject::ESettingsList*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void FlushSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.FlushSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoreSetting(int SettingId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.StoreSetting");
			byte params[8] = { NULL };
			*(int*)&params[0] = SettingId;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int ReadSetting(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.ReadSetting");
			byte params[8] = { NULL };
			*(int*)&params[0] = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReadSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.ReadSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeAudioVolumes()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.InitializeAudioVolumes");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadAudioSettings(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.LoadAudioSettings");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyAudioSetting(int Type, int val, bool bStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.ApplyAudioSetting");
			byte params[12] = { NULL };
			*(int*)&params[0] = Type;
			*(int*)&params[4] = val;
			*(bool*)&params[8] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSettingToList(ScriptString* SettingName, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.AddSettingToList");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = SettingName;
			*(int*)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMasterVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetMasterVolume");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEffectsVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetEffectsVolume");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMusicVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetMusicVolume");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVGSVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetVGSVolume");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVoiceVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetVoiceVolume");
			byte params[4] = { NULL };
			*(float*)&params[0] = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetBassBoost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.GetBassBoost");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetBassBoost(bool NewBassBoost)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetBassBoost");
			byte params[4] = { NULL };
			*(bool*)&params[0] = NewBassBoost;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSettingNameFromType(TrObject::ESettingsList Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.GetSettingNameFromType");
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)&params[0] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
