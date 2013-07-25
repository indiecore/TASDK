#pragma once
#include "Engine__GameplayEvents.h"
#include "Engine__GameInfo.h"
#include "Engine__Controller.h"
#include "Engine__TeamInfo.h"
#include "Engine__CoverLink.h"
#include "Engine__GenericParamListStatEntry.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.GameplayEventsWriter." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GameplayEventsWriter : public GameplayEvents
	{
	public:
		ADD_OBJECT(GameInfo, Game)
		int ResolvePlayerIndex(class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.ResolvePlayerIndex");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void StartLogging(float HeartbeatDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.StartLogging");
			byte* params = (byte*)malloc(4);
			*(float*)params = HeartbeatDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ResetLogging(float HeartbeatDelta)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.ResetLogging");
			byte* params = (byte*)malloc(4);
			*(float*)params = HeartbeatDelta;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void EndLogging()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.EndLogging");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsSessionInProgress()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.IsSessionInProgress");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool OpenStatsFile(ScriptArray<wchar_t> Filename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.OpenStatsFile");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = Filename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		void CloseStatsFile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.CloseStatsFile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool SerializeHeader()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.SerializeHeader");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool SerializeFooter()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.SerializeFooter");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Poll()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.Poll");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void LogGameIntEvent(int EventID, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGameIntEvent");
			byte* params = (byte*)malloc(8);
			*(int*)params = EventID;
			*(int*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogGameStringEvent(int EventID, ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGameStringEvent");
			byte* params = (byte*)malloc(16);
			*(int*)params = EventID;
			*(ScriptArray<wchar_t>*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogGameFloatEvent(int EventID, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGameFloatEvent");
			byte* params = (byte*)malloc(8);
			*(int*)params = EventID;
			*(float*)(params + 4) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogGamePositionEvent(int EventID, Vector& Position, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogGamePositionEvent");
			byte* params = (byte*)malloc(20);
			*(int*)params = EventID;
			*(Vector*)(params + 4) = Position;
			*(float*)(params + 16) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Position = *(Vector*)(params + 4);
			free(params);
		}
		void LogTeamIntEvent(int EventID, class TeamInfo* Team, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogTeamIntEvent");
			byte* params = (byte*)malloc(12);
			*(int*)params = EventID;
			*(class TeamInfo**)(params + 4) = Team;
			*(int*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogTeamFloatEvent(int EventID, class TeamInfo* Team, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogTeamFloatEvent");
			byte* params = (byte*)malloc(12);
			*(int*)params = EventID;
			*(class TeamInfo**)(params + 4) = Team;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogTeamStringEvent(int EventID, class TeamInfo* Team, ScriptArray<wchar_t> Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogTeamStringEvent");
			byte* params = (byte*)malloc(20);
			*(int*)params = EventID;
			*(class TeamInfo**)(params + 4) = Team;
			*(ScriptArray<wchar_t>*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogPlayerIntEvent(int EventID, class Controller* Player, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerIntEvent");
			byte* params = (byte*)malloc(12);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(int*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogPlayerFloatEvent(int EventID, class Controller* Player, float Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerFloatEvent");
			byte* params = (byte*)malloc(12);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(float*)(params + 8) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogPlayerStringEvent(int EventID, class Controller* Player, ScriptArray<wchar_t> EventString)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerStringEvent");
			byte* params = (byte*)malloc(20);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(ScriptArray<wchar_t>*)(params + 8) = EventString;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogPlayerSpawnEvent(int EventID, class Controller* Player, ScriptClass* PawnClass, int TeamID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerSpawnEvent");
			byte* params = (byte*)malloc(16);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(ScriptClass**)(params + 8) = PawnClass;
			*(int*)(params + 12) = TeamID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogPlayerLoginChange(int EventID, class Controller* Player, ScriptArray<wchar_t> PlayerName, 
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void* PlayerID, bool bSplitScreen)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerLoginChange");
			byte* params = (byte*)malloc(32);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(ScriptArray<wchar_t>*)(params + 8) = PlayerName;
			*(
// WARNING: Unknown structure type 'ScriptStruct Engine.OnlineSubsystem.UniqueNetId'!
void**)(params + 20) = PlayerID;
			*(bool*)(params + 28) = bSplitScreen;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogAllPlayerPositionsEvent(int EventID)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogAllPlayerPositionsEvent");
			byte* params = (byte*)malloc(4);
			*(int*)params = EventID;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogPlayerKillDeath(int EventID, int KillType, class Controller* Killer, ScriptClass* dmgType, class Controller* Dead)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerKillDeath");
			byte* params = (byte*)malloc(20);
			*(int*)params = EventID;
			*(int*)(params + 4) = KillType;
			*(class Controller**)(params + 8) = Killer;
			*(ScriptClass**)(params + 12) = dmgType;
			*(class Controller**)(params + 16) = Dead;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogPlayerPlayerEvent(int EventID, class Controller* Player, class Controller* Target)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogPlayerPlayerEvent");
			byte* params = (byte*)malloc(12);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(class Controller**)(params + 8) = Target;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogWeaponIntEvent(int EventID, class Controller* Player, ScriptClass* WeaponClass, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogWeaponIntEvent");
			byte* params = (byte*)malloc(16);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(ScriptClass**)(params + 8) = WeaponClass;
			*(int*)(params + 12) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogDamageEvent(int EventID, class Controller* Player, ScriptClass* dmgType, class Controller* Target, int Amount)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogDamageEvent");
			byte* params = (byte*)malloc(20);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(ScriptClass**)(params + 8) = dmgType;
			*(class Controller**)(params + 12) = Target;
			*(int*)(params + 16) = Amount;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogProjectileIntEvent(int EventID, class Controller* Player, ScriptClass* Proj, int Value)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogProjectileIntEvent");
			byte* params = (byte*)malloc(16);
			*(int*)params = EventID;
			*(class Controller**)(params + 4) = Player;
			*(ScriptClass**)(params + 8) = Proj;
			*(int*)(params + 12) = Value;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LogSystemPollEvents()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.LogSystemPollEvents");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class GenericParamListStatEntry* GetGenericParamListEntry()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.GetGenericParamListEntry");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GenericParamListStatEntry**)params;
			free(params);
			return returnVal;
		}
		void RecordAIPathFail(class Controller* AI, ScriptArray<wchar_t> Reason, Vector Dest)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.RecordAIPathFail");
			byte* params = (byte*)malloc(28);
			*(class Controller**)params = AI;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			*(Vector*)(params + 16) = Dest;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int RecordCoverLinkFireLinks(class CoverLink* Link, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.GameplayEventsWriter.RecordCoverLinkFireLinks");
			byte* params = (byte*)malloc(12);
			*(class CoverLink**)params = Link;
			*(class Controller**)(params + 4) = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_OBJECT
