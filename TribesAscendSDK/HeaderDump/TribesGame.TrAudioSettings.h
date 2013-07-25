#pragma once
#include "GFxUI.GFxObject.h"
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
		int GetCurrentSettingValue(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.GetCurrentSettingValue");
			byte* params = (byte*)malloc(5);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void FlushSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.FlushSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoreSetting(int SettingId, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.StoreSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = SettingId;
			*(int*)(params + 4) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int ReadSetting(int SettingId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.ReadSetting");
			byte* params = (byte*)malloc(8);
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyAudioSetting(int Type, int val, bool bStore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.ApplyAudioSetting");
			byte* params = (byte*)malloc(12);
			*(int*)params = Type;
			*(int*)(params + 4) = val;
			*(bool*)(params + 8) = bStore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddSettingToList(ScriptArray<wchar_t> SettingName, int val)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.AddSettingToList");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = SettingName;
			*(int*)(params + 12) = val;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMasterVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetMasterVolume");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetEffectsVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetEffectsVolume");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetMusicVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetMusicVolume");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVGSVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetVGSVolume");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetVoiceVolume(float NewVolume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetVoiceVolume");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool GetBassBoost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.GetBassBoost");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetBassBoost(bool NewBassBoost)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.SetBassBoost");
			byte* params = (byte*)malloc(4);
			*(bool*)params = NewBassBoost;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetSettingNameFromType(byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrAudioSettings.GetSettingNameFromType");
			byte* params = (byte*)malloc(13);
			*params = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
