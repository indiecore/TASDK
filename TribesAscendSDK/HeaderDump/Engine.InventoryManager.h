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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(17102);
			byte params[12] = { NULL };
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)&params[4] = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18796);
			byte params[12] = { NULL };
			*(class Inventory**)params = NewItem;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18826);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetPendingFireLength(class Weapon* InWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18827);
			byte params[8] = { NULL };
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		void SetPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18830);
			byte params[8] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(int*)&params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18833);
			byte params[8] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(int*)&params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool IsPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18836);
			byte params[12] = { NULL };
			*(class Weapon**)params = InWeapon;
			*(int*)&params[4] = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void ClearAllPendingFire(class Weapon* InWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18840);
			byte params[4] = { NULL };
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InventoryActors(ScriptClass* BaseClass, class Inventory*& Inv)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18843);
			byte params[8] = { NULL };
			*(ScriptClass**)params = BaseClass;
			*(class Inventory**)&params[4] = Inv;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Inv = *(class Inventory**)&params[4];
		}
		void SetupFor(class Pawn* P)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18846);
			byte params[4] = { NULL };
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18848);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Inventory* FindInventoryType(ScriptClass* DesiredClass, bool bAllowSubclass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18852);
			byte params[12] = { NULL };
			*(ScriptClass**)params = DesiredClass;
			*(bool*)&params[4] = bAllowSubclass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		class Inventory* CreateInventory(ScriptClass* NewInventoryItemClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18857);
			byte params[12] = { NULL };
			*(ScriptClass**)params = NewInventoryItemClass;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18866);
			byte params[4] = { NULL };
			*(class Inventory**)params = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DiscardInventory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18870);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OwnerDied()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18876);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18877);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		float GetWeaponRatingFor(class Weapon* W)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18879);
			byte params[8] = { NULL };
			*(class Weapon**)params = W;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		class Weapon* GetBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18887);
			byte params[8] = { NULL };
			*(bool*)params = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Weapon**)&params[4];
		}
		void SwitchToBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18896);
			byte params[4] = { NULL };
			*(bool*)params = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18899);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18903);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18908);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void InternalSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18910);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18911);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18917);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool CancelWeaponChange()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18919);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void ClearPendingWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18921);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ChangedWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18922);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ClientWeaponSet(class Weapon* NewWeapon, bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18924);
			byte params[12] = { NULL };
			*(class Weapon**)params = NewWeapon;
			*(bool*)&params[4] = bOptionalSet;
			*(bool*)&params[8] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateController()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18931);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
