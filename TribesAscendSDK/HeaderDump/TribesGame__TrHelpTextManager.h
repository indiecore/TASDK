#pragma once
#include "Engine__Actor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHelpTextManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrHelpTextManager : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, m_bShowHelpTexts, 0x1)
		ADD_VAR(::BoolProperty, m_bSuppressOffhandReminder, 0x100)
		ADD_VAR(::BoolProperty, m_bSuppressSpotTargetReminder, 0x10000000)
		ADD_VAR(::BoolProperty, m_bSuppressGeneratorDescriptionLevel1, 0x4)
		ADD_VAR(::BoolProperty, m_bSuppressGeneratorDescriptionLevel2, 0x8)
		ADD_VAR(::BoolProperty, m_bSuppressGeneratorDescriptionLevel3, 0x10)
		ADD_VAR(::BoolProperty, m_bSuppressGeneratorDescriptionLevel4, 0x20)
		ADD_VAR(::BoolProperty, m_bSuppressCTFFlagDescription, 0x200)
		ADD_VAR(::BoolProperty, m_bSuppressRabbitFlagDescription, 0x800)
		ADD_VAR(::BoolProperty, m_bSuppressInventoryStationDescription, 0x2000)
		ADD_VAR(::BoolProperty, m_bSuppressVehicleStationDescription, 0x4000)
		ADD_VAR(::BoolProperty, m_bSuppressBaseTurretDescriptionLevel1, 0x8000)
		ADD_VAR(::BoolProperty, m_bSuppressBaseTurretDescriptionLevel2, 0x10000)
		ADD_VAR(::BoolProperty, m_bSuppressBaseTurretDescriptionLevel3, 0x20000)
		ADD_VAR(::BoolProperty, m_bSuppressBaseTurretDescriptionLevel4, 0x40000)
		ADD_VAR(::BoolProperty, m_bSuppressRadarSensorDescriptionLevel1, 0x80000)
		ADD_VAR(::BoolProperty, m_bSuppressRadarSensorDescriptionLevel2, 0x100000)
		ADD_VAR(::BoolProperty, m_bSuppressRadarSensorDescriptionLevel3, 0x200000)
		ADD_VAR(::BoolProperty, m_bSuppressRadarSensorDescriptionLevel4, 0x400000)
		ADD_VAR(::BoolProperty, m_bSuppressRepairStationDescription, 0x800000)
		ADD_VAR(::BoolProperty, m_bSuppressSkiingHowTo, 0x2)
		ADD_VAR(::BoolProperty, m_bSuppressJetpackHowTo, 0x40)
		ADD_VAR(::BoolProperty, m_bSuppressOutOfAmmoNotifier, 0x80)
		ADD_VAR(::BoolProperty, m_bSuppressHoldingEnemyFlagDescription, 0x400)
		ADD_VAR(::BoolProperty, m_bSuppressHoldingRabbitFlagDescription, 0x1000)
		ADD_VAR(::BoolProperty, m_bSuppressArmoredTargetDescription, 0x1000000)
		ADD_VAR(::BoolProperty, m_bSuppressCreditsDescription, 0x2000000)
		ADD_VAR(::BoolProperty, m_bSuppressYouCanPickupPassengerReminder, 0x4000000)
		ADD_VAR(::BoolProperty, m_bSuppressConduitDescription, 0x8000000)
		ADD_VAR(::BoolProperty, m_bSuppressChangingClassDescription, 0x20000000)
		ADD_VAR(::BoolProperty, m_bSuppressChangingClassHowTo, 0x40000000)
		ADD_VAR(::StrProperty, m_HelpTextSkiingHowTo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextSkiingHowToMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionLevel1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionMenuTitleLevel1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionLevel2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionMenuTitleLevel2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionLevel3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionMenuTitleLevel3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionLevel4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextGeneratorDescriptionMenuTitleLevel4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextJetpackHowTo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextJetpackHowToMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextOutOfAmmoNotifier, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextOutOfAmmoNotifierMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextOffhandReminder, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextOffhandReminderMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextCTFFlagDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextCTFFlagDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextHoldingEnemyFlagDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextHoldingEnemyFlagDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRabbitFlagDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRabbitFlagDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextHoldingRabbitFlagDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextHoldingRabbitFlagDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextInventoryStationDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextInventoryStationDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextVehicleStationDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextVehicleStationDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionLevel1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionMenuTitleLevel1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionLevel2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionMenuTitleLevel2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionLevel3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionMenuTitleLevel3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionLevel4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextBaseTurretDescriptionMenuTitleLevel4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionLevel1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionMenuTitleLevel1, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionLevel2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionMenuTitleLevel2, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionLevel3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionMenuTitleLevel3, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionLevel4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRadarSensorDescriptionMenuTitleLevel4, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRepairStationDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextRepairStationDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextArmoredTargetDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextArmoredTargetDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextCreditsDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextCreditsDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextYouCanPickupPassengerReminder, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextYouCanPickupPassengerReminderMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextConduitDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextConduitDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextSpotTargetReminder, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextSpotTargetReminderMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextChangingClassDescription, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextChangingClassDescriptionMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextChangingClassHowTo, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_HelpTextChangingClassHowToMenuTitle, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_LocalizedSuppressString, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_OffhandReminderRecursiveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_SpotTargetReminderRecursiveTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_OffhandReminderInitialTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_SpotTargetReminderInitialTime, 0xFFFFFFFF)
		bool RequestHelpText(byte RequestedType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.RequestHelpText");
			byte* params = (byte*)malloc(5);
			*params = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckDestroy()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.CheckDestroy");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsSuppressed(byte RequestedType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.IsSuppressed");
			byte* params = (byte*)malloc(5);
			*params = RequestedType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void RemoveHelpText(byte TypeToRemove, float Time, bool bDoNotSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.RemoveHelpText");
			byte* params = (byte*)malloc(9);
			*params = TypeToRemove;
			*(float*)(params + 4) = Time;
			*(bool*)(params + 8) = bDoNotSuppress;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SuppressHelpText(byte TypeToSuppress)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.SuppressHelpText");
			byte* params = (byte*)malloc(1);
			*params = TypeToSuppress;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.UpdateHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> FormatText(ScriptArray<wchar_t> InString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.FormatText");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = InString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		int HelpTextQueueSort(byte A, byte B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.HelpTextQueueSort");
			byte* params = (byte*)malloc(6);
			*params = A;
			*(params + 1) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool UnsuppressedHelpTextsExist()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.UnsuppressedHelpTextsExist");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetConfig()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.ResetConfig");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void EnableHelpText(bool bEnabled)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrHelpTextManager.EnableHelpText");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnabled;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
