#pragma once
#include "Engine.Weapon.h"
#include "UTGame.UTInventoryManager.h"
#include "TribesGame.TrStatsInterface.h"
#include "TribesGame.TrObject.h"
#include "TribesGame.TrDevice.h"
#include "Engine.Inventory.h"
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
	class TrInventoryManager : public UTInventoryManager
	{
	public:
		ADD_BOOL(c_bRetryEquippingPrimaryWeapon, 544, 0x1)
		ADD_OBJECT(TrStatsInterface, Stats, 540)
		ADD_STRUCT(TrObject::TR_EQUIP_POINT, m_PreviousDeviceEquipPoint, 536)
		ADD_OBJECT(TrDevice, m_RealLastDevice, 532)
		class TrDevice* GetDeviceByEquipPoint(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(72629);
			byte params[5] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDevice**)&params[4];
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(76825);
			byte params[12] = { NULL };
			*(class Inventory**)params = NewItem;
			*(bool*)&params[4] = bDoNotActivate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98103);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98104);
			byte params[8] = { NULL };
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class TrDevice* GetDeviceByWeaponClass(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98111);
			byte params[8] = { NULL };
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDevice**)&params[4];
		}
		class TrDevice* GetDeviceByWeaponId(int WeaponId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98117);
			byte params[8] = { NULL };
			*(int*)params = WeaponId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class TrDevice**)&params[4];
		}
		void TrGetWeaponList(ScriptArray<class TrDevice*>& WeaponList, bool bInhandOnly)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98123);
			byte params[16] = { NULL };
			*(ScriptArray<class TrDevice*>*)params = WeaponList;
			*(bool*)&params[12] = bInhandOnly;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			WeaponList = *(ScriptArray<class TrDevice*>*)params;
		}
		void DiscardEquippedDeployable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98128);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustWeapon(int NewOffset)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98130);
			byte params[4] = { NULL };
			*(int*)params = NewOffset;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98137);
			byte params[4] = { NULL };
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98146);
			byte params[4] = { NULL };
			*(class Inventory**)params = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AutoFireWeapon(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98149);
			byte params[1] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchWeaponByEquipPoint(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98154);
			byte params[1] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SwitchToPreviousWeapon()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98158);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerAutoFireWeapon(TrObject::TR_EQUIP_POINT EquipPoint)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(98159);
			byte params[1] = { NULL };
			*(TrObject::TR_EQUIP_POINT*)params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
