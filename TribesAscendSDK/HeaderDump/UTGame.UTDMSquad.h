#pragma once
#include "Engine.Controller.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTSquadAI.h"
#include "UTGame.UTVehicle.h"
#include "Engine.HUD.h"
#include "Engine.Pawn.h"
namespace UnrealScript
{
	class UTDMSquad : public UTSquadAI
	{
	public:
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47186);
			byte params[12] = { NULL };
			*(class HUD**)params = HUD;
			*(float*)&params[4] = YL;
			*(float*)&params[8] = YPos;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			YL = *(float*)&params[4];
			YPos = *(float*)&params[8];
		}
		bool IsDefending(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47193);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void AddBot(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47196);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveBot(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47198);
			byte params[4] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool ShouldDeferTo(class Controller* C)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47200);
			byte params[8] = { NULL };
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckSquadObjectives(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47203);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool WaitAtThisPosition(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47206);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool NearFormationCenter(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47209);
			byte params[8] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool BeDevious(class Pawn* Enemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47212);
			byte params[8] = { NULL };
			*(class Pawn**)params = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47215);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		bool SetEnemy(class UTBot* B, class Pawn* NewEnemy)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47217);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class Pawn**)&params[4] = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47222);
			byte params[8] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool AllowContinueOnFoot(class UTBot* B, class UTVehicle* V)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47225);
			byte params[12] = { NULL };
			*(class UTBot**)params = B;
			*(class UTVehicle**)&params[4] = V;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		float VehicleDesireability(class UTVehicle* V, class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47229);
			byte params[12] = { NULL };
			*(class UTVehicle**)params = V;
			*(class UTBot**)&params[4] = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[8];
		}
		bool AssignSquadResponsibility(class UTBot* B)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(47233);
			byte params[8] = { NULL };
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
	};
}
