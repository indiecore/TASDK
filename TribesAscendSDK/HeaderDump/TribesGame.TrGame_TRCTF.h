#pragma once
#include "TribesGame.TrFlagBase.h"
#include "TribesGame.TrGame.h"
#include "Engine.Pawn.h"
#include "TribesGame.TrFlagCTF.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.AIController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.PlayerController.h"
#include "UTGame.UTPlayerController.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrGame_TRCTF : public TrGame
	{
	public:
		ADD_OBJECT(TrFlagCTF, m_Flags, 1456)
		ADD_OBJECT(ScriptClass, AnnouncerMessageClass, 1464)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.ApplyServerSettings");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetHandicapNeed");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool GetLocationFor(class Pawn* StatusPawn, class Actor*& LocationObject, int& MessageIndex, int LocationSpeechOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetLocationFor");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = StatusPawn;
			*(class Actor**)&params[4] = LocationObject;
			*(int*)&params[8] = MessageIndex;
			*(int*)&params[12] = LocationSpeechOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			LocationObject = *(class Actor**)&params[4];
			MessageIndex = *(int*)&params[8];
			return *(bool*)&params[16];
		}
		void RegisterFlag(class UTCarriedObject* F, int TeamIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.RegisterFlag");
			byte params[8] = { NULL };
			*(class UTCarriedObject**)&params[0] = F;
			*(int*)&params[4] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NearGoal(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.NearGoal");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WantFastSpawnFor(class AIController* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.WantFastSpawnFor");
			byte params[8] = { NULL };
			*(class AIController**)&params[0] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.CheckEndGame");
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ScoreFlag(class Controller* Scorer, class TrFlagBase* theFlag)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.ScoreFlag");
			byte params[8] = { NULL };
			*(class Controller**)&params[0] = Scorer;
			*(class TrFlagBase**)&params[4] = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewObjective(class PlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.ViewObjective");
			byte params[4] = { NULL };
			*(class PlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetAutoObjectiveFor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetAutoObjectiveFor");
			byte params[8] = { NULL };
			*(class UTPlayerController**)&params[0] = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void AnnounceScore(int ScoringTeam)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.AnnounceScore");
			byte params[4] = { NULL };
			*(int*)&params[0] = ScoringTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.CheckScore");
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)&params[0] = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrGame_TRCTF.GetGameTypeId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
	};
}
#undef ADD_OBJECT
