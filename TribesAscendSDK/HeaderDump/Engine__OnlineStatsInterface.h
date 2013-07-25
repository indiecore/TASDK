#pragma once
#include "Core__Interface.h"
#include "Engine__OnlineStatsRead.h"
#include "Engine__OnlineStatsWrite.h"
namespace UnrealScript
{
	class OnlineStatsInterface : public Interface
	{
	public:
		bool WriteOnlinePlayerScores(ScriptName SessionName, int LeaderboardId, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& PlayerScores)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.WriteOnlinePlayerScores");
			byte* params = (byte*)malloc(28);
			*(ScriptName*)params = SessionName;
			*(int*)(params + 8) = LeaderboardId;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12) = PlayerScores;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			PlayerScores = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 12);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool RegisterHostStatGuid(ScriptArray<wchar_t>& HostStatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.RegisterHostStatGuid");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = HostStatGuid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			HostStatGuid = *(ScriptArray<wchar_t>*)params;
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetClientStatGuid()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.GetClientStatGuid");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool RegisterStatGuid(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, ScriptArray<wchar_t>& ClientStatGuid)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.RegisterStatGuid");
			byte* params = (byte*)malloc(24);
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)params = PlayerID;
			*(ScriptArray<wchar_t>*)(params + 8) = ClientStatGuid;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ClientStatGuid = *(ScriptArray<wchar_t>*)(params + 8);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetHostStatGuid()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.GetHostStatGuid");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		bool ReadOnlineStats(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& Players, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStats");
			byte* params = (byte*)malloc(20);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = Players;
			*(class OnlineStatsRead**)(params + 12) = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Players = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool ReadOnlineStatsForFriends(byte LocalUserNum, class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStatsForFriends");
			byte* params = (byte*)malloc(9);
			*params = LocalUserNum;
			*(class OnlineStatsRead**)(params + 4) = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ReadOnlineStatsByRank(class OnlineStatsRead* StatsRead, int StartIndex, int NumToRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStatsByRank");
			byte* params = (byte*)malloc(16);
			*(class OnlineStatsRead**)params = StatsRead;
			*(int*)(params + 4) = StartIndex;
			*(int*)(params + 8) = NumToRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool ReadOnlineStatsByRankAroundPlayer(byte LocalUserNum, class OnlineStatsRead* StatsRead, int NumRows)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ReadOnlineStatsByRankAroundPlayer");
			byte* params = (byte*)malloc(13);
			*params = LocalUserNum;
			*(class OnlineStatsRead**)(params + 4) = StatsRead;
			*(int*)(params + 8) = NumRows;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnReadOnlineStatsComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.OnReadOnlineStatsComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnRegisterHostStatGuidComplete(bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.OnRegisterHostStatGuidComplete");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnFlushOnlineStatsComplete(ScriptName SessionName, bool bWasSuccessful)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.OnFlushOnlineStatsComplete");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			*(bool*)(params + 8) = bWasSuccessful;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddReadOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.AddReadOnlineStatsCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearReadOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* ReadOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ClearReadOnlineStatsCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = ReadOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FreeStats(class OnlineStatsRead* StatsRead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.FreeStats");
			byte* params = (byte*)malloc(4);
			*(class OnlineStatsRead**)params = StatsRead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool WriteOnlineStats(ScriptName SessionName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* Player, class OnlineStatsWrite* StatsWrite)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.WriteOnlineStats");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = SessionName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 8) = Player;
			*(class OnlineStatsWrite**)(params + 16) = StatsWrite;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		bool FlushOnlineStats(ScriptName SessionName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.FlushOnlineStats");
			byte* params = (byte*)malloc(12);
			*(ScriptName*)params = SessionName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void AddFlushOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FlushOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.AddFlushOnlineStatsCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = FlushOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearFlushOnlineStatsCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* FlushOnlineStatsCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ClearFlushOnlineStatsCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = FlushOnlineStatsCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddRegisterHostStatGuidCompleteDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterHostStatGuidCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.AddRegisterHostStatGuidCompleteDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterHostStatGuidCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearRegisterHostStatGuidCompleteDelegateDelegate(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* RegisterHostStatGuidCompleteDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.OnlineStatsInterface.ClearRegisterHostStatGuidCompleteDelegateDelegate");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = RegisterHostStatGuidCompleteDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
