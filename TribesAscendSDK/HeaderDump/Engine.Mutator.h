#pragma once
#include "Engine.PlayerController.h"
#include "Engine.Pawn.h"
#include "Engine.Info.h"
#include "Engine.Actor.h"
#include "Core.Object.h"
#include "Engine.Controller.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.NavigationPoint.h"
#include "Engine.Vehicle.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class Mutator : public Info
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptString*>, GroupNames, 480)
		ADD_OBJECT(Mutator, NextMutator, 476)
		ADD_BOOL(bUserAdded, 492, 0x1)
		bool PreventDeath(class Pawn* Killed, class Controller* Killer, ScriptClass* DamageType, Vector HitLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17066);
			byte params[28] = { NULL };
			*(class Pawn**)params = Killed;
			*(class Controller**)&params[4] = Killer;
			*(ScriptClass**)&params[8] = DamageType;
			*(Vector*)&params[12] = HitLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool CheckRelevance(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17091);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OverridePickupQuery(class Pawn* Other, ScriptClass* ItemClass, class Actor* Pickup, byte& bAllowPickup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17100);
			byte params[17] = { NULL };
			*(class Pawn**)params = Other;
			*(ScriptClass**)&params[4] = ItemClass;
			*(class Actor**)&params[8] = Pickup;
			params[12] = bAllowPickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			bAllowPickup = params[12];
			return *(bool*)&params[16];
		}
		bool HandleRestartGame()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17132);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		bool CheckEndGame(class PlayerReplicationInfo* Winner, ScriptString* Reason)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17164);
			byte params[20] = { NULL };
			*(class PlayerReplicationInfo**)params = Winner;
			*(ScriptString**)&params[4] = Reason;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		class NavigationPoint* FindPlayerStart(class Controller* Player, byte InTeam, ScriptString* IncomingName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17202);
			byte params[21] = { NULL };
			*(class Controller**)params = Player;
			params[4] = InTeam;
			*(ScriptString**)&params[8] = IncomingName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class NavigationPoint**)&params[20];
		}
		bool CanLeaveVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17246);
			byte params[12] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PreBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20673);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool MutatorIsAllowed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20674);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20676);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Mutate(ScriptString* MutateString, class PlayerController* Sender)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20677);
			byte params[16] = { NULL };
			*(ScriptString**)params = MutateString;
			*(class PlayerController**)&params[12] = Sender;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ModifyLogin(ScriptString*& Portal, ScriptString*& Options)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20680);
			byte params[24] = { NULL };
			*(ScriptString**)params = Portal;
			*(ScriptString**)&params[12] = Options;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Portal = *(ScriptString**)params;
			Options = *(ScriptString**)&params[12];
		}
		void ModifyPlayer(class Pawn* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20683);
			byte params[4] = { NULL };
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMutator(class Mutator* M)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20685);
			byte params[4] = { NULL };
			*(class Mutator**)params = M;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AlwaysKeep(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20687);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsRelevant(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20690);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool CheckReplacement(class Actor* Other)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20696);
			byte params[8] = { NULL };
			*(class Actor**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void NotifyLogout(class Controller* Exiting)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20699);
			byte params[4] = { NULL };
			*(class Controller**)params = Exiting;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NotifyLogin(class Controller* NewPlayer)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20701);
			byte params[4] = { NULL };
			*(class Controller**)params = NewPlayer;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverEnteredVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20703);
			byte params[8] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DriverLeftVehicle(class Vehicle* V, class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20708);
			byte params[8] = { NULL };
			*(class Vehicle**)params = V;
			*(class Pawn**)&params[4] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InitMutator(ScriptString* Options, ScriptString*& ErrorMessage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20711);
			byte params[24] = { NULL };
			*(ScriptString**)params = Options;
			*(ScriptString**)&params[12] = ErrorMessage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ErrorMessage = *(ScriptString**)&params[12];
		}
		void GetSeamlessTravelActorList(bool bToEntry, ScriptArray<class Actor*>& ActorList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20714);
			byte params[16] = { NULL };
			*(bool*)params = bToEntry;
			*(ScriptArray<class Actor*>*)&params[4] = ActorList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ActorList = *(ScriptArray<class Actor*>*)&params[4];
		}
		void ScoreObjective(class PlayerReplicationInfo* Scorer, int Score)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20731);
			byte params[8] = { NULL };
			*(class PlayerReplicationInfo**)params = Scorer;
			*(int*)&params[4] = Score;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ScoreKill(class Controller* Killer, class Controller* Killed)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20734);
			byte params[8] = { NULL };
			*(class Controller**)params = Killer;
			*(class Controller**)&params[4] = Killed;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void NetDamage(int OriginalDamage, int& Damage, class Pawn* injured, class Controller* InstigatedBy, Vector HitLocation, Vector& Momentum, ScriptClass* DamageType, class Actor* DamageCauser)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20737);
			byte params[48] = { NULL };
			*(int*)params = OriginalDamage;
			*(int*)&params[4] = Damage;
			*(class Pawn**)&params[8] = injured;
			*(class Controller**)&params[12] = InstigatedBy;
			*(Vector*)&params[16] = HitLocation;
			*(Vector*)&params[28] = Momentum;
			*(ScriptClass**)&params[40] = DamageType;
			*(class Actor**)&params[44] = DamageCauser;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Damage = *(int*)&params[4];
			Momentum = *(Vector*)&params[28];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
