#pragma once
#include "Engine.Actor.h"
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
namespace UnrealScript
{
	class TrHelpTextManager : public Actor
	{
	public:
		enum EHelpTextType : byte
		{
			HelpText_SkiingHowTo = 0,
			HelpText_GeneratorDescriptionLevel1 = 1,
			HelpText_GeneratorDescriptionLevel2 = 2,
			HelpText_GeneratorDescriptionLevel3 = 3,
			HelpText_GeneratorDescriptionLevel4 = 4,
			HelpText_JetpackHowTo = 5,
			HelpText_OutOfAmmoNotifier = 6,
			HelpText_OffhandReminder = 7,
			HelpText_CTFFlagDescription = 8,
			HelpText_HoldingEnemyFlagDescription = 9,
			HelpText_RabbitFlagDescription = 10,
			HelpText_HoldingRabbitFlagDescription = 11,
			HelpText_InventoryStationDescription = 12,
			HelpText_VehicleStationDescription = 13,
			HelpText_BaseTurretDescriptionLevel1 = 14,
			HelpText_BaseTurretDescriptionLevel2 = 15,
			HelpText_BaseTurretDescriptionLevel3 = 16,
			HelpText_BaseTurretDescriptionLevel4 = 17,
			HelpText_RadarSensorDescriptionLevel1 = 18,
			HelpText_RadarSensorDescriptionLevel2 = 19,
			HelpText_RadarSensorDescriptionLevel3 = 20,
			HelpText_RadarSensorDescriptionLevel4 = 21,
			HelpText_RepairStationDescription = 22,
			HelpText_ArmoredTargetDescription = 23,
			HelpText_CreditsDescription = 24,
			HelpText_YouCanPickupPassengerReminder = 25,
			HelpText_ConduitDescription = 26,
			HelpText_SpotTargetReminder = 27,
			HelpText_ChangingClassDescription = 28,
			HelpText_ChangingClassHowTo = 29,
			HelpText_MAX = 30,
		};
		class HelpTextInfo
		{
		public:
			ADD_BOOL(bSelfSuppress, 8, 0x1)
			ADD_STRUCT(int, Priority, 4)
			ADD_STRUCT(TrHelpTextManager::EHelpTextType, HelpTextType, 0)
		};
		class HelpTextTypeRemovalTimerInfo
		{
		public:
			ADD_BOOL(bSuppress, 8, 0x1)
			ADD_STRUCT(float, RemainingTime, 4)
			ADD_STRUCT(TrHelpTextManager::EHelpTextType, HelpTextTypeToRemove, 0)
		};
		ADD_BOOL(m_bShowHelpTexts, 476, 0x1)
		ADD_BOOL(m_bSuppressOffhandReminder, 476, 0x100)
		ADD_BOOL(m_bSuppressSpotTargetReminder, 476, 0x10000000)
		ADD_BOOL(m_bSuppressGeneratorDescriptionLevel1, 476, 0x4)
		ADD_BOOL(m_bSuppressGeneratorDescriptionLevel2, 476, 0x8)
		ADD_BOOL(m_bSuppressGeneratorDescriptionLevel3, 476, 0x10)
		ADD_BOOL(m_bSuppressGeneratorDescriptionLevel4, 476, 0x20)
		ADD_BOOL(m_bSuppressCTFFlagDescription, 476, 0x200)
		ADD_BOOL(m_bSuppressRabbitFlagDescription, 476, 0x800)
		ADD_BOOL(m_bSuppressInventoryStationDescription, 476, 0x2000)
		ADD_BOOL(m_bSuppressVehicleStationDescription, 476, 0x4000)
		ADD_BOOL(m_bSuppressBaseTurretDescriptionLevel1, 476, 0x8000)
		ADD_BOOL(m_bSuppressBaseTurretDescriptionLevel2, 476, 0x10000)
		ADD_BOOL(m_bSuppressBaseTurretDescriptionLevel3, 476, 0x20000)
		ADD_BOOL(m_bSuppressBaseTurretDescriptionLevel4, 476, 0x40000)
		ADD_BOOL(m_bSuppressRadarSensorDescriptionLevel1, 476, 0x80000)
		ADD_BOOL(m_bSuppressRadarSensorDescriptionLevel2, 476, 0x100000)
		ADD_BOOL(m_bSuppressRadarSensorDescriptionLevel3, 476, 0x200000)
		ADD_BOOL(m_bSuppressRadarSensorDescriptionLevel4, 476, 0x400000)
		ADD_BOOL(m_bSuppressRepairStationDescription, 476, 0x800000)
		ADD_BOOL(m_bSuppressSkiingHowTo, 476, 0x2)
		ADD_BOOL(m_bSuppressJetpackHowTo, 476, 0x40)
		ADD_BOOL(m_bSuppressOutOfAmmoNotifier, 476, 0x80)
		ADD_BOOL(m_bSuppressHoldingEnemyFlagDescription, 476, 0x400)
		ADD_BOOL(m_bSuppressHoldingRabbitFlagDescription, 476, 0x1000)
		ADD_BOOL(m_bSuppressArmoredTargetDescription, 476, 0x1000000)
		ADD_BOOL(m_bSuppressCreditsDescription, 476, 0x2000000)
		ADD_BOOL(m_bSuppressYouCanPickupPassengerReminder, 476, 0x4000000)
		ADD_BOOL(m_bSuppressConduitDescription, 476, 0x8000000)
		ADD_BOOL(m_bSuppressChangingClassDescription, 476, 0x20000000)
		ADD_BOOL(m_bSuppressChangingClassHowTo, 476, 0x40000000)
		ADD_STRUCT(ScriptArray<TrHelpTextManager::EHelpTextType>, m_HelpTextQueue, 1240)
		ADD_STRUCT(ScriptArray<TrHelpTextManager::HelpTextTypeRemovalTimerInfo>, m_HelpTextTypesToRemoveOnTimers, 1252)
		ADD_STRUCT(ScriptArray<TrHelpTextManager::HelpTextInfo>, m_HelpTextConfig, 1228)
		ADD_STRUCT(ScriptString*, m_HelpTextSkiingHowTo, 480)
		ADD_STRUCT(ScriptString*, m_HelpTextSkiingHowToMenuTitle, 840)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionLevel1, 492)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionMenuTitleLevel1, 852)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionLevel2, 504)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionMenuTitleLevel2, 864)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionLevel3, 516)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionMenuTitleLevel3, 876)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionLevel4, 528)
		ADD_STRUCT(ScriptString*, m_HelpTextGeneratorDescriptionMenuTitleLevel4, 888)
		ADD_STRUCT(ScriptString*, m_HelpTextJetpackHowTo, 540)
		ADD_STRUCT(ScriptString*, m_HelpTextJetpackHowToMenuTitle, 900)
		ADD_STRUCT(ScriptString*, m_HelpTextOutOfAmmoNotifier, 552)
		ADD_STRUCT(ScriptString*, m_HelpTextOutOfAmmoNotifierMenuTitle, 912)
		ADD_STRUCT(ScriptString*, m_HelpTextOffhandReminder, 564)
		ADD_STRUCT(ScriptString*, m_HelpTextOffhandReminderMenuTitle, 924)
		ADD_STRUCT(ScriptString*, m_HelpTextCTFFlagDescription, 576)
		ADD_STRUCT(ScriptString*, m_HelpTextCTFFlagDescriptionMenuTitle, 936)
		ADD_STRUCT(ScriptString*, m_HelpTextHoldingEnemyFlagDescription, 588)
		ADD_STRUCT(ScriptString*, m_HelpTextHoldingEnemyFlagDescriptionMenuTitle, 948)
		ADD_STRUCT(ScriptString*, m_HelpTextRabbitFlagDescription, 600)
		ADD_STRUCT(ScriptString*, m_HelpTextRabbitFlagDescriptionMenuTitle, 960)
		ADD_STRUCT(ScriptString*, m_HelpTextHoldingRabbitFlagDescription, 612)
		ADD_STRUCT(ScriptString*, m_HelpTextHoldingRabbitFlagDescriptionMenuTitle, 972)
		ADD_STRUCT(ScriptString*, m_HelpTextInventoryStationDescription, 624)
		ADD_STRUCT(ScriptString*, m_HelpTextInventoryStationDescriptionMenuTitle, 984)
		ADD_STRUCT(ScriptString*, m_HelpTextVehicleStationDescription, 636)
		ADD_STRUCT(ScriptString*, m_HelpTextVehicleStationDescriptionMenuTitle, 996)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionLevel1, 648)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionMenuTitleLevel1, 1008)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionLevel2, 660)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionMenuTitleLevel2, 1020)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionLevel3, 672)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionMenuTitleLevel3, 1032)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionLevel4, 684)
		ADD_STRUCT(ScriptString*, m_HelpTextBaseTurretDescriptionMenuTitleLevel4, 1044)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionLevel1, 696)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionMenuTitleLevel1, 1056)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionLevel2, 708)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionMenuTitleLevel2, 1068)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionLevel3, 720)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionMenuTitleLevel3, 1080)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionLevel4, 732)
		ADD_STRUCT(ScriptString*, m_HelpTextRadarSensorDescriptionMenuTitleLevel4, 1092)
		ADD_STRUCT(ScriptString*, m_HelpTextRepairStationDescription, 744)
		ADD_STRUCT(ScriptString*, m_HelpTextRepairStationDescriptionMenuTitle, 1104)
		ADD_STRUCT(ScriptString*, m_HelpTextArmoredTargetDescription, 756)
		ADD_STRUCT(ScriptString*, m_HelpTextArmoredTargetDescriptionMenuTitle, 1116)
		ADD_STRUCT(ScriptString*, m_HelpTextCreditsDescription, 768)
		ADD_STRUCT(ScriptString*, m_HelpTextCreditsDescriptionMenuTitle, 1128)
		ADD_STRUCT(ScriptString*, m_HelpTextYouCanPickupPassengerReminder, 780)
		ADD_STRUCT(ScriptString*, m_HelpTextYouCanPickupPassengerReminderMenuTitle, 1140)
		ADD_STRUCT(ScriptString*, m_HelpTextConduitDescription, 792)
		ADD_STRUCT(ScriptString*, m_HelpTextConduitDescriptionMenuTitle, 1152)
		ADD_STRUCT(ScriptString*, m_HelpTextSpotTargetReminder, 804)
		ADD_STRUCT(ScriptString*, m_HelpTextSpotTargetReminderMenuTitle, 1164)
		ADD_STRUCT(ScriptString*, m_HelpTextChangingClassDescription, 816)
		ADD_STRUCT(ScriptString*, m_HelpTextChangingClassDescriptionMenuTitle, 1176)
		ADD_STRUCT(ScriptString*, m_HelpTextChangingClassHowTo, 828)
		ADD_STRUCT(ScriptString*, m_HelpTextChangingClassHowToMenuTitle, 1188)
		ADD_STRUCT(ScriptString*, m_LocalizedSuppressString, 1200)
		ADD_STRUCT(float, m_OffhandReminderRecursiveTime, 1216)
		ADD_STRUCT(float, m_SpotTargetReminderRecursiveTime, 1224)
		ADD_STRUCT(float, m_OffhandReminderInitialTime, 1212)
		ADD_STRUCT(float, m_SpotTargetReminderInitialTime, 1220)
		bool RequestHelpText(TrHelpTextManager::EHelpTextType RequestedType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.RequestHelpText");
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitHelpTextManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.InitHelpTextManager");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LevelLoadCompleted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.LevelLoadCompleted");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Tick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.Tick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckDestroy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.CheckDestroy");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsSuppressed(TrHelpTextManager::EHelpTextType RequestedType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.IsSuppressed");
			byte params[5] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void RemoveHelpText(TrHelpTextManager::EHelpTextType TypeToRemove, float Time, bool bDoNotSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.RemoveHelpText");
			byte params[9] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = TypeToRemove;
			*(float*)&params[4] = Time;
			*(bool*)&params[8] = bDoNotSuppress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SuppressHelpText(TrHelpTextManager::EHelpTextType TypeToSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.SuppressHelpText");
			byte params[1] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = TypeToSuppress;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.UpdateHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* FormatText(ScriptString* InString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.FormatText");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = InString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		int HelpTextQueueSort(TrHelpTextManager::EHelpTextType A, TrHelpTextManager::EHelpTextType B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.HelpTextQueueSort");
			byte params[6] = { NULL };
			*(TrHelpTextManager::EHelpTextType*)&params[0] = A;
			*(TrHelpTextManager::EHelpTextType*)&params[1] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool UnsuppressedHelpTextsExist()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.UnsuppressedHelpTextsExist");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OffhandReminderTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.OffhandReminderTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearOffhandReminderTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.ClearOffhandReminderTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpotTargetReminderTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.SpotTargetReminderTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClearSpotTargetReminderTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.ClearSpotTargetReminderTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateTypesToRemoveOnTimers(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.UpdateTypesToRemoveOnTimers");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetConfig()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.ResetConfig");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableHelpText(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.EnableHelpText");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
