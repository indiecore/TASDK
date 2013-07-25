#pragma once
#include "Engine.InventoryManager.h"
#include "UTGame.UTWeapon.h"
#include "Engine.Weapon.h"
#include "Engine.Inventory.h"
#include "Engine.HUD.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.UTInventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.UTInventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class UTInventoryManager : public InventoryManager
	{
	public:
		ADD_VAR(::BoolProperty, bInfiniteAmmo, 0x1)
		ADD_VAR(::FloatProperty, LastAdjustWeaponTime, 0xFFFFFFFF)
		ADD_OBJECT(UTWeapon, PendingSwitchWeapon)
		ADD_OBJECT(Weapon, PreviousWeapon)
		bool NeedsAmmo(ScriptClass* TestWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.NeedsAmmo");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = TestWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void ClientSyncWeapon(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ClientSyncWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OwnerEvent(ScriptName EventName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.OwnerEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = EventName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void GetWeaponList(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& WeaponList, bool bFilter, int GroupFilter, bool bNoEmpty)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.GetWeaponList");
			byte* params = (byte*)malloc(24);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = WeaponList;
			*(bool*)(params + 12) = bFilter;
			*(int*)(params + 16) = GroupFilter;
			*(bool*)(params + 20) = bNoEmpty;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			WeaponList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SwitchWeapon");
			byte* params = (byte*)malloc(1);
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AdjustWeapon(int NewOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.AdjustWeapon");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
			byte* params = (byte*)malloc(4);
			*(bool*)params = bAmmoForSuperWeapons;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SetCurrentWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ClientSetCurrentWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ServerSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ServerSetCurrentWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SetPendingWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClientWeaponSet(class Weapon* NewWeapon, bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ClientWeaponSet");
			byte* params = (byte*)malloc(12);
			*(class Weapon**)params = NewWeapon;
			*(bool*)(params + 4) = bOptionalSet;
			*(bool*)(params + 8) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Inventory* CreateInventory(ScriptClass* NewInventoryItemClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.CreateInventory");
			byte* params = (byte*)malloc(12);
			*(ScriptClass**)params = NewInventoryItemClass;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Inventory**)(params + 8);
			free(params);
			return returnVal;
		}
		void ProcessRetrySwitch()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.ProcessRetrySwitch");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RetrySwitchTo(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.RetrySwitchTo");
			byte* params = (byte*)malloc(4);
			*(class UTWeapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckSwitchTo(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.CheckSwitchTo");
			byte* params = (byte*)malloc(4);
			*(class UTWeapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.AddInventory");
			byte* params = (byte*)malloc(12);
			*(class Inventory**)params = NewItem;
			*(bool*)(params + 4) = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		void DiscardInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.DiscardInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.RemoveFromInventory");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddAmmoToWeapon(int AmountToAdd, ScriptClass* WeaponClassToAddTo)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.AddAmmoToWeapon");
			byte* params = (byte*)malloc(8);
			*(int*)params = AmountToAdd;
			*(ScriptClass**)(params + 4) = WeaponClassToAddTo;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class Inventory* HasInventoryOfClass(ScriptClass* InvClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.HasInventoryOfClass");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = InvClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Inventory**)(params + 4);
			free(params);
			return returnVal;
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
			byte* params = (byte*)malloc(4);
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchToBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.UTInventoryManager.SwitchToBestWeapon");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
