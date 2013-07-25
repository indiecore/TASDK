#pragma once
#include "Engine__Actor.h"
#include "Engine__Inventory.h"
#include "Engine__Weapon.h"
#include "Engine__Pawn.h"
#include "Engine__HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.InventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.InventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class InventoryManager : public Actor
	{
	public:
		ADD_VAR(::BoolProperty, bMustHoldWeapon, 0x1)
		ADD_OBJECT(Weapon, LastAttemptedSwitchToWeapon)
		ADD_OBJECT(Weapon, PendingWeapon)
		ADD_OBJECT(Inventory, InventoryChain)
		bool HandlePickupQuery(ScriptClass* ItemClass, class Actor* Pickup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.HandlePickupQuery");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = ItemClass;
			*(class Actor**)(params + 4) = Pickup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.AddInventory");
			byte* params = (byte*)malloc(12);
			*(class Inventory**)params = NewItem;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetPendingFireLength(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.GetPendingFireLength");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		void SetPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SetPendingFire");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = InWeapon;
			*(int*)(params + 4) = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ClearPendingFire");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = InWeapon;
			*(int*)(params + 4) = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool IsPendingFire(class Weapon* InWeapon, int InFiringMode)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.IsPendingFire");
			byte* params = (byte*)malloc(12);
			*(class Weapon**)params = InWeapon;
			*(int*)(params + 4) = InFiringMode;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void ClearAllPendingFire(class Weapon* InWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ClearAllPendingFire");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = InWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InventoryActors(ScriptClass* BaseClass, class Inventory*& Inv)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.InventoryActors");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = BaseClass;
			*(class Inventory**)(params + 4) = Inv;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Inv = *(class Inventory**)(params + 4);
			free(params);
		}
		void SetupFor(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SetupFor");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Destroyed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.Destroyed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		class Inventory* FindInventoryType(ScriptClass* DesiredClass, bool bAllowSubclass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.FindInventoryType");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = DesiredClass;
			*(bool*)(params + 4) = bAllowSubclass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Inventory**)(params + 8);
			free(params);
			return returnVal;
		}
		class Inventory* CreateInventory(ScriptClass* NewInventoryItemClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.CreateInventory");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = NewInventoryItemClass;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Inventory**)(params + 8);
			free(params);
			return returnVal;
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.RemoveFromInventory");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		float GetWeaponRatingFor(class Weapon* W)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.GetWeaponRatingFor");
			byte* params = (byte*)malloc(8);
			*(class Weapon**)params = W;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		class Weapon* GetBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.GetBestWeapon");
			byte* params = (byte*)malloc(8);
			*(bool*)params = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Weapon**)(params + 4);
			free(params);
			return returnVal;
		}
		void SwitchToBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SwitchToBestWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void InternalSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.InternalSetCurrentWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.ServerSetCurrentWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.SetPendingWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool CancelWeaponChange()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.CancelWeaponChange");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(12);
			*(class Weapon**)params = NewWeapon;
			*(bool*)(params + 4) = bOptionalSet;
			*(bool*)(params + 8) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateController()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.InventoryManager.UpdateController");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
