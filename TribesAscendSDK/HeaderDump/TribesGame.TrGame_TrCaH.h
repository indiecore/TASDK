#pragma once
#include "TribesGame.TrGame.h"
#include "Engine.PlayerStart.h"
#include "Engine.Controller.h"
#include "UTGame.UTTeamInfo.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrCaHCapturePoint.h"
#include "TribesGame.TrPawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrGame_TrCaH." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrGame_TrCaH : public TrGame
	{
	public:
		ADD_VAR(::IntProperty, m_nPostCapturePointTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nTicketCountTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_5PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_4PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_3PointGoalScore, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, m_nRemainingTicketTime, 0xFFFFFFFF)
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetTeam(class Controller* Other, class UTTeamInfo* NewTeam, bool bNewTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.SetTeam");
			byte* params = (byte*)malloc(12);
			*(class Controller**)params = Other;
			*(class UTTeamInfo**)(params + 4) = NewTeam;
			*(bool*)(params + 8) = bNewTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Logout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.Logout");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ResetLevel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ResetLevel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.CheckScore");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void GotoPendingRoundStartTimer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.GotoPendingRoundStartTimer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		void AwardPoint(byte TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.AwardPoint");
			byte* params = (byte*)malloc(1);
			*params = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RestartPlayer(class Controller* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.RestartPlayer");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.GetGameTypeId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void OnCapturePointHeld(class TrCaHCapturePoint* HeldPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.OnCapturePointHeld");
			byte* params = (byte*)malloc(4);
			*(class TrCaHCapturePoint**)params = HeldPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnCapturePointOwnershipChanged(class TrCaHCapturePoint* PointThatChanged, class TrPawn* TRP)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.OnCapturePointOwnershipChanged");
			byte* params = (byte*)malloc(8);
			*(class TrCaHCapturePoint**)params = PointThatChanged;
			*(class TrPawn**)(params + 4) = TRP;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float RatePlayerStart(class PlayerStart* P, byte Team, class Controller* Player)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.RatePlayerStart");
			byte* params = (byte*)malloc(13);
			*(class PlayerStart**)params = P;
			*(params + 4) = Team;
			*(class Controller**)(params + 8) = Player;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		class PlayerStart* ChoosePlayerStart(class Controller* Player, byte InTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TrCaH.ChoosePlayerStart");
			byte* params = (byte*)malloc(9);
			*(class Controller**)params = Player;
			*(params + 4) = InTeam;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class PlayerStart**)(params + 8);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
