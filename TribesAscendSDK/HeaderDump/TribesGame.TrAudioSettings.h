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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57196);
			byte params[5] = { NULL };
			*(TrObject::ESettingsList*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void FlushSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68950);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StoreSetting(int SettingId, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68951);
			byte params[8] = { NULL };
			*(int*)params = SettingId;
			*(int*)&params[4] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int ReadSetting(int SettingId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68954);
			byte params[8] = { NULL };
			*(int*)params = SettingId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReadSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68957);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitializeAudioVolumes()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68960);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LoadAudioSettings(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68961);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyAudioSetting(int Type, int val, bool bStore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68964);
			byte params[12] = { NULL };
			*(int*)params = Type;
			*(int*)&params[4] = val;
			*(bool*)&params[8] = bStore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddSettingToList(ScriptString* SettingName, int val)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68969);
			byte params[16] = { NULL };
			*(ScriptString**)params = SettingName;
			*(int*)&params[12] = val;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMasterVolume(float NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68973);
			byte params[4] = { NULL };
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetEffectsVolume(float NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68976);
			byte params[4] = { NULL };
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetMusicVolume(float NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68979);
			byte params[4] = { NULL };
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVGSVolume(float NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68982);
			byte params[4] = { NULL };
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVoiceVolume(float NewVolume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68985);
			byte params[4] = { NULL };
			*(float*)params = NewVolume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool GetBassBoost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68988);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetBassBoost(bool NewBassBoost)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68993);
			byte params[4] = { NULL };
			*(bool*)params = NewBassBoost;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSettingNameFromType(TrObject::ESettingsList Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(68996);
			byte params[13] = { NULL };
			*(TrObject::ESettingsList*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
