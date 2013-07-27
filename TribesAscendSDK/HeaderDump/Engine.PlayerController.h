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
#include "Engine.Trigger.h"
#include "Engine.OnlineGameSearch.h"
#include "Engine.PlayerInput.h"
#include "Engine.SeqAct_ControlMovieTexture.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.Interaction.h"
#include "Engine.ForceFeedbackManager.h"
#include "Engine.UIDataStore_OnlinePlayerData.h"
#include "Core.Object.h"
#include "Engine.NetConnection.h"
#include "Engine.CheatManager.h"
#include "Engine.InterpTrackInstDirector.h"
#include "Engine.Canvas.h"
#include "Engine.Inventory.h"
#include "Engine.SeqAct_DrawText.h"
#include "Engine.SoundCue.h"
#include "Engine.OnlineGameSettings.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.SeqAct_ConsoleCommand.h"
#include "Engine.UIInteraction.h"
#include "Engine.SeqAct_ToggleInput.h"
#include "Engine.MaterialInterface.h"
#include "Engine.SeqAct_SetCameraTarget.h"
#include "Engine.SeqAct_ToggleHUD.h"
#include "Engine.SeqAct_ForceFeedback.h"
#include "Engine.ForceFeedbackWaveform.h"
#include "Engine.AnimNotify_Rumble.h"
#include "Engine.SeqAct_ToggleCinematicMode.h"
#include "Engine.LevelStreaming.h"
#include "Engine.Font.h"
#include "Engine.TextureMovie.h"
#include "Engine.SeqAct_FlyThroughHasEnded.h"
#include "Engine.CameraShake.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class PlayerController : public Controller
	{
	public:
		static const float MAXCLIENTUPDATEINTERVAL;
		static const float CLIENTADJUSTUPDATECOST;
		static const float MAXVEHICLEPOSITIONERRORSQUARED;
		static const float MAXNEARZEROVELOCITYSQUARED;
		static const float MAXPOSITIONERRORSQUARED;
		enum EProgressMessageType : byte
		{
			PMT_Clear = 0,
			PMT_Information = 1,
			PMT_AdminMessage = 2,
			PMT_DownloadProgress = 3,
			PMT_ConnectionFailure = 4,
			PMT_PeerConnectionFailure = 5,
			PMT_PeerHostMigrationFailure = 6,
			PMT_SocketFailure = 7,
			PMT_MAX = 8,
		};
		enum EInputMatchAction : byte
		{
			IMA_GreaterThan = 0,
			IMA_LessThan = 1,
			IMA_MAX = 2,
		};
		enum EInputTypes : byte
		{
			IT_XAxis = 0,
			IT_YAxis = 1,
			IT_MAX = 2,
		};
		class DebugTextInfo
		{
		public:
			ADD_OBJECT(Actor, SrcActor, 0)
			ADD_STRUCT(float, TimeRemaining, 40)
			ADD_OBJECT(Font, Font, 68)
			ADD_BOOL(bAbsoluteLocation, 52, 0x1)
			ADD_STRUCT(Object::Vector, SrcActorOffset, 4)
			ADD_STRUCT(Object::Vector, SrcActorDesiredOffset, 16)
			ADD_STRUCT(float, Duration, 44)
			ADD_BOOL(bKeepAttachedToActor, 52, 0x2)
			ADD_STRUCT(Object::Vector, OrigActorLocation, 56)
			ADD_STRUCT(Object::Color, TextColor, 48)
			ADD_STRUCT(ScriptString*, DebugText, 28)
		};
		class ConnectedPeerInfo
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PlayerID, 0)
			ADD_STRUCT(OnlineSubsystem::ENATType, NatType, 8)
			ADD_BOOL(bLostConnectionToHost, 12, 0x1)
		};
		class ClientAdjustment
		{
		public:
			ADD_STRUCT(Actor::EPhysics, newPhysics, 4)
			ADD_STRUCT(Object::Vector, NewLoc, 8)
			ADD_STRUCT(Object::Vector, NewVel, 20)
			ADD_OBJECT(Actor, NewBase, 32)
			ADD_STRUCT(Object::Vector, NewFloor, 36)
			ADD_STRUCT(float, TimeStamp, 0)
			ADD_STRUCT(byte, bAckGoodMove, 48)
		};
		class InputEntry
		{
		public:
			ADD_STRUCT(PlayerController::EInputTypes, Type, 0)
			ADD_STRUCT(float, Value, 4)
			ADD_STRUCT(float, TimeDelta, 8)
			ADD_STRUCT(PlayerController::EInputMatchAction, Action, 12)
		};
		class InputMatchRequest
		{
		public:
			ADD_STRUCT(ScriptArray<PlayerController::InputEntry>, Inputs, 0)
			ADD_OBJECT(Actor, MatchActor, 12)
			ADD_STRUCT(ScriptName, MatchFuncName, 16)
			ADD_STRUCT(ScriptName, FailedFuncName, 36)
			ADD_STRUCT(ScriptName, RequestName, 44)
			ADD_STRUCT(int, MatchIdx, 52)
			ADD_STRUCT(float, LastMatchTime, 56)
		};
		ADD_STRUCT(float, LODDistanceFactor, 960)
		ADD_OBJECT(Player, Player, 900)
		ADD_OBJECT(Actor, ViewTarget, 936)
		ADD_OBJECT(Camera, PlayerCamera, 904)
		ADD_BOOL(bIsExternalUIOpen, 912, 0x400000)
		ADD_BOOL(bPendingDestroy, 912, 0x200)
		ADD_BOOL(bIsControllerConnected, 912, 0x800000)
		ADD_OBJECT(CoverReplicator, MyCoverReplicator, 1352)
		ADD_STRUCT(float, MaxTimeMargin, 1044)
		ADD_STRUCT(float, MaxResponseTime, 916)
		ADD_STRUCT(float, LastActiveTime, 1048)
		ADD_OBJECT(OnlineSubsystem, OnlineSub, 1248)
		ADD_STRUCT(ScriptArray<PlayerController::ConnectedPeerInfo>, ConnectedPeers, 1220)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, BestNextHostPeers, 1232)
		ADD_OBJECT(OnlineGameSearch, MigratedSearchToJoin, 1244)
		ADD_STRUCT(float, TimeMargin, 1036)
		ADD_BOOL(bShortConnectTimeOut, 912, 0x100)
		ADD_OBJECT(HUD, myHUD, 992)
		ADD_STRUCT(float, WaitDelay, 920)
		ADD_OBJECT(SavedMove, SavedMoves, 1000)
		ADD_OBJECT(SavedMove, PendingMove, 1008)
		ADD_OBJECT(PlayerInput, PlayerInput, 1132)
		ADD_OBJECT(ScriptClass, InputClass, 1136)
		ADD_STRUCT(ScriptArray<class Interaction*>, Interactions, 1172)
		ADD_STRUCT(ScriptString*, ForceFeedbackManagerClassName, 1156)
		ADD_OBJECT(ForceFeedbackManager, ForceFeedbackManager, 1168)
		ADD_OBJECT(UIDataStore_OnlinePlayerData, OnlinePlayerData, 1260)
		ADD_BOOL(bFrozen, 912, 0x1)
		ADD_OBJECT(Pawn, AcknowledgedPawn, 924)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, HearSoundActiveComponents, 1384)
		ADD_STRUCT(ScriptArray<
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void*>, HearSoundPoolComponents, 1396)
		ADD_STRUCT(float, FOVAngle, 948)
		ADD_STRUCT(float, DefaultFOV, 956)
		ADD_STRUCT(float, DesiredFOV, 952)
		ADD_STRUCT(float, LastBroadcastTime, 1288)
		ADD_STRUCT(ScriptString*, LastBroadcastString, 1292)
		ADD_STRUCT(float, LastUpdateTime, 1028)
		ADD_STRUCT(float, CurrentTimeStamp, 1024)
		ADD_BOOL(bWasSpeedHack, 912, 0x400)
		ADD_STRUCT(float, LastSpeedHackLog, 1064)
		ADD_STRUCT(PlayerController::ClientAdjustment, PendingAdjustment, 1068)
		ADD_STRUCT(float, ServerTimeStamp, 1032)
		ADD_OBJECT(ScriptClass, SavedMoveClass, 996)
		ADD_BOOL(bDoubleJump, 912, 0x4)
		ADD_STRUCT(int, ClientCap, 1052)
		ADD_STRUCT(float, LastPingUpdate, 1060)
		ADD_OBJECT(SavedMove, FreeMoves, 1004)
		ADD_STRUCT(Object::Vector, LastAckedAccel, 1012)
		ADD_BOOL(bUpdatePosition, 912, 0x8)
		ADD_STRUCT(byte, bRun, 931)
		ADD_STRUCT(byte, bDuck, 932)
		ADD_BOOL(bPressedJump, 912, 0x2)
		ADD_BOOL(bUpdating, 912, 0x10)
		ADD_STRUCT(float, ClientUpdateTime, 1040)
		ADD_BOOL(bCinematicMode, 912, 0x10000)
		ADD_STRUCT(float, InteractDistance, 1264)
		ADD_BOOL(bAimingHelp, 912, 0x1000)
		ADD_BOOL(bClientSimulatingViewTarget, 912, 0x2000)
		ADD_OBJECT(ScriptClass, CameraClass, 908)
		ADD_STRUCT(Actor::EDoubleClickDir, DoubleClickDir, 928)
		ADD_STRUCT(int, GroundPitch, 1120)
		ADD_BOOL(bCheatFlying, 912, 0x40)
		ADD_STRUCT(float, LastSpectatorStateSynchTime, 1420)
		ADD_STRUCT(float, SpectatorCameraSpeed, 1368)
		ADD_OBJECT(PlayerReplicationInfo, RealViewTarget, 940)
		ADD_STRUCT(float, MinRespawnDelay, 1376)
		ADD_OBJECT(NetConnection, PendingSwapConnection, 1372)
		ADD_STRUCT(byte, bIgnoreMoveInput, 929)
		ADD_STRUCT(byte, bIgnoreLookInput, 930)
		ADD_BOOL(bCinemaDisableInputMove, 912, 0x20000)
		ADD_BOOL(bCinemaDisableInputLook, 912, 0x40000)
		ADD_STRUCT(ScriptArray<ScriptName>, PendingMapChangeLevelNames, 1340)
		ADD_BOOL(bHasVoiceHandshakeCompleted, 912, 0x8000)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, VoicePacketFilter, 1208)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, GameplayVoiceMuteList, 1196)
		ADD_STRUCT(ScriptArray<OnlineSubsystem::UniqueNetId>, VoiceMuteList, 1184)
		ADD_STRUCT(ScriptArray<PlayerController::DebugTextInfo>, DebugTextList, 1356)
		ADD_STRUCT(byte, NetPlayerIndex, 933)
		ADD_OBJECT(CheatManager, CheatManager, 1124)
		ADD_BOOL(bNeverSwitchOnPickup, 912, 0x20)
		ADD_BOOL(bCameraPositionLocked, 912, 0x80)
		ADD_BOOL(bWasSaturated, 912, 0x800)
		ADD_BOOL(bPreventRespawn, 912, 0x4000)
		ADD_BOOL(bIgnoreNetworkMessages, 912, 0x80000)
		ADD_BOOL(bReplicateAllPawns, 912, 0x100000)
		ADD_BOOL(bIsUsingStreamingVolumes, 912, 0x200000)
		ADD_BOOL(bCheckSoundOcclusion, 912, 0x1000000)
		ADD_BOOL(bDebugCameraAnims, 912, 0x2000000)
		ADD_BOOL(bBlockCameraAnimsFromOverridingPostProcess, 912, 0x4000000)
		ADD_BOOL(bLogHearSoundOverflow, 912, 0x8000000)
		ADD_BOOL(bCheckRelevancyThroughPortals, 912, 0x10000000)
		ADD_BOOL(bDebugClientAdjustPosition, 912, 0x20000000)
		ADD_OBJECT(InterpTrackInstDirector, ControllingDirTrackInst, 944)
		ADD_STRUCT(Object::Rotator, TargetViewRotation, 964)
		ADD_STRUCT(float, TargetEyeHeight, 976)
		ADD_STRUCT(Object::Rotator, BlendedTargetViewRotation, 980)
		ADD_STRUCT(float, DynamicPingThreshold, 1056)
		ADD_OBJECT(ScriptClass, CheatClass, 1128)
		ADD_STRUCT(Object::Vector, FailedPathStart, 1140)
		ADD_STRUCT(ScriptName, DelayedJoinSessionName, 1268)
		ADD_STRUCT(ScriptArray<PlayerController::InputMatchRequest>, InputRequests, 1276)
		ADD_STRUCT(int, MaxConcurrentHearSounds, 1380)
		ADD_STRUCT(ScriptArray<class Actor*>, HiddenActors, 1408)
		float GetFOVAngle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetFOVAngle");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[0];
		}
		ScriptString* GetPlayerNetworkAddress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPlayerNetworkAddress");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		class Actor* GetViewTarget()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetViewTarget");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[0];
		}
		bool IsPrimaryPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPrimaryPlayer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetNetSpeed(int NewSpeed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetNetSpeed");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetServerNetworkAddress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetServerNetworkAddress");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* ConsoleCommand(ScriptString* Command, bool bWriteToLog)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ConsoleCommand");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Command;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		void ClientTravel(ScriptString* URL, Actor::ETravelType TravelType, bool bSeamless, Object::Guid MapPackageGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientTravel");
			byte params[33] = { NULL };
			*(ScriptString**)&params[0] = URL;
			*(Actor::ETravelType*)&params[12] = TravelType;
			*(bool*)&params[16] = bSeamless;
			*(Object::Guid*)&params[20] = MapPackageGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateURL(ScriptString* NewOption, ScriptString* NewValue, bool bSave1Default)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdateURL");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = NewOption;
			*(ScriptString**)&params[12] = NewValue;
			*(bool*)&params[24] = bSave1Default;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDefaultURL(ScriptString* Option)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetDefaultURL");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Option;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void CopyToClipboard(ScriptString* Text)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CopyToClipboard");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* PasteFromClipboard()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PasteFromClipboard");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void SetAllowMatureLanguage(bool bAllowMatureLanguge)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetAllowMatureLanguage");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAllowMatureLanguge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAudioGroupVolume(ScriptName GroupName, float Volume)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetAudioGroupVolume");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = GroupName;
			*(float*)&params[8] = Volume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientConvolve(ScriptString* C, int H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientConvolve");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = C;
			*(int*)&params[12] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerProcessConvolve(ScriptString* C, int H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerProcessConvolve");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = C;
			*(int*)&params[12] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckSpeedHack(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CheckSpeedHack");
			byte params[8] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int FindStairRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FindStairRotation");
			byte params[8] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void CleanUpAudioComponents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CleanUpAudioComponents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FellOutOfWorld");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceClearUnpauseDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ForceClearUnpauseDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnExternalUIChanged(bool bIsOpening)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnExternalUIChanged");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIsOpening;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanUnpauseExternalUI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanUnpauseExternalUI");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnControllerChanged");
			byte params[8] = { NULL };
			*(int*)&params[0] = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanUnpauseControllerConnected()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanUnpauseControllerConnected");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		class CoverReplicator* SpawnCoverReplicator()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SpawnCoverReplicator");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class CoverReplicator**)&params[0];
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
		int FindConnectedPeerIndex(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FindConnectedPeerIndex");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void AddPeer(OnlineSubsystem::UniqueNetId PeerNetId, OnlineSubsystem::ENATType NatType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AddPeer");
			byte params[9] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			*(OnlineSubsystem::ENATType*)&params[8] = NatType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemovePeer(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemovePeer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAddPeer(OnlineSubsystem::UniqueNetId PeerNetId, OnlineSubsystem::ENATType NatType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerAddPeer");
			byte params[9] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			*(OnlineSubsystem::ENATType*)&params[8] = NatType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRemovePeer(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerRemovePeer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUpdateBestNextHosts(OnlineSubsystem::UniqueNetId SortedNextHosts, byte NumEntries)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientUpdateBestNextHosts");
			byte params[9] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = SortedNextHosts;
			params[80] = NumEntries;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPeerDisconnectHost(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyPeerDisconnectHost");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsBestHostPeer(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsBestHostPeer");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MigrateNewHost()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.MigrateNewHost");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnEndGameForHostMigrate(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnEndGameForHostMigrate");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetRegisteredPlayersInSession(ScriptName SessionName, ScriptArray<OnlineSubsystem::UniqueNetId>& OutRegisteredPlayers)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetRegisteredPlayersInSession");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = OutRegisteredPlayers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutRegisteredPlayers = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
		}
		void RemoveMissingPeersFromSession(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemoveMissingPeersFromSession");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregisterPlayerCompleteForMigrate(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnUnregisterPlayerCompleteForMigrate");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnHostMigratedOnlineGame(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnHostMigratedOnlineGame");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetCurrentSearchClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetCurrentSearchClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[0];
		}
		void PeerDesignatedAsHost(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PeerDesignatedAsHost");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PeerTravelAsHost(float TravelCountdownTimer, ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PeerTravelAsHost");
			byte params[16] = { NULL };
			*(float*)&params[0] = TravelCountdownTimer;
			*(ScriptString**)&params[4] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TellPeerToTravel(OnlineSubsystem::UniqueNetId ToPeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TellPeerToTravel");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = ToPeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TellPeerToTravelToSession(OnlineSubsystem::UniqueNetId ToPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo, int PlatformSpecificInfoSize)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TellPeerToTravelToSession");
			byte params[25] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = ToPeerNetId;
			*(ScriptName*)&params[8] = SessionName;
			*(ScriptClass**)&params[16] = SearchClass;
			params[20] = PlatformSpecificInfo;
			*(int*)&params[100] = PlatformSpecificInfoSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PeerReceivedMigratedSession(OnlineSubsystem::UniqueNetId FromPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PeerReceivedMigratedSession");
			byte params[21] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = FromPeerNetId;
			*(ScriptName*)&params[8] = SessionName;
			*(ScriptClass**)&params[16] = SearchClass;
			params[20] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEndGameForJoinMigrate(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnEndGameForJoinMigrate");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinMigratedGame(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnJoinMigratedGame");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PreRender");
			byte params[4] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineSubsystem**)&params[0];
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
			byte params[4] = { NULL };
			*(float*)&params[0] = ScaleBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsControllerTiltActive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsControllerTiltActive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetControllerTiltDesiredIfAvailable(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetControllerTiltDesiredIfAvailable");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetControllerTiltActive(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetControllerTiltActive");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyUseControllerTiltInput(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetOnlyUseControllerTiltInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetUseTiltForwardAndBack(bool bActive)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetUseTiltForwardAndBack");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsKeyboardAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsKeyboardAvailable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool IsMouseAvailable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsMouseAvailable");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClientGotoState(ScriptName NewState, ScriptName NewLabel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientGotoState");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = NewState;
			*(ScriptName*)&params[8] = NewLabel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AskForPawn()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AskForPawn");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GivePawn(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GivePawn");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Possess");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AcknowledgePossession");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerAcknowledgePossession");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnPossess()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UnPossess");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PawnDied");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetHUD(ScriptClass* newHUDType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetHUD");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = newHUDType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HandlePickup");
			byte params[4] = { NULL };
			*(class Inventory**)&params[0] = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CleanupPRI()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CleanupPRI");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveLocalizedMessage(ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI, class Object* OptionalObject)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ReceiveLocalizedMessage");
			byte params[20] = { NULL };
			*(ScriptClass**)&params[0] = Message;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlaySound(class SoundCue* ASound)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlaySound");
			byte params[4] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HearSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HearSoundFinished");
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[0] = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetPooledAudioComponent(class SoundCue* ASound, class Actor* SourceActor, bool bStopWhenOwnerDestroyed, bool bUseLocation, Object::Vector SourceLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPooledAudioComponent");
			byte params[32] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			*(bool*)&params[12] = bUseLocation;
			*(Object::Vector*)&params[16] = SourceLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[28];
		}
		void ClientHearSound(class SoundCue* ASound, class Actor* SourceActor, Object::Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientHearSound");
			byte params[28] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(Object::Vector*)&params[8] = SourceLocation;
			*(bool*)&params[20] = bStopWhenOwnerDestroyed;
			*(bool*)&params[24] = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsClosestLocalPlayerToActor(class Actor* TheActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsClosestLocalPlayerToActor");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Kismet_ClientPlaySound(class SoundCue* ASound, class Actor* SourceActor, float VolumeMultiplier, float PitchMultiplier, float FadeInTime, bool bSuppressSubtitles, bool bSuppressSpatialization)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Kismet_ClientPlaySound");
			byte params[28] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(float*)&params[8] = VolumeMultiplier;
			*(float*)&params[12] = PitchMultiplier;
			*(float*)&params[16] = FadeInTime;
			*(bool*)&params[20] = bSuppressSubtitles;
			*(bool*)&params[24] = bSuppressSpatialization;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Kismet_ClientStopSound(class SoundCue* ASound, class Actor* SourceActor, float FadeOutTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Kismet_ClientStopSound");
			byte params[12] = { NULL };
			*(class SoundCue**)&params[0] = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(float*)&params[8] = FadeOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayActorFaceFXAnim(class Actor* SourceActor, class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayActorFaceFXAnim");
			byte params[36] = { NULL };
			*(class Actor**)&params[0] = SourceActor;
			*(class FaceFXAnimSet**)&params[4] = AnimSet;
			*(ScriptString**)&params[8] = GroupName;
			*(ScriptString**)&params[20] = SeqName;
			*(class SoundCue**)&params[32] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientMessage(ScriptString* S, ScriptName Type, float MsgLifeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientMessage");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(ScriptName*)&params[12] = Type;
			*(float*)&params[20] = MsgLifeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanCommunicate");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool AllowTTSMessageFrom(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AllowTTSMessageFrom");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class SoundCue* CreateTTSSoundCue(ScriptString* StrToSpeak, class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CreateTTSSoundCue");
			byte params[20] = { NULL };
			*(ScriptString**)&params[0] = StrToSpeak;
			*(class PlayerReplicationInfo**)&params[12] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[16];
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
		void SpeakTTS(ScriptString* S, class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SpeakTTS");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = S;
			*(class PlayerReplicationInfo**)&params[12] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamMessage(class PlayerReplicationInfo* PRI, ScriptString* S, ScriptName Type, float MsgLifeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TeamMessage");
			byte params[28] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			*(ScriptString**)&params[4] = S;
			*(ScriptName*)&params[16] = Type;
			*(float*)&params[24] = MsgLifeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void OnPartyMemberListChanged(bool bJoinedOrLeft, ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnPartyMemberListChanged");
			byte params[24] = { NULL };
			*(bool*)&params[0] = bJoinedOrLeft;
			*(ScriptString**)&params[4] = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[16] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPartyMembersInfoChanged(ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID, int CustomData1, int CustomData2, int CustomData3, int CustomData4)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnPartyMembersInfoChanged");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[12] = PlayerID;
			*(int*)&params[20] = CustomData1;
			*(int*)&params[24] = CustomData2;
			*(int*)&params[28] = CustomData3;
			*(int*)&params[32] = CustomData4;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(float*)&params[0] = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetFOV()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ResetFOV");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FOV");
			byte params[4] = { NULL };
			*(float*)&params[0] = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTextMessage(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AllowTextMessage");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void Say(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Say");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSay(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerSay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientAdminMessage(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientAdminMessage");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TeamSay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerTeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerTeamSay");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreClientTravel(ScriptString* PendingURL, Actor::ETravelType TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PreClientTravel");
			byte params[17] = { NULL };
			*(ScriptString**)&params[0] = PendingURL;
			*(Actor::ETravelType*)&params[12] = TravelType;
			*(bool*)&params[16] = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UIInteraction* GetUIController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetUIController");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIInteraction**)&params[0];
		}
		void Camera(ScriptName NewMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Camera");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerCamera(ScriptName NewMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerCamera");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetCameraMode");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetCameraMode");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetCameraMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ResetCameraMode");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetCameraFade(bool bEnableFading, Object::Color FadeColor, Object::Vector2D FadeAlpha, float FadeTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetCameraFade");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bEnableFading;
			*(Object::Color*)&params[4] = FadeColor;
			*(Object::Vector2D*)&params[8] = FadeAlpha;
			*(float*)&params[16] = FadeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UsingFirstPersonCamera()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UsingFirstPersonCamera");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ForceDeathUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ForceDeathUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DualServerMove(float TimeStamp0, Object::Vector InAccel0, byte PendingFlags, int View0, float TimeStamp, Object::Vector InAccel, Object::Vector ClientLoc, byte NewFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DualServerMove");
			byte params[55] = { NULL };
			*(float*)&params[0] = TimeStamp0;
			*(Object::Vector*)&params[4] = InAccel0;
			params[16] = PendingFlags;
			*(int*)&params[20] = View0;
			*(float*)&params[24] = TimeStamp;
			*(Object::Vector*)&params[28] = InAccel;
			*(Object::Vector*)&params[40] = ClientLoc;
			params[52] = NewFlags;
			params[53] = ClientRoll;
			*(int*)&params[56] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OldServerMove(float OldTimeStamp, byte OldAccelX, byte OldAccelY, byte OldAccelZ, byte OldMoveFlags)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OldServerMove");
			byte params[8] = { NULL };
			*(float*)&params[0] = OldTimeStamp;
			params[4] = OldAccelX;
			params[5] = OldAccelY;
			params[6] = OldAccelZ;
			params[7] = OldMoveFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetServerMoveDeltaTime(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetServerMoveDeltaTime");
			byte params[8] = { NULL };
			*(float*)&params[0] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void ServerMoveHandleClientError(float TimeStamp, Object::Vector Accel, Object::Vector ClientLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerMoveHandleClientError");
			byte params[28] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(Object::Vector*)&params[4] = Accel;
			*(Object::Vector*)&params[16] = ClientLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerMove(float TimeStamp, Object::Vector InAccel, Object::Vector ClientLoc, byte MoveFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerMove");
			byte params[34] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(Object::Vector*)&params[4] = InAccel;
			*(Object::Vector*)&params[16] = ClientLoc;
			params[28] = MoveFlags;
			params[29] = ClientRoll;
			*(int*)&params[32] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendClientAdjustment()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SendClientAdjustment");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerDrive(float InForward, float InStrafe, float aUp, bool InJump, int View)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerDrive");
			byte params[20] = { NULL };
			*(float*)&params[0] = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = aUp;
			*(bool*)&params[12] = InJump;
			*(int*)&params[16] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessDrive(float InForward, float InStrafe, float InUp, bool InJump)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ProcessDrive");
			byte params[16] = { NULL };
			*(float*)&params[0] = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = InUp;
			*(bool*)&params[12] = InJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessMove(float DeltaTime, Object::Vector newAccel, Actor::EDoubleClickDir DoubleClickMove, Object::Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ProcessMove");
			byte params[29] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Vector*)&params[4] = newAccel;
			*(Actor::EDoubleClickDir*)&params[16] = DoubleClickMove;
			*(Object::Rotator*)&params[20] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveAutonomous(float DeltaTime, byte CompressedFlags, Object::Vector newAccel, Object::Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.MoveAutonomous");
			byte params[29] = { NULL };
			*(float*)&params[0] = DeltaTime;
			params[4] = CompressedFlags;
			*(Object::Vector*)&params[8] = newAccel;
			*(Object::Rotator*)&params[20] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VeryShortClientAdjustPosition(float TimeStamp, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.VeryShortClientAdjustPosition");
			byte params[20] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(float*)&params[4] = NewLocX;
			*(float*)&params[8] = NewLocY;
			*(float*)&params[12] = NewLocZ;
			*(class Actor**)&params[16] = NewBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShortClientAdjustPosition(float TimeStamp, ScriptName NewState, Actor::EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ShortClientAdjustPosition");
			byte params[29] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(ScriptName*)&params[4] = NewState;
			*(Actor::EPhysics*)&params[12] = newPhysics;
			*(float*)&params[16] = NewLocX;
			*(float*)&params[20] = NewLocY;
			*(float*)&params[24] = NewLocZ;
			*(class Actor**)&params[28] = NewBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientCapBandwidth(int Cap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientCapBandwidth");
			byte params[4] = { NULL };
			*(int*)&params[0] = Cap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientAckGoodMove(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientAckGoodMove");
			byte params[4] = { NULL };
			*(float*)&params[0] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePing(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdatePing");
			byte params[4] = { NULL };
			*(float*)&params[0] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientAdjustPosition(float TimeStamp, ScriptName NewState, Actor::EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientAdjustPosition");
			byte params[41] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(ScriptName*)&params[4] = NewState;
			*(Actor::EPhysics*)&params[12] = newPhysics;
			*(float*)&params[16] = NewLocX;
			*(float*)&params[20] = NewLocY;
			*(float*)&params[24] = NewLocZ;
			*(float*)&params[28] = NewVelX;
			*(float*)&params[32] = NewVelY;
			*(float*)&params[36] = NewVelZ;
			*(class Actor**)&params[40] = NewBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LongClientAdjustPosition(float TimeStamp, ScriptName NewState, Actor::EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase, float NewFloorX, float NewFloorY, float NewFloorZ)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LongClientAdjustPosition");
			byte params[53] = { NULL };
			*(float*)&params[0] = TimeStamp;
			*(ScriptName*)&params[4] = NewState;
			*(Actor::EPhysics*)&params[12] = newPhysics;
			*(float*)&params[16] = NewLocX;
			*(float*)&params[20] = NewLocY;
			*(float*)&params[24] = NewLocZ;
			*(float*)&params[28] = NewVelX;
			*(float*)&params[32] = NewVelY;
			*(float*)&params[36] = NewVelZ;
			*(class Actor**)&params[40] = NewBase;
			*(float*)&params[44] = NewFloorX;
			*(float*)&params[48] = NewFloorY;
			*(float*)&params[52] = NewFloorZ;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateStateFromAdjustment(ScriptName NewState)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdateStateFromAdjustment");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = NewState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerUpdatePing(int NewPing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUpdatePing");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewPing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SavedMove**)&params[0];
		}
		int CompressAccel(int C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CompressAccel");
			byte params[8] = { NULL };
			*(int*)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReplicateMove(float DeltaTime, Object::Vector newAccel, Actor::EDoubleClickDir DoubleClickMove, Object::Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ReplicateMove");
			byte params[29] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Vector*)&params[4] = newAccel;
			*(Actor::EDoubleClickDir*)&params[16] = DoubleClickMove;
			*(Object::Rotator*)&params[20] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallServerMove(class SavedMove* NewMove, Object::Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CallServerMove");
			byte params[25] = { NULL };
			*(class SavedMove**)&params[0] = NewMove;
			*(Object::Vector*)&params[4] = ClientLoc;
			params[16] = ClientRoll;
			*(int*)&params[20] = View;
			*(class SavedMove**)&params[24] = OldMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bShouldPauseRumble;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanUnpause()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanUnpause");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool SetPause(bool bPause, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetPause");
			byte params[20] = { NULL };
			*(bool*)&params[0] = bPause;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsPaused()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPaused");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDesiredPauseState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.StopFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartAltFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.StartAltFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAltFire(byte FireModeNum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.StopAltFire");
			byte params[1] = { NULL };
			params[0] = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetTriggerUseList(float interactDistanceToCheck, float crosshairDist, float minDot, bool bUsuableOnly, ScriptArray<class Trigger*>& out_useList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetTriggerUseList");
			byte params[28] = { NULL };
			*(float*)&params[0] = interactDistanceToCheck;
			*(float*)&params[4] = crosshairDist;
			*(float*)&params[8] = minDot;
			*(bool*)&params[12] = bUsuableOnly;
			*(ScriptArray<class Trigger*>*)&params[16] = out_useList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_useList = *(ScriptArray<class Trigger*>*)&params[16];
		}
		bool Use()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Use");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool ServerUse()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUse");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PerformedUseAction");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool FindVehicleToDrive()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.FindVehicleToDrive");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.TriggerInteracted");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
		void SetName(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeName(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerChangeName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SwitchTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeTeam(ScriptString* TeamName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ChangeTeam");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = TeamName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeTeam(int N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerChangeTeam");
			byte params[4] = { NULL };
			*(int*)&params[0] = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetProgressMessage(PlayerController::EProgressMessageType MessageType, ScriptString* Message, ScriptString* Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetProgressMessage");
			byte params[29] = { NULL };
			*(PlayerController::EProgressMessageType*)&params[0] = MessageType;
			*(ScriptString**)&params[4] = Message;
			*(ScriptString**)&params[16] = Title;
			*(bool*)&params[28] = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.Restart");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerNotifyLoadedWorld(ScriptName WorldPackageName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerNotifyLoadedWorld");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = WorldPackageName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyLoadedWorld(ScriptName WorldPackageName, bool bFinalDest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyLoadedWorld");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = WorldPackageName;
			*(bool*)&params[8] = bFinalDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HasClientLoadedCurrentWorld()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HasClientLoadedCurrentWorld");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ForceSingleNetUpdateFor(class Actor* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ForceSingleNetUpdateFor");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnterStartState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.EnterStartState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientRestart");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GameHasEnded");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientGameEnded");
			byte params[8] = { NULL };
			*(class Actor**)&params[0] = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyChangedWeapon(class Weapon* PreviousWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyChangedWeapon");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = PreviousWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PlayerTick");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerMove(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PlayerMove");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AimingHelp");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CameraLookAtFinished(class SeqAct_CameraLookAt* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CameraLookAtFinished");
			byte params[4] = { NULL };
			*(class SeqAct_CameraLookAt**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Object::Rotator GetAdjustedAimFor(class Weapon* W, Object::Vector StartFireLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetAdjustedAimFor");
			byte params[28] = { NULL };
			*(class Weapon**)&params[0] = W;
			*(Object::Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[16];
		}
		float AimHelpDot(bool bInstantHit)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AimHelpDot");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool NotifyLanded(Object::Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyLanded");
			byte params[20] = { NULL };
			*(Object::Vector*)&params[0] = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AdjustFOV(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AdjustFOV");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsLocalPlayerController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsLocalPlayerController");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void SetViewTarget(class Actor* NewViewTarget, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetViewTarget");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = NewViewTarget;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewTargetWithBlend(class Actor* NewViewTarget, float BlendTime, Camera::EViewTargetBlendFunction BlendFunc, float BlendExp, bool bLockOutgoing)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetViewTargetWithBlend");
			byte params[17] = { NULL };
			*(class Actor**)&params[0] = NewViewTarget;
			*(float*)&params[4] = BlendTime;
			*(Camera::EViewTargetBlendFunction*)&params[8] = BlendFunc;
			*(float*)&params[12] = BlendExp;
			*(bool*)&params[16] = bLockOutgoing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetViewTarget(class Actor* A, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetViewTarget");
			byte params[20] = { NULL };
			*(class Actor**)&params[0] = A;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		void GetPlayerViewPoint(Object::Vector& out_Location, Object::Rotator& out_Rotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPlayerViewPoint");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = out_Location;
			*(Object::Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Object::Vector*)&params[0];
			out_Rotation = *(Object::Rotator*)&params[12];
		}
		void ViewShake(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ViewShake");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.UpdateRotation");
			byte params[4] = { NULL };
			*(float*)&params[0] = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Object::Rotator& out_ViewRotation, Object::Rotator DeltaRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ProcessViewRotation");
			byte params[28] = { NULL };
			*(float*)&params[0] = DeltaTime;
			*(Object::Rotator*)&params[4] = out_ViewRotation;
			*(Object::Rotator*)&params[16] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Object::Rotator*)&params[4];
		}
		Object::Rotator LimitViewRotation(Object::Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LimitViewRotation");
			byte params[32] = { NULL };
			*(Object::Rotator*)&params[0] = ViewRotation;
			*(float*)&params[12] = ViewPitchMin;
			*(float*)&params[16] = ViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Object::Rotator*)&params[20];
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CheckJumpOrDuck");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsSpectating()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsSpectating");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ServerSetSpectatorLocation(Object::Vector NewLoc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerSetSpectatorLocation");
			byte params[12] = { NULL };
			*(Object::Vector*)&params[0] = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(int*)&params[0] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewSelf(Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerViewSelf");
			byte params[16] = { NULL };
			*(Camera::ViewTargetTransitionParams*)&params[0] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsWaiting()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsWaiting");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		bool CanRestartPlayer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanRestartPlayer");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DrawHUD");
			byte params[4] = { NULL };
			*(class HUD**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleInput(class SeqAct_ToggleInput* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnToggleInput");
			byte params[4] = { NULL };
			*(class SeqAct_ToggleInput**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientIgnoreMoveInput(bool bIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientIgnoreMoveInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientIgnoreLookInput(bool bIgnore)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientIgnoreLookInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void OnDrawText(class SeqAct_DrawText* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnDrawText");
			byte params[4] = { NULL };
			*(class SeqAct_DrawText**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientDrawKismetText(HUD::KismetDrawTextInfo DrawTextInfo, float DisplayTime)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientDrawKismetText");
			byte params[56] = { NULL };
			*(HUD::KismetDrawTextInfo*)&params[0] = DrawTextInfo;
			*(float*)&params[52] = DisplayTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientClearKismetText(Object::Vector2D MessageOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientClearKismetText");
			byte params[8] = { NULL };
			*(Object::Vector2D*)&params[0] = MessageOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetCameraTarget(class SeqAct_SetCameraTarget* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnSetCameraTarget");
			byte params[4] = { NULL };
			*(class SeqAct_SetCameraTarget**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHUD(class SeqAct_ToggleHUD* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnToggleHUD");
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHUD**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Object::Vector HitLocation, int Damage, ScriptClass* DamageType, Object::Vector Momentum)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyTakeHit");
			byte params[36] = { NULL };
			*(class Controller**)&params[0] = InstigatedBy;
			*(Object::Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Object::Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnForceFeedback(class SeqAct_ForceFeedback* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnForceFeedback");
			byte params[4] = { NULL };
			*(class SeqAct_ForceFeedback**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStopForceFeedbackWaveform");
			byte params[4] = { NULL };
			*(class ForceFeedbackWaveform**)&params[0] = FFWaveform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRumble(class AnimNotify_Rumble* TheAnimNotify)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.PlayRumble");
			byte params[4] = { NULL };
			*(class AnimNotify_Rumble**)&params[0] = TheAnimNotify;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayForceFeedbackWaveform");
			byte params[8] = { NULL };
			*(class ForceFeedbackWaveform**)&params[0] = FFWaveform;
			*(class Actor**)&params[4] = FFWaveformInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsForceFeedbackAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsForceFeedbackAllowed");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void OnToggleCinematicMode(class SeqAct_ToggleCinematicMode* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnToggleCinematicMode");
			byte params[4] = { NULL };
			*(class SeqAct_ToggleCinematicMode**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCinematicMode(bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsButtons)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetCinematicMode");
			byte params[24] = { NULL };
			*(bool*)&params[0] = bInCinematicMode;
			*(bool*)&params[4] = bHidePlayer;
			*(bool*)&params[8] = bAffectsHUD;
			*(bool*)&params[12] = bAffectsMovement;
			*(bool*)&params[16] = bAffectsTurning;
			*(bool*)&params[20] = bAffectsButtons;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetCinematicMode(bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsHUD)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetCinematicMode");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bInCinematicMode;
			*(bool*)&params[4] = bAffectsMovement;
			*(bool*)&params[8] = bAffectsTurning;
			*(bool*)&params[12] = bAffectsHUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IgnoreMoveInput(bool bNewMoveInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IgnoreMoveInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewMoveInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMoveInputIgnored()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsMoveInputIgnored");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void IgnoreLookInput(bool bNewLookInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IgnoreLookInput");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNewLookInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsLookInputIgnored()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsLookInputIgnored");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ResetPlayerMovementInput()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ResetPlayerMovementInput");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnConsoleCommand(class SeqAct_ConsoleCommand* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnConsoleCommand");
			byte params[4] = { NULL };
			*(class SeqAct_ConsoleCommand**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientForceGarbageCollection()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientForceGarbageCollection");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LevelStreamingStatusChanged(class LevelStreaming* LevelObject, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LevelStreamingStatusChanged");
			byte params[16] = { NULL };
			*(class LevelStreaming**)&params[0] = LevelObject;
			*(bool*)&params[4] = bNewShouldBeLoaded;
			*(bool*)&params[8] = bNewShouldBeVisible;
			*(bool*)&params[12] = bNewShouldBlockOnLoad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUpdateLevelStreamingStatus(ScriptName PackageName, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientUpdateLevelStreamingStatus");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = PackageName;
			*(bool*)&params[8] = bNewShouldBeLoaded;
			*(bool*)&params[12] = bNewShouldBeVisible;
			*(bool*)&params[16] = bNewShouldBlockOnLoad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerUpdateLevelVisibility(ScriptName PackageName, bool bIsVisible)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUpdateLevelVisibility");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = PackageName;
			*(bool*)&params[8] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPrepareMapChange(ScriptName LevelName, bool bFirst, bool bLast)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPrepareMapChange");
			byte params[16] = { NULL };
			*(ScriptName*)&params[0] = LevelName;
			*(bool*)&params[8] = bFirst;
			*(bool*)&params[12] = bLast;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
		bool IsPlayerMuted(OnlineSubsystem::UniqueNetId& Sender)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPlayerMuted");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = Sender;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Sender = *(OnlineSubsystem::UniqueNetId*)&params[0];
			return *(bool*)&params[8];
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetSeamlessTravelActorList");
			byte params[16] = { NULL };
			*(bool*)&params[0] = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void SeamlessTravelTo(class PlayerController* NewPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SeamlessTravelTo");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = NewPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeamlessTravelFrom(class PlayerController* OldPC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SeamlessTravelFrom");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = OldPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetOnlineStatus()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetOnlineStatus");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerController* GetPlayerControllerFromNetId(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPlayerControllerFromNetId");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerController**)&params[8];
		}
		void ClientVoiceHandshakeComplete()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientVoiceHandshakeComplete");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientMutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientMutePlayer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUnmutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientUnmutePlayer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameplayMutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GameplayMutePlayer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameplayUnmutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GameplayUnmutePlayer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerMutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerMutePlayer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerUnmutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerUnmutePlayer");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyDirectorControl(bool bNowControlling)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.NotifyDirectorControl");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bNowControlling;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShowSubtitles(bool bValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SetShowSubtitles");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsShowingSubtitles()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsShowingSubtitles");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
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
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRegisteredForArbitration(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerRegisteredForArbitration");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteAccepted(OnlineGameSearch::OnlineGameSearchResult& InviteResult)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnGameInviteAccepted");
			byte params[8] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)&params[0] = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InviteResult = *(OnlineGameSearch::OnlineGameSearchResult*)&params[0];
		}
		bool InviteHasEnoughSpace(class OnlineGameSettings* InviteSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.InviteHasEnoughSpace");
			byte params[8] = { NULL };
			*(class OnlineGameSettings**)&params[0] = InviteSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanAllPlayersPlayOnline()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.CanAllPlayersPlayOnline");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClearInviteDelegates()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClearInviteDelegates");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnEndForInviteComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnEndForInviteComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroyForInviteComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnDestroyForInviteComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ModifyClientURL(ScriptString* URL)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ModifyClientURL");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void OnInviteJoinComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnInviteJoinComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(int*)&params[0] = LeaderboardId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWriteLeaderboardStats(ScriptClass* OnlineStatsWriteClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientWriteLeaderboardStats");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = OnlineStatsWriteClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetHostUniqueId(OnlineSubsystem::UniqueNetId InHostId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetHostUniqueId");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = InHostId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			*(class SeqAct_Destroy**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugTextList(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.DrawDebugTextList");
			byte params[8] = { NULL };
			*(class Canvas**)&params[0] = Canvas;
			*(float*)&params[4] = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDebugText(ScriptString* DebugText, class Actor* SrcActor, float Duration, Object::Vector Offset, Object::Vector DesiredOffset, Object::Color TextColor, bool bSkipOverwriteCheck, bool bAbsoluteLocation, bool bKeepAttachedToActor, class Font* InFont)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.AddDebugText");
			byte params[64] = { NULL };
			*(ScriptString**)&params[0] = DebugText;
			*(class Actor**)&params[12] = SrcActor;
			*(float*)&params[16] = Duration;
			*(Object::Vector*)&params[20] = Offset;
			*(Object::Vector*)&params[32] = DesiredOffset;
			*(Object::Color*)&params[44] = TextColor;
			*(bool*)&params[48] = bSkipOverwriteCheck;
			*(bool*)&params[52] = bAbsoluteLocation;
			*(bool*)&params[56] = bKeepAttachedToActor;
			*(class Font**)&params[60] = InFont;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveDebugText(class Actor* SrcActor)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemoveDebugText");
			byte params[4] = { NULL };
			*(class Actor**)&params[0] = SrcActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveAllDebugStrings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.RemoveAllDebugStrings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRegisterHostStatGuid(ScriptString* StatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientRegisterHostStatGuid");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = StatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegisterHostStatGuidComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnRegisterHostStatGuidComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRegisterClientStatGuid(ScriptString* StatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ServerRegisterClientStatGuid");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = StatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void IncrementNumberOfMatchesPlayed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IncrementNumberOfMatchesPlayed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SoakPause(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.SoakPause");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientTravelToSession(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientTravelToSession");
			byte params[13] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinTravelToSessionComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnJoinTravelToSessionComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReturnToParty(OnlineSubsystem::UniqueNetId RequestingPlayerId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientReturnToParty");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = RequestingPlayerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSplitscreenPlayer(int& out_SplitscreenPlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsSplitscreenPlayer");
			byte params[8] = { NULL };
			*(int*)&params[0] = out_SplitscreenPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_SplitscreenPlayerIndex = *(int*)&params[0];
			return *(bool*)&params[4];
		}
		class PlayerReplicationInfo* GetSplitscreenPlayerByIndex(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetSplitscreenPlayerByIndex");
			byte params[8] = { NULL };
			*(int*)&params[0] = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[4];
		}
		int GetSplitscreenPlayerCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetSplitscreenPlayerCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void ClientControlMovieTexture(class TextureMovie* MovieTexture, SeqAct_ControlMovieTexture::EMovieControlType Mode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientControlMovieTexture");
			byte params[5] = { NULL };
			*(class TextureMovie**)&params[0] = MovieTexture;
			*(SeqAct_ControlMovieTexture::EMovieControlType*)&params[4] = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetForceMipLevelsToBeResident(class MaterialInterface* Material, float ForceDuration, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSetForceMipLevelsToBeResident");
			byte params[12] = { NULL };
			*(class MaterialInterface**)&params[0] = Material;
			*(float*)&params[4] = ForceDuration;
			*(int*)&params[8] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPrestreamTextures(class Actor* ForcedActor, float ForceDuration, bool bEnableStreaming, int CinematicTextureGroups)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPrestreamTextures");
			byte params[16] = { NULL };
			*(class Actor**)&params[0] = ForcedActor;
			*(float*)&params[4] = ForceDuration;
			*(bool*)&params[8] = bEnableStreaming;
			*(int*)&params[12] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPartyLeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.IsPartyLeader");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		ScriptString* GetPartyMapName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPartyMapName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		ScriptString* GetPartyGameTypeName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetPartyGameTypeName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool GetAchievementProgression(int AchievementId, float& CurrentValue, float& MaxValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.GetAchievementProgression");
			byte params[16] = { NULL };
			*(int*)&params[0] = AchievementId;
			*(float*)&params[4] = CurrentValue;
			*(float*)&params[8] = MaxValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CurrentValue = *(float*)&params[4];
			MaxValue = *(float*)&params[8];
			return *(bool*)&params[12];
		}
		void OnFlyThroughHasEnded(class SeqAct_FlyThroughHasEnded* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnFlyThroughHasEnded");
			byte params[4] = { NULL };
			*(class SeqAct_FlyThroughHasEnded**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
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
			byte params[8] = { NULL };
			*(class CameraShake**)&params[0] = ShakeData;
			*(float*)&params[4] = ShakeScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayCameraShake(class CameraShake* Shake, float Scale, bool bTryForceFeedback, Camera::ECameraAnimPlaySpace PlaySpace, Object::Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayCameraShake");
			byte params[25] = { NULL };
			*(class CameraShake**)&params[0] = Shake;
			*(float*)&params[4] = Scale;
			*(bool*)&params[8] = bTryForceFeedback;
			*(Camera::ECameraAnimPlaySpace*)&params[12] = PlaySpace;
			*(Object::Rotator*)&params[16] = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStopCameraShake");
			byte params[4] = { NULL };
			*(class CameraShake**)&params[0] = Shake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCameraShake(class SeqAct_CameraShake* inAction)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnCameraShake");
			byte params[4] = { NULL };
			*(class SeqAct_CameraShake**)&params[0] = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, Camera::ECameraAnimPlaySpace Space, Object::Rotator CustomPlaySpace)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientPlayCameraAnim");
			byte params[41] = { NULL };
			*(class CameraAnim**)&params[0] = AnimToPlay;
			*(float*)&params[4] = Scale;
			*(float*)&params[8] = Rate;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLoop;
			*(bool*)&params[24] = bRandomStartTime;
			*(Camera::ECameraAnimPlaySpace*)&params[28] = Space;
			*(Object::Rotator*)&params[32] = CustomPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopCameraAnim(class CameraAnim* AnimToStop)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientStopCameraAnim");
			byte params[4] = { NULL };
			*(class CameraAnim**)&params[0] = AnimToStop;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSpawnCameraLensEffect(ScriptClass* LensEffectEmitterClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.ClientSpawnCameraLensEffect");
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = LensEffectEmitterClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetSoundMode(class SeqAct_SetSoundMode* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.OnSetSoundMode");
			byte params[4] = { NULL };
			*(class SeqAct_SetSoundMode**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HasPeerConnection(OnlineSubsystem::UniqueNetId& PeerNetId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.HasPeerConnection");
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PeerNetId = *(OnlineSubsystem::UniqueNetId*)&params[0];
			return *(bool*)&params[8];
		}
		void BugItGo(float X, float Y, float Z, int Pitch, int Yaw, int Roll)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItGo");
			byte params[24] = { NULL };
			*(float*)&params[0] = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Z;
			*(int*)&params[12] = Pitch;
			*(int*)&params[16] = Yaw;
			*(int*)&params[20] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugItGoString(ScriptString* TheLocation, ScriptString* TheRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItGoString");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = TheLocation;
			*(ScriptString**)&params[12] = TheRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugItWorker(Object::Vector TheLocation, Object::Rotator TheRotation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItWorker");
			byte params[24] = { NULL };
			*(Object::Vector*)&params[0] = TheLocation;
			*(Object::Rotator*)&params[12] = TheRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugIt(ScriptString* ScreenShotDescription)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugIt");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ScreenShotDescription;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogOutBugItGoToLogFile(ScriptString* InScreenShotDesc, ScriptString* InGoString, ScriptString* InLocString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LogOutBugItGoToLogFile");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = InScreenShotDesc;
			*(ScriptString**)&params[12] = InGoString;
			*(ScriptString**)&params[24] = InLocString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogLoc()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LogLoc");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BugItAI(ScriptString* ScreenShotDescription)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItAI");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ScreenShotDescription;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogOutBugItAIGoToLogFile(ScriptString* InScreenShotDesc, ScriptString* InGoString, ScriptString* InLocString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.LogOutBugItAIGoToLogFile");
			byte params[36] = { NULL };
			*(ScriptString**)&params[0] = InScreenShotDesc;
			*(ScriptString**)&params[12] = InGoString;
			*(ScriptString**)&params[24] = InLocString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugItStringCreator(Object::Vector& ViewLocation, Object::Rotator& ViewRotation, ScriptString*& GoString, ScriptString*& LocString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerController.BugItStringCreator");
			byte params[48] = { NULL };
			*(Object::Vector*)&params[0] = ViewLocation;
			*(Object::Rotator*)&params[12] = ViewRotation;
			*(ScriptString**)&params[24] = GoString;
			*(ScriptString**)&params[36] = LocString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ViewLocation = *(Object::Vector*)&params[0];
			ViewRotation = *(Object::Rotator*)&params[12];
			GoString = *(ScriptString**)&params[24];
			LocString = *(ScriptString**)&params[36];
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
			byte params[4] = { NULL };
			*(ScriptClass**)&params[0] = GameClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
	const float PlayerController::MAXCLIENTUPDATEINTERVAL = 0.25f;
	const float PlayerController::CLIENTADJUSTUPDATECOST = 180.0f;
	const float PlayerController::MAXVEHICLEPOSITIONERRORSQUARED = 900.0f;
	const float PlayerController::MAXNEARZEROVELOCITYSQUARED = 9.0f;
	const float PlayerController::MAXPOSITIONERRORSQUARED = 3.0f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
