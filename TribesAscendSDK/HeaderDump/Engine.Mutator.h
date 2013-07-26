#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "Engine.Info.h"
#include "Engine.Actor.h"
#include "Engine.Controller.h"
#include "Core.Object.Vector.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Vehicle.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Mutator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Mutator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Mutator : public Info
	{
	public:
		ADD_OBJECT(Mutator, NextMutator)
		ADD_VAR(::BoolProperty, bUserAdded, 0x1)
		bool PreventDeath(class Pawn* Killed, class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.PreventDeath");
			byte* params = (byte*)malloc(28);
			*(class Pawn**)params = Killed;
			*(class Controller**)(params + 4) = Killer;
			*(ScriptClass**)(params + 8) = DamageType;
			*(Vector*)(params + 12) = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		bool CheckRelevance(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.CheckRelevance");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool OverridePickupQuery(class Pawn* Other, ScriptClass* ItemClass, class Actor* Pickup, byte& bAllowPickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.OverridePickupQuery");
			byte* params = (byte*)malloc(17);
			*(class Pawn**)params = Other;
			*(ScriptClass**)(params + 4) = ItemClass;
			*(class Actor**)(params + 8) = Pickup;
			*(params + 12) = bAllowPickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			bAllowPickup = *(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool HandleRestartGame()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.HandleRestartGame");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptArray<wchar_t> Reason)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.CheckEndGame");
			byte* params = (byte*)malloc(20);
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptArray<wchar_t>*)(params + 4) = Reason;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		class NavigationPoint* FindPlayerStart(class Controller* Player, byte InTeam, ScriptArray<wchar_t> IncomingName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.FindPlayerStart");
			byte* params = (byte*)malloc(21);
			*(class Controller**)params = Player;
			*(params + 4) = InTeam;
			*(ScriptArray<wchar_t>*)(params + 8) = IncomingName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class NavigationPoint**)(params + 20);
			free(params);
			return returnVal;
		}
		bool CanLeaveVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.CanLeaveVehicle");
			byte* params = (byte*)malloc(12);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.PreBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.MutatorIsAllowed");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Mutate(ScriptArray<wchar_t> MutateString, class PlayerController* Sender)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.Mutate");
			byte* params = (byte*)malloc(16);
			*(ScriptArray<wchar_t>*)params = MutateString;
			*(class PlayerController**)(params + 12) = Sender;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ModifyLogin(ScriptArray<wchar_t>& Portal, ScriptArray<wchar_t>& Options)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.ModifyLogin");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Portal;
			*(ScriptArray<wchar_t>*)(params + 12) = Options;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Portal = *(ScriptArray<wchar_t>*)params;
			Options = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
		void ModifyPlayer(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.ModifyPlayer");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddMutator(class Mutator* M)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.AddMutator");
			byte* params = (byte*)malloc(4);
			*(class Mutator**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AlwaysKeep(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.AlwaysKeep");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsRelevant(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.IsRelevant");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.CheckReplacement");
			byte* params = (byte*)malloc(8);
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void NotifyLogout(class Controller* Exiting)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.NotifyLogout");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NotifyLogin(class Controller* NewPlayer)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.NotifyLogin");
			byte* params = (byte*)malloc(4);
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverEnteredVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.DriverEnteredVehicle");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DriverLeftVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.DriverLeftVehicle");
			byte* params = (byte*)malloc(8);
			*(class Vehicle**)params = V;
			*(class Pawn**)(params + 4) = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InitMutator(ScriptArray<wchar_t> Options, ScriptArray<wchar_t>& ErrorMessage)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.InitMutator");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = Options;
			*(ScriptArray<wchar_t>*)(params + 12) = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ErrorMessage = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
		}
		void GetSeamlessTravelActorList(bool bToEntry, 
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& ActorList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.GetSeamlessTravelActorList");
			byte* params = (byte*)malloc(16);
			*(bool*)params = bToEntry;
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4) = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ActorList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)(params + 4);
			free(params);
		}
		void ScoreObjective(class PlayerReplicationInfo* Scorer, int Score)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.ScoreObjective");
			byte* params = (byte*)malloc(8);
			*(class PlayerReplicationInfo**)params = Scorer;
			*(int*)(params + 4) = Score;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ScoreKill(class Controller* Killer, class Controller* Killed)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.ScoreKill");
			byte* params = (byte*)malloc(8);
			*(class Controller**)params = Killer;
			*(class Controller**)(params + 4) = Killed;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void NetDamage(int OriginalDamage, int& Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType, class Actor* DamageCauser)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Mutator.NetDamage");
			byte* params = (byte*)malloc(48);
			*(int*)params = OriginalDamage;
			*(int*)(params + 4) = Damage;
			*(class Pawn**)(params + 8) = injured;
			*(class Controller**)(params + 12) = InstigatedBy;
			*(Vector*)(params + 16) = HitLocation;
			*(Vector*)(params + 28) = Momentum;
			*(ScriptClass**)(params + 40) = DamageType;
			*(class Actor**)(params + 44) = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Damage = *(int*)(params + 4);
			Momentum = *(Vector*)(params + 28);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
