#pragma once
#include "UTGame__UTSquadAI.h"
#include "UTGame__UTVehicle.h"
#include "Engine__HUD.h"
#include "UTGame__UTBot.h"
#include "Engine__Pawn.h"
#include "Engine__Controller.h"
namespace UnrealScript
{
	class UTDMSquad : public UTSquadAI
	{
	public:
		void DisplayDebug(class HUD* HUD, float& YL, float& YPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.DisplayDebug");
			byte* params = (byte*)malloc(12);
			*(class HUD**)params = HUD;
			*(float*)(params + 4) = YL;
			*(float*)(params + 8) = YPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			YL = *(float*)(params + 4);
			YPos = *(float*)(params + 8);
			free(params);
		}
		bool IsDefending(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.IsDefending");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void AddBot(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.AddBot");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveBot(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.RemoveBot");
			byte* params = (byte*)malloc(4);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool ShouldDeferTo(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.ShouldDeferTo");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckSquadObjectives(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.CheckSquadObjectives");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool WaitAtThisPosition(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.WaitAtThisPosition");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NearFormationCenter(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.NearFormationCenter");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool BeDevious(class Pawn* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.BeDevious");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		ScriptName GetOrders()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.GetOrders");
			byte* params = (byte*)malloc(8);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptName*)params;
			free(params);
			return returnVal;
		}
		bool SetEnemy(class UTBot* B, class Pawn* NewEnemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.SetEnemy");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Pawn**)(params + 4) = NewEnemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool FriendlyToward(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.FriendlyToward");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool AllowContinueOnFoot(class UTBot* B, class UTVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.AllowContinueOnFoot");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class UTVehicle**)(params + 4) = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		float VehicleDesireability(class UTVehicle* V, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.VehicleDesireability");
			byte* params = (byte*)malloc(12);
			*(class UTVehicle**)params = V;
			*(class UTBot**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AssignSquadResponsibility(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTDMSquad.AssignSquadResponsibility");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
