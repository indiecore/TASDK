#pragma once
#include "TribesGame__TrPlayerController.h"
#include "Engine__MaterialInstanceConstant.h"
#include "UTGame__GFxMinimapHud.h"
#include "GFxUI__GFxObject.h"
#include "TribesGame__TrDevice.h"
#include "Engine__MaterialEffect.h"
#include "TribesGame__GFxTrReticules.h"
#include "TribesGame__GFxDeviceAmmoCount.h"
#include "Engine__TeamInfo.h"
#include "TribesGame__TrHUD.h"
#include "Engine__LocalPlayer.h"
#include "Engine__Weapon.h"
#include "TribesGame__TrVehicle.h"
#include "TribesGame__TrPlayerReplicationInfo.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GfxTrHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.GfxTrHud." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.GfxTrHud." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GfxTrHud : public GFxMinimapHud
	{
	public:
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.GfxTrHud.TrTempMessage' for the property named 'm_HeroStatusTempMessage'!
		// WARNING: Unknown structure type 'ScriptStruct TribesGame.GfxTrHud.TrTempMessage' for the property named 'm_PromptPanelTempMessage'!
		ADD_VAR(::StrProperty, m_sRound, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, VGSMenuList)
		ADD_OBJECT(GFxObject, _global)
		ADD_OBJECT(MaterialInstanceConstant, m_DirDamageMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_DirectionalDamageEffect)
		ADD_VAR(::FloatProperty, m_fDirectionalDamageFadeTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nNearDeathHealthMax, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, KillCamInfoObject)
		ADD_OBJECT(GFxObject, VGSMenuEntry)
		ADD_OBJECT(GFxObject, SpecHelp_LockViewTF)
		ADD_OBJECT(GFxObject, SpecHelp_ZoomOutTF)
		ADD_OBJECT(GFxObject, SpecHelp_ZoomInTF)
		ADD_OBJECT(GFxObject, SpecHelp_FreeCameraTF)
		ADD_OBJECT(GFxObject, SpecHelp_FastestPlayerTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeVehiclesTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeBookmarksTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeFlagstandsTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeFlagsTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangeGeneratorsTF)
		ADD_OBJECT(GFxObject, SpecHelp_ChangePlayersTF)
		ADD_OBJECT(GFxObject, SpecHelp_DecreaseSpeedTF)
		ADD_OBJECT(GFxObject, SpecHelp_IncreaseSpeedTF)
		ADD_OBJECT(GFxObject, SpecHelp_StrafeRightTF)
		ADD_OBJECT(GFxObject, SpecHelp_StrafeLeftTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveBackTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveForwardTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveDownTF)
		ADD_OBJECT(GFxObject, SpecHelp_MoveUpTF)
		ADD_OBJECT(GFxObject, SpecHelp_ObjKaratsTF)
		ADD_OBJECT(GFxObject, SpecHelp_SpecHudTF)
		ADD_OBJECT(GFxObject, SpecHelp_MainmenuTF)
		ADD_OBJECT(GFxObject, SpecHelp_ScoreboardTF)
		ADD_OBJECT(GFxObject, SpecHelp_TeamSelectTF)
		ADD_OBJECT(GFxObject, SpecHelp_HelpTF)
		ADD_OBJECT(GFxObject, SpecFloat_DescriptionTF)
		ADD_OBJECT(GFxObject, SpecFloat_FloatCameraNameTF)
		ADD_OBJECT(GFxObject, SpecObjective_HealthTF)
		ADD_OBJECT(GFxObject, SpecObjective_HealthFillBar)
		ADD_OBJECT(GFxObject, SpecObjective_DescriptionTF)
		ADD_OBJECT(GFxObject, SpecObjective_ObjectiveNameTF)
		ADD_OBJECT(GFxObject, SpecBookmark_DescriptionTF)
		ADD_OBJECT(GFxObject, SpecBookmark_BookmarkNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_SkiIndicator_fillBar_speedoTF)
		ADD_OBJECT(GFxObject, SpecVehicle_SkiIndicator_fillBar)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleGroup_secondaryReady)
		ADD_OBJECT(GFxObject, SpecVehicle_SecondaryNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleGroup_primaryReady)
		ADD_OBJECT(GFxObject, SpecVehicle_PrimaryNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_EnergyTF)
		ADD_OBJECT(GFxObject, SpecVehicle_EnergyFillBar)
		ADD_OBJECT(GFxObject, SpecVehicle_HealthTF)
		ADD_OBJECT(GFxObject, SpecVehicle_HealthFillBar)
		ADD_OBJECT(GFxObject, SpecVehicle_PassengerNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_DriverNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_VehicleNameTF)
		ADD_OBJECT(GFxObject, SpecVehicle_FlagCarried)
		ADD_OBJECT(GFxObject, SpecPlayer_SkiIndicator_fillBar_speedoTF)
		ADD_OBJECT(GFxObject, SpecPlayer_SkiIndicator_fillBar)
		ADD_OBJECT(GFxObject, SpecPlayer_Perk2TF)
		ADD_OBJECT(GFxObject, SpecPlayer_PerkItem2)
		ADD_OBJECT(GFxObject, SpecPlayer_Perk1TF)
		ADD_OBJECT(GFxObject, SpecPlayer_PerkItem1)
		ADD_OBJECT(GFxObject, SpecPlayer_PackNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PackIcons_count)
		ADD_OBJECT(GFxObject, SpecPlayer_PackIcons_icon)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandIcons_count)
		ADD_OBJECT(GFxObject, SpecPlayer_OffhandIcons_icon)
		ADD_OBJECT(GFxObject, SpecPlayer_SecondaryAmmoTF)
		ADD_OBJECT(GFxObject, SpecPlayer_SecondaryNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PrimaryAmmoTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PrimaryNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_EnergyTF)
		ADD_OBJECT(GFxObject, SpecPlayer_EnergyFillBar)
		ADD_OBJECT(GFxObject, SpecPlayer_HealthTF)
		ADD_OBJECT(GFxObject, SpecPlayer_HealthFillBar)
		ADD_OBJECT(GFxObject, SpecPlayer_RegenTF)
		ADD_OBJECT(GFxObject, SpecPlayer_ClassNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_PlayerNameTF)
		ADD_OBJECT(GFxObject, SpecPlayer_FlagCarried)
		ADD_OBJECT(GFxObject, SpecObjective)
		ADD_OBJECT(GFxObject, SpecBookmark)
		ADD_OBJECT(GFxObject, SpawnCounter)
		ADD_OBJECT(GFxObject, SpecVehicle)
		ADD_OBJECT(GFxObject, SpecPlayer)
		ADD_OBJECT(GFxObject, SpecFloat)
		ADD_OBJECT(GFxObject, SpecHelp)
		ADD_OBJECT(GFxObject, VGS)
		ADD_OBJECT(GFxObject, NotificationPopup)
		ADD_OBJECT(GFxObject, DeployStatus)
		ADD_OBJECT(GFxObject, GlobalAlertTF)
		ADD_OBJECT(GFxObject, Credits_And_Streaks_CallItem)
		ADD_OBJECT(GFxObject, PlayerStats_Offhand1_Count)
		ADD_OBJECT(GFxObject, PlayerStats_Offhand1_Icon)
		ADD_OBJECT(GFxObject, PlayerStats_PackCount)
		ADD_OBJECT(GFxObject, PlayerStats_PackMC)
		ADD_OBJECT(GFxObject, PlayerStats_Pack)
		ADD_OBJECT(GFxObject, playerStats_Offhand1)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleSlot)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleEnergyFill)
		ADD_OBJECT(GFxObject, VehicleStats_EnergyTF_TextField)
		ADD_OBJECT(GFxObject, VehicleStats_VehicleHealthFill)
		ADD_OBJECT(GFxObject, VehicleStats_HealthTF_TextField)
		ADD_OBJECT(GFxObject, VehicleStats)
		ADD_OBJECT(GFxObject, TeamStats)
		ADD_OBJECT(GFxObject, Offhands_And_Flag_FlagInHand)
		ADD_OBJECT(GFxObject, Credits_And_Streaks_CreditsGroup_CreditsMC_CreditsN)
		ADD_OBJECT(GFxObject, RabbitScoreboard)
		ADD_OBJECT(GFxObject, TeamScoreBoard)
		ADD_OBJECT(GFxObject, ArenaStats)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyScoreTF)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyScoreTF)
		ADD_OBJECT(GFxObject, ArenaStats_roundCountTF)
		ADD_OBJECT(GFxObject, ArenaStats_arenaGameTimerTF)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic08)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic07)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic06)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic05)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic04)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic03)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic02)
		ADD_OBJECT(GFxObject, ArenaStats_EnemyManGraphic01)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic08)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic07)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic06)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic05)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic04)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic03)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic02)
		ADD_OBJECT(GFxObject, ArenaStats_FriendlyManGraphic01)
		ADD_OBJECT(GFxObject, CaHControlPointE)
		ADD_OBJECT(GFxObject, CaHControlPointD)
		ADD_OBJECT(GFxObject, CaHControlPointC)
		ADD_OBJECT(GFxObject, CaHControlPointB)
		ADD_OBJECT(GFxObject, CaHControlPointA)
		ADD_OBJECT(GFxObject, CaHStats)
		ADD_OBJECT(GFxObject, DaDStats)
		ADD_OBJECT(GFxObject, TdmStats)
		ADD_OBJECT(GFxObject, TdmStats_gameTimer)
		ADD_OBJECT(GFxObject, TdmStats_rightFlagStatus)
		ADD_OBJECT(GFxObject, TdmStats_leftFlagStatus)
		ADD_OBJECT(GFxObject, CTFStats)
		ADD_OBJECT(GFxObject, CTFStats_Timer)
		ADD_OBJECT(GFxObject, CTFStats_RightScore)
		ADD_OBJECT(GFxObject, CTFStats_LeftScore)
		ADD_OBJECT(GFxObject, CTFStats_RightFlagTimer)
		ADD_OBJECT(GFxObject, CTFStats_LeftFlagTimer)
		ADD_OBJECT(GFxObject, CTFStats_RightFlagStatus)
		ADD_OBJECT(GFxObject, CTFStats_LeftFlagStatus)
		ADD_OBJECT(GFxObject, CTFStats_RightGenTimer)
		ADD_OBJECT(GFxObject, CTFStats_LeftGenTimer)
		ADD_OBJECT(GFxObject, CTFStats_RightGenStatus)
		ADD_OBJECT(GFxObject, CTFStats_LeftGenStatus)
		ADD_OBJECT(GFxObject, RabbitStats_Timer)
		ADD_OBJECT(GFxObject, RabbitStats_LeaderScore)
		ADD_OBJECT(GFxObject, RabbitStats_LeaderText)
		ADD_OBJECT(GFxObject, RabbitStats)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PlayerHighlight)
		ADD_OBJECT(GFxObject, RabbitScoreboard_RankIcon)
		ADD_OBJECT(GFxObject, RabbitScoreboard_RankTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_ClassTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PingTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_AssistsTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_KillsTF)
		ADD_OBJECT(GFxObject, RabbitScoreboard_ScoreT)
		ADD_OBJECT(GFxObject, RabbitScoreboard_PlayerTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_RankTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_RankIcon)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_ClassTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_PingTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_AssistsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_KillsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_ScoreTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Blue_PlayerNameTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_RankTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_RankIcon)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_ClassTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_PingTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_AssistsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_KillsTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_ScoreTF)
		ADD_OBJECT(GFxObject, TeamScoreboard_Red_PlayerNameTF)
		ADD_OBJECT(GFxObject, PlayerStats_EnergyFillBar)
		ADD_OBJECT(GFxObject, PlayerStats_GhostHealthBar)
		ADD_OBJECT(GFxObject, PlayerStats_HealthFillBar)
		ADD_OBJECT(GFxObject, SpawnCounter_TimeLabel)
		ADD_OBJECT(GFxObject, SpawnCounter_StatusMessage)
		ADD_OBJECT(GFxObject, CreditsAndStreaks_Streak)
		ADD_OBJECT(GFxObject, CreditsAndStreaks)
		ADD_OBJECT(GFxObject, SkiIndicatorFillBar)
		ADD_OBJECT(GFxObject, SkiIndicatorTF)
		ADD_OBJECT(GFxObject, SkiIndicator)
		ADD_OBJECT(GFxObject, CombatLog)
		ADD_OBJECT(GFxObject, KillMessageArea)
		ADD_OBJECT(GFxObject, KillCamInfo)
		ADD_OBJECT(GFxObject, PromptPanel)
		ADD_OBJECT(GFxObject, HeroStatus_outputTF)
		ADD_OBJECT(GFxObject, PlayerStats)
		ADD_OBJECT(GFxObject, Visor)
		ADD_OBJECT(GFxDeviceAmmoCount, deviceAmmoPoolMP)
		ADD_OBJECT(GFxDeviceAmmoCount, deviceAmmoCountMP)
		ADD_OBJECT(GFxTrReticules, Reticules)
		ADD_OBJECT(GFxObject, sniperPowerUp)
		ADD_OBJECT(TrDevice, m_LastOffhand)
		ADD_OBJECT(TeamInfo, m_LastTeam)
		ADD_VAR(::IntProperty, m_nLastVehicleAmmoPool, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastVehicleEnergy, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastVehicleHealth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastSeatMask, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSpeedometerUpdateInterval, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_SkiSpeedSteps, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_VGSMenuListCount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastSpeedometerUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentGhostHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastActualHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastMaxHealth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fLastRotation, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVGSLoadouts, 0x200)
		ADD_VAR(::BoolProperty, m_bNearDeathOn, 0x100)
		ADD_VAR(::BoolProperty, bShowingBadge, 0x80)
		ADD_VAR(::BoolProperty, m_bLastIn3P, 0x40)
		ADD_VAR(::BoolProperty, m_bShowingAmmoClip, 0x20)
		ADD_VAR(::BoolProperty, m_bLastInVehicle, 0x10)
		ADD_VAR(::BoolProperty, m_bGameOver, 0x8)
		ADD_VAR(::BoolProperty, m_bShowPlayerStats, 0x4)
		ADD_VAR(::BoolProperty, m_bLastHasFlag, 0x2)
		ADD_VAR(::BoolProperty, m_bLastSkiing, 0x1)
		ADD_VAR(::FloatProperty, m_fCrosshairDepth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastFriendlyGeneratorTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastEnemyGeneratorTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastOffhandCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPercentReload, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPercentLaser, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastSkiSpeedStep, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nStreakEvent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nCrossHairMode, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastAmmoPool, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastCredits, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPercent, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageHeight, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageWidth, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageOriginY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_HUDStageOriginX, 0xFFFFFFFF)
		ADD_OBJECT(TrPlayerController, m_TrPC)
		ADD_OBJECT(TrHUD, m_TrHUD)
		// Here lies the not-yet-implemented method 'DelegateSoundAccolade'
		// Here lies the not-yet-implemented method 'DelegateLoadVGSMenu'
		// Here lies the not-yet-implemented method 'Start'
		// Here lies the not-yet-implemented method 'registerReticules'
		// Here lies the not-yet-implemented method 'Init'
		// Here lies the not-yet-implemented method 'SetLoadVGSMenuDelegate'
		// Here lies the not-yet-implemented method 'SetSoundAccoladeDelegate'
		// Here lies the not-yet-implemented method 'RabbitLeaderboardUpdateSlot'
		// Here lies the not-yet-implemented method 'RabbitLeaderboardUpdateTime'
		// Here lies the not-yet-implemented method 'SetFontIndex'
		// Here lies the not-yet-implemented method 'ClearPromptPanel'
		// Here lies the not-yet-implemented method 'RemoveFromPromptPanel'
		// Here lies the not-yet-implemented method 'ClearPromptPanelMessage'
		// Here lies the not-yet-implemented method 'LoadVGSMenu'
		// Here lies the not-yet-implemented method 'AddVGSEntry'
		// Here lies the not-yet-implemented method 'AddToPromptPanelTime'
		// Here lies the not-yet-implemented method 'AddtoPromptPanelAS'
		// Here lies the not-yet-implemented method 'UpdateHeroStatus'
		// Here lies the not-yet-implemented method 'ClearHeroStatus'
		// Here lies the not-yet-implemented method 'SetSpeedometer'
		// Here lies the not-yet-implemented method 'SetPlayerRankIcon'
		// Here lies the not-yet-implemented method 'SetPlayerTeamIcon'
		// Here lies the not-yet-implemented method 'SetPlayerClassObjects'
		// Here lies the not-yet-implemented method 'ShouldShowSpectatorReticule'
		// Here lies the not-yet-implemented method 'SystemEnableNotifies'
		// Here lies the not-yet-implemented method 'ConfigureSpectatorHUD'
		// Here lies the not-yet-implemented method 'ConfigureHUDState'
		// Here lies the not-yet-implemented method 'ShowChatLog'
		// Here lies the not-yet-implemented method 'HideChatLog'
		// Here lies the not-yet-implemented method 'ShowCenterHUDElements'
		// Here lies the not-yet-implemented method 'UpdateCreditsAndStreaks'
		// Here lies the not-yet-implemented method 'SetScoreboardTitle'
		// Here lies the not-yet-implemented method 'UpdateRespawnText'
		// Here lies the not-yet-implemented method 'SetRespawnText'
		// Here lies the not-yet-implemented method 'UpdateRespawnTimer'
		// Here lies the not-yet-implemented method 'UpdateHUDCredits'
		// Here lies the not-yet-implemented method 'registerHUDView'
		// Here lies the not-yet-implemented method 'SetHUDStageSize'
		// Here lies the not-yet-implemented method 'SetAmmoCountTF'
		// Here lies the not-yet-implemented method 'ClearStats'
		// Here lies the not-yet-implemented method 'ForceHealthUpdate'
		// Here lies the not-yet-implemented method 'GetSkiSpeedStep'
		// Here lies the not-yet-implemented method 'ConfigureSkiSpeedSteps'
		// Here lies the not-yet-implemented method 'GetFrameNumberForVehicle'
		// Here lies the not-yet-implemented method 'TickHud'
		// Here lies the not-yet-implemented method 'ASSetHeading'
		// Here lies the not-yet-implemented method 'TickDirectionalDamageEffect'
		// Here lies the not-yet-implemented method 'ChangeDamageEffectParameter'
		// Here lies the not-yet-implemented method 'PlayDamageEffectWithNoDirectionalIndicator'
		// Here lies the not-yet-implemented method 'ApplyDirectionalDamageEffect'
		// Here lies the not-yet-implemented method 'ApplyNearDeathEffect'
		// Here lies the not-yet-implemented method 'DisplayHit'
		// Here lies the not-yet-implemented method 'UpdateHealth'
		// Here lies the not-yet-implemented method 'TickGhostHealth'
		// Here lies the not-yet-implemented method 'UpdateEnergy'
		// Here lies the not-yet-implemented method 'SetOwnership'
		// Here lies the not-yet-implemented method 'TeamScoreboardUpdateSlot'
		// Here lies the not-yet-implemented method 'RabbitScoreboardUpdateSlot'
		// Here lies the not-yet-implemented method 'RabbitScoreboardActivePlayer'
		// Here lies the not-yet-implemented method 'RabbitLeaderboardShow'
		// Here lies the not-yet-implemented method 'TeamCTFStatsUpdateGeneratorStatus'
		// Here lies the not-yet-implemented method 'TeamCTFStatsUpdateGeneratorTimer'
		// Here lies the not-yet-implemented method 'TeamCTFStatsUpdateFlagReturnTime'
		// Here lies the not-yet-implemented method 'TeamCTFStatsUpdateFlagStatus'
		// Here lies the not-yet-implemented method 'TeamCTFStatsUpdateTeamScore'
		// Here lies the not-yet-implemented method 'TeamCTFStatsUpdateTime'
		// Here lies the not-yet-implemented method 'TeamCTFStatsShow'
		// Here lies the not-yet-implemented method 'TeamRabbitStatsUpdateFlagStatus'
		// Here lies the not-yet-implemented method 'TeamRabbitStatsUpdateTeamScore'
		// Here lies the not-yet-implemented method 'ASC_FriendlyTDMScoreUpdate'
		// Here lies the not-yet-implemented method 'ASC_EnemyTDMScoreUpdate'
		// Here lies the not-yet-implemented method 'TeamRabbitStatsPointBreak'
		// Here lies the not-yet-implemented method 'ASC_FriendlyTDMPointBreak'
		// Here lies the not-yet-implemented method 'ASC_EnemyTDMPointBreak'
		// Here lies the not-yet-implemented method 'ShowNotification'
		// Here lies the not-yet-implemented method 'HideNotification'
		// Here lies the not-yet-implemented method 'TeamRabbitStatsUpdateTime'
		// Here lies the not-yet-implemented method 'TeamRabbitStatsShow'
		// Here lies the not-yet-implemented method 'ArenaUpdateManGraphic'
		// Here lies the not-yet-implemented method 'ArenaStatsUpdateTime'
		// Here lies the not-yet-implemented method 'ArenaStatsUpdateRoundCount'
		// Here lies the not-yet-implemented method 'ArenaStatsUpdateFriendlyRoundScore'
		// Here lies the not-yet-implemented method 'ArenaStatsUpdateEnemyRoundScore'
		// Here lies the not-yet-implemented method 'ArenaStatsShow'
		// Here lies the not-yet-implemented method 'ArenaStatsPointBreak'
		// Here lies the not-yet-implemented method 'ASC_FriendlyArenaPointBreak'
		// Here lies the not-yet-implemented method 'ASC_EnemyArenaPointBreak'
		// Here lies the not-yet-implemented method 'ArenaStatsUpdateTeamScore'
		// Here lies the not-yet-implemented method 'ASC_FriendlyArenaLivesUpdate'
		// Here lies the not-yet-implemented method 'ASC_EnemyArenaLivesUpdate'
		// Here lies the not-yet-implemented method 'DaDStatsShow'
		// Here lies the not-yet-implemented method 'DaDUpdateFriendlyStats'
		// Here lies the not-yet-implemented method 'DaDUpdateEnemyStats'
		// Here lies the not-yet-implemented method 'CaHStatsShow'
		// Here lies the not-yet-implemented method 'CaHControlPointAShow'
		// Here lies the not-yet-implemented method 'CaHControlPointBShow'
		// Here lies the not-yet-implemented method 'CaHControlPointCShow'
		// Here lies the not-yet-implemented method 'CaHControlPointDShow'
		// Here lies the not-yet-implemented method 'CaHControlPointEShow'
		// Here lies the not-yet-implemented method 'CaHUpdate'
		// Here lies the not-yet-implemented method 'CaHPointUpdate'
		// Here lies the not-yet-implemented method 'CaHFriendlyPointBreak'
		// Here lies the not-yet-implemented method 'CaHEnemyPointBreak'
		// Here lies the not-yet-implemented method 'TeamScoreboardShow'
		// Here lies the not-yet-implemented method 'RabbitScoreboardShow'
		// Here lies the not-yet-implemented method 'UpdateCredits'
		// Here lies the not-yet-implemented method 'UpdateFlagInHand'
		// Here lies the not-yet-implemented method 'UpdateSkiing'
		// Here lies the not-yet-implemented method 'UpdateSkiLevel'
		// Here lies the not-yet-implemented method 'UpdateTeamStats'
		// Here lies the not-yet-implemented method 'UpdateVehicleStats'
		// Here lies the not-yet-implemented method 'UpdateVehicleHealth'
		// Here lies the not-yet-implemented method 'UpdateVehicleEnergy'
		// Here lies the not-yet-implemented method 'UpdateVehicleSeat'
		// Here lies the not-yet-implemented method 'UpdateOffhand'
		// Here lies the not-yet-implemented method 'UpdateOwnedItem'
		// Here lies the not-yet-implemented method 'SoundAccolade'
		// Here lies the not-yet-implemented method 'UpdateCallIn'
		// Here lies the not-yet-implemented method 'RetrieveGFxObject'
		// Here lies the not-yet-implemented method 'SetGlobalAlert'
		// Here lies the not-yet-implemented method 'HideGlobalAlert'
		// Here lies the not-yet-implemented method 'CreateKillCamInfo'
		// Here lies the not-yet-implemented method 'ShowKillCamInfo'
		// Here lies the not-yet-implemented method 'GetWeaponNameFromDamageType'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_FlagCarried'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_PlayerName'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_ClassName'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_NextRegen'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_HealthFillBar'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_Health'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_EnergyFillBar'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_Energy'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_PrimaryWeaponName'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_PrimaryAmmoCount'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_SecondaryWeaponName'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_SecondaryAmmoCount'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_OffhandIcon'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_OffhandAmmo'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_OffhandName'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_PackIcon'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_PackAmmo'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_PackName'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_Perk1Icon'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_Perk1Name'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_Perk2Icon'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_Perk2Name'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_SkiIndicatorFillBar'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_SkiIndicatorSpeed'
		// Here lies the not-yet-implemented method 'SetSpectatorPlayerPanel_Selected'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_FlagCarried'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_VehicleName'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_DriverName'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_PassengerName'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_HealthFillBar'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_Health'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_EnergyFillBar'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_Energy'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_PrimaryWeaponName'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_PrimaryWeaponReady'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_PrimaryWeaponVisible'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_SecondaryWeaponName'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_SecondaryWeaponReady'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_SecondaryWeaponVisible'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_SkiIndicatorFillBar'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_SkiIndicatorSpeed'
		// Here lies the not-yet-implemented method 'SetSpectatorVehiclePanel_Selected'
		// Here lies the not-yet-implemented method 'SetSpectatorBookmarkPanel_BookmarkName'
		// Here lies the not-yet-implemented method 'SetSpectatorObjectivePanel_ObjectiveName'
		// Here lies the not-yet-implemented method 'SetSpectatorObjectivePanel_ObjectiveDescription'
		// Here lies the not-yet-implemented method 'SetSpectatorObjectivePanel_HealthFillBar'
		// Here lies the not-yet-implemented method 'SetSpectatorFloatCameraPanel_Name'
		// Here lies the not-yet-implemented method 'SetSpectatorFloatCameraPanel_Description'
		// Here lies the not-yet-implemented method 'ShowSpectatorControls'
		// Here lies the not-yet-implemented method 'HideVGSMenu'
		// Here lies the not-yet-implemented method 'HideTutorial'
		// Here lies the not-yet-implemented method 'ShowFlagCarried'
		// Here lies the not-yet-implemented method 'HideFlagCarried'
		// Here lies the not-yet-implemented method 'HideKillCamInfo'
		// Here lies the not-yet-implemented method 'UpdateVGSMenuList'
		// Here lies the not-yet-implemented method 'ShowEnding'
		// Here lies the not-yet-implemented method 'UpdateChatLog'
		// Here lies the not-yet-implemented method 'SetPowerOscillation'
		// Here lies the not-yet-implemented method 'UpdateChatLogInput'
		// Here lies the not-yet-implemented method 'TeamScoreboardActivePlayer'
		// Here lies the not-yet-implemented method 'TeamScoreboardUpdateTime'
		// Here lies the not-yet-implemented method 'RabbitScoreboardUpdateTime'
		// Here lies the not-yet-implemented method 'TeamScoreboardUpdateTeamScore'
		// Here lies the not-yet-implemented method 'UpdateTutorial'
		// Here lies the not-yet-implemented method 'AddUpdateToCombatLog'
		// Here lies the not-yet-implemented method 'AddUpdateToKillMessage'
		// Here lies the not-yet-implemented method 'ShowSpectatorPlayer'
		// Here lies the not-yet-implemented method 'HideSpectatorPlayer'
		// Here lies the not-yet-implemented method 'ShowSpectatorVehicle'
		// Here lies the not-yet-implemented method 'HideSpectatorVehicle'
		// Here lies the not-yet-implemented method 'ShowSpectatorBookmark'
		// Here lies the not-yet-implemented method 'HideSpectatorBookmark'
		// Here lies the not-yet-implemented method 'ShowSpectatorObjectivePanel'
		// Here lies the not-yet-implemented method 'HideSpectatorObjectivePanel'
		// Here lies the not-yet-implemented method 'ShowSpectatorFloatCameraPanel'
		// Here lies the not-yet-implemented method 'HideSpectatorFloatCameraPanel'
		// Here lies the not-yet-implemented method 'AddFlyingIcon'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
