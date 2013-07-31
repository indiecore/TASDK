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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9304);
			byte params[28] = { NULL };
			*(ScriptName*)params = SessionName;
			*(int*)&params[8] = LeaderboardId;
			*(ScriptArray<OnlineSubsystem::OnlinePlayerScore>*)&params[12] = PlayerScores;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			PlayerScores = *(ScriptArray<OnlineSubsystem::OnlinePlayerScore>*)&params[12];
			return *(bool*)&params[24];
		}
		bool RegisterHostStatGuid(ScriptString*& HostStatGuid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9360);
			byte params[16] = { NULL };
			*(ScriptString**)params = HostStatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			HostStatGuid = *(ScriptString**)params;
			return *(bool*)&params[12];
		}
		ScriptString* GetClientStatGuid()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9365);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool RegisterStatGuid(OnlineSubsystem::UniqueNetId PlayerID, ScriptString*& ClientStatGuid)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9369);
			byte params[24] = { NULL };
			*(OnlineSubsystem::UniqueNetId*)params = PlayerID;
			*(ScriptString**)&params[8] = ClientStatGuid;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ClientStatGuid = *(ScriptString**)&params[8];
			return *(bool*)&params[20];
		}
		ScriptString* GetHostStatGuid()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(16958);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool ReadOnlineStats(ScriptArray<OnlineSubsystem::UniqueNetId>& Players, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22756);
			byte params[20] = { NULL };
			*(ScriptArray<OnlineSubsystem::UniqueNetId>*)params = Players;
			*(class OnlineStatsRead**)&params[12] = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Players = *(ScriptArray<OnlineSubsystem::UniqueNetId>*)params;
			return *(bool*)&params[16];
		}
		bool ReadOnlineStatsForFriends(byte LocalUserNum, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22761);
			byte params[9] = { NULL };
			*params = LocalUserNum;
			*(class OnlineStatsRead**)&params[4] = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool ReadOnlineStatsByRank(class OnlineStatsRead* StatsRead, int StartIndex, int NumToRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22765);
			byte params[16] = { NULL };
			*(class OnlineStatsRead**)params = StatsRead;
			*(int*)&params[4] = StartIndex;
			*(int*)&params[8] = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool ReadOnlineStatsByRankAroundPlayer(byte LocalUserNum, class OnlineStatsRead* StatsRead, int NumRows)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22770);
			byte params[13] = { NULL };
			*params = LocalUserNum;
			*(class OnlineStatsRead**)&params[4] = StatsRead;
			*(int*)&params[8] = NumRows;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void OnReadOnlineStatsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22775);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnRegisterHostStatGuidComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22778);
			byte params[4] = { NULL };
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnFlushOnlineStatsComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22780);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			*(bool*)&params[8] = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddReadOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22782);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearReadOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22784);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FreeStats(class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22786);
			byte params[4] = { NULL };
			*(class OnlineStatsRead**)params = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WriteOnlineStats(ScriptName SessionName, OnlineSubsystem::UniqueNetId Player, class OnlineStatsWrite* StatsWrite)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22788);
			byte params[24] = { NULL };
			*(ScriptName*)params = SessionName;
			*(OnlineSubsystem::UniqueNetId*)&params[8] = Player;
			*(class OnlineStatsWrite**)&params[16] = StatsWrite;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		bool FlushOnlineStats(ScriptName SessionName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22793);
			byte params[12] = { NULL };
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void AddFlushOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FlushOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22798);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = FlushOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearFlushOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FlushOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22800);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = FlushOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddRegisterHostStatGuidCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterHostStatGuidCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22808);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterHostStatGuidCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearRegisterHostStatGuidCompleteDelegateDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterHostStatGuidCompleteDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(22810);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterHostStatGuidCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
