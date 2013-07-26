#pragma once
#include "TribesGame.TrGame.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrFlagRabbit.h"
#include "Engine.PlayerStart.h"
#include "Engine.Controller.h"
#include "UTGame.UTTeamInfo.h"
#include "TribesGame.TrGame_TRRabbit.ScoreStruct.h"
#include "TribesGame.TrPlayerController.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TRRabbit." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGame_TRRabbit." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRRabbit : public TrGame
	{
	public:
		ADD_OBJECT(PlayerReplicationInfo, m_HolderPRI)
		ADD_OBJECT(PlayerReplicationInfo, m_Leader)
		ADD_VAR(::FloatProperty, m_fScoreInterval, 0xFFFFFFFF)
		ADD_OBJECT(TrFlagRabbit, m_Flag)
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RegisterFlag(class TrFlagRabbit* F)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.RegisterFlag");
			byte* params = (byte*)malloc(4);
			*(class TrFlagRabbit**)params = F;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PickedUpFlag(class Controller* Holder)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PickedUpFlag");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Holder;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DroppedFlag()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.DroppedFlag");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.SetTeam");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)(params + 4) = NewTeam;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ScoreFlagTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ScoreFlagTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreFlagHold(bool firstPass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ScoreFlagHold");
			byte* params = (byte*)malloc(4);
			*(bool*)params = firstPass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ChangePreviousRabbitTeam()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.ChangePreviousRabbitTeam");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScoreStruct MakeScoreStruct(class TrPlayerController* C, float Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.MakeScoreStruct");
			byte* params = (byte*)malloc(16);
			*(class TrPlayerController**)params = C;
			*(float*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScoreStruct*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SortPlayerScores(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.SortPlayerScores");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		byte PickTeam(byte Num, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PickTeam");
			byte* params = (byte*)malloc(6);
			*params = Num;
			*(class Controller**)(params + 4) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 8);
			free(params);
			return returnVal;
		}
		byte PickTeamForMigration(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PickTeamForMigration");
			byte* params = (byte*)malloc(5);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		void PlayEndOfMatchMessage()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.PlayEndOfMatchMessage");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DiscardInventory(class Pawn* Other, class Controller* Killer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.DiscardInventory");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			*(class Controller**)(params + 4) = Killer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.RatePlayerStart");
			byte* params = (byte*)malloc(13);
			*(class PlayerStart**)params = P;
			*(params + 4) = Team;
			*(class Controller**)(params + 8) = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRRabbit.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
