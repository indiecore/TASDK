#pragma once
#include "Engine.Weapon.h"
#include "UTGame.UTInventoryManager.h"
#include "TribesGame.TrStatsInterface.h"
#include "TribesGame.TrDevice.h"
#include "Engine.Inventory.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrInventoryManager." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrInventoryManager." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrInventoryManager : public UTInventoryManager
	{
	public:
		ADD_VAR(::BoolProperty, c_bRetryEquippingPrimaryWeapon, 0x1)
		ADD_OBJECT(TrStatsInterface, Stats)
		ADD_VAR(::ByteProperty, m_PreviousDeviceEquipPoint, 0xFFFFFFFF)
		ADD_OBJECT(TrDevice, m_RealLastDevice)
		class TrDevice* GetDeviceByEquipPoint(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.GetDeviceByEquipPoint");
			byte* params = (byte*)malloc(5);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDevice**)(params + 4);
			free(params);
			return returnVal;
		}
		bool AddInventory(class Inventory* NewItem, bool bDoNotActivate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.AddInventory");
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.PostBeginPlay");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ReplicatedEvent(ScriptName VarName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.ReplicatedEvent");
			byte* params = (byte*)malloc(8);
			*(ScriptName*)params = VarName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class TrDevice* GetDeviceByWeaponClass(ScriptClass* DeviceClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.GetDeviceByWeaponClass");
			byte* params = (byte*)malloc(8);
			*(ScriptClass**)params = DeviceClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDevice**)(params + 4);
			free(params);
			return returnVal;
		}
		class TrDevice* GetDeviceByWeaponId(int WeaponId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.GetDeviceByWeaponId");
			byte* params = (byte*)malloc(8);
			*(int*)params = WeaponId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class TrDevice**)(params + 4);
			free(params);
			return returnVal;
		}
		void TrGetWeaponList(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void*& WeaponList, bool bInhandOnly)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.TrGetWeaponList");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params = WeaponList;
			*(bool*)(params + 12) = bInhandOnly;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			WeaponList = *(
// ERROR: Unknown object class 'Class Core.ArrayProperty'!
void**)params;
			free(params);
		}
		void DiscardEquippedDeployable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.DiscardEquippedDeployable");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void AdjustWeapon(int NewOffset)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.AdjustWeapon");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewOffset;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetPendingWeapon(class Weapon* DesiredWeapon)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.SetPendingWeapon");
			byte* params = (byte*)malloc(4);
			*(class Weapon**)params = DesiredWeapon;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveFromInventory(class Inventory* ItemToRemove)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.RemoveFromInventory");
			byte* params = (byte*)malloc(4);
			*(class Inventory**)params = ItemToRemove;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AutoFireWeapon(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.AutoFireWeapon");
			byte* params = (byte*)malloc(1);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchWeaponByEquipPoint(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.SwitchWeaponByEquipPoint");
			byte* params = (byte*)malloc(1);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SwitchToPreviousWeapon()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.SwitchToPreviousWeapon");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ServerAutoFireWeapon(byte EquipPoint)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrInventoryManager.ServerAutoFireWeapon");
			byte* params = (byte*)malloc(1);
			*params = EquipPoint;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
