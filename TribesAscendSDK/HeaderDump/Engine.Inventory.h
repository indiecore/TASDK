#pragma once
#include "Engine.Controller.h"
#include "Engine.Actor.h"
#include "Engine.SoundCue.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.InventoryManager.h"
#include "Engine.Pawn.h"
#include "Core.Object.Vector.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Inventory." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Inventory." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Inventory : public Actor
	{
	public:
		ADD_OBJECT(ScriptClass, DroppedPickupClass)
		ADD_VAR(::StrProperty, PickupForce, 0xFFFFFFFF)
		ADD_OBJECT(SoundCue, PickupSound)
		ADD_VAR(::StrProperty, PickupMessage, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, MaxDesireability, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, RespawnTime, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bPredictRespawns, 0x4)
		ADD_VAR(::BoolProperty, bDelayedSpawn, 0x2)
		ADD_VAR(::BoolProperty, bDropOnDeath, 0x1)
		ADD_VAR(::StrProperty, ItemName, 0xFFFFFFFF)
		ADD_OBJECT(InventoryManager, InvManager)
		ADD_OBJECT(Inventory, Inventory)
		float DetourWeight(class Pawn* Other, float PathWeight)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.DetourWeight");
			byte* params = (byte*)malloc(12);
			*(class Pawn**)params = Other;
			*(float*)(params + 4) = PathWeight;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 8);
			free(params);
			return returnVal;
		}
		void GiveTo(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.GiveTo");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetHumanReadableName()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.GetHumanReadableName");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float BotDesireability(class Actor* PickupHolder, class Pawn* P, class Controller* C)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.BotDesireability");
			byte* params = (byte*)malloc(16);
			*(class Actor**)params = PickupHolder;
			*(class Pawn**)(params + 4) = P;
			*(class Controller**)(params + 8) = C;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 12);
			free(params);
			return returnVal;
		}
		void AnnouncePickup(class Pawn* Other)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.AnnouncePickup");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = Other;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GivenTo(class Pawn* thisPawn, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.GivenTo");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = thisPawn;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientGivenTo(class Pawn* NewOwner, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.ClientGivenTo");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = NewOwner;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ItemRemovedFromInvManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.ItemRemovedFromInvManager");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool DenyPickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.DenyPickupQuery");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)(params + 4) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void DropFrom(Vector StartLocation, Vector StartVelocity)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.DropFrom");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = StartLocation;
			*(Vector*)(params + 12) = StartVelocity;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetLocalString(int Switch, class PlayerReplicationInfo* RelatedPRI, class PlayerReplicationInfo* RelatedPRI)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Inventory.GetLocalString");
			byte* params = (byte*)malloc(24);
			*(int*)params = Switch;
			*(class PlayerReplicationInfo**)(params + 4) = RelatedPRI;
			*(class PlayerReplicationInfo**)(params + 8) = RelatedPRI;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
