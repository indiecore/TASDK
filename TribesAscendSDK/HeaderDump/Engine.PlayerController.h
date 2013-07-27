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
		struct DebugTextInfo
		{
		public:
			ADD_OBJECT(Actor, SrcActor, 0)
			ADD_STRUCT(float, TimeRemaining, 40)
			ADD_OBJECT(Font, Font, 68)
			ADD_BOOL(bAbsoluteLocation, 52, 0x1)
			ADD_STRUCT(Vector, SrcActorOffset, 4)
			ADD_STRUCT(Vector, SrcActorDesiredOffset, 16)
			ADD_STRUCT(float, Duration, 44)
			ADD_BOOL(bKeepAttachedToActor, 52, 0x2)
			ADD_STRUCT(Vector, OrigActorLocation, 56)
			ADD_STRUCT(Object::Color, TextColor, 48)
			ADD_STRUCT(ScriptString*, DebugText, 28)
		};
		struct ConnectedPeerInfo
		{
		public:
			ADD_STRUCT(OnlineSubsystem::UniqueNetId, PlayerID, 0)
			ADD_STRUCT(OnlineSubsystem::ENATType, NatType, 8)
			ADD_BOOL(bLostConnectionToHost, 12, 0x1)
		};
		struct ClientAdjustment
		{
		public:
			ADD_STRUCT(Actor::EPhysics, newPhysics, 4)
			ADD_STRUCT(Vector, NewLoc, 8)
			ADD_STRUCT(Vector, NewVel, 20)
			ADD_OBJECT(Actor, NewBase, 32)
			ADD_STRUCT(Vector, NewFloor, 36)
			ADD_STRUCT(float, TimeStamp, 0)
			ADD_STRUCT(byte, bAckGoodMove, 48)
		};
		struct InputEntry
		{
		public:
			ADD_STRUCT(PlayerController::EInputTypes, Type, 0)
			ADD_STRUCT(float, Value, 4)
			ADD_STRUCT(float, TimeDelta, 8)
			ADD_STRUCT(PlayerController::EInputMatchAction, Action, 12)
		};
		struct InputMatchRequest
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
		ADD_STRUCT(Vector, LastAckedAccel, 1012)
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
		ADD_STRUCT(Rotator, TargetViewRotation, 964)
		ADD_STRUCT(float, TargetEyeHeight, 976)
		ADD_STRUCT(Rotator, BlendedTargetViewRotation, 980)
		ADD_STRUCT(float, DynamicPingThreshold, 1056)
		ADD_OBJECT(ScriptClass, CheatClass, 1128)
		ADD_STRUCT(Vector, FailedPathStart, 1140)
		ADD_STRUCT(ScriptName, DelayedJoinSessionName, 1268)
		ADD_STRUCT(ScriptArray<PlayerController::InputMatchRequest>, InputRequests, 1276)
		ADD_STRUCT(int, MaxConcurrentHearSounds, 1380)
		ADD_STRUCT(ScriptArray<class Actor*>, HiddenActors, 1408)
		float GetFOVAngle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(4261);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
		ScriptString* GetPlayerNetworkAddress()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(5730);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		class Actor* GetViewTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6638);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)params;
		}
		bool IsPrimaryPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(6862);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetNetSpeed(int NewSpeed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7554);
			byte params[4] = { NULL };
			*(int*)params = NewSpeed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetServerNetworkAddress()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7556);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* ConsoleCommand(ScriptString* Command, bool bWriteToLog)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7558);
			byte params[28] = { NULL };
			*(ScriptString**)params = Command;
			*(bool*)&params[12] = bWriteToLog;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[16];
		}
		void ClientTravel(ScriptString* URL, Actor::ETravelType TravelType, bool bSeamless, Object::Guid MapPackageGuid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7562);
			byte params[33] = { NULL };
			*(ScriptString**)params = URL;
			*(Actor::ETravelType*)&params[12] = TravelType;
			*(bool*)&params[16] = bSeamless;
			*(Object::Guid*)&params[20] = MapPackageGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateURL(ScriptString* NewOption, ScriptString* NewValue, bool bSave1Default)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7567);
			byte params[28] = { NULL };
			*(ScriptString**)params = NewOption;
			*(ScriptString**)&params[12] = NewValue;
			*(bool*)&params[24] = bSave1Default;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetDefaultURL(ScriptString* Option)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7571);
			byte params[24] = { NULL };
			*(ScriptString**)params = Option;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void CopyToClipboard(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7574);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* PasteFromClipboard()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7576);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void SetAllowMatureLanguage(bool bAllowMatureLanguge)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7578);
			byte params[4] = { NULL };
			*(bool*)params = bAllowMatureLanguge;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAudioGroupVolume(ScriptName GroupName, float Volume)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7580);
			byte params[12] = { NULL };
			*(ScriptName*)params = GroupName;
			*(float*)&params[8] = Volume;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientConvolve(ScriptString* C, int H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7583);
			byte params[16] = { NULL };
			*(ScriptString**)params = C;
			*(int*)&params[12] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerProcessConvolve(ScriptString* C, int H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7586);
			byte params[16] = { NULL };
			*(ScriptString**)params = C;
			*(int*)&params[12] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckSpeedHack(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7589);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int FindStairRotation(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7592);
			byte params[8] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void CleanUpAudioComponents()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7595);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FellOutOfWorld(ScriptClass* dmgType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7596);
			byte params[4] = { NULL };
			*(ScriptClass**)params = dmgType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ForceClearUnpauseDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7598);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnExternalUIChanged(bool bIsOpening)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7600);
			byte params[4] = { NULL };
			*(bool*)params = bIsOpening;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanUnpauseExternalUI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7603);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnControllerChanged(int ControllerId, bool bIsConnected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7606);
			byte params[8] = { NULL };
			*(int*)params = ControllerId;
			*(bool*)&params[4] = bIsConnected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanUnpauseControllerConnected()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7614);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		class CoverReplicator* SpawnCoverReplicator()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7616);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class CoverReplicator**)params;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7620);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7629);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterPlayerDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7630);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int FindConnectedPeerIndex(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7631);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void AddPeer(OnlineSubsystem::UniqueNetId PeerNetId, OnlineSubsystem::ENATType NatType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7638);
			byte params[9] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			*(OnlineSubsystem::ENATType*)&params[8] = NatType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemovePeer(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7646);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAddPeer(OnlineSubsystem::UniqueNetId PeerNetId, OnlineSubsystem::ENATType NatType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7650);
			byte params[9] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			*(OnlineSubsystem::ENATType*)&params[8] = NatType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRemovePeer(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7655);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUpdateBestNextHosts(OnlineSubsystem::UniqueNetId SortedNextHosts, byte NumEntries)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7659);
			byte params[9] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = SortedNextHosts;
			params[80] = NumEntries;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyPeerDisconnectHost(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7664);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsBestHostPeer(OnlineSubsystem::UniqueNetId PeerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7667);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool MigrateNewHost()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7672);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnEndGameForHostMigrate(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7679);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetRegisteredPlayersInSession(ScriptName SessionName, ScriptArray<OnlineSubsystem::UniqueNetId>& OutRegisteredPlayers)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7682);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8] = OutRegisteredPlayers;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutRegisteredPlayers = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[8];
		}
		void RemoveMissingPeersFromSession(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7686);
			byte params[8] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnUnregisterPlayerCompleteForMigrate(ScriptName SessionName, OnlineSubsystem::UniqueNetId PlayerID, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7697);
			byte params[20] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = PlayerID;
			*(bool*)&params[16] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnHostMigratedOnlineGame(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7701);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptClass* GetCurrentSearchClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7704);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)params;
		}
		void PeerDesignatedAsHost(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7706);
			byte params[8] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PeerTravelAsHost(float TravelCountdownTimer, ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7717);
			byte params[16] = { NULL };
			*(float*)params = TravelCountdownTimer;
			*(ScriptString**)&params[4] = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TellPeerToTravel(OnlineSubsystem::UniqueNetId ToPeerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7720);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = ToPeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TellPeerToTravelToSession(OnlineSubsystem::UniqueNetId ToPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo, int PlatformSpecificInfoSize)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7722);
			byte params[25] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = ToPeerNetId;
			*(ScriptName*)&params[8] = SessionName;
			*(ScriptClass**)&params[16] = SearchClass;
			params[20] = PlatformSpecificInfo;
			*(int*)&params[100] = PlatformSpecificInfoSize;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PeerReceivedMigratedSession(OnlineSubsystem::UniqueNetId FromPeerNetId, ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7728);
			byte params[21] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = FromPeerNetId;
			*(ScriptName*)&params[8] = SessionName;
			*(ScriptClass**)&params[16] = SearchClass;
			params[20] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnEndGameForJoinMigrate(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7737);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinMigratedGame(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7743);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreRender(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7749);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetTimeMargin()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7751);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerShortTimeout()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7753);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerGivePawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7757);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void KickWarning()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7758);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AddCheats(bool bForce)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7760);
			byte params[4] = { NULL };
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnableCheats()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7762);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnDefaultHUD()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7763);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7765);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientReset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7768);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanOutSavedMoves()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7769);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PreControllerIdChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7772);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PostControllerIdChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7774);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class OnlineSubsystem* GetOnlineSubsystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7780);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class OnlineSubsystem**)params;
		}
		void InitInputSystem()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7782);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitializeDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7794);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterCustomPlayerDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7795);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterStandardPlayerDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7810);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterPlayerDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7820);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterStandardPlayerDataStores()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7826);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReloadProfileSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7834);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetRumbleScale(float ScaleBy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7836);
			byte params[4] = { NULL };
			*(float*)params = ScaleBy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsControllerTiltActive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7839);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetControllerTiltDesiredIfAvailable(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7841);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetControllerTiltActive(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7843);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetOnlyUseControllerTiltInput(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7845);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetUseTiltForwardAndBack(bool bActive)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7847);
			byte params[4] = { NULL };
			*(bool*)params = bActive;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsKeyboardAvailable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7849);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool IsMouseAvailable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7851);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClientGotoState(ScriptName NewState, ScriptName NewLabel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7853);
			byte params[16] = { NULL };
			*(ScriptName*)params = NewState;
			*(ScriptName*)&params[8] = NewLabel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AskForPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7856);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GivePawn(class Pawn* NewPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7858);
			byte params[4] = { NULL };
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Possess(class Pawn* aPawn, bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7860);
			byte params[8] = { NULL };
			*(class Pawn**)params = aPawn;
			*(bool*)&params[4] = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7869);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerAcknowledgePossession(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7874);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UnPossess()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7876);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PawnDied(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7877);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetHUD(ScriptClass* newHUDType)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7879);
			byte params[4] = { NULL };
			*(ScriptClass**)params = newHUDType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandlePickup(class Inventory* Inv)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7881);
			byte params[4] = { NULL };
			*(class Inventory**)params = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CleanupPRI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7883);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceiveLocalizedMessage(ScriptClass* Message, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7884);
			byte params[20] = { NULL };
			*(ScriptClass**)params = Message;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlaySound(class SoundCue* ASound)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7890);
			byte params[4] = { NULL };
			*(class SoundCue**)params = ASound;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HearSoundFinished(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* AC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7892);
			byte params[4] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)params = AC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void* GetPooledAudioComponent(class SoundCue* ASound, class Actor* SourceActor, bool bStopWhenOwnerDestroyed, bool bUseLocation, Vector SourceLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7897);
			byte params[32] = { NULL };
			*(class SoundCue**)params = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(bool*)&params[8] = bStopWhenOwnerDestroyed;
			*(bool*)&params[12] = bUseLocation;
			*(Vector*)&params[16] = SourceLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(
// ERROR: Unknown object class 'Class Core.ComponentProperty'!
void**)&params[28];
		}
		void ClientHearSound(class SoundCue* ASound, class Actor* SourceActor, Vector SourceLocation, bool bStopWhenOwnerDestroyed, bool bIsOccluded)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7904);
			byte params[28] = { NULL };
			*(class SoundCue**)params = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(Vector*)&params[8] = SourceLocation;
			*(bool*)&params[20] = bStopWhenOwnerDestroyed;
			*(bool*)&params[24] = bIsOccluded;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsClosestLocalPlayerToActor(class Actor* TheActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7916);
			byte params[8] = { NULL };
			*(class Actor**)params = TheActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Kismet_ClientPlaySound(class SoundCue* ASound, class Actor* SourceActor, float VolumeMultiplier, float PitchMultiplier, float FadeInTime, bool bSuppressSubtitles, bool bSuppressSpatialization)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7921);
			byte params[28] = { NULL };
			*(class SoundCue**)params = ASound;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7938);
			byte params[12] = { NULL };
			*(class SoundCue**)params = ASound;
			*(class Actor**)&params[4] = SourceActor;
			*(float*)&params[8] = FadeOutTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayActorFaceFXAnim(class Actor* SourceActor, class FaceFXAnimSet* AnimSet, ScriptString* GroupName, ScriptString* SeqName, class SoundCue* SoundCueToPlay)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7946);
			byte params[36] = { NULL };
			*(class Actor**)params = SourceActor;
			*(class FaceFXAnimSet**)&params[4] = AnimSet;
			*(ScriptString**)&params[8] = GroupName;
			*(ScriptString**)&params[20] = SeqName;
			*(class SoundCue**)&params[32] = SoundCueToPlay;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientMessage(ScriptString* S, ScriptName Type, float MsgLifeTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7952);
			byte params[24] = { NULL };
			*(ScriptString**)params = S;
			*(ScriptName*)&params[12] = Type;
			*(float*)&params[20] = MsgLifeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanCommunicate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7956);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool AllowTTSMessageFrom(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7958);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class SoundCue* CreateTTSSoundCue(ScriptString* StrToSpeak, class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7961);
			byte params[20] = { NULL };
			*(ScriptString**)params = StrToSpeak;
			*(class PlayerReplicationInfo**)&params[12] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SoundCue**)&params[16];
		}
		void Talk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7965);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void TeamTalk()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7970);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpeakTTS(ScriptString* S, class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7973);
			byte params[16] = { NULL };
			*(ScriptString**)params = S;
			*(class PlayerReplicationInfo**)&params[12] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamMessage(class PlayerReplicationInfo* PRI, ScriptString* S, ScriptName Type, float MsgLifeTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7978);
			byte params[28] = { NULL };
			*(class PlayerReplicationInfo**)params = PRI;
			*(ScriptString**)&params[4] = S;
			*(ScriptName*)&params[16] = Type;
			*(float*)&params[24] = MsgLifeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayBeepSound()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7984);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterOnlineDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7985);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnPartyMemberListChanged(bool bJoinedOrLeft, ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7988);
			byte params[24] = { NULL };
			*(bool*)params = bJoinedOrLeft;
			*(ScriptString**)&params[4] = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[16] = PlayerID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnPartyMembersInfoChanged(ScriptString* PlayerName, OnlineSubsystem::UniqueNetId PlayerID, int CustomData1, int CustomData2, int CustomData3, int CustomData4)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7992);
			byte params[36] = { NULL };
			*(ScriptString**)params = PlayerName;
			*(OnlineSubsystem::UniqueNetId*)&params[12] = PlayerID;
			*(int*)&params[20] = CustomData1;
			*(int*)&params[24] = CustomData2;
			*(int*)&params[28] = CustomData3;
			*(int*)&params[32] = CustomData4;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearOnlineDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(7999);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CleanupPawn()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8001);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8009);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FixFOV()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8010);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetFOV(float NewFOV)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8014);
			byte params[4] = { NULL };
			*(float*)params = NewFOV;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetFOV()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8016);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void FOV(float F)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8017);
			byte params[4] = { NULL };
			*(float*)params = F;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AllowTextMessage(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8019);
			byte params[16] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void Say(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8025);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSay(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8027);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientAdminMessage(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8030);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8033);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerTeamSay(ScriptString* msg)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8035);
			byte params[12] = { NULL };
			*(ScriptString**)params = msg;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PreClientTravel(ScriptString* PendingURL, Actor::ETravelType TravelType, bool bIsSeamlessTravel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8039);
			byte params[17] = { NULL };
			*(ScriptString**)params = PendingURL;
			*(Actor::ETravelType*)&params[12] = TravelType;
			*(bool*)&params[16] = bIsSeamlessTravel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class UIInteraction* GetUIController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8045);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class UIInteraction**)params;
		}
		void Camera(ScriptName NewMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8047);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerCamera(ScriptName NewMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8049);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8051);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCameraMode(ScriptName NewCamMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8053);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewCamMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ResetCameraMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8055);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetCameraFade(bool bEnableFading, Object::Color FadeColor, Object::Vector2D FadeAlpha, float FadeTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8058);
			byte params[20] = { NULL };
			*(bool*)params = bEnableFading;
			*(Object::Color*)&params[4] = FadeColor;
			*(Object::Vector2D*)&params[8] = FadeAlpha;
			*(float*)&params[16] = FadeTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool UsingFirstPersonCamera()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8063);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ForceDeathUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8065);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DualServerMove(float TimeStamp0, Vector InAccel0, byte PendingFlags, int View0, float TimeStamp, Vector InAccel, Vector ClientLoc, byte NewFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8067);
			byte params[55] = { NULL };
			*(float*)params = TimeStamp0;
			*(Vector*)&params[4] = InAccel0;
			params[16] = PendingFlags;
			*(int*)&params[20] = View0;
			*(float*)&params[24] = TimeStamp;
			*(Vector*)&params[28] = InAccel;
			*(Vector*)&params[40] = ClientLoc;
			params[52] = NewFlags;
			params[53] = ClientRoll;
			*(int*)&params[56] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OldServerMove(float OldTimeStamp, byte OldAccelX, byte OldAccelY, byte OldAccelZ, byte OldMoveFlags)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8078);
			byte params[8] = { NULL };
			*(float*)params = OldTimeStamp;
			params[4] = OldAccelX;
			params[5] = OldAccelY;
			params[6] = OldAccelZ;
			params[7] = OldMoveFlags;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetServerMoveDeltaTime(float TimeStamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8086);
			byte params[8] = { NULL };
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		void ServerMoveHandleClientError(float TimeStamp, Vector Accel, Vector ClientLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8092);
			byte params[28] = { NULL };
			*(float*)params = TimeStamp;
			*(Vector*)&params[4] = Accel;
			*(Vector*)&params[16] = ClientLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerMove(float TimeStamp, Vector InAccel, Vector ClientLoc, byte MoveFlags, byte ClientRoll, int View)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8109);
			byte params[34] = { NULL };
			*(float*)params = TimeStamp;
			*(Vector*)&params[4] = InAccel;
			*(Vector*)&params[16] = ClientLoc;
			params[28] = MoveFlags;
			params[29] = ClientRoll;
			*(int*)&params[32] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SendClientAdjustment()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8125);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerDrive(float InForward, float InStrafe, float aUp, bool InJump, int View)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8126);
			byte params[20] = { NULL };
			*(float*)params = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = aUp;
			*(bool*)&params[12] = InJump;
			*(int*)&params[16] = View;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessDrive(float InForward, float InStrafe, float InUp, bool InJump)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8133);
			byte params[16] = { NULL };
			*(float*)params = InForward;
			*(float*)&params[4] = InStrafe;
			*(float*)&params[8] = InUp;
			*(bool*)&params[12] = InJump;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessMove(float DeltaTime, Vector newAccel, Actor::EDoubleClickDir DoubleClickMove, Rotator DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8138);
			byte params[29] = { NULL };
			*(float*)params = DeltaTime;
			*(Vector*)&params[4] = newAccel;
			*(Actor::EDoubleClickDir*)&params[16] = DoubleClickMove;
			*(Rotator*)&params[20] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void MoveAutonomous(float DeltaTime, byte CompressedFlags, Vector newAccel, Rotator DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8143);
			byte params[29] = { NULL };
			*(float*)params = DeltaTime;
			params[4] = CompressedFlags;
			*(Vector*)&params[8] = newAccel;
			*(Rotator*)&params[20] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void VeryShortClientAdjustPosition(float TimeStamp, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8153);
			byte params[20] = { NULL };
			*(float*)params = TimeStamp;
			*(float*)&params[4] = NewLocX;
			*(float*)&params[8] = NewLocY;
			*(float*)&params[12] = NewLocZ;
			*(class Actor**)&params[16] = NewBase;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShortClientAdjustPosition(float TimeStamp, ScriptName NewState, Actor::EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, class Actor* NewBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8160);
			byte params[29] = { NULL };
			*(float*)params = TimeStamp;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8169);
			byte params[4] = { NULL };
			*(int*)params = Cap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientAckGoodMove(float TimeStamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8172);
			byte params[4] = { NULL };
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdatePing(float TimeStamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8174);
			byte params[4] = { NULL };
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientAdjustPosition(float TimeStamp, ScriptName NewState, Actor::EPhysics newPhysics, float NewLocX, float NewLocY, float NewLocZ, float NewVelX, float NewVelY, float NewVelZ, class Actor* NewBase)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8175);
			byte params[41] = { NULL };
			*(float*)params = TimeStamp;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8190);
			byte params[53] = { NULL };
			*(float*)params = TimeStamp;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8226);
			byte params[8] = { NULL };
			*(ScriptName*)params = NewState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerUpdatePing(int NewPing)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8228);
			byte params[4] = { NULL };
			*(int*)params = NewPing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearAckedMoves()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8231);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientUpdatePosition()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8233);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class SavedMove* GetFreeMove()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8250);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class SavedMove**)params;
		}
		int CompressAccel(int C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8255);
			byte params[8] = { NULL };
			*(int*)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void ReplicateMove(float DeltaTime, Vector newAccel, Actor::EDoubleClickDir DoubleClickMove, Rotator DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8258);
			byte params[29] = { NULL };
			*(float*)params = DeltaTime;
			*(Vector*)&params[4] = newAccel;
			*(Actor::EDoubleClickDir*)&params[16] = DoubleClickMove;
			*(Rotator*)&params[20] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CallServerMove(class SavedMove* NewMove, Vector ClientLoc, byte ClientRoll, int View, class SavedMove* OldMove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8281);
			byte params[25] = { NULL };
			*(class SavedMove**)params = NewMove;
			*(Vector*)&params[4] = ClientLoc;
			params[16] = ClientRoll;
			*(int*)&params[20] = View;
			*(class SavedMove**)&params[24] = OldMove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void HandleWalking()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8292);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerRestartGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8293);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RestartLevel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8294);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PauseRumbleForAllPlayers(bool bShouldPauseRumble)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8295);
			byte params[4] = { NULL };
			*(bool*)params = bShouldPauseRumble;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CanUnpause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8298);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool SetPause(bool bPause, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* CanUnpauseDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8300);
			byte params[20] = { NULL };
			*(bool*)params = bPause;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[4] = CanUnpauseDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsPaused()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8308);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Pause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8310);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerPause()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8311);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ConditionalPause(bool bDesiredPauseState)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8312);
			byte params[4] = { NULL };
			*(bool*)params = bDesiredPauseState;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ThrowWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8314);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerThrowWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8315);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8318);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8319);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8320);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8324);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartAltFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8326);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StopAltFire(byte FireModeNum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8328);
			byte params[1] = { NULL };
			*params = FireModeNum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetTriggerUseList(float interactDistanceToCheck, float crosshairDist, float minDot, bool bUsuableOnly, ScriptArray<class Trigger*>& out_useList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8330);
			byte params[28] = { NULL };
			*(float*)params = interactDistanceToCheck;
			*(float*)&params[4] = crosshairDist;
			*(float*)&params[8] = minDot;
			*(bool*)&params[12] = bUsuableOnly;
			*(ScriptArray<class Trigger*>*)&params[16] = out_useList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_useList = *(ScriptArray<class Trigger*>*)&params[16];
		}
		bool Use()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8344);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool ServerUse()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8347);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool PerformedUseAction()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8349);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool FindVehicleToDrive()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8351);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool TriggerInteracted()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8361);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Suicide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8376);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerSuicide()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8377);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetName(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8379);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeName(ScriptString* S)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8387);
			byte params[12] = { NULL };
			*(ScriptString**)params = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchTeam()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8389);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangeTeam(ScriptString* TeamName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8391);
			byte params[12] = { NULL };
			*(ScriptString**)params = TeamName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerChangeTeam(int N)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8394);
			byte params[4] = { NULL };
			*(int*)params = N;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetProgressMessage(PlayerController::EProgressMessageType MessageType, ScriptString* Message, ScriptString* Title, bool bIgnoreFutureNetworkMessages)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8399);
			byte params[29] = { NULL };
			*(PlayerController::EProgressMessageType*)params = MessageType;
			*(ScriptString**)&params[4] = Message;
			*(ScriptString**)&params[16] = Title;
			*(bool*)&params[28] = bIgnoreFutureNetworkMessages;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Restart(bool bVehicleTransition)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8404);
			byte params[4] = { NULL };
			*(bool*)params = bVehicleTransition;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerNotifyLoadedWorld(ScriptName WorldPackageName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8406);
			byte params[8] = { NULL };
			*(ScriptName*)params = WorldPackageName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyLoadedWorld(ScriptName WorldPackageName, bool bFinalDest)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8408);
			byte params[12] = { NULL };
			*(ScriptName*)params = WorldPackageName;
			*(bool*)&params[8] = bFinalDest;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HasClientLoadedCurrentWorld()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8414);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ForceSingleNetUpdateFor(class Actor* Target)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8416);
			byte params[4] = { NULL };
			*(class Actor**)params = Target;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void EnterStartState()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8418);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRestart(class Pawn* NewPawn)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8426);
			byte params[4] = { NULL };
			*(class Pawn**)params = NewPawn;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameHasEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8428);
			byte params[8] = { NULL };
			*(class Actor**)params = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientGameEnded(class Actor* EndGameFocus, bool bIsWinner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8431);
			byte params[8] = { NULL };
			*(class Actor**)params = EndGameFocus;
			*(bool*)&params[4] = bIsWinner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyChangedWeapon(class Weapon* PreviousWeapon, class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8434);
			byte params[8] = { NULL };
			*(class Weapon**)params = PreviousWeapon;
			*(class Weapon**)&params[4] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerTick(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8437);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayerMove(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8439);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AimingHelp(bool bInstantHit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8441);
			byte params[8] = { NULL };
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void CameraLookAtFinished(class SeqAct_CameraLookAt* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8445);
			byte params[4] = { NULL };
			*(class SeqAct_CameraLookAt**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		Rotator GetAdjustedAimFor(class Weapon* W, Vector StartFireLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8447);
			byte params[28] = { NULL };
			*(class Weapon**)params = W;
			*(Vector*)&params[4] = StartFireLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[16];
		}
		float AimHelpDot(bool bInstantHit)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8469);
			byte params[8] = { NULL };
			*(bool*)params = bInstantHit;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		bool NotifyLanded(Vector HitNormal, class Actor* FloorActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8472);
			byte params[20] = { NULL };
			*(Vector*)params = HitNormal;
			*(class Actor**)&params[12] = FloorActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void AdjustFOV(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8476);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsLocalPlayerController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8478);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetViewTarget(class Actor* NewViewTarget, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8480);
			byte params[20] = { NULL };
			*(class Actor**)params = NewViewTarget;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetViewTargetWithBlend(class Actor* NewViewTarget, float BlendTime, Camera::EViewTargetBlendFunction BlendFunc, float BlendExp, bool bLockOutgoing)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8483);
			byte params[17] = { NULL };
			*(class Actor**)params = NewViewTarget;
			*(float*)&params[4] = BlendTime;
			*(Camera::EViewTargetBlendFunction*)&params[8] = BlendFunc;
			*(float*)&params[12] = BlendExp;
			*(bool*)&params[16] = bLockOutgoing;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetViewTarget(class Actor* A, Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8490);
			byte params[20] = { NULL };
			*(class Actor**)params = A;
			*(Camera::ViewTargetTransitionParams*)&params[4] = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerVerifyViewTarget()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8494);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpawnPlayerCamera()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8496);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void GetPlayerViewPoint(Vector& out_Location, Rotator& out_Rotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8498);
			byte params[24] = { NULL };
			*(Vector*)params = out_Location;
			*(Rotator*)&params[12] = out_Rotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Location = *(Vector*)params;
			out_Rotation = *(Rotator*)&params[12];
		}
		void ViewShake(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8502);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateRotation(float DeltaTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8504);
			byte params[4] = { NULL };
			*(float*)params = DeltaTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ProcessViewRotation(float DeltaTime, Rotator& out_ViewRotation, Rotator DeltaRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8513);
			byte params[28] = { NULL };
			*(float*)params = DeltaTime;
			*(Rotator*)&params[4] = out_ViewRotation;
			*(Rotator*)&params[16] = DeltaRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_ViewRotation = *(Rotator*)&params[4];
		}
		Rotator LimitViewRotation(Rotator ViewRotation, float ViewPitchMin, float ViewPitchMax)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8517);
			byte params[32] = { NULL };
			*(Rotator*)params = ViewRotation;
			*(float*)&params[12] = ViewPitchMin;
			*(float*)&params[16] = ViewPitchMax;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(Rotator*)&params[20];
		}
		void CheckJumpOrDuck()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8522);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsSpectating()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8698);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ServerSetSpectatorLocation(Vector NewLoc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8700);
			byte params[12] = { NULL };
			*(Vector*)params = NewLoc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewNextPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8733);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerViewPrevPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8734);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ViewAPlayer(int Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8735);
			byte params[4] = { NULL };
			*(int*)params = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerViewSelf(Camera::ViewTargetTransitionParams TransitionParams)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8745);
			byte params[16] = { NULL };
			*(Camera::ViewTargetTransitionParams*)params = TransitionParams;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsWaiting()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8765);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CanRestartPlayer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8985);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8988);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleInput(class SeqAct_ToggleInput* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8990);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleInput**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientIgnoreMoveInput(bool bIgnore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8996);
			byte params[4] = { NULL };
			*(bool*)params = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientIgnoreLookInput(bool bIgnore)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(8998);
			byte params[4] = { NULL };
			*(bool*)params = bIgnore;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisplayDebug(class HUD* HUD, float& out_YL, float& out_YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9000);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = out_YL;
			*(float*)&params[8] = out_YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_YL = *(float*)&params[4];
			out_YPos = *(float*)&params[8];
		}
		void OnDrawText(class SeqAct_DrawText* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9006);
			byte params[4] = { NULL };
			*(class SeqAct_DrawText**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientDrawKismetText(HUD::KismetDrawTextInfo DrawTextInfo, float DisplayTime)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9008);
			byte params[56] = { NULL };
			*(HUD::KismetDrawTextInfo*)params = DrawTextInfo;
			*(float*)&params[52] = DisplayTime;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientClearKismetText(Object::Vector2D MessageOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9011);
			byte params[8] = { NULL };
			*(Object::Vector2D*)params = MessageOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetCameraTarget(class SeqAct_SetCameraTarget* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9080);
			byte params[4] = { NULL };
			*(class SeqAct_SetCameraTarget**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnToggleHUD(class SeqAct_ToggleHUD* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9085);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleHUD**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyTakeHit(class Controller* InstigatedBy, Vector HitLocation, int Damage, ScriptClass* DamageType, Vector Momentum)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9088);
			byte params[36] = { NULL };
			*(class Controller**)params = InstigatedBy;
			*(Vector*)&params[4] = HitLocation;
			*(int*)&params[16] = Damage;
			*(ScriptClass**)&params[20] = DamageType;
			*(Vector*)&params[24] = Momentum;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnForceFeedback(class SeqAct_ForceFeedback* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9095);
			byte params[4] = { NULL };
			*(class SeqAct_ForceFeedback**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9099);
			byte params[4] = { NULL };
			*(class ForceFeedbackWaveform**)params = FFWaveform;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayRumble(class AnimNotify_Rumble* TheAnimNotify)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9100);
			byte params[4] = { NULL };
			*(class AnimNotify_Rumble**)params = TheAnimNotify;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayForceFeedbackWaveform(class ForceFeedbackWaveform* FFWaveform, class Actor* FFWaveformInstigator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9105);
			byte params[8] = { NULL };
			*(class ForceFeedbackWaveform**)params = FFWaveform;
			*(class Actor**)&params[4] = FFWaveformInstigator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsForceFeedbackAllowed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9110);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void OnToggleCinematicMode(class SeqAct_ToggleCinematicMode* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9113);
			byte params[4] = { NULL };
			*(class SeqAct_ToggleCinematicMode**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCinematicMode(bool bInCinematicMode, bool bHidePlayer, bool bAffectsHUD, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsButtons)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9122);
			byte params[24] = { NULL };
			*(bool*)params = bInCinematicMode;
			*(bool*)&params[4] = bHidePlayer;
			*(bool*)&params[8] = bAffectsHUD;
			*(bool*)&params[12] = bAffectsMovement;
			*(bool*)&params[16] = bAffectsTurning;
			*(bool*)&params[20] = bAffectsButtons;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetCinematicMode(bool bInCinematicMode, bool bAffectsMovement, bool bAffectsTurning, bool bAffectsHUD)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9133);
			byte params[16] = { NULL };
			*(bool*)params = bInCinematicMode;
			*(bool*)&params[4] = bAffectsMovement;
			*(bool*)&params[8] = bAffectsTurning;
			*(bool*)&params[12] = bAffectsHUD;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IgnoreMoveInput(bool bNewMoveInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9138);
			byte params[4] = { NULL };
			*(bool*)params = bNewMoveInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsMoveInputIgnored()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9140);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void IgnoreLookInput(bool bNewLookInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9142);
			byte params[4] = { NULL };
			*(bool*)params = bNewLookInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsLookInputIgnored()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9144);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ResetPlayerMovementInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9146);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnConsoleCommand(class SeqAct_ConsoleCommand* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9147);
			byte params[4] = { NULL };
			*(class SeqAct_ConsoleCommand**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientForceGarbageCollection()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9152);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void LevelStreamingStatusChanged(class LevelStreaming* LevelObject, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9154);
			byte params[16] = { NULL };
			*(class LevelStreaming**)params = LevelObject;
			*(bool*)&params[4] = bNewShouldBeLoaded;
			*(bool*)&params[8] = bNewShouldBeVisible;
			*(bool*)&params[12] = bNewShouldBlockOnLoad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUpdateLevelStreamingStatus(ScriptName PackageName, bool bNewShouldBeLoaded, bool bNewShouldBeVisible, bool bNewShouldBlockOnLoad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9160);
			byte params[20] = { NULL };
			*(ScriptName*)params = PackageName;
			*(bool*)&params[8] = bNewShouldBeLoaded;
			*(bool*)&params[12] = bNewShouldBeVisible;
			*(bool*)&params[16] = bNewShouldBlockOnLoad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerUpdateLevelVisibility(ScriptName PackageName, bool bIsVisible)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9165);
			byte params[12] = { NULL };
			*(ScriptName*)params = PackageName;
			*(bool*)&params[8] = bIsVisible;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPrepareMapChange(ScriptName LevelName, bool bFirst, bool bLast)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9168);
			byte params[16] = { NULL };
			*(ScriptName*)params = LevelName;
			*(bool*)&params[8] = bFirst;
			*(bool*)&params[12] = bLast;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DelayedPrepareMapChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9174);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientCommitMapChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9178);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientCancelPendingMapChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9180);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientFlushLevelStreaming()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9182);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientSetBlockOnAsyncLoading()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9183);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsPlayerMuted(OnlineSubsystem::UniqueNetId& Sender)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9189);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = Sender;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Sender = *(OnlineSubsystem::UniqueNetId*)params;
			return *(bool*)&params[8];
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9192);
			byte params[16] = { NULL };
			*(bool*)params = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void SeamlessTravelTo(class PlayerController* NewPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9196);
			byte params[4] = { NULL };
			*(class PlayerController**)params = NewPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeamlessTravelFrom(class PlayerController* OldPC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9198);
			byte params[4] = { NULL };
			*(class PlayerController**)params = OldPC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetOnlineStatus()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9200);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class PlayerController* GetPlayerControllerFromNetId(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9201);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerController**)&params[8];
		}
		void ClientVoiceHandshakeComplete()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9204);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientMutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9206);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientUnmutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9212);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameplayMutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9218);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GameplayUnmutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9221);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerMutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9226);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerUnmutePlayer(OnlineSubsystem::UniqueNetId PlayerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9229);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyDirectorControl(bool bNowControlling)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9233);
			byte params[4] = { NULL };
			*(bool*)params = bNowControlling;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetShowSubtitles(bool bValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9235);
			byte params[4] = { NULL };
			*(bool*)params = bValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsShowingSubtitles()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9237);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClientWasKicked()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9239);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRegisterForArbitration()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9240);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnArbitrationRegisterComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9243);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRegisteredForArbitration(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9246);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnGameInviteAccepted(OnlineGameSearch::OnlineGameSearchResult& InviteResult)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9248);
			byte params[8] = { NULL };
			*(OnlineGameSearch::OnlineGameSearchResult*)params = InviteResult;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			InviteResult = *(OnlineGameSearch::OnlineGameSearchResult*)params;
		}
		bool InviteHasEnoughSpace(class OnlineGameSettings* InviteSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9255);
			byte params[8] = { NULL };
			*(class OnlineGameSettings**)params = InviteSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CanAllPlayersPlayOnline()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9262);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClearInviteDelegates()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9268);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnEndForInviteComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9269);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnDestroyForInviteComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9274);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* ModifyClientURL(ScriptString* URL)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9277);
			byte params[24] = { NULL };
			*(ScriptString**)params = URL;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void OnInviteJoinComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9280);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyInviteFailed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9289);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotAllPlayersCanJoinInvite()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9290);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NotifyNotEnoughSpaceInInvite()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9291);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientArbitratedMatchEnded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9292);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWriteOnlinePlayerScores(int LeaderboardId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9293);
			byte params[4] = { NULL };
			*(int*)params = LeaderboardId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWriteLeaderboardStats(ScriptClass* OnlineStatsWriteClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9306);
			byte params[4] = { NULL };
			*(ScriptClass**)params = OnlineStatsWriteClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetHostUniqueId(OnlineSubsystem::UniqueNetId InHostId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9308);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = InHostId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopNetworkedVoice()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9310);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientStartNetworkedVoice()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9312);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnDestroy(class SeqAct_Destroy* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9314);
			byte params[4] = { NULL };
			*(class SeqAct_Destroy**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DrawDebugTextList(class Canvas* Canvas, float RenderDelta)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9316);
			byte params[8] = { NULL };
			*(class Canvas**)params = Canvas;
			*(float*)&params[4] = RenderDelta;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddDebugText(ScriptString* DebugText, class Actor* SrcActor, float Duration, Vector Offset, Vector DesiredOffset, Object::Color TextColor, bool bSkipOverwriteCheck, bool bAbsoluteLocation, bool bKeepAttachedToActor, class Font* InFont)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9342);
			byte params[64] = { NULL };
			*(ScriptString**)params = DebugText;
			*(class Actor**)&params[12] = SrcActor;
			*(float*)&params[16] = Duration;
			*(Vector*)&params[20] = Offset;
			*(Vector*)&params[32] = DesiredOffset;
			*(Object::Color*)&params[44] = TextColor;
			*(bool*)&params[48] = bSkipOverwriteCheck;
			*(bool*)&params[52] = bAbsoluteLocation;
			*(bool*)&params[56] = bKeepAttachedToActor;
			*(class Font**)&params[60] = InFont;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveDebugText(class Actor* SrcActor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9354);
			byte params[4] = { NULL };
			*(class Actor**)params = SrcActor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveAllDebugStrings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9357);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientRegisterHostStatGuid(ScriptString* StatGuid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9358);
			byte params[12] = { NULL };
			*(ScriptString**)params = StatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegisterHostStatGuidComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9362);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerRegisterClientStatGuid(ScriptString* StatGuid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9367);
			byte params[12] = { NULL };
			*(ScriptString**)params = StatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStartOnlineGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9371);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientEndOnlineGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9376);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CanViewUserCreatedContent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9378);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void IncrementNumberOfMatchesPlayed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9383);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SoakPause(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9387);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientTravelToSession(ScriptName SessionName, ScriptClass* SearchClass, byte PlatformSpecificInfo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9389);
			byte params[13] = { NULL };
			*(ScriptName*)params = SessionName;
			*(ScriptClass**)&params[8] = SearchClass;
			params[12] = PlatformSpecificInfo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnJoinTravelToSessionComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9398);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientReturnToParty(OnlineSubsystem::UniqueNetId RequestingPlayerId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9402);
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = RequestingPlayerId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsSplitscreenPlayer(int& out_SplitscreenPlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9406);
			byte params[8] = { NULL };
			*(int*)params = out_SplitscreenPlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_SplitscreenPlayerIndex = *(int*)params;
			return *(bool*)&params[4];
		}
		class PlayerReplicationInfo* GetSplitscreenPlayerByIndex(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9415);
			byte params[8] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[4];
		}
		int GetSplitscreenPlayerCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9425);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void ClientControlMovieTexture(class TextureMovie* MovieTexture, SeqAct_ControlMovieTexture::EMovieControlType Mode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9430);
			byte params[5] = { NULL };
			*(class TextureMovie**)params = MovieTexture;
			*(SeqAct_ControlMovieTexture::EMovieControlType*)&params[4] = Mode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetForceMipLevelsToBeResident(class MaterialInterface* Material, float ForceDuration, int CinematicTextureGroups)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9433);
			byte params[12] = { NULL };
			*(class MaterialInterface**)params = Material;
			*(float*)&params[4] = ForceDuration;
			*(int*)&params[8] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPrestreamTextures(class Actor* ForcedActor, float ForceDuration, bool bEnableStreaming, int CinematicTextureGroups)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9437);
			byte params[16] = { NULL };
			*(class Actor**)params = ForcedActor;
			*(float*)&params[4] = ForceDuration;
			*(bool*)&params[8] = bEnableStreaming;
			*(int*)&params[12] = CinematicTextureGroups;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPartyLeader()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9442);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		ScriptString* GetPartyMapName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9446);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetPartyGameTypeName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9448);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool GetAchievementProgression(int AchievementId, float& CurrentValue, float& MaxValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9450);
			byte params[16] = { NULL };
			*(int*)params = AchievementId;
			*(float*)&params[4] = CurrentValue;
			*(float*)&params[8] = MaxValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			CurrentValue = *(float*)&params[4];
			MaxValue = *(float*)&params[8];
			return *(bool*)&params[12];
		}
		void OnFlyThroughHasEnded(class SeqAct_FlyThroughHasEnded* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9455);
			byte params[4] = { NULL };
			*(class SeqAct_FlyThroughHasEnded**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Sentinel_SetupForGamebasedTravelTheWorld()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9461);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Sentinel_PreAcquireTravelTheWorldPoints()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9462);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Sentinel_PostAcquireTravelTheWorldPoints()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9463);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InputMatchDelegate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9464);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DoForceFeedbackForScreenShake(class CameraShake* ShakeData, float ShakeScale)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9465);
			byte params[8] = { NULL };
			*(class CameraShake**)params = ShakeData;
			*(float*)&params[4] = ShakeScale;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayCameraShake(class CameraShake* Shake, float Scale, bool bTryForceFeedback, Camera::ECameraAnimPlaySpace PlaySpace, Rotator UserPlaySpaceRot)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9468);
			byte params[25] = { NULL };
			*(class CameraShake**)params = Shake;
			*(float*)&params[4] = Scale;
			*(bool*)&params[8] = bTryForceFeedback;
			*(Camera::ECameraAnimPlaySpace*)&params[12] = PlaySpace;
			*(Rotator*)&params[16] = UserPlaySpaceRot;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopCameraShake(class CameraShake* Shake)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9474);
			byte params[4] = { NULL };
			*(class CameraShake**)params = Shake;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnCameraShake(class SeqAct_CameraShake* inAction)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9476);
			byte params[4] = { NULL };
			*(class SeqAct_CameraShake**)params = inAction;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientPlayCameraAnim(class CameraAnim* AnimToPlay, float Scale, float Rate, float BlendInTime, float BlendOutTime, bool bLoop, bool bRandomStartTime, Camera::ECameraAnimPlaySpace Space, Rotator CustomPlaySpace)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9488);
			byte params[41] = { NULL };
			*(class CameraAnim**)params = AnimToPlay;
			*(float*)&params[4] = Scale;
			*(float*)&params[8] = Rate;
			*(float*)&params[12] = BlendInTime;
			*(float*)&params[16] = BlendOutTime;
			*(bool*)&params[20] = bLoop;
			*(bool*)&params[24] = bRandomStartTime;
			*(Camera::ECameraAnimPlaySpace*)&params[28] = Space;
			*(Rotator*)&params[32] = CustomPlaySpace;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientStopCameraAnim(class CameraAnim* AnimToStop)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9500);
			byte params[4] = { NULL };
			*(class CameraAnim**)params = AnimToStop;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSpawnCameraLensEffect(ScriptClass* LensEffectEmitterClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9502);
			byte params[4] = { NULL };
			*(ScriptClass**)params = LensEffectEmitterClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnSetSoundMode(class SeqAct_SetSoundMode* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9504);
			byte params[4] = { NULL };
			*(class SeqAct_SetSoundMode**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool HasPeerConnection(OnlineSubsystem::UniqueNetId& PeerNetId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9513);
			byte params[12] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PeerNetId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PeerNetId = *(OnlineSubsystem::UniqueNetId*)params;
			return *(bool*)&params[8];
		}
		void BugItGo(float X, float Y, float Z, int Pitch, int Yaw, int Roll)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9516);
			byte params[24] = { NULL };
			*(float*)params = X;
			*(float*)&params[4] = Y;
			*(float*)&params[8] = Z;
			*(int*)&params[12] = Pitch;
			*(int*)&params[16] = Yaw;
			*(int*)&params[20] = Roll;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugItGoString(ScriptString* TheLocation, ScriptString* TheRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9525);
			byte params[24] = { NULL };
			*(ScriptString**)params = TheLocation;
			*(ScriptString**)&params[12] = TheRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugItWorker(Vector TheLocation, Rotator TheRotation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9528);
			byte params[24] = { NULL };
			*(Vector*)params = TheLocation;
			*(Rotator*)&params[12] = TheRotation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugIt(ScriptString* ScreenShotDescription)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9532);
			byte params[12] = { NULL };
			*(ScriptString**)params = ScreenShotDescription;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogOutBugItGoToLogFile(ScriptString* InScreenShotDesc, ScriptString* InGoString, ScriptString* InLocString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9538);
			byte params[36] = { NULL };
			*(ScriptString**)params = InScreenShotDesc;
			*(ScriptString**)&params[12] = InGoString;
			*(ScriptString**)&params[24] = InLocString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogLoc()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9539);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void BugItAI(ScriptString* ScreenShotDescription)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9544);
			byte params[12] = { NULL };
			*(ScriptString**)params = ScreenShotDescription;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LogOutBugItAIGoToLogFile(ScriptString* InScreenShotDesc, ScriptString* InGoString, ScriptString* InLocString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9550);
			byte params[36] = { NULL };
			*(ScriptString**)params = InScreenShotDesc;
			*(ScriptString**)&params[12] = InGoString;
			*(ScriptString**)&params[24] = InLocString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BugItStringCreator(Vector& ViewLocation, Rotator& ViewRotation, ScriptString*& GoString, ScriptString*& LocString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9551);
			byte params[48] = { NULL };
			*(Vector*)params = ViewLocation;
			*(Rotator*)&params[12] = ViewRotation;
			*(ScriptString**)&params[24] = GoString;
			*(ScriptString**)&params[36] = LocString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ViewLocation = *(Vector*)params;
			ViewRotation = *(Rotator*)&params[12];
			GoString = *(ScriptString**)&params[24];
			LocString = *(ScriptString**)&params[36];
		}
		void OnEngineInitialTick()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9556);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableDebugAI()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9557);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReceivedGameClass(ScriptClass* GameClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9564);
			byte params[4] = { NULL };
			*(ScriptClass**)params = GameClass;
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
