#pragma once
#include "Engine__UberPostProcessEffect.h"
#include "UTGame__UTGFxHudWrapper.h"
#include "TribesGame__TrSpectatorHUDCache.h"
#include "Engine__MaterialInstanceConstant.h"
#include "TribesGame__TrHUDTeamCTFStats.h"
#include "TribesGame__TrPlayerController.h"
#include "TribesGame__GFxTrUI_TeamSelectionMenu.h"
#include "Engine__Texture2D.h"
#include "TribesGame__TrDeployable.h"
#include "TribesGame__GfxTrHud.h"
#include "Engine__MaterialEffect.h"
#include "TribesGame__TrDaDStats.h"
#include "TribesGame__TrCaHStats.h"
#include "TribesGame__TrArenaStats.h"
#include "TribesGame__TrTeamRabbitStats.h"
#include "TribesGame__TrRabbitLeaderboard.h"
#include "TribesGame__TrScoreboard.h"
#include "TribesGame__GFxTrUI_VehicleMenu.h"
#include "Engine__Material.h"
#include "Engine__Canvas.h"
#include "Engine__PlayerReplicationInfo.h"
#include "Core__Object.h"
#include "TribesGame__TrPawn.h"
#include "TribesGame__TrVehicle.h"
#include "TribesGame__TrCamera_SpectatorBookmark.h"
#include "Engine__Actor.h"
#include "Engine__PlayerController.h"
#include "TribesGame__TrProj_Mine.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty TribesGame.TrHUD." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrHUD." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrHUD : public UTGFxHudWrapper
	{
	public:
		ADD_VAR(::BoolProperty, m_bIsControllerSkiing, 0x8)
		ADD_OBJECT(TrSpectatorHUDCache, m_SpectatorHUDCache)
		ADD_OBJECT(GFxTrUI_TeamSelectionMenu, TeamSelectionMenuMovie)
		ADD_OBJECT(TrPlayerController, TrPlayerOwner)
		ADD_VAR(::BoolProperty, bIsMainMenuOpen, 0x1000)
		ADD_OBJECT(MaterialInstanceConstant, MarkerBaseMIC)
		ADD_VAR(::BoolProperty, bShowObjectives, 0x4)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorFriendly'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorEnemy'!
		ADD_OBJECT(Texture2D, BaseDeployableLevel1)
		ADD_OBJECT(Texture2D, BaseDeployableLevel2)
		ADD_OBJECT(Texture2D, BaseDeployableLevel3)
		ADD_OBJECT(Texture2D, BaseDeployableLevel4)
		ADD_OBJECT(Texture2D, BaseDeployableLevel5)
		ADD_OBJECT(Texture2D, BaseNoPower)
		ADD_OBJECT(Texture2D, DeployableTurret)
		ADD_OBJECT(Texture2D, BaseTurretLevel1)
		ADD_OBJECT(Texture2D, BaseTurretLevel2)
		ADD_OBJECT(Texture2D, BaseTurretLevel3)
		ADD_OBJECT(Texture2D, BaseTurretLevel4)
		ADD_OBJECT(Texture2D, BaseTurretLevel5)
		ADD_OBJECT(Texture2D, BaseTurretLevel1_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel2_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel3_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel4_Down)
		ADD_OBJECT(Texture2D, BaseTurretLevel5_Down)
		ADD_VAR(::IntProperty, m_nPotentialSeekingTargetHUDRotationRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomTime, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, HUDMarkerMissileLocked)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomOpacityStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomOpacityEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSeekingTargetHUDZoomStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fInitialSeekingTargetYaw, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, HUDMarkerMissileLocking)
		ADD_OBJECT(Texture2D, HUDMarkerMissileTargetLocked)
		ADD_OBJECT(Texture2D, HUDMarkerMissileTarget)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomOpacityStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomOpacityEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomStart, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fPotentialSeekingTargetHUDZoomEnd, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCaratPlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCaratPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMarker2DDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentWhiteoutValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TeamPlayerInfoMaxDist, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, DeployableSensor)
		ADD_OBJECT(Texture2D, MarkerLight)
		ADD_OBJECT(Texture2D, MarkerMedium)
		ADD_OBJECT(Texture2D, MarkerHeavy)
		ADD_OBJECT(Texture2D, FlagHeldLight)
		ADD_OBJECT(Texture2D, FlagHeldMedium)
		ADD_OBJECT(Texture2D, FlagHeldHeavy)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorEnemy_IsFriend'!
		ADD_VAR(::FloatProperty, m_fNamePlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarPlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarPlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fHealthBarHeight, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorFriendly_IsFriend'!
		ADD_OBJECT(GfxTrHud, m_GFxHud)
		ADD_VAR(::IntProperty, FriendlyChatColorIdx, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'FriendlyChatColor'!
		ADD_VAR(::IntProperty, EnemyChatColorIdx, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'EnemyChatColor'!
		ADD_VAR(::IntProperty, WhisperChatColorIdx, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'WhisperChatColor'!
		ADD_VAR(::IntProperty, InfoChatColorIdx, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bVotePending, 0x800)
		ADD_OBJECT(Texture2D, FlagEmptyBase)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel1)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel1_Down)
		ADD_OBJECT(Texture2D, DeployableJammer)
		ADD_OBJECT(Texture2D, DeployableShield)
		ADD_OBJECT(Texture2D, BaseSensorLevel1)
		ADD_OBJECT(Texture2D, BaseSensorLevel2)
		ADD_OBJECT(Texture2D, BaseSensorLevel3)
		ADD_OBJECT(Texture2D, BaseSensorLevel4)
		ADD_OBJECT(Texture2D, BaseSensorLevel5)
		ADD_OBJECT(Texture2D, BaseSensorLevel1_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel2_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel3_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel4_Down)
		ADD_OBJECT(Texture2D, BaseSensorLevel5_Down)
		ADD_OBJECT(Texture2D, HUDMarkerLaserTargetAimPoint)
		ADD_OBJECT(Texture2D, HUDMarkerLaserTarget)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LaserTargetTracePossible'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'LaserTargetTraceImprobable'!
		ADD_OBJECT(Texture2D, AmmoDropPickup)
		ADD_OBJECT(Texture2D, FlagAtBase)
		ADD_OBJECT(Texture2D, FlagDropped)
		ADD_VAR(::FloatProperty, m_fOverheadNumberColorizeTimeMax, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberColorizeTimeMin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberMaxScaleAmount, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberScaleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberFadeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fOverheadNumberTotalTime, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'm_OverheadNumberColorMax'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'm_OverheadNumberColorMin'!
		ADD_VAR(::FloatProperty, m_fOverheadNumberZSpeed, 0xFFFFFFFF)
		ADD_OBJECT(UberPostProcessEffect, m_UperPPEffect)
		// WARNING: Unknown structure type 'ScriptStruct Engine.Canvas.FontRenderInfo' for the property named 'm_nNameFontRenderInfo'!
		ADD_VAR(::FloatProperty, m_fMineDeployerNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMineDeployerNamePlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMineNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fMineNamePlacementX, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleNamePlacementY, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fVehicleNamePlacementX, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, AwardMIC)
		ADD_VAR(::FloatProperty, AwardTimelineLoc, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardFadeInScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardTimelineLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardBaseHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, AwardBaseSize, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fCurrentFumbledFlagValue, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_FumbledFlagFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_FumbledFlagMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_FumbledFlagMaterialEffect)
		ADD_VAR(::FloatProperty, m_WhiteoutFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_WhiteoutMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_WhiteoutMaterialEffect)
		ADD_VAR(::FloatProperty, m_VignetteValueMultiplier, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_VignetteFadeTarget, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_VignetteFadeSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_VignetteMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_VignetteMaterialEffect)
		ADD_VAR(::IntProperty, LastChangeResCheckTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastChangeResTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LastCreditTotal, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_JammerPackFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_JammerPackMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_JammerPackMaterialEffect)
		ADD_VAR(::FloatProperty, m_ShieldHitFadeOutSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_ShieldHitFadeInSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_ShieldFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_ShieldMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_ShieldMaterialEffect)
		ADD_VAR(::FloatProperty, m_InvulnerableFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_InvulnerableMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_InvulnerableMaterialEffect)
		ADD_VAR(::FloatProperty, m_PickupFlashFadeOutSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_PickupFlashMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_PickupFlashMaterialEffect)
		ADD_VAR(::FloatProperty, m_fSkiEffectStrobeTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectFadeOutTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectFadeInTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectMinIntensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fSkiEffectMaxIntensity, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fControllerSkiSpeed, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInstanceConstant, m_SkiEffectMaterialInstance)
		ADD_OBJECT(MaterialEffect, m_SkiEffect)
		ADD_OBJECT(ScriptClass, m_GameClass)
		ADD_OBJECT(ScriptClass, m_MusicManagerClass)
		ADD_VAR(::FloatProperty, m_fEnemyGeneratorRestoreTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, m_fFriendlyGeneratorRestoreTime, 0xFFFFFFFF)
		ADD_OBJECT(TrCaHStats, CaHStats)
		ADD_OBJECT(TrDaDStats, DaDStats)
		ADD_OBJECT(TrArenaStats, ArenaStats)
		ADD_OBJECT(TrTeamRabbitStats, TeamRabbitStats)
		ADD_OBJECT(TrHUDTeamCTFStats, HUDTeamCTFStats)
		ADD_OBJECT(TrRabbitLeaderboard, RabbitLeaderboard)
		ADD_OBJECT(TrScoreboard, Scoreboard)
		ADD_OBJECT(GFxTrUI_VehicleMenu, VehicleMenuMovie)
		ADD_OBJECT(Material, MapMaterialReference)
		ADD_OBJECT(MaterialInstanceConstant, LowAmmoMic)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'TeamChatColor'!
		ADD_VAR(::IntProperty, SelfChatColorIdx, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, SpottedTarget_MotionMine)
		ADD_OBJECT(Texture2D, SpottedTarget)
		ADD_OBJECT(Texture2D, DeployableMine)
		ADD_OBJECT(Texture2D, DeployableClaymore)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel5_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel4_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel3_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel2_Down)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel5)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel4)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel3)
		ADD_OBJECT(Texture2D, BaseGeneratorLevel2)
		ADD_OBJECT(Texture2D, BaseVehicleStation)
		ADD_OBJECT(Texture2D, BaseRepairStation)
		ADD_OBJECT(Texture2D, BaseInventoryStation)
		ADD_OBJECT(Texture2D, HUDMarkerMissileIncoming)
		ADD_OBJECT(Texture2D, FlagHeldVehicle)
		ADD_OBJECT(Texture2D, VehicleMarkerNoDriver)
		ADD_OBJECT(Texture2D, VehicleMarkerHeavy)
		ADD_OBJECT(Texture2D, VehicleMarkerMedium)
		ADD_OBJECT(Texture2D, VehicleMarkerLight)
		ADD_OBJECT(Texture2D, VehicleMarker)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.LinearColor' for the property named 'MarkerColorNone'!
		ADD_VAR(::IntProperty, m_LastDeployableCount, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_LastMineCount, 0xFFFFFFFF)
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ColorEnemy'!
		// WARNING: Unknown structure type 'ScriptStruct Core.Object.Color' for the property named 'ColorFriend'!
		ADD_VAR(::FloatProperty, ObjectiveInfoMaxDist, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sLastClassName, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, m_sWinningPlayer, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAccoladePlaying, 0x40000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorFloatCameraPanelVisible, 0x20000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorObjectivePanelVisible, 0x10000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorBookmarkPanelVisible, 0x8000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorVehiclePanelVisible, 0x4000)
		ADD_VAR(::BoolProperty, m_bIsSpectatorPlayerPanelVisible, 0x2000)
		ADD_VAR(::BoolProperty, bPlayAward, 0x400)
		ADD_VAR(::BoolProperty, m_bUpdateFumbledFlagEffect, 0x200)
		ADD_VAR(::BoolProperty, m_bUpdateWhiteoutEffect, 0x100)
		ADD_VAR(::BoolProperty, bLoadSequenceComplete, 0x80)
		ADD_VAR(::BoolProperty, bRestoreHUDState, 0x40)
		ADD_VAR(::BoolProperty, m_bEffectFadingIn, 0x20)
		ADD_VAR(::BoolProperty, m_bStrobeIn, 0x10)
		ADD_VAR(::BoolProperty, HasGlobalChatAsAlert, 0x2)
		ADD_VAR(::BoolProperty, m_bGameOver, 0x1)
		ADD_VAR(::IntProperty, m_nLastPerk2Icon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nLastPerk1Icon, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nWinningTeam, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'DrawMarkerText'
		// Here lies the not-yet-implemented method 'DrawMICMarker'
		// Here lies the not-yet-implemented method 'GetEdgeScreenCoordinates'
		// Here lies the not-yet-implemented method 'DrawMarker'
		// Here lies the not-yet-implemented method 'DrawRotatedMarker'
		// Here lies the not-yet-implemented method 'ShowDebugInfo'
		// Here lies the not-yet-implemented method 'CreateHUDMovie'
		// Here lies the not-yet-implemented method 'ShowSpectatorControls'
		// Here lies the not-yet-implemented method 'SetShowScores'
		// Here lies the not-yet-implemented method 'PostBeginPlay'
		// Here lies the not-yet-implemented method 'InitializeGameHUD'
		// Here lies the not-yet-implemented method 'FadeInTimer'
		// Here lies the not-yet-implemented method 'Fade'
		// Here lies the not-yet-implemented method 'PlayRoundOver'
		// Here lies the not-yet-implemented method 'ShowRoundEnding'
		// Here lies the not-yet-implemented method 'PlayMatchOver'
		// Here lies the not-yet-implemented method 'ShowEnding'
		// Here lies the not-yet-implemented method 'FadeInSummary'
		// Here lies the not-yet-implemented method 'ScaleformJoystickInputEvent'
		// Here lies the not-yet-implemented method 'ToggleSkiEffect'
		// Here lies the not-yet-implemented method 'TogglePauseMenu'
		// Here lies the not-yet-implemented method 'ToggleMovieHUD'
		// Here lies the not-yet-implemented method 'ToggleVehicleMenu'
		// Here lies the not-yet-implemented method 'ToggleTeamSelectionMenu'
		// Here lies the not-yet-implemented method 'SetPowerOscillation'
		// Here lies the not-yet-implemented method 'AddUpdateToCombatLog'
		// Here lies the not-yet-implemented method 'AddToPromptPanel'
		// Here lies the not-yet-implemented method 'AddToPromptPanelTime'
		// Here lies the not-yet-implemented method 'ClearPromptPanel'
		// Here lies the not-yet-implemented method 'AddToHeroStatus'
		// Here lies the not-yet-implemented method 'ClearHeroStatus'
		// Here lies the not-yet-implemented method 'ClearPromptPanelMessage'
		// Here lies the not-yet-implemented method 'UpdateVGSMenu'
		// Here lies the not-yet-implemented method 'HideVGSMenu'
		// Here lies the not-yet-implemented method 'AddToHelpText'
		// Here lies the not-yet-implemented method 'ClearHelpText'
		// Here lies the not-yet-implemented method 'AddUpdateToKillMessage'
		// Here lies the not-yet-implemented method 'AddFlyingIcon'
		// Here lies the not-yet-implemented method 'OnSpectate'
		// Here lies the not-yet-implemented method 'CreateSpectatorHUDCache'
		// Here lies the not-yet-implemented method 'ClearSpectatorHUDCache'
		// Here lies the not-yet-implemented method 'HideHUDElements'
		// Here lies the not-yet-implemented method 'ShowHUDPlayerSpawning'
		// Here lies the not-yet-implemented method 'ShowHUDPlayerAlive'
		// Here lies the not-yet-implemented method 'ShowCenterHUDElements'
		// Here lies the not-yet-implemented method 'UpdateRespawnText'
		// Here lies the not-yet-implemented method 'UpdateRespawnTimer'
		// Here lies the not-yet-implemented method 'UpdateHUDCredits'
		// Here lies the not-yet-implemented method 'TeamScoreboardShow'
		// Here lies the not-yet-implemented method 'RabbitScoreboardShow'
		// Here lies the not-yet-implemented method 'TeamScoreboardUpdateSlot'
		// Here lies the not-yet-implemented method 'RabbitScoreboardUpdateSlot'
		// Here lies the not-yet-implemented method 'TeamScoreboardUpdateTeamScore'
		// Here lies the not-yet-implemented method 'TeamScoreboardUpdateTime'
		// Here lies the not-yet-implemented method 'RabbitScoreboardUpdateTime'
		// Here lies the not-yet-implemented method 'TeamScoreboardActivePlayer'
		// Here lies the not-yet-implemented method 'RabbitScoreboardActivePlayer'
		// Here lies the not-yet-implemented method 'ResolutionChanged'
		// Here lies the not-yet-implemented method 'RestoreHUDState'
		// Here lies the not-yet-implemented method 'HideMenus'
		// Here lies the not-yet-implemented method 'RemoveMovies'
		// Here lies the not-yet-implemented method 'CompleteVehicleMenuClose'
		// Here lies the not-yet-implemented method 'CompleteTeamSelectionMenuClose'
		// Here lies the not-yet-implemented method 'ClearCrosshairOnFriendly'
		// Here lies the not-yet-implemented method 'CheckCrosshairOnFriendly'
		// Here lies the not-yet-implemented method 'DrawColoredMarkerText'
		// Here lies the not-yet-implemented method 'DrawSmallText'
		// Here lies the not-yet-implemented method 'DrawHealthBar'
		// Here lies the not-yet-implemented method 'PostRender'
		// Here lies the not-yet-implemented method 'GetRemainingFriendlyGeneratorRestoreTime'
		// Here lies the not-yet-implemented method 'GetRemainingEnemyGeneratorRestoreTime'
		// Here lies the not-yet-implemented method 'UpdateSkiEffect'
		// Here lies the not-yet-implemented method 'UpdatePickupFlashEffect'
		// Here lies the not-yet-implemented method 'PulsePickupFlashEffect'
		// Here lies the not-yet-implemented method 'UpdateInvulnerableEfect'
		// Here lies the not-yet-implemented method 'UpdateShieldEffect'
		// Here lies the not-yet-implemented method 'PulseShieldEffect'
		// Here lies the not-yet-implemented method 'UpdateJammerEffect'
		// Here lies the not-yet-implemented method 'UpdateFadeEffect'
		// Here lies the not-yet-implemented method 'FumbleFlag'
		// Here lies the not-yet-implemented method 'UpdateFumbledFlagEffect'
		// Here lies the not-yet-implemented method 'Whiteout'
		// Here lies the not-yet-implemented method 'ClearWhiteout'
		// Here lies the not-yet-implemented method 'UpdateWhiteoutEffect'
		// Here lies the not-yet-implemented method 'LocalizedMessage'
		// Here lies the not-yet-implemented method 'ChatMessageReceived'
		// Here lies the not-yet-implemented method 'StripTag'
		// Here lies the not-yet-implemented method 'SendLocalMessageToGlobalAlert'
		// Here lies the not-yet-implemented method 'SendLocalMessageToChat'
		// Here lies the not-yet-implemented method 'SetPlayerClassObjects'
		// Here lies the not-yet-implemented method 'HideGlobalAlert'
		// Here lies the not-yet-implemented method 'KickVoteMessage'
		// Here lies the not-yet-implemented method 'EnableGameTypeHUD'
		// Here lies the not-yet-implemented method 'ShowSpectatorPlayer'
		// Here lies the not-yet-implemented method 'HideSpectatorPlayer'
		// Here lies the not-yet-implemented method 'UpdateSpectatorPlayerPanel'
		// Here lies the not-yet-implemented method 'ShowSpectatorVehicle'
		// Here lies the not-yet-implemented method 'HideSpectatorVehicle'
		// Here lies the not-yet-implemented method 'UpdateSpectatorVehiclePanel'
		// Here lies the not-yet-implemented method 'ShowSpectatorBookmark'
		// Here lies the not-yet-implemented method 'HideSpectatorBookmark'
		// Here lies the not-yet-implemented method 'UpdateSpectatorBookmarkPanel'
		// Here lies the not-yet-implemented method 'ShowSpectatorObjectivePanel'
		// Here lies the not-yet-implemented method 'HideSpectatorObjectivePanel'
		// Here lies the not-yet-implemented method 'UpdateSpectatorObjectivePanel'
		// Here lies the not-yet-implemented method 'ShowSpectatorFloatCameraPanel'
		// Here lies the not-yet-implemented method 'HideSpectatorFloatCameraPanel'
		// Here lies the not-yet-implemented method 'UpdateSpectatorFloatCameraPanel'
		// Here lies the not-yet-implemented method 'HideAllSpectatorPanels'
		// Here lies the not-yet-implemented method 'OnViewTargetChange'
		// Here lies the not-yet-implemented method 'TestNumber'
		// Here lies the not-yet-implemented method 'AddOverheadNumber'
		// Here lies the not-yet-implemented method 'UpdateOverheadNumbers'
		// Here lies the not-yet-implemented method 'Tick'
		// Here lies the not-yet-implemented method 'PostRenderFor'
		// Here lies the not-yet-implemented method 'PlayAward'
		// Here lies the not-yet-implemented method 'QueueAccolade'
		// Here lies the not-yet-implemented method 'CheckQueuedAccolades'
		// Here lies the not-yet-implemented method 'RunQueuedAccoladesTimer'
		// Here lies the not-yet-implemented method 'ClearQueuedAccoladesTimer'
		// Here lies the not-yet-implemented method 'DeployableReplicated'
		// Here lies the not-yet-implemented method 'MineReplicated'
		// Here lies the not-yet-implemented method 'UpdateOwnedItems'
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
