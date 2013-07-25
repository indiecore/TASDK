#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "UTGame.UTBot.h"
#include "UTGame.UTCTFFlag.h"
#include "UTGame.UTSquadAI.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Pawn.h"
#include "UTGame.UTVehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTCTFSquadAI." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTCTFSquadAI." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTCTFSquadAI : public UTSquadAI
	{
	public:
		ADD_OBJECT(UTCTFFlag, EnemyFlag)
		ADD_OBJECT(UTCTFFlag, FriendlyFlag)
		ADD_OBJECT(NavigationPoint, HidePath)
		ADD_VAR(::FloatProperty, LastSeeFlagCarrier, 0xFFFFFFFF)
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool AllowDetourTo(class UTBot* B, class NavigationPoint* N)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.AllowDetourTo");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class NavigationPoint**)(params + 4) = N;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool ShouldUseAlternatePaths()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.ShouldUseAlternatePaths");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetAlternatePathTo(class NavigationPoint* NewRouteObjective, class UTBot* RouteMaker)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.SetAlternatePathTo");
			byte* params = (byte*)malloc(8);
			*(class NavigationPoint**)params = NewRouteObjective;
			*(class UTBot**)(params + 4) = RouteMaker;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool BeDevious(class Pawn* Enemy)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.BeDevious");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = Enemy;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FindPathToObjective(class UTBot* B, class Actor* O)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.FindPathToObjective");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class Actor**)(params + 4) = O;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GoPickupFlag(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.GoPickupFlag");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		class Actor* FormationCenter(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.FormationCenter");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Actor**)(params + 4);
			free(params);
			return returnVal;
		}
		bool VisibleToEnemiesOf(class Actor* A, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.VisibleToEnemiesOf");
			byte* params = (byte*)malloc(12);
			*(class Actor**)params = A;
			*(class UTBot**)(params + 4) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		class NavigationPoint* FindHidePathFor(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.FindHidePathFor");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckVehicle(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.CheckVehicle");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool OrdersForFlagCarrier(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.OrdersForFlagCarrier");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool MustKeepEnemy(class Pawn* E)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.MustKeepEnemy");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = E;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NearEnemyBase(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.NearEnemyBase");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool NearHomeBase(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.NearHomeBase");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool FlagNearBase()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.FlagNearBase");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool OverrideFollowPlayer(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.OverrideFollowPlayer");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckSquadObjectives(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.CheckSquadObjectives");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void EnemyFlagTakenBy(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.EnemyFlagTakenBy");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AllowTaunt(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.AllowTaunt");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool ShouldDeferTo(class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.ShouldDeferTo");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		byte PriorityObjective(class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.PriorityObjective");
			byte* params = (byte*)malloc(5);
			*(class UTBot**)params = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 4);
			free(params);
			return returnVal;
		}
		float ModifyThreat(float Current, class Pawn* NewThreat, bool bThreatVisible, class UTBot* B)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.ModifyThreat");
			byte* params = (byte*)malloc(20);
			*(float*)params = Current;
			*(class Pawn**)(params + 4) = NewThreat;
			*(bool*)(params + 8) = bThreatVisible;
			*(class UTBot**)(params + 12) = B;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 16);
			free(params);
			return returnVal;
		}
		bool AllowContinueOnFoot(class UTBot* B, class UTVehicle* V)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.AllowContinueOnFoot");
			byte* params = (byte*)malloc(12);
			*(class UTBot**)params = B;
			*(class UTVehicle**)(params + 4) = V;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void ModifyAggression(class UTBot* B, float& Aggression)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTCTFSquadAI.ModifyAggression");
			byte* params = (byte*)malloc(8);
			*(class UTBot**)params = B;
			*(float*)(params + 4) = Aggression;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Aggression = *(float*)(params + 4);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
