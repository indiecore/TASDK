#pragma once
#include "Core.Interface.h"
#include "Engine.OnlineSubsystem.h"
#include "Engine.OnlineStatsRead.h"
#include "Engine.OnlineStatsWrite.h"
namespace UnrealScript
{
	class OnlineStatsInterface : public Interface
	{
	public:
		bool WriteOnlinePlayerScores(ScriptName SessionName, int LeaderboardId, ScriptArray<OnlineSubsystem::OnlinePlayerScore>& PlayerScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.WriteOnlinePlayerScores");
			byte params[28] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(int*)&params[8] = LeaderboardId;
			*(ScriptArray<OnlineSubsystem::OnlinePlayerScore>*)&params[12] = PlayerScores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerScores = *(ScriptArray<OnlineSubsystem::OnlinePlayerScore>*)&params[12];
			return *(bool*)&params[24];
		}
		bool RegisterHostStatGuid(ScriptString*& HostStatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.RegisterHostStatGuid");
			byte params[16] = { NULL };
			*(ScriptString**)&params[0] = HostStatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HostStatGuid = *(ScriptString**)&params[0];
			return *(bool*)&params[12];
		}
		ScriptString* GetClientStatGuid()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.GetClientStatGuid");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool RegisterStatGuid(OnlineSubsystem::UniqueNetId PlayerID, ScriptString*& ClientStatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.RegisterStatGuid");
			byte params[24] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)&params[0] = PlayerID;
			*(ScriptString**)&params[8] = ClientStatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ClientStatGuid = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		ScriptString* GetHostStatGuid()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.GetHostStatGuid");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool ReadOnlineStats(ScriptArray<OnlineSubsystem::UniqueNetId>& Players, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStats");
			byte params[20] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0] = Players;
			*(class OnlineStatsRead**)&params[12] = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)&params[0];
			return *(bool*)&params[16];
		}
		bool ReadOnlineStatsForFriends(byte LocalUserNum, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStatsForFriends");
			byte params[9] = { NULL };
			params[0] = LocalUserNum;
			*(class OnlineStatsRead**)&params[4] = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ReadOnlineStatsByRank(class OnlineStatsRead* StatsRead, int StartIndex, int NumToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStatsByRank");
			byte params[16] = { NULL };
			*(class OnlineStatsRead**)&params[0] = StatsRead;
			*(int*)&params[4] = StartIndex;
			*(int*)&params[8] = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ReadOnlineStatsByRankAroundPlayer(byte LocalUserNum, class OnlineStatsRead* StatsRead, int NumRows)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStatsByRankAroundPlayer");
			byte params[13] = { NULL };
			params[0] = LocalUserNum;
			*(class OnlineStatsRead**)&params[4] = StatsRead;
			*(int*)&params[8] = NumRows;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnReadOnlineStatsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.OnReadOnlineStatsComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegisterHostStatGuidComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.OnRegisterHostStatGuidComplete");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFlushOnlineStatsComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.OnFlushOnlineStatsComplete");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.AddReadOnlineStatsCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ClearReadOnlineStatsCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = ReadOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FreeStats(class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.FreeStats");
			byte params[4] = { NULL };
			*(class OnlineStatsRead**)&params[0] = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WriteOnlineStats(ScriptName SessionName, OnlineSubsystem::UniqueNetId Player, class OnlineStatsWrite* StatsWrite)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.WriteOnlineStats");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = Player;
			*(class OnlineStatsWrite**)&params[16] = StatsWrite;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool FlushOnlineStats(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.FlushOnlineStats");
			byte params[12] = { NULL };
			*(ScriptName*)&params[0] = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddFlushOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FlushOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.AddFlushOnlineStatsCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = FlushOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlushOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FlushOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ClearFlushOnlineStatsCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = FlushOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRegisterHostStatGuidCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterHostStatGuidCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.AddRegisterHostStatGuidCompleteDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = RegisterHostStatGuidCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRegisterHostStatGuidCompleteDelegateDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterHostStatGuidCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ClearRegisterHostStatGuidCompleteDelegateDelegate");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = RegisterHostStatGuidCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
