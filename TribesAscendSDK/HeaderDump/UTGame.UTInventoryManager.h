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
		struct AmmoStore
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
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(40497);
			byte params[8] = { NULL };
			*(ScriptClass**)params = TestWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void ClientSyncWeapon(class Weapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48037);
			byte params[4] = { NULL };
			*(class Weapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OwnerEvent(ScriptName EventName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48040);
			byte params[8] = { NULL };
			*(ScriptName*)params = EventName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GetWeaponList(ScriptArray<class UTWeapon*>& WeaponList, bool bFilter, int GroupFilter, bool bNoEmpty)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48043);
			byte params[24] = { NULL };
			*(ScriptArray<class UTWeapon*>*)params = WeaponList;
			*(bool*)&params[12] = bFilter;
			*(int*)&params[16] = GroupFilter;
			*(bool*)&params[20] = bNoEmpty;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WeaponList = *(ScriptArray<class UTWeapon*>*)params;
		}
		void SwitchWeapon(byte NewGroup)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48051);
			byte params[1] = { NULL };
			*params = NewGroup;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AdjustWeapon(int NewOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48057);
			byte params[4] = { NULL };
			*(int*)params = NewOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PrevWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48064);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void NextWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48065);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AllAmmo(bool bAmmoForSuperWeapons)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48066);
			byte params[4] = { NULL };
			*(bool*)params = bAmmoForSuperWeapons;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48069);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48071);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ServerSetCurrentWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48073);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48075);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClientWeaponSet(class Weapon* NewWeapon, bool bOptionalSet, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48080);
			byte params[12] = { NULL };
			*(class Weapon**)params = NewWeapon;
			*(bool*)&params[4] = bOptionalSet;
			*(bool*)&params[8] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Inventory* CreateInventory(ScriptClass* NewInventoryItemClass, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48085);
			byte params[12] = { NULL };
			*(ScriptClass**)params = NewInventoryItemClass;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[8];
		}
		void ProcessRetrySwitch()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48089);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RetrySwitchTo(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48091);
			byte params[4] = { NULL };
			*(class UTWeapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckSwitchTo(class UTWeapon* NewWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48093);
			byte params[4] = { NULL };
			*(class UTWeapon**)params = NewWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48095);
			byte params[12] = { NULL };
			*(class Inventory**)params = NewItem;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void DiscardInventory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48101);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48103);
			byte params[4] = { NULL };
			*(class Inventory**)params = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddAmmoToWeapon(int AmountToAdd, ScriptClass* WeaponClassToAddTo)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48109);
			byte params[8] = { NULL };
			*(int*)params = AmountToAdd;
			*(ScriptClass**)&params[4] = WeaponClassToAddTo;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class Inventory* HasInventoryOfClass(ScriptClass* InvClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48115);
			byte params[8] = { NULL };
			*(ScriptClass**)params = InvClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Inventory**)&params[4];
		}
		void ChangedWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48119);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SwitchToPreviousWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48122);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DrawHUD(class HUD* H)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48123);
			byte params[4] = { NULL };
			*(class HUD**)params = H;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToBestWeapon(bool bForceADifferentWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(48125);
			byte params[4] = { NULL };
			*(bool*)params = bForceADifferentWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
