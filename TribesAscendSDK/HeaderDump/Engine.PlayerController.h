#pragma once
#include "Engine.Actor.h"
#include "Engine.SeqAct_CameraLookAt.h"
#include "Engine.Controller.h"
#include "Engine.Player.h"
#include "Engine.Weapon.h"
#include "Engine.Pawn.h"
#include "Engine.SavedMove.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.SeqAct_CameraShake.h"
#include "Engine.Camera.h"
#include "Engine.SeqAct_SetSoundMode.h"
#include "Engine.HUD.h"
#include "Engine.CoverReplicator.h"
#include "Engine.CameraAnim.h"
#include "Engine.SeqAct_Destroy.h"
#include "Engine.OnlineGameSearch.h"
#include "Engine.PlayerInput.h"
#include "Engine.ForceFeedbackManager.h"
#include "Engine.UIDataStore_OnlinePlayerData.h"
#include "Engine.PlayerController.ClientAdjustment.h"
#include "Engine.OnlineGameSettings.h"
#include "Engine.FaceFXAnimSet.h"
#include "Core.Object.Vector.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.NetConnection.h"
#include "Engine.CheatManager.h"
#include "Engine.InterpTrackInstDirector.h"
#include "Engine.OnlineGameSearch.OnlineGameSearchResult.h"
#include "Engine.SeqAct_ToggleInput.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Guid.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.Canvas.h"
#include "Engine.Inventory.h"
#include "Core.Object.h"
#include "Engine.SeqAct_DrawText.h"
#include "Engine.Camera.ViewTargetTransitionParams.h"
#include "Engine.SoundCue.h"
#include "Engine.SeqAct_ConsoleCommand.h"
#include "Engine.UIInteraction.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Core.Object.Color.h"
#include "Core.Object.Vector2D.h"
#include "Engine.HUD.KismetDrawTextInfo.h"
#include "Engine.MaterialInterface.h"
#include "Engine.SeqAct_SetCameraTarget.h"
#include "Engine.SeqAct_ToggleHUD.h"
#include "Engine.SeqAct_ForceFeedback.h"
#include "Engine.AnimNotify_Rumble.h"
#include "Engine.SeqAct_ToggleCinematicMode.h"
#include "Engine.LevelStreaming.h"
#include "Engine.Font.h"
#include "Engine.TextureMovie.h"
#include "Engine.SeqAct_FlyThroughHasEnded.h"
#include "Engine.CameraShake.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PlayerController." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PlayerController." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PlayerController : public Controller
	{
	public:
		ADD_VAR(::FloatProperty, LODDistanceFactor, 0xFFFFFFFF)
		ADD_OBJECT(Player, Player)
		ADD_OBJECT(Actor, ViewTarget)
		ADD_OBJECT(Camera, PlayerCamera)
		ADD_VAR(::BoolProperty, bIsExternalUIOpen, 0x400000)
		ADD_VAR(::BoolProperty, bPendingDestroy, 0x200)
		ADD_VAR(::BoolProperty, bIsControllerConnected, 0x800000)
		ADD_OBJECT(CoverReplicator, MyCoverReplicator)
		ADD_VAR(::FloatProperty, MaxTimeMargin, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxResponseTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastActiveTime, 0xFFFFFFFF)
		ADD_OBJECT(OnlineSubsystem, OnlineSub)
		ADD_OBJECT(OnlineGameSearch, MigratedSearchToJoin)
		ADD_VAR(::FloatProperty, TimeMargin, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bShortConnectTimeOut, 0x100)
		ADD_OBJECT(HUD, myHUD)
		ADD_VAR(::FloatProperty, WaitDelay, 0xFFFFFFFF)
		ADD_OBJECT(SavedMove, SavedMoves)
		ADD_OBJECT(SavedMove, PendingMove)
		ADD_OBJECT(PlayerInput, PlayerInput)
		ADD_OBJECT(ScriptClass, InputClass)
		ADD_VAR(::StrProperty, ForceFeedbackManagerClassName, 0xFFFFFFFF)
		ADD_OBJECT(ForceFeedbackManager, ForceFeedbackManager)
		ADD_OBJECT(UIDataStore_OnlinePlayerData, OnlinePlayerData)
		ADD_VAR(::BoolProperty, bFrozen, 0x1)
		ADD_OBJECT(Pawn, AcknowledgedPawn)
		ADD_VAR(::FloatProperty, FOVAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DefaultFOV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DesiredFOV, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastBroadcastTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, LastBroadcastString, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, CurrentTimeStamp, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWasSpeedHack, 0x400)
		ADD_VAR(::FloatProperty, LastSpeedHackLog, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ClientAdjustment>, PendingAdjustment, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ServerTimeStamp, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, SavedMoveClass)
		ADD_VAR(::BoolProperty, bDoubleJump, 0x4)
		ADD_VAR(::IntProperty, ClientCap, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, LastPingUpdate, 0xFFFFFFFF)
		ADD_OBJECT(SavedMove, FreeMoves)
		ADD_STRUCT(::VectorProperty, LastAckedAccel, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bUpdatePosition, 0x8)
		ADD_VAR(::ByteProperty, bRun, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bDuck, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPressedJump, 0x2)
		ADD_VAR(::BoolProperty, bUpdating, 0x10)
		ADD_VAR(::FloatProperty, ClientUpdateTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCinematicMode, 0x10000)
		ADD_VAR(::FloatProperty, InteractDistance, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAimingHelp, 0x1000)
		ADD_VAR(::BoolProperty, bClientSimulatingViewTarget, 0x2000)
		ADD_OBJECT(ScriptClass, CameraClass)
		ADD_VAR(::ByteProperty, DoubleClickDir, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GroundPitch, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCheatFlying, 0x40)
		ADD_VAR(::FloatProperty, LastSpectatorStateSynchTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, SpectatorCameraSpeed, 0xFFFFFFFF)
		ADD_OBJECT(PlayerReplicationInfo, RealViewTarget)
		ADD_VAR(::FloatProperty, MinRespawnDelay, 0xFFFFFFFF)
		ADD_OBJECT(NetConnection, PendingSwapConnection)
		ADD_VAR(::ByteProperty, bIgnoreMoveInput, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, bIgnoreLookInput, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bCinemaDisableInputMove, 0x20000)
		ADD_VAR(::BoolProperty, bCinemaDisableInputLook, 0x40000)
		ADD_VAR(::BoolProperty, bHasVoiceHandshakeCompleted, 0x8000)
		ADD_VAR(::ByteProperty, NetPlayerIndex, 0xFFFFFFFF)
		ADD_OBJECT(CheatManager, CheatManager)
		ADD_VAR(::BoolProperty, bNeverSwitchOnPickup, 0x20)
		ADD_VAR(::BoolProperty, bCameraPositionLocked, 0x80)
		ADD_VAR(::BoolProperty, bWasSaturated, 0x800)
		ADD_VAR(::BoolProperty, bPreventRespawn, 0x4000)
		ADD_VAR(::BoolProperty, bIgnoreNetworkMessages, 0x80000)
		ADD_VAR(::BoolProperty, bReplicateAllPawns, 0x100000)
		ADD_VAR(::BoolProperty, bIsUsingStreamingVolumes, 0x200000)
		ADD_VAR(::BoolProperty, bCheckSoundOcclusion, 0x1000000)
		ADD_VAR(::BoolProperty, bDebugCameraAnims, 0x2000000)
		ADD_VAR(::BoolProperty, bBlockCameraAnimsFromOverridingPostProcess, 0x4000000)
		ADD_VAR(::BoolProperty, bLogHearSoundOverflow, 0x8000000)
		ADD_VAR(::BoolProperty, bCheckRelevancyThroughPortals, 0x10000000)
		ADD_VAR(::BoolProperty, bDebugClientAdjustPosition, 0x20000000)
		ADD_OBJECT(InterpTrackInstDirector, ControllingDirTrackInst)
		ADD_STRUCT(::RotatorProperty, TargetViewRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TargetEyeHeight, 0xFFFFFFFF)
		ADD_STRUCT(::RotatorProperty, BlendedTargetViewRotation, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DynamicPingThreshold, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, CheatClass)
		ADD_STRUCT(::VectorProperty, FailedPathStart, 0xFFFFFFFF)
		ADD_VAR(::NameProperty, DelayedJoinSessionName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxConcurrentHearSounds, 0xFFFFFFFF)
		float GetFOVAngle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetFOVAngle");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPlayerNetworkAddress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPlayerNetworkAddress");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		class Actor* GetViewTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetViewTarget");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)params;
			free(params);
			return returnVal;
		}
		bool IsPrimaryPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPrimaryPlayer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetNetSpeed(int NewSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetNetSpeed");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetServerNetworkAddress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetServerNetworkAddress");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> ConsoleCommand(ScriptArray<wchar_t> Command, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ConsoleCommand");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Command;
			*(bool*)(params + 12) = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 16);
			free(params);
			return returnVal;
		}
		void ClientTravel(ScriptArray<wchar_t> URL, byte TravelType, bool bSeamless, Guid MapPackageGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientTravel");
			byte* params = (byte*)malloc(33);
			*(ScriptArray<wchar_t>*)params = URL;
			*(params + 12) = TravelType;
			*(bool*)(params + 16) = bSeamless;
			*(Guid*)(params + 20) = MapPackageGuid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateURL(ScriptArray<wchar_t> NewOption, ScriptArray<wchar_t> NewValue, bool bSave1Default)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdateURL");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = NewOption;
			*(ScriptArray<wchar_t>*)(params + 12) = NewValue;
			*(bool*)(params + 24) = bSave1Default;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetDefaultURL(ScriptArray<wchar_t> Option)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetDefaultURL");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Option;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void CopyToClipboard(ScriptArray<wchar_t> Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CopyToClipboard");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> PasteFromClipboard()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PasteFromClipboard");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void SetAllowMatureLanguage(bool bAllowMatureLanguge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetAllowMatureLanguage");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAllowMatureLanguge;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAudioGroupVolume(ScriptName GroupName, float Volume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetAudioGroupVolume");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = GroupName;
			*(float*)(params + 8) = Volume;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientConvolve(ScriptArray<wchar_t> C, int H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientConvolve");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = C;
			*(int*)(params + 12) = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerProcessConvolve(ScriptArray<wchar_t> C, int H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerProcessConvolve");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = C;
			*(int*)(params + 12) = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckSpeedHack(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CheckSpeedHack");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int FindStairRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FindStairRotation");
			byte* params = (byte*)malloc(8);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void CleanUpAudioComponents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CleanUpAudioComponents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FellOutOfWorld");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ForceClearUnpauseDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ForceClearUnpauseDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnExternalUIChanged(bool bIsOpening)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnExternalUIChanged");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIsOpening;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanUnpauseExternalUI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanUnpauseExternalUI");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnControllerChanged");
			byte* params = (byte*)malloc(8);
			*(int*)params = ControllerId;
			*(bool*)(params + 4) = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanUnpauseControllerConnected()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanUnpauseControllerConnected");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		class CoverReplicator* SpawnCoverReplicator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SpawnCoverReplicator");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class CoverReplicator**)params;
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ReceivedPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterPlayerDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RegisterPlayerDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindConnectedPeerIndex(UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FindConnectedPeerIndex");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddPeer(UniqueNetId PeerNetId, byte NatType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AddPeer");
			byte* params = (byte*)malloc(9);
			*(UniqueNetId*)params = PeerNetId;
			*(params + 8) = NatType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemovePeer(UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemovePeer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerAddPeer(UniqueNetId PeerNetId, byte NatType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerAddPeer");
			byte* params = (byte*)malloc(9);
			*(UniqueNetId*)params = PeerNetId;
			*(params + 8) = NatType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerRemovePeer(UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerRemovePeer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientUpdateBestNextHosts(UniqueNetId SortedNextHosts, byte NumEntries)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientUpdateBestNextHosts");
			byte* params = (byte*)malloc(9);
			*(UniqueNetId*)params = SortedNextHosts;
			*(params + 80) = NumEntries;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyPeerDisconnectHost(UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyPeerDisconnectHost");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsBestHostPeer(UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsBestHostPeer");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool MigrateNewHost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.MigrateNewHost");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnEndGameForHostMigrate(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnEndGameForHostMigrate");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetRegisteredPlayersInSession(ScriptName SessionName, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& OutRegisteredPlayers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetRegisteredPlayersInSession");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8) = OutRegisteredPlayers;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutRegisteredPlayers = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 8);
			free(params);
		}
		void RemoveMissingPeersFromSession(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemoveMissingPeersFromSession");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnUnregisterPlayerCompleteForMigrate(ScriptName SessionName, UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnUnregisterPlayerCompleteForMigrate");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = SessionName;
			*(UniqueNetId*)(params + 8) = PlayerID;
			*(bool*)(params + 16) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnHostMigratedOnlineGame(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnHostMigratedOnlineGame");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptClass* GetCurrentSearchClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetCurrentSearchClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptClass**)params;
			free(params);
			return returnVal;
		}
		void PeerDesignatedAsHost(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PeerDesignatedAsHost");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PeerTravelAsHost(float TravelCountdownTimer, ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PeerTravelAsHost");
			byte* params = (byte*)malloc(16);
			*(float*)params = TravelCountdownTimer;
			*(ScriptArray<wchar_t>*)(params + 4) = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TellPeerToTravel(UniqueNetId ToPeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TellPeerToTravel");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = ToPeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TellPeerToTravelToSession(UniqueNetId ToPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo, int PlatformSpecificInfoSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TellPeerToTravelToSession");
			byte* params = (byte*)malloc(25);
			*(UniqueNetId*)params = ToPeerNetId;
			*(ScriptName*)(params + 8) = SessionName;
			*(ScriptClass**)(params + 16) = SearchClass;
			*(params + 20) = PlatformSpecificInfo;
			*(int*)(params + 100) = PlatformSpecificInfoSize;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PeerReceivedMigratedSession(UniqueNetId FromPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PeerReceivedMigratedSession");
			byte* params = (byte*)malloc(21);
			*(UniqueNetId*)params = FromPeerNetId;
			*(ScriptName*)(params + 8) = SessionName;
			*(ScriptClass**)(params + 16) = SearchClass;
			*(params + 20) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnEndGameForJoinMigrate(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnEndGameForJoinMigrate");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnJoinMigratedGame(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnJoinMigratedGame");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PreRender");
			byte* params = (byte*)malloc(4);
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetTimeMargin()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ResetTimeMargin");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerShortTimeout()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerShortTimeout");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerGivePawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerGivePawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickWarning()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.KickWarning");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCheats(bool bForce)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AddCheats");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnableCheats()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.EnableCheats");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnDefaultHUD()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SpawnDefaultHUD");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientReset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanOutSavedMoves()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CleanOutSavedMoves");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreControllerIdChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PreControllerIdChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostControllerIdChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PostControllerIdChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineSubsystem* GetOnlineSubsystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetOnlineSubsystem");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class OnlineSubsystem**)params;
			free(params);
			return returnVal;
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.InitInputSystem");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitializeDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientInitializeDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterCustomPlayerDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RegisterCustomPlayerDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterStandardPlayerDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RegisterStandardPlayerDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterPlayerDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UnregisterPlayerDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterStandardPlayerDataStores()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UnregisterStandardPlayerDataStores");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReloadProfileSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ReloadProfileSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetRumbleScale(float ScaleBy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetRumbleScale");
			byte* params = (byte*)malloc(4);
			*(float*)params = ScaleBy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsControllerTiltActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsControllerTiltActive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetControllerTiltDesiredIfAvailable(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetControllerTiltDesiredIfAvailable");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetControllerTiltActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetControllerTiltActive");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOnlyUseControllerTiltInput(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetOnlyUseControllerTiltInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetUseTiltForwardAndBack(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetUseTiltForwardAndBack");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsKeyboardAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsKeyboardAvailable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool IsMouseAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsMouseAvailable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClientGotoState(ScriptName NewState, ScriptName NewLabel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientGotoState");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = NewState;
			*(ScriptName*)(params + 8) = NewLabel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AskForPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AskForPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GivePawn(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GivePawn");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Possess");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = aPawn;
			*(bool*)(params + 4) = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AcknowledgePossession");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerAcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerAcknowledgePossession");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UnPossess()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UnPossess");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PawnDied");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetHUD(ScriptClass* newHUDType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetHUD");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = newHUDType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HandlePickup");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = Inv;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CleanupPRI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CleanupPRI");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveLocalizedMessage(ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ReceiveLocalizedMessage");
			byte* params = (byte*)malloc(20);
			*(ScriptClass**)params = Message;
			*(int*)(params + 4) = Switch;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 12) = RelatedPRI;
			*(class Object**)(params + 16) = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlaySound(class SoundCue* ASound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlaySound");
			byte* params = (byte*)malloc(4);
			*(class SoundCue**)params = ASound;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HearSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HearSoundFinished");
			byte* params = (byte*)malloc(4);
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetPooledAudioComponent(class SoundCue* ASound, class Actor* SourceActor, bool bStopWhenOwnerDestroyed, bool bUseLocation, Vector SourceLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPooledAudioComponent");
			byte* params = (byte*)malloc(32);
			*(class SoundCue**)params = ASound;
			*(class Actor**)(params + 4) = SourceActor;
			*(bool*)(params + 8) = bStopWhenOwnerDestroyed;
			*(bool*)(params + 12) = bUseLocation;
			*(Vector*)(params + 16) = SourceLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)(params + 28);
			free(params);
			return returnVal;
		}
		void ClientHearSound(class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientHearSound");
			byte* params = (byte*)malloc(28);
			*(class SoundCue**)params = ASound;
			*(class Actor**)(params + 4) = SourceActor;
			*(Vector*)(params + 8) = SourceLocation;
			*(bool*)(params + 20) = bStopWhenOwnerDestroyed;
			*(bool*)(params + 24) = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsClosestLocalPlayerToActor(class Actor* TheActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsClosestLocalPlayerToActor");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Kismet_ClientPlaySound(class SoundCue* ASound, class Actor* SourceActor, float VolumeMultiplier, float PitchMultiplier, float FadeInTime, bool bSuppressSubtitles, bool bSuppressSpatialization)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Kismet_ClientPlaySound");
			byte* params = (byte*)malloc(28);
			*(class SoundCue**)params = ASound;
			*(class Actor**)(params + 4) = SourceActor;
			*(float*)(params + 8) = VolumeMultiplier;
			*(float*)(params + 12) = PitchMultiplier;
			*(float*)(params + 16) = FadeInTime;
			*(bool*)(params + 20) = bSuppressSubtitles;
			*(bool*)(params + 24) = bSuppressSpatialization;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Kismet_ClientStopSound(class SoundCue* ASound, class Actor* SourceActor, float FadeOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Kismet_ClientStopSound");
			byte* params = (byte*)malloc(12);
			*(class SoundCue**)params = ASound;
			*(class Actor**)(params + 4) = SourceActor;
			*(float*)(params + 8) = FadeOutTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayActorFaceFXAnim(class Actor* SourceActor, class FaceFXAnimSet* AnimSet, ScriptArray<wchar_t> GroupName, ScriptArray<wchar_t> SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayActorFaceFXAnim");
			byte* params = (byte*)malloc(36);
			*(class Actor**)params = SourceActor;
			*(class FaceFXAnimSet**)(params + 4) = AnimSet;
			*(ScriptArray<wchar_t>*)(params + 8) = GroupName;
			*(ScriptArray<wchar_t>*)(params + 20) = SeqName;
			*(class SoundCue**)(params + 32) = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientMessage(ScriptArray<wchar_t> S, ScriptName Type, float MsgLifeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientMessage");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = S;
			*(ScriptName*)(params + 12) = Type;
			*(float*)(params + 20) = MsgLifeTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanCommunicate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool AllowTTSMessageFrom(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AllowTTSMessageFrom");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class SoundCue* CreateTTSSoundCue(ScriptArray<wchar_t> StrToSpeak, class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CreateTTSSoundCue");
			byte* params = (byte*)malloc(20);
			*(ScriptArray<wchar_t>*)params = StrToSpeak;
			*(class PlayerReplicationInfo**)(params + 12) = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SoundCue**)(params + 16);
			free(params);
			return returnVal;
		}
		void Talk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Talk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamTalk()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TeamTalk");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpeakTTS(ScriptArray<wchar_t> S, class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SpeakTTS");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = S;
			*(class PlayerReplicationInfo**)(params + 12) = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamMessage(class PlayerReplicationInfo* PRI, ScriptArray<wchar_t> S, ScriptName Type, float MsgLifeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TeamMessage");
			byte* params = (byte*)malloc(28);
			*(class PlayerReplicationInfo**)params = PRI;
			*(ScriptArray<wchar_t>*)(params + 4) = S;
			*(ScriptName*)(params + 16) = Type;
			*(float*)(params + 24) = MsgLifeTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayBeepSound()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PlayBeepSound");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterOnlineDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RegisterOnlineDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPartyMemberListChanged(bool bJoinedOrLeft, ScriptArray<wchar_t> PlayerName, UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnPartyMemberListChanged");
			byte* params = (byte*)malloc(24);
			*(bool*)params = bJoinedOrLeft;
			*(ScriptArray<wchar_t>*)(params + 4) = PlayerName;
			*(UniqueNetId*)(params + 16) = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnPartyMembersInfoChanged(ScriptArray<wchar_t> PlayerName, UniqueNetId PlayerID, int CustomData1, int CustomData2, int CustomData3, int CustomData4)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnPartyMembersInfoChanged");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = PlayerName;
			*(UniqueNetId*)(params + 12) = PlayerID;
			*(int*)(params + 20) = CustomData1;
			*(int*)(params + 24) = CustomData2;
			*(int*)(params + 28) = CustomData3;
			*(int*)(params + 32) = CustomData4;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearOnlineDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClearOnlineDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CleanupPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FixFOV()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FixFOV");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetFOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetFOV()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ResetFOV");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowTextMessage(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AllowTextMessage");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void Say(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Say");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSay(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerSay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientAdminMessage(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientAdminMessage");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void TeamSay(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TeamSay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerTeamSay(ScriptArray<wchar_t> msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerTeamSay");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PreClientTravel(ScriptArray<wchar_t> PendingURL, byte TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PreClientTravel");
			byte* params = (byte*)malloc(17);
			*(ScriptArray<wchar_t>*)params = PendingURL;
			*(params + 12) = TravelType;
			*(bool*)(params + 16) = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class UIInteraction* GetUIController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetUIController");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class UIInteraction**)params;
			free(params);
			return returnVal;
		}
		void Camera(ScriptName NewMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Camera");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerCamera(ScriptName NewMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerCamera");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetCameraMode");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetCameraMode");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetCameraMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ResetCameraMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetCameraFade(bool bEnableFading, Color FadeColor, Vector2D FadeAlpha, float FadeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetCameraFade");
			byte* params = (byte*)malloc(20);
			*(bool*)params = bEnableFading;
			*(Color*)(params + 4) = FadeColor;
			*(Vector2D*)(params + 8) = FadeAlpha;
			*(float*)(params + 16) = FadeTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool UsingFirstPersonCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UsingFirstPersonCamera");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ForceDeathUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ForceDeathUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DualServerMove(float TimeStamp0, Vector InAccel0, byte PendingFlags, int View0, float TimeStamp, Vector InAccel, Vector ClientLoc, byte NewFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DualServerMove");
			byte* params = (byte*)malloc(55);
			*(float*)params = TimeStamp0;
			*(Vector*)(params + 4) = InAccel0;
			*(params + 16) = PendingFlags;
			*(int*)(params + 20) = View0;
			*(float*)(params + 24) = TimeStamp;
			*(Vector*)(params + 28) = InAccel;
			*(Vector*)(params + 40) = ClientLoc;
			*(params + 52) = NewFlags;
			*(params + 53) = ClientRoll;
			*(int*)(params + 56) = View;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OldServerMove(float OldTimeStamp, byte OldAccelX, byte OldAccelY, byte OldAccelZ, byte OldMoveFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OldServerMove");
			byte* params = (byte*)malloc(8);
			*(float*)params = OldTimeStamp;
			*(params + 4) = OldAccelX;
			*(params + 5) = OldAccelY;
			*(params + 6) = OldAccelZ;
			*(params + 7) = OldMoveFlags;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetServerMoveDeltaTime(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetServerMoveDeltaTime");
			byte* params = (byte*)malloc(8);
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		void ServerMoveHandleClientError(float TimeStamp, Vector Accel, Vector ClientLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerMoveHandleClientError");
			byte* params = (byte*)malloc(28);
			*(float*)params = TimeStamp;
			*(Vector*)(params + 4) = Accel;
			*(Vector*)(params + 16) = ClientLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerMove(float TimeStamp, Vector InAccel, Vector ClientLoc, byte MoveFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerMove");
			byte* params = (byte*)malloc(34);
			*(float*)params = TimeStamp;
			*(Vector*)(params + 4) = InAccel;
			*(Vector*)(params + 16) = ClientLoc;
			*(params + 28) = MoveFlags;
			*(params + 29) = ClientRoll;
			*(int*)(params + 32) = View;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SendClientAdjustment()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SendClientAdjustment");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerDrive(float InForward, float InStrafe, float aUp, bool InJump, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerDrive");
			byte* params = (byte*)malloc(20);
			*(float*)params = InForward;
			*(float*)(params + 4) = InStrafe;
			*(float*)(params + 8) = aUp;
			*(bool*)(params + 12) = InJump;
			*(int*)(params + 16) = View;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessDrive(float InForward, float InStrafe, float InUp, bool InJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ProcessDrive");
			byte* params = (byte*)malloc(16);
			*(float*)params = InForward;
			*(float*)(params + 4) = InStrafe;
			*(float*)(params + 8) = InUp;
			*(bool*)(params + 12) = InJump;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessMove(float DeltaTime, Vector newAccel, byte DoubleClickMove, Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ProcessMove");
			byte* params = (byte*)malloc(29);
			*(float*)params = DeltaTime;
			*(Vector*)(params + 4) = newAccel;
			*(params + 16) = DoubleClickMove;
			*(Rotator*)(params + 20) = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void MoveAutonomous(float DeltaTime, byte CompressedFlags, Vector newAccel, Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.MoveAutonomous");
			byte* params = (byte*)malloc(29);
			*(float*)params = DeltaTime;
			*(params + 4) = CompressedFlags;
			*(Vector*)(params + 8) = newAccel;
			*(Rotator*)(params + 20) = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void VeryShortClientAdjustPosition(float TimeStamp, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.VeryShortClientAdjustPosition");
			byte* params = (byte*)malloc(20);
			*(float*)params = TimeStamp;
			*(float*)(params + 4) = NewLocX;
			*(float*)(params + 8) = NewLocY;
			*(float*)(params + 12) = NewLocZ;
			*(class Actor**)(params + 16) = NewBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShortClientAdjustPosition(float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ShortClientAdjustPosition");
			byte* params = (byte*)malloc(29);
			*(float*)params = TimeStamp;
			*(ScriptName*)(params + 4) = NewState;
			*(params + 12) = newPhysics;
			*(float*)(params + 16) = NewLocX;
			*(float*)(params + 20) = NewLocY;
			*(float*)(params + 24) = NewLocZ;
			*(class Actor**)(params + 28) = NewBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientCapBandwidth(int Cap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientCapBandwidth");
			byte* params = (byte*)malloc(4);
			*(int*)params = Cap;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientAckGoodMove(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientAckGoodMove");
			byte* params = (byte*)malloc(4);
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdatePing(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdatePing");
			byte* params = (byte*)malloc(4);
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientAdjustPosition(float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientAdjustPosition");
			byte* params = (byte*)malloc(41);
			*(float*)params = TimeStamp;
			*(ScriptName*)(params + 4) = NewState;
			*(params + 12) = newPhysics;
			*(float*)(params + 16) = NewLocX;
			*(float*)(params + 20) = NewLocY;
			*(float*)(params + 24) = NewLocZ;
			*(float*)(params + 28) = NewVelX;
			*(float*)(params + 32) = NewVelY;
			*(float*)(params + 36) = NewVelZ;
			*(class Actor**)(params + 40) = NewBase;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LongClientAdjustPosition(float TimeStamp, ScriptName NewState, byte newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LongClientAdjustPosition");
			byte* params = (byte*)malloc(53);
			*(float*)params = TimeStamp;
			*(ScriptName*)(params + 4) = NewState;
			*(params + 12) = newPhysics;
			*(float*)(params + 16) = NewLocX;
			*(float*)(params + 20) = NewLocY;
			*(float*)(params + 24) = NewLocZ;
			*(float*)(params + 28) = NewVelX;
			*(float*)(params + 32) = NewVelY;
			*(float*)(params + 36) = NewVelZ;
			*(class Actor**)(params + 40) = NewBase;
			*(float*)(params + 44) = NewFloorX;
			*(float*)(params + 48) = NewFloorY;
			*(float*)(params + 52) = NewFloorZ;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateStateFromAdjustment(ScriptName NewState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdateStateFromAdjustment");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerUpdatePing(int NewPing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUpdatePing");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewPing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearAckedMoves()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClearAckedMoves");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientUpdatePosition()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientUpdatePosition");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class SavedMove* GetFreeMove()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetFreeMove");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class SavedMove**)params;
			free(params);
			return returnVal;
		}
		int CompressAccel(int C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CompressAccel");
			byte* params = (byte*)malloc(8);
			*(int*)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void ReplicateMove(float DeltaTime, Vector newAccel, byte DoubleClickMove, Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ReplicateMove");
			byte* params = (byte*)malloc(29);
			*(float*)params = DeltaTime;
			*(Vector*)(params + 4) = newAccel;
			*(params + 16) = DoubleClickMove;
			*(Rotator*)(params + 20) = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CallServerMove(class SavedMove* NewMove, Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CallServerMove");
			byte* params = (byte*)malloc(25);
			*(class SavedMove**)params = NewMove;
			*(Vector*)(params + 4) = ClientLoc;
			*(params + 16) = ClientRoll;
			*(int*)(params + 20) = View;
			*(class SavedMove**)(params + 24) = OldMove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void HandleWalking()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HandleWalking");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRestartGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerRestartGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RestartLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PauseRumbleForAllPlayers(bool bShouldPauseRumble)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PauseRumbleForAllPlayers");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bShouldPauseRumble;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CanUnpause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanUnpause");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SetPause(bool bPause, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetPause");
			byte* params = (byte*)malloc(20);
			*(bool*)params = bPause;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 4) = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsPaused()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPaused");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Pause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Pause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerPause");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConditionalPause(bool bDesiredPauseState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ConditionalPause");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDesiredPauseState;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ThrowWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ThrowWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerThrowWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerThrowWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PrevWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NextWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.StartFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.StopFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StartAltFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.StartAltFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void StopAltFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.StopAltFire");
			byte* params = (byte*)malloc(1);
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetTriggerUseList(float interactDistanceToCheck, float crosshairDist, float minDot, bool bUsuableOnly, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& out_useList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetTriggerUseList");
			byte* params = (byte*)malloc(28);
			*(float*)params = interactDistanceToCheck;
			*(float*)(params + 4) = crosshairDist;
			*(float*)(params + 8) = minDot;
			*(bool*)(params + 12) = bUsuableOnly;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16) = out_useList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_useList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 16);
			free(params);
		}
		bool Use()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Use");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool ServerUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUse");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PerformedUseAction");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool FindVehicleToDrive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FindVehicleToDrive");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TriggerInteracted");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Suicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Suicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSuicide()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerSuicide");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetName(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerChangeName(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerChangeName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SwitchTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeTeam(ScriptArray<wchar_t> TeamName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ChangeTeam");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = TeamName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerChangeTeam(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerChangeTeam");
			byte* params = (byte*)malloc(4);
			*(int*)params = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetProgressMessage(byte MessageType, ScriptArray<wchar_t> Message, ScriptArray<wchar_t> Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetProgressMessage");
			byte* params = (byte*)malloc(29);
			*params = MessageType;
			*(ScriptArray<wchar_t>*)(params + 4) = Message;
			*(ScriptArray<wchar_t>*)(params + 16) = Title;
			*(bool*)(params + 28) = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Restart");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerNotifyLoadedWorld(ScriptName WorldPackageName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerNotifyLoadedWorld");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = WorldPackageName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyLoadedWorld(ScriptName WorldPackageName, bool bFinalDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyLoadedWorld");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = WorldPackageName;
			*(bool*)(params + 8) = bFinalDest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HasClientLoadedCurrentWorld()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HasClientLoadedCurrentWorld");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ForceSingleNetUpdateFor(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ForceSingleNetUpdateFor");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EnterStartState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.EnterStartState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientRestart");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GameHasEnded");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = EndGameFocus;
			*(bool*)(params + 4) = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientGameEnded");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = EndGameFocus;
			*(bool*)(params + 4) = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyChangedWeapon(class Weapon* PreviousWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyChangedWeapon");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = PreviousWeapon;
			*(class Weapon**)(params + 4) = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PlayerTick");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayerMove(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PlayerMove");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AimingHelp");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void CameraLookAtFinished(class SeqAct_CameraLookAt* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CameraLookAtFinished");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_CameraLookAt**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetAdjustedAimFor");
			byte* params = (byte*)malloc(28);
			*(class Weapon**)params = W;
			*(Vector*)(params + 4) = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 16);
			free(params);
			return returnVal;
		}
		float AimHelpDot(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AimHelpDot");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NotifyLanded(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyLanded");
			byte* params = (byte*)malloc(20);
			*(Vector*)params = HitNormal;
			*(class Actor**)(params + 12) = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AdjustFOV(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AdjustFOV");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsLocalPlayerController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsLocalPlayerController");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetViewTarget(class Actor* NewViewTarget, ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetViewTarget");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = NewViewTarget;
			*(ViewTargetTransitionParams*)(params + 4) = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetViewTargetWithBlend(class Actor* NewViewTarget, float BlendTime, byte BlendFunc, float BlendExp, bool bLockOutgoing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetViewTargetWithBlend");
			byte* params = (byte*)malloc(17);
			*(class Actor**)params = NewViewTarget;
			*(float*)(params + 4) = BlendTime;
			*(params + 8) = BlendFunc;
			*(float*)(params + 12) = BlendExp;
			*(bool*)(params + 16) = bLockOutgoing;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetViewTarget(class Actor* A, ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetViewTarget");
			byte* params = (byte*)malloc(20);
			*(class Actor**)params = A;
			*(ViewTargetTransitionParams*)(params + 4) = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerVerifyViewTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerVerifyViewTarget");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnPlayerCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SpawnPlayerCamera");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPlayerViewPoint");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = out_Location;
			*(Rotator*)(params + 12) = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)(params + 12);
			free(params);
		}
		void ViewShake(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ViewShake");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdateRotation");
			byte* params = (byte*)malloc(4);
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ProcessViewRotation");
			byte* params = (byte*)malloc(28);
			*(float*)params = DeltaTime;
			*(Rotator*)(params + 4) = out_ViewRotation;
			*(Rotator*)(params + 16) = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_ViewRotation = *(Rotator*)(params + 4);
			free(params);
		}
		Rotator LimitViewRotation(Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LimitViewRotation");
			byte* params = (byte*)malloc(32);
			*(Rotator*)params = ViewRotation;
			*(float*)(params + 12) = ViewPitchMin;
			*(float*)(params + 16) = ViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(Rotator*)(params + 20);
			free(params);
			return returnVal;
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CheckJumpOrDuck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsSpectating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsSpectating");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ServerSetSpectatorLocation(Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerSetSpectatorLocation");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewNextPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerViewNextPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerViewPrevPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerViewPrevPlayer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewAPlayer(int Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ViewAPlayer");
			byte* params = (byte*)malloc(4);
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerViewSelf(ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerViewSelf");
			byte* params = (byte*)malloc(16);
			*(ViewTargetTransitionParams*)params = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsWaiting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsWaiting");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CanRestartPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanRestartPlayer");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DrawHUD");
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggleInput(class SeqAct_ToggleInput* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnToggleInput");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ToggleInput**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientIgnoreMoveInput(bool bIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientIgnoreMoveInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientIgnoreLookInput(bool bIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientIgnoreLookInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = out_YL;
			*(float*)(params + 8) = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_YL = *(float*)(params + 4);
			out_YPos = *(float*)(params + 8);
			free(params);
		}
		void OnDrawText(class SeqAct_DrawText* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnDrawText");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_DrawText**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientDrawKismetText(KismetDrawTextInfo DrawTextInfo, float DisplayTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientDrawKismetText");
			byte* params = (byte*)malloc(56);
			*(KismetDrawTextInfo*)params = DrawTextInfo;
			*(float*)(params + 52) = DisplayTime;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientClearKismetText(Vector2D MessageOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientClearKismetText");
			byte* params = (byte*)malloc(8);
			*(Vector2D*)params = MessageOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetCameraTarget(class SeqAct_SetCameraTarget* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnSetCameraTarget");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetCameraTarget**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnToggleHUD(class SeqAct_ToggleHUD* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnToggleHUD");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ToggleHUD**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyTakeHit");
			byte* params = (byte*)malloc(36);
			*(class Controller**)params = InstigatedBy;
			*(Vector*)(params + 4) = HitLocation;
			*(int*)(params + 16) = Damage;
			*(ScriptClass**)(params + 20) = DamageType;
			*(Vector*)(params + 24) = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnForceFeedback(class SeqAct_ForceFeedback* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnForceFeedback");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ForceFeedback**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientStopForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStopForceFeedbackWaveform");
			byte* params = (byte*)malloc(4);
			*(class ForceFeedbackWaveform**)params = FFWaveform;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayRumble(class AnimNotify_Rumble* TheAnimNotify)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PlayRumble");
			byte* params = (byte*)malloc(4);
			*(class AnimNotify_Rumble**)params = TheAnimNotify;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayForceFeedbackWaveform");
			byte* params = (byte*)malloc(8);
			*(class ForceFeedbackWaveform**)params = FFWaveform;
			*(class Actor**)(params + 4) = FFWaveformInstigator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsForceFeedbackAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsForceFeedbackAllowed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void OnToggleCinematicMode(class SeqAct_ToggleCinematicMode* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnToggleCinematicMode");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ToggleCinematicMode**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCinematicMode(bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsButtons)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetCinematicMode");
			byte* params = (byte*)malloc(24);
			*(bool*)params = bInCinematicMode;
			*(bool*)(params + 4) = bHidePlayer;
			*(bool*)(params + 8) = bAffectsHUD;
			*(bool*)(params + 12) = bAffectsMovement;
			*(bool*)(params + 16) = bAffectsTurning;
			*(bool*)(params + 20) = bAffectsButtons;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetCinematicMode(bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsHUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetCinematicMode");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bInCinematicMode;
			*(bool*)(params + 4) = bAffectsMovement;
			*(bool*)(params + 8) = bAffectsTurning;
			*(bool*)(params + 12) = bAffectsHUD;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IgnoreMoveInput(bool bNewMoveInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IgnoreMoveInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewMoveInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsMoveInputIgnored()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsMoveInputIgnored");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void IgnoreLookInput(bool bNewLookInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IgnoreLookInput");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNewLookInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsLookInputIgnored()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsLookInputIgnored");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ResetPlayerMovementInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ResetPlayerMovementInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnConsoleCommand(class SeqAct_ConsoleCommand* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnConsoleCommand");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_ConsoleCommand**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientForceGarbageCollection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientForceGarbageCollection");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LevelStreamingStatusChanged(class LevelStreaming* LevelObject, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LevelStreamingStatusChanged");
			byte* params = (byte*)malloc(16);
			*(class LevelStreaming**)params = LevelObject;
			*(bool*)(params + 4) = bNewShouldBeLoaded;
			*(bool*)(params + 8) = bNewShouldBeVisible;
			*(bool*)(params + 12) = bNewShouldBlockOnLoad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientUpdateLevelStreamingStatus(ScriptName PackageName, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientUpdateLevelStreamingStatus");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = PackageName;
			*(bool*)(params + 8) = bNewShouldBeLoaded;
			*(bool*)(params + 12) = bNewShouldBeVisible;
			*(bool*)(params + 16) = bNewShouldBlockOnLoad;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerUpdateLevelVisibility(ScriptName PackageName, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUpdateLevelVisibility");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = PackageName;
			*(bool*)(params + 8) = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPrepareMapChange(ScriptName LevelName, bool bFirst, bool bLast)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPrepareMapChange");
			byte* params = (byte*)malloc(16);
			*(ScriptName*)params = LevelName;
			*(bool*)(params + 8) = bFirst;
			*(bool*)(params + 12) = bLast;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DelayedPrepareMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DelayedPrepareMapChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientCommitMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientCommitMapChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientCancelPendingMapChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientCancelPendingMapChange");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientFlushLevelStreaming()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientFlushLevelStreaming");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetBlockOnAsyncLoading()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetBlockOnAsyncLoading");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPlayerMuted(UniqueNetId& Sender)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPlayerMuted");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = Sender;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Sender = *(UniqueNetId*)params;
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void GetSeamlessTravelActorList(bool bToEntry, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetSeamlessTravelActorList");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bToEntry;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ActorList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void SeamlessTravelTo(class PlayerController* NewPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SeamlessTravelTo");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = NewPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeamlessTravelFrom(class PlayerController* OldPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SeamlessTravelFrom");
			byte* params = (byte*)malloc(4);
			*(class PlayerController**)params = OldPC;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetOnlineStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetOnlineStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerController* GetPlayerControllerFromNetId(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPlayerControllerFromNetId");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerController**)(params + 8);
			free(params);
			return returnVal;
		}
		void ClientVoiceHandshakeComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientVoiceHandshakeComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientMutePlayer(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientMutePlayer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientUnmutePlayer(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientUnmutePlayer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GameplayMutePlayer(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GameplayMutePlayer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GameplayUnmutePlayer(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GameplayUnmutePlayer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerMutePlayer(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerMutePlayer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerUnmutePlayer(UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUnmutePlayer");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyDirectorControl(bool bNowControlling)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyDirectorControl");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bNowControlling;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetShowSubtitles(bool bValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetShowSubtitles");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsShowingSubtitles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsShowingSubtitles");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClientWasKicked()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientWasKicked");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRegisterForArbitration()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientRegisterForArbitration");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnArbitrationRegisterComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnArbitrationRegisterComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerRegisteredForArbitration(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerRegisteredForArbitration");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnGameInviteAccepted(OnlineGameSearchResult& InviteResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnGameInviteAccepted");
			byte* params = (byte*)malloc(8);
			*(OnlineGameSearchResult*)params = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			InviteResult = *(OnlineGameSearchResult*)params;
			free(params);
		}
		bool InviteHasEnoughSpace(class OnlineGameSettings* InviteSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.InviteHasEnoughSpace");
			byte* params = (byte*)malloc(8);
			*(class OnlineGameSettings**)params = InviteSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CanAllPlayersPlayOnline()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanAllPlayersPlayOnline");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void ClearInviteDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClearInviteDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnEndForInviteComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnEndForInviteComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnDestroyForInviteComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnDestroyForInviteComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> ModifyClientURL(ScriptArray<wchar_t> URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ModifyClientURL");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnInviteJoinComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnInviteJoinComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyInviteFailed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyInviteFailed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotAllPlayersCanJoinInvite()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyNotAllPlayersCanJoinInvite");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotEnoughSpaceInInvite()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyNotEnoughSpaceInInvite");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientArbitratedMatchEnded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientArbitratedMatchEnded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWriteOnlinePlayerScores(int LeaderboardId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientWriteOnlinePlayerScores");
			byte* params = (byte*)malloc(4);
			*(int*)params = LeaderboardId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientWriteLeaderboardStats(ScriptClass* OnlineStatsWriteClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientWriteLeaderboardStats");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = OnlineStatsWriteClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetHostUniqueId(UniqueNetId InHostId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetHostUniqueId");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = InHostId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientStopNetworkedVoice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStopNetworkedVoice");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientStartNetworkedVoice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStartNetworkedVoice");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnDestroy(class SeqAct_Destroy* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnDestroy");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_Destroy**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DrawDebugTextList(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DrawDebugTextList");
			byte* params = (byte*)malloc(8);
			*(class Canvas**)params = Canvas;
			*(float*)(params + 4) = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddDebugText(ScriptArray<wchar_t> DebugText, class Actor* SrcActor, float Duration, Vector Offset, Vector DesiredOffset, Color TextColor, bool bSkipOverwriteCheck, bool bAbsoluteLocation, bool bKeepAttachedToActor, class Font* InFont)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AddDebugText");
			byte* params = (byte*)malloc(64);
			*(ScriptArray<wchar_t>*)params = DebugText;
			*(class Actor**)(params + 12) = SrcActor;
			*(float*)(params + 16) = Duration;
			*(Vector*)(params + 20) = Offset;
			*(Vector*)(params + 32) = DesiredOffset;
			*(Color*)(params + 44) = TextColor;
			*(bool*)(params + 48) = bSkipOverwriteCheck;
			*(bool*)(params + 52) = bAbsoluteLocation;
			*(bool*)(params + 56) = bKeepAttachedToActor;
			*(class Font**)(params + 60) = InFont;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveDebugText(class Actor* SrcActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemoveDebugText");
			byte* params = (byte*)malloc(4);
			*(class Actor**)params = SrcActor;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveAllDebugStrings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemoveAllDebugStrings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRegisterHostStatGuid(ScriptArray<wchar_t> StatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientRegisterHostStatGuid");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = StatGuid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnRegisterHostStatGuidComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnRegisterHostStatGuidComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerRegisterClientStatGuid(ScriptArray<wchar_t> StatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerRegisterClientStatGuid");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = StatGuid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientStartOnlineGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStartOnlineGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientEndOnlineGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientEndOnlineGame");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanViewUserCreatedContent()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanViewUserCreatedContent");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void IncrementNumberOfMatchesPlayed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IncrementNumberOfMatchesPlayed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SoakPause(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SoakPause");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientTravelToSession(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientTravelToSession");
			byte* params = (byte*)malloc(13);
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)(params + 8) = SearchClass;
			*(params + 12) = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnJoinTravelToSessionComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnJoinTravelToSessionComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientReturnToParty(UniqueNetId RequestingPlayerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientReturnToParty");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = RequestingPlayerId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsSplitscreenPlayer(int& out_SplitscreenPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsSplitscreenPlayer");
			byte* params = (byte*)malloc(8);
			*(int*)params = out_SplitscreenPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			out_SplitscreenPlayerIndex = *(int*)params;
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class PlayerReplicationInfo* GetSplitscreenPlayerByIndex(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetSplitscreenPlayerByIndex");
			byte* params = (byte*)malloc(8);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerReplicationInfo**)(params + 4);
			free(params);
			return returnVal;
		}
		int GetSplitscreenPlayerCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetSplitscreenPlayerCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void ClientControlMovieTexture(class TextureMovie* MovieTexture, byte Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientControlMovieTexture");
			byte* params = (byte*)malloc(5);
			*(class TextureMovie**)params = MovieTexture;
			*(params + 4) = Mode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetForceMipLevelsToBeResident(class MaterialInterface* Material, float ForceDuration, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetForceMipLevelsToBeResident");
			byte* params = (byte*)malloc(12);
			*(class MaterialInterface**)params = Material;
			*(float*)(params + 4) = ForceDuration;
			*(int*)(params + 8) = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPrestreamTextures(class Actor* ForcedActor, float ForceDuration, bool bEnableStreaming, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPrestreamTextures");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = ForcedActor;
			*(float*)(params + 4) = ForceDuration;
			*(bool*)(params + 8) = bEnableStreaming;
			*(int*)(params + 12) = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsPartyLeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPartyLeader");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPartyMapName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPartyMapName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetPartyGameTypeName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPartyGameTypeName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool GetAchievementProgression(int AchievementId, float& CurrentValue, float& MaxValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetAchievementProgression");
			byte* params = (byte*)malloc(16);
			*(int*)params = AchievementId;
			*(float*)(params + 4) = CurrentValue;
			*(float*)(params + 8) = MaxValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			CurrentValue = *(float*)(params + 4);
			MaxValue = *(float*)(params + 8);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnFlyThroughHasEnded(class SeqAct_FlyThroughHasEnded* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnFlyThroughHasEnded");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_FlyThroughHasEnded**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Sentinel_SetupForGamebasedTravelTheWorld()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Sentinel_SetupForGamebasedTravelTheWorld");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Sentinel_PreAcquireTravelTheWorldPoints()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Sentinel_PreAcquireTravelTheWorldPoints");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Sentinel_PostAcquireTravelTheWorldPoints()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Sentinel_PostAcquireTravelTheWorldPoints");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InputMatchDelegate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.InputMatchDelegate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoForceFeedbackForScreenShake(class CameraShake* ShakeData, float ShakeScale)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DoForceFeedbackForScreenShake");
			byte* params = (byte*)malloc(8);
			*(class CameraShake**)params = ShakeData;
			*(float*)(params + 4) = ShakeScale;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayCameraShake(class CameraShake* Shake, float Scale, bool bTryForceFeedback, byte PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayCameraShake");
			byte* params = (byte*)malloc(25);
			*(class CameraShake**)params = Shake;
			*(float*)(params + 4) = Scale;
			*(bool*)(params + 8) = bTryForceFeedback;
			*(params + 12) = PlaySpace;
			*(Rotator*)(params + 16) = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientStopCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStopCameraShake");
			byte* params = (byte*)malloc(4);
			*(class CameraShake**)params = Shake;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnCameraShake(class SeqAct_CameraShake* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnCameraShake");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_CameraShake**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientPlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, byte Space, Rotator CustomPlaySpace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayCameraAnim");
			byte* params = (byte*)malloc(41);
			*(class CameraAnim**)params = AnimToPlay;
			*(float*)(params + 4) = Scale;
			*(float*)(params + 8) = Rate;
			*(float*)(params + 12) = BlendInTime;
			*(float*)(params + 16) = BlendOutTime;
			*(bool*)(params + 20) = bLoop;
			*(bool*)(params + 24) = bRandomStartTime;
			*(params + 28) = Space;
			*(Rotator*)(params + 32) = CustomPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientStopCameraAnim(class CameraAnim* AnimToStop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStopCameraAnim");
			byte* params = (byte*)malloc(4);
			*(class CameraAnim**)params = AnimToStop;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSpawnCameraLensEffect(ScriptClass* LensEffectEmitterClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSpawnCameraLensEffect");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = LensEffectEmitterClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnSetSoundMode(class SeqAct_SetSoundMode* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnSetSoundMode");
			byte* params = (byte*)malloc(4);
			*(class SeqAct_SetSoundMode**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool HasPeerConnection(UniqueNetId& PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HasPeerConnection");
			byte* params = (byte*)malloc(12);
			*(UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PeerNetId = *(UniqueNetId*)params;
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void BugItGo(float X, float Y, float Z, int Pitch, int Yaw, int Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItGo");
			byte* params = (byte*)malloc(24);
			*(float*)params = X;
			*(float*)(params + 4) = Y;
			*(float*)(params + 8) = Z;
			*(int*)(params + 12) = Pitch;
			*(int*)(params + 16) = Yaw;
			*(int*)(params + 20) = Roll;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BugItGoString(ScriptArray<wchar_t> TheLocation, ScriptArray<wchar_t> TheRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItGoString");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = TheLocation;
			*(ScriptArray<wchar_t>*)(params + 12) = TheRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BugItWorker(Vector TheLocation, Rotator TheRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItWorker");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = TheLocation;
			*(Rotator*)(params + 12) = TheRotation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BugIt(ScriptArray<wchar_t> ScreenShotDescription)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugIt");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ScreenShotDescription;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogOutBugItGoToLogFile(ScriptArray<wchar_t> InScreenShotDesc, ScriptArray<wchar_t> InGoString, ScriptArray<wchar_t> InLocString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LogOutBugItGoToLogFile");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = InScreenShotDesc;
			*(ScriptArray<wchar_t>*)(params + 12) = InGoString;
			*(ScriptArray<wchar_t>*)(params + 24) = InLocString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogLoc()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LogLoc");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BugItAI(ScriptArray<wchar_t> ScreenShotDescription)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItAI");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ScreenShotDescription;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogOutBugItAIGoToLogFile(ScriptArray<wchar_t> InScreenShotDesc, ScriptArray<wchar_t> InGoString, ScriptArray<wchar_t> InLocString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LogOutBugItAIGoToLogFile");
			byte* params = (byte*)malloc(36);
			*(ScriptArray<wchar_t>*)params = InScreenShotDesc;
			*(ScriptArray<wchar_t>*)(params + 12) = InGoString;
			*(ScriptArray<wchar_t>*)(params + 24) = InLocString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void BugItStringCreator(Vector& ViewLocation, Rotator& ViewRotation, ScriptArray<wchar_t>& GoString, ScriptArray<wchar_t>& LocString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItStringCreator");
			byte* params = (byte*)malloc(48);
			*(Vector*)params = ViewLocation;
			*(Rotator*)(params + 12) = ViewRotation;
			*(ScriptArray<wchar_t>*)(params + 24) = GoString;
			*(ScriptArray<wchar_t>*)(params + 36) = LocString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ViewLocation = *(Vector*)params;
			ViewRotation = *(Rotator*)(params + 12);
			GoString = *(ScriptArray<wchar_t>*)(params + 24);
			LocString = *(ScriptArray<wchar_t>*)(params + 36);
			free(params);
		}
		void OnEngineInitialTick()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnEngineInitialTick");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableDebugAI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DisableDebugAI");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedGameClass(ScriptClass* GameClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ReceivedGameClass");
			byte* params = (byte*)malloc(4);
			*(ScriptClass**)params = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
