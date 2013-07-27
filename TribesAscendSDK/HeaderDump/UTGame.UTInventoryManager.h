#pragma once
#include "Engine.InventoryManager.h"
#include "UTGame.UTWeapon.h"
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
	class UTInventoryManager : public InventoryManager
	{
	public:
		class AmmoStore
		{
		public:
			ADD_OBJECT(ScriptClass, WeaponClass, 4)
			ADD_STRUCT(int, Amount, 0)
		};
		ADD_BOOL(bInfiniteAmmo, 504, 0x1)
		ADD_STRUCT(ScriptArray<UTInventoryManager::AmmoStore>, AmmoStorage, 508)
		ADD_STRUCT(float, LastAdjustWeaponTime, 528)
		ADD_OBJECT(UTWeapon, PendingSwitchWeapon, 524)
		ADD_OBJECT(Weapon, PreviousWeapon, 520)
		bool NeedsAmmo(ScriptClass* TestWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.NeedsAmmo");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = TestWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ClientSyncWeapon(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ClientSyncWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OwnerEvent(ScriptName EventName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.OwnerEvent");
			byte params[8] = { NULL };
			*(ScriptName*)&params[0] = EventName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetWeaponList(ScriptArray<class UTWeapon*>& WeaponList, bool bFilter, int GroupFilter, bool bNoEmpty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.GetWeaponList");
			byte params[24] = { NULL };
			*(ScriptArray<class UTWeapon*>*)&params[0] = WeaponList;
			*(bool*)&params[12] = bFilter;
			*(int*)&params[16] = GroupFilter;
			*(bool*)&params[20] = bNoEmpty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WeaponList = *(ScriptArray<class UTWeapon*>*)&params[0];
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SwitchWeapon");
			byte params[1] = { NULL };
			params[0] = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustWeapon(int NewOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.AdjustWeapon");
			byte params[4] = { NULL };
			*(int*)&params[0] = NewOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.PrevWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.NextWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllAmmo(bool bAmmoForSuperWeapons)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.AllAmmo");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bAmmoForSuperWeapons;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SetCurrentWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ClientSetCurrentWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ServerSetCurrentWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SetPendingWeapon");
			byte params[4] = { NULL };
			*(class Weapon**)&params[0] = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponSet(class Weapon* NewWeapon, bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ClientWeaponSet");
			byte params[12] = { NULL };
			*(class Weapon**)&params[0] = NewWeapon;
			*(bool*)&params[4] = bOptionalSet;
			*(bool*)&params[8] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Inventory* CreateInventory(ScriptClass* NewInventoryItemClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.CreateInventory");
			byte params[12] = { NULL };
			*(ScriptClass**)&params[0] = NewInventoryItemClass;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		void ProcessRetrySwitch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ProcessRetrySwitch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RetrySwitchTo(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.RetrySwitchTo");
			byte params[4] = { NULL };
			*(class UTWeapon**)&params[0] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckSwitchTo(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.CheckSwitchTo");
			byte params[4] = { NULL };
			*(class UTWeapon**)&params[0] = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.AddInventory");
			byte params[12] = { NULL };
			*(class Inventory**)&params[0] = NewItem;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DiscardInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.DiscardInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.RemoveFromInventory");
			byte params[4] = { NULL };
			*(class Inventory**)&params[0] = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAmmoToWeapon(int AmountToAdd, ScriptClass* WeaponClassToAddTo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.AddAmmoToWeapon");
			byte params[8] = { NULL };
			*(int*)&params[0] = AmountToAdd;
			*(ScriptClass**)&params[4] = WeaponClassToAddTo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Inventory* HasInventoryOfClass(ScriptClass* InvClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.HasInventoryOfClass");
			byte params[8] = { NULL };
			*(ScriptClass**)&params[0] = InvClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[4];
		}
		void ChangedWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ChangedWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchToPreviousWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SwitchToPreviousWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.DrawHUD");
			byte params[4] = { NULL };
			*(class HUD**)&params[0] = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SwitchToBestWeapon");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
