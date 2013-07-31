#pragma once
#include "Engine.OnlinePlayerStorage.h"
#include "Engine.Settings.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class OnlineProfileSettings : public OnlinePlayerStorage
	{
	public:
		enum EProfileSettingID : byte
		{
			PSI_Unknown = 0,
			PSI_ControllerVibration = 1,
			PSI_YInversion = 2,
			PSI_GamerCred = 3,
			PSI_GamerRep = 4,
			PSI_VoiceMuted = 5,
			PSI_VoiceThruSpeakers = 6,
			PSI_VoiceVolume = 7,
			PSI_GamerPictureKey = 8,
			PSI_GamerMotto = 9,
			PSI_GamerTitlesPlayed = 10,
			PSI_GamerAchievementsEarned = 11,
			PSI_GameDifficulty = 12,
			PSI_ControllerSensitivity = 13,
			PSI_PreferredColor1 = 14,
			PSI_PreferredColor2 = 15,
			PSI_AutoAim = 16,
			PSI_AutoCenter = 17,
			PSI_MovementControl = 18,
			PSI_RaceTransmission = 19,
			PSI_RaceCameraLocation = 20,
			PSI_RaceBrakeControl = 21,
			PSI_RaceAcceleratorControl = 22,
			PSI_GameCredEarned = 23,
			PSI_GameAchievementsEarned = 24,
			PSI_EndLiveIds = 25,
			PSI_ProfileVersionNum = 26,
			PSI_ProfileSaveCount = 27,
			PSI_MAX = 28,
		};
		enum EProfileDifficultyOptions : byte
		{
			PDO_Normal = 0,
			PDO_Easy = 1,
			PDO_Hard = 2,
			PDO_MAX = 3,
		};
		enum EProfileControllerSensitivityOptions : byte
		{
			PCSO_Medium = 0,
			PCSO_Low = 1,
			PCSO_High = 2,
			PCSO_MAX = 3,
		};
		enum EProfilePreferredColorOptions : byte
		{
			PPCO_None = 0,
			PPCO_Black = 1,
			PPCO_White = 2,
			PPCO_Yellow = 3,
			PPCO_Orange = 4,
			PPCO_Pink = 5,
			PPCO_Red = 6,
			PPCO_Purple = 7,
			PPCO_Blue = 8,
			PPCO_Green = 9,
			PPCO_Brown = 10,
			PPCO_Silver = 11,
			PPCO_MAX = 12,
		};
		enum EProfileAutoAimOptions : byte
		{
			PAAO_Off = 0,
			PAAO_On = 1,
			PAAO_MAX = 2,
		};
		enum EProfileAutoCenterOptions : byte
		{
			PACO_Off = 0,
			PACO_On = 1,
			PACO_MAX = 2,
		};
		enum EProfileMovementControlOptions : byte
		{
			PMCO_L_Thumbstick = 0,
			PMCO_R_Thumbstick = 1,
			PMCO_MAX = 2,
		};
		enum EProfileRaceTransmissionOptions : byte
		{
			PRTO_Auto = 0,
			PRTO_Manual = 1,
			PRTO_MAX = 2,
		};
		enum EProfileRaceCameraLocationOptions : byte
		{
			PRCLO_Behind = 0,
			PRCLO_Front = 1,
			PRCLO_Inside = 2,
			PRCLO_MAX = 3,
		};
		enum EProfileRaceBrakeControlOptions : byte
		{
			PRBCO_Trigger = 0,
			PRBCO_Button = 1,
			PRBCO_MAX = 2,
		};
		enum EProfileRaceAcceleratorControlOptions : byte
		{
			PRACO_Trigger = 0,
			PRACO_Button = 1,
			PRACO_MAX = 2,
		};
		enum EProfileYInversionOptions : byte
		{
			PYIO_Off = 0,
			PYIO_On = 1,
			PYIO_MAX = 2,
		};
		enum EProfileXInversionOptions : byte
		{
			PXIO_Off = 0,
			PXIO_On = 1,
			PXIO_MAX = 2,
		};
		enum EProfileOmniDirEvadeOptions : byte
		{
			PODI_Off = 0,
			PODI_On = 1,
			PODI_MAX = 2,
		};
		enum EProfileControllerVibrationToggleOptions : byte
		{
			PCVTO_Off = 0,
			PCVTO_IgnoreThis = 1,
			PCVTO_IgnoreThis2 = 2,
			PCVTO_On = 3,
			PCVTO_MAX = 4,
		};
		enum EProfileVoiceThruSpeakersOptions : byte
		{
			PVTSO_Off = 0,
			PVTSO_On = 1,
			PVTSO_Both = 2,
			PVTSO_MAX = 3,
		};
		ADD_STRUCT(ScriptArray<int>, ProfileSettingIds, 100)
		ADD_STRUCT(ScriptArray<OnlinePlayerStorage::OnlineProfileSetting>, DefaultSettings, 112)
		ADD_STRUCT(ScriptArray<Settings::IdToStringMapping>, OwnerMappings, 124)
		bool GetProfileSettingDefaultId(int ProfileSettingId, int& DefaultId, int& ListIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22645);
			byte params[16] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = DefaultId;
			*(int*)&params[8] = ListIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DefaultId = *(int*)&params[4];
			ListIndex = *(int*)&params[8];
			return *(bool*)&params[12];
		}
		bool GetProfileSettingDefaultInt(int ProfileSettingId, int& DefaultInt)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22650);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(int*)&params[4] = DefaultInt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DefaultInt = *(int*)&params[4];
			return *(bool*)&params[8];
		}
		bool GetProfileSettingDefaultFloat(int ProfileSettingId, float& DefaultFloat)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22654);
			byte params[12] = { NULL };
			*(int*)params = ProfileSettingId;
			*(float*)&params[4] = DefaultFloat;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			DefaultFloat = *(float*)&params[4];
			return *(bool*)&params[8];
		}
		void SetToDefaults()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22658);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AppendVersionToReadIds()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22659);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ModifyAvailableProfileSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22660);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
