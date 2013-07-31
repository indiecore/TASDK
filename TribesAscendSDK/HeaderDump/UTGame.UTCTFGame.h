#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "UTGame.UTTeamGame.h"
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "UTGame.UTCTFFlag.h"
#include "Engine.PlayerReplicationInfo.h"
#include "UTGame.UTCarriedObject.h"
#include "Engine.AIController.h"
#include "UTGame.UTPlayerController.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFGame : public UTTeamGame
	{
	public:
		ADD_OBJECT(ScriptClass, AnnouncerMessageClass, 1336)
		ADD_OBJECT(UTCTFFlag, Flags, 1328)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45359);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetEndGameFocus(class PlayerReplicationInfo* Winner)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45365);
			byte params[4] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int GetHandicapNeed(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45368);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool GetLocationFor(class Pawn* StatusPawn, class Actor*& LocationObject, int& MessageIndex, int LocationSpeechOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45371);
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45380);
			byte params[8] = { NULL };
			*(class UTCarriedObject**)params = F;
			*(int*)&params[4] = TeamIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool NearGoal(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45383);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WantFastSpawnFor(class AIController* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45387);
			byte params[8] = { NULL };
			*(class AIController**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45391);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void ScoreFlag(class Controller* Scorer, class UTCTFFlag* theFlag)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45398);
			byte params[8] = { NULL };
			*(class Controller**)params = Scorer;
			*(class UTCTFFlag**)&params[4] = theFlag;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ViewObjective(class PlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45416);
			byte params[4] = { NULL };
			*(class PlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Actor* GetAutoObjectiveFor(class UTPlayerController* PC)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(45419);
			byte params[8] = { NULL };
			*(class UTPlayerController**)params = PC;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Actor**)&params[4];
		}
	};
}
#undef ADD_OBJECT
