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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90617);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ApplyServerSettings()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90619);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90621);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool GetLocationFor(class Pawn* StatusPawn, class Actor*& LocationObject, int& MessageIndex, int LocationSpeechOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90624);
			byte params[20] = { NULL };
			*(class Pawn**)params = StatusPawn;
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90633);
			byte params[8] = { NULL };
			*(class UTCarriedObject**)params = F;
			*(int*)&params[4] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NearGoal(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90637);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WantFastSpawnFor(class AIController* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90641);
			byte params[8] = { NULL };
			*(class AIController**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90644);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ScoreFlag(class Controller* Scorer, class TrFlagBase* theFlag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90650);
			byte params[8] = { NULL };
			*(class Controller**)params = Scorer;
			*(class TrFlagBase**)&params[4] = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewObjective(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90672);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetAutoObjectiveFor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90675);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
		void AnnounceScore(int ScoringTeam)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90678);
			byte params[4] = { NULL };
			*(int*)params = ScoringTeam;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CheckScore(class PlayerReplicationInfo* Scorer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90683);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetGameTypeId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(90686);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
	};
}
#undef ADD_OBJECT
