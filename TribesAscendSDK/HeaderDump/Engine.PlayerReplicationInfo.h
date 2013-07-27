#pragma once
#include "Engine.ReplicationInfo.h"
#include "Engine.Texture2D.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.TeamInfo.h"
#include "Engine.AudioDevice.h"
#include "Engine.Controller.h"
#include "Engine.HUD.h"
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
	class PlayerReplicationInfo : public ReplicationInfo
	{
	public:
		class AutomatedTestingDatum
		{
		public:
			ADD_STRUCT(int, NumberOfMatchesPlayed, 0)
			ADD_STRUCT(int, NumMapListCyclesDone, 4)
		};
		ADD_BOOL(bAdmin, 524, 0x1)
		ADD_STRUCT(ScriptString*, PlayerName, 492)
		ADD_STRUCT(int, PlayerID, 516)
		ADD_STRUCT(OnlineSubsystem::UniqueNetId, UniqueId, 580)
		ADD_BOOL(bOnlySpectator, 524, 0x4)
		ADD_OBJECT(TeamInfo, Team, 520)
		ADD_STRUCT(ScriptName, SessionName, 588)
		ADD_STRUCT(float, ExactPing, 564)
		ADD_STRUCT(byte, Ping, 484)
		ADD_BOOL(bIsSpectator, 524, 0x2)
		ADD_BOOL(bReadyToPlay, 524, 0x10)
		ADD_BOOL(bOutOfLives, 524, 0x20)
		ADD_STRUCT(float, Score, 476)
		ADD_STRUCT(PlayerReplicationInfo::AutomatedTestingDatum, AutomatedTestingData, 596)
		ADD_STRUCT(int, StartTime, 528)
		ADD_STRUCT(ScriptString*, SavedNetworkAddress, 568)
		ADD_BOOL(bWaitingPlayer, 524, 0x8)
		ADD_STRUCT(int, Kills, 556)
		ADD_BOOL(bFromPreviousLevel, 524, 0x200)
		ADD_BOOL(bIsInactive, 524, 0x100)
		ADD_STRUCT(ScriptString*, OldName, 504)
		ADD_OBJECT(Texture2D, Avatar, 648)
		ADD_STRUCT(int, StatAvgOutBPS, 644)
		ADD_STRUCT(int, StatMaxOutBPS, 640)
		ADD_STRUCT(int, StatAvgInBPS, 636)
		ADD_STRUCT(int, StatMaxInBPS, 632)
		ADD_STRUCT(int, StatPKLMax, 628)
		ADD_STRUCT(int, StatPKLMin, 624)
		ADD_STRUCT(int, StatPKLTotal, 620)
		ADD_STRUCT(int, StatPingMax, 616)
		ADD_STRUCT(int, StatPingMin, 612)
		ADD_STRUCT(int, StatPingTotals, 608)
		ADD_STRUCT(int, StatConnectionCounts, 604)
		ADD_OBJECT(ScriptClass, GameMessageClass, 560)
		ADD_STRUCT(ScriptString*, StringUnknown, 544)
		ADD_STRUCT(ScriptString*, StringSpectating, 532)
		ADD_BOOL(bHasBeenWelcomed, 524, 0x80)
		ADD_BOOL(bBot, 524, 0x40)
		ADD_STRUCT(int, NumLives, 488)
		ADD_STRUCT(AudioDevice::ETTSSpeaker, TTSSpeaker, 485)
		ADD_STRUCT(int, Deaths, 480)
		class PlayerReplicationInfo* Duplicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.Duplicate");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class PlayerReplicationInfo**)&params[0];
		}
		void UpdatePing(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.UpdatePing");
			byte params[4] = { NULL };
			*(float*)&params[0] = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitialize(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.ClientInitialize");
			byte params[4] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPlayerTeam(class TeamInfo* NewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetPlayerTeam");
			byte params[4] = { NULL };
			*(class TeamInfo**)&params[0] = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.ReplicatedEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldBroadCastWelcomeMessage(bool bExiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.ShouldBroadCastWelcomeMessage");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bExiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Reset()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.Reset");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.GetHumanReadableName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.DisplayDebug");
			byte params[12] = { NULL };
			*(class HUD**)&params[0] = HUD;
			*(float*)&params[4] = YL;
			*(float*)&params[8] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YL = *(float*)&params[4];
			YPos = *(float*)&params[8];
		}
		void SetPlayerName(ScriptString* S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetPlayerName");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = S;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetWaitingPlayer(bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetWaitingPlayer");
			byte params[4] = { NULL };
			*(bool*)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OverrideWith(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.OverrideWith");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CopyProperties(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.CopyProperties");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = PRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void IncrementDeaths(int Amt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.IncrementDeaths");
			byte params[4] = { NULL };
			*(int*)&params[0] = Amt;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SeamlessTravelTo(class PlayerReplicationInfo* NewPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SeamlessTravelTo");
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = NewPRI;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetUniqueId(OnlineSubsystem::UniqueNetId PlayerUniqueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetUniqueId");
			byte params[8] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerUniqueId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.GetTeamNum");
			byte params[1] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[0];
		}
		bool IsInvalidName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.IsInvalidName");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void RegisterPlayerWithSession()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.RegisterPlayerWithSession");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UnregisterPlayerFromSession()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.UnregisterPlayerFromSession");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.GetSpectatorName");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
