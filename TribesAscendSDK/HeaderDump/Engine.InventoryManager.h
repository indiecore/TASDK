#pragma once
#include "Engine.Actor.h"
#include "Engine.Pawn.h"
#include "Engine.Weapon.h"
#include "Engine.Inventory.h"
#include "Engine.HUD.h"
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
	class InventoryManager : public Actor
	{
	public:
		ADD_STRUCT(ScriptArray<int>, PendingFire, 492)
		ADD_BOOL(bMustHoldWeapon, 488, 0x1)
		ADD_OBJECT(Weapon, LastAttemptedSwitchToWeapon, 484)
		ADD_OBJECT(Weapon, PendingWeapon, 480)
		ADD_OBJECT(Inventory, InventoryChain, 476)
		bool HandlePickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.HandlePickupQuery");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.AddInventory");
			byte params[12] = { NULL };
			*(class Inventory**)&params[0] = NewItem;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetPendingFireLength(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.GetPendingFireLength");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void SetPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SetPendingFire");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(int*)&params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ClearPendingFire");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(int*)&params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.IsPendingFire");
			byte params[12] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			*(int*)&params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ClearAllPendingFire(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ClearAllPendingFire");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InventoryActors(ScriptClass* BaseClass, class Inventory*& Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.InventoryActors");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = BaseClass;
			*(class Inventory**)&params[4] = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Inv = *(class Inventory**)&params[4];
		}
		void SetupFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SetupFor");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Inventory* FindInventoryType(ScriptClass* DesiredClass, bool bAllowSubclass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.FindInventoryType");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = DesiredClass;
			*(bool*)&params[4] = bAllowSubclass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		class Inventory* CreateInventory(ScriptClass* NewInventoryItemClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.CreateInventory");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = NewInventoryItemClass;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.RemoveFromInventory");
			byte params[4] = { NULL };
			*(class Inventory**)&params[0] = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DiscardInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.DiscardInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OwnerDied()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.OwnerDied");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.DrawHUD");
			byte params[4] = { NULL };
			*(class HUD**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetWeaponRatingFor(class Weapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.GetWeaponRatingFor");
			byte params[8] = { NULL };
			*(class Weapon**)&params[0] = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		class Weapon* GetBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.GetBestWeapon");
			byte params[8] = { NULL };
			*(bool*)&params[0] = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Weapon**)&params[4];
		}
		void SwitchToBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SwitchToBestWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.PrevWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.NextWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SetCurrentWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InternalSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.InternalSetCurrentWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ServerSetCurrentWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SetPendingWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CancelWeaponChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.CancelWeaponChange");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		void ClearPendingWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ClearPendingWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangedWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ChangedWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWeaponSet(class Weapon* NewWeapon, bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ClientWeaponSet");
			byte params[12] = { NULL };
			*(class Weapon**)&params[0] = NewWeapon;
			*(bool*)&params[4] = bOptionalSet;
			*(bool*)&params[8] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.UpdateController");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
