#pragma once
#include "Engine.ReplicationInfo.h"
#include "Engine.OnlineSubsystem.UniqueNetId.h"
#include "Engine.TeamInfo.h"
#include "Engine.PlayerReplicationInfo.AutomatedTestingDatum.h"
#include "Engine.Texture2D.h"
#include "Engine.Controller.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.PlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.PlayerReplicationInfo." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.PlayerReplicationInfo." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class PlayerReplicationInfo : public ReplicationInfo
	{
	public:
		ADD_VAR(::BoolProperty, bAdmin, 0x1)
		ADD_VAR(::StrProperty, PlayerName, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PlayerID, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<UniqueNetId>, UniqueId, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bOnlySpectator, 0x4)
		ADD_OBJECT(TeamInfo, Team)
		ADD_VAR(::NameProperty, SessionName, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ExactPing, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, Ping, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsSpectator, 0x2)
		ADD_VAR(::BoolProperty, bReadyToPlay, 0x10)
		ADD_VAR(::BoolProperty, bOutOfLives, 0x20)
		ADD_VAR(::FloatProperty, Score, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<AutomatedTestingDatum>, AutomatedTestingData, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StartTime, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, SavedNetworkAddress, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bWaitingPlayer, 0x8)
		ADD_VAR(::IntProperty, Kills, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bFromPreviousLevel, 0x200)
		ADD_VAR(::BoolProperty, bIsInactive, 0x100)
		ADD_VAR(::StrProperty, OldName, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, Avatar)
		ADD_VAR(::IntProperty, StatAvgOutBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatMaxOutBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatAvgInBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatMaxInBPS, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPKLMax, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPKLMin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPKLTotal, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPingMax, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPingMin, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatPingTotals, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, StatConnectionCounts, 0xFFFFFFFF)
		ADD_OBJECT(ScriptClass, GameMessageClass)
		ADD_VAR(::StrProperty, StringUnknown, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, StringSpectating, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bHasBeenWelcomed, 0x80)
		ADD_VAR(::BoolProperty, bBot, 0x40)
		ADD_VAR(::IntProperty, NumLives, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, TTSSpeaker, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Deaths, 0xFFFFFFFF)
		class PlayerReplicationInfo* Duplicate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.Duplicate");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerReplicationInfo**)params;
			free(params);
			return returnVal;
		}
		void UpdatePing(float TimeStamp)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.UpdatePing");
			byte* params = (byte*)malloc(4);
			*(float*)params = TimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientInitialize(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.ClientInitialize");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPlayerTeam(class TeamInfo* NewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetPlayerTeam");
			byte* params = (byte*)malloc(4);
			*(class TeamInfo**)params = NewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldBroadCastWelcomeMessage(bool bExiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.ShouldBroadCastWelcomeMessage");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bExiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
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
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = YL;
			*(float*)(params + 8) = YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			YL = *(float*)(params + 4);
			YPos = *(float*)(params + 8);
			free(params);
		}
		void SetPlayerName(ScriptArray<wchar_t> S)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetPlayerName");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = S;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetWaitingPlayer(bool B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetWaitingPlayer");
			byte* params = (byte*)malloc(4);
			*(bool*)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OverrideWith(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.OverrideWith");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CopyProperties(class PlayerReplicationInfo* PRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.CopyProperties");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = PRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void IncrementDeaths(int Amt)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.IncrementDeaths");
			byte* params = (byte*)malloc(4);
			*(int*)params = Amt;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SeamlessTravelTo(class PlayerReplicationInfo* NewPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SeamlessTravelTo");
			byte* params = (byte*)malloc(4);
			*(class PlayerReplicationInfo**)params = NewPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetUniqueId(UniqueNetId PlayerUniqueId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.SetUniqueId");
			byte* params = (byte*)malloc(8);
			*(UniqueNetId*)params = PlayerUniqueId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte GetTeamNum()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.GetTeamNum");
			byte* params = (byte*)malloc(1);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *params;
			free(params);
			return returnVal;
		}
		bool IsInvalidName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.IsInvalidName");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
		ScriptArray<wchar_t> GetSpectatorName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.PlayerReplicationInfo.GetSpectatorName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
