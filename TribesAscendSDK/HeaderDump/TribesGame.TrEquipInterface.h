#pragma once
#include "Core.Object.h"
#include "TribesGame.TrObject.h"
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
namespace UnrealScript
{
	class TrEquipInterface : public Object
	{
	public:
		ADD_BOOL(m_bLoadComplete, 60, 0x1)
		bool IsClassOwned(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53581);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsLoadoutOwned(int ClassId, int Loadout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53591);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetLoadoutName(int ClassId, int Loadout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(53593);
			byte params[20] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		float GetClassUnlockPercent(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56825);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		int GetClassPrice(int ClassId, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56828);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetDailyDealItemId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56831);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetDailyDealPercentOff()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(56833);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetBundleParent(int BundleId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57808);
			byte params[8] = { NULL };
			*(int*)params = BundleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool IsBundleOwned(int BundleId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57810);
			byte params[8] = { NULL };
			*(int*)params = BundleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetVendorSize(int VendorId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57817);
			byte params[8] = { NULL };
			*(int*)params = VendorId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetVendorItemId(int VendorId, int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57819);
			byte params[12] = { NULL };
			*(int*)params = VendorId;
			*(int*)&params[4] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool GetVendorItemPrice(int VendorId, int VendorItemId, int Currency, int& Price)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57834);
			byte params[20] = { NULL };
			*(int*)params = VendorId;
			*(int*)&params[4] = VendorItemId;
			*(int*)&params[8] = Currency;
			*(int*)&params[12] = Price;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Price = *(int*)&params[12];
			return *(bool*)&params[16];
		}
		bool GetVendorItemInfo(int VendorId, int VendorItemId, ScriptString*& ItemName, ScriptString*& itemDescr, ScriptString*& ribbonDesc)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57846);
			byte params[48] = { NULL };
			*(int*)params = VendorId;
			*(int*)&params[4] = VendorItemId;
			*(ScriptString**)&params[8] = ItemName;
			*(ScriptString**)&params[20] = itemDescr;
			*(ScriptString**)&params[32] = ribbonDesc;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ItemName = *(ScriptString**)&params[8];
			itemDescr = *(ScriptString**)&params[20];
			ribbonDesc = *(ScriptString**)&params[32];
			return *(bool*)&params[44];
		}
		bool RequestPurchaseGeneral(int VendorId, int VendorItemId, int Currency, ScriptString* UserCustomInput)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(57889);
			byte params[28] = { NULL };
			*(int*)params = VendorId;
			*(int*)&params[4] = VendorItemId;
			*(int*)&params[8] = Currency;
			*(ScriptString**)&params[12] = UserCustomInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		int GetActiveEquipId(int ClassId, int Type, int Loadout)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58161);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetEquipCount(int ClassId, int Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58167);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetEquipId(int ClassId, int Type, int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58169);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool SetLoadoutName(int ClassId, int Loadout, ScriptString* loadoutName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58224);
			byte params[24] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			*(ScriptString**)&params[8] = loadoutName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		int GetFirstClassId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58236);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetNextClassId(int PrevClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58238);
			byte params[8] = { NULL };
			*(int*)params = PrevClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetClassId(int Index)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58250);
			byte params[8] = { NULL };
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool RequestPurchaseClass(int ClassId, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58287);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetReticuleValue(int EquipId, TrObject::ReticuleDataType Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58603);
			byte params[9] = { NULL };
			*(int*)params = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptString* GetReticuleString(int EquipId, TrObject::ReticuleDataType Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58605);
			byte params[17] = { NULL };
			*(int*)params = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		bool SetActiveEquipId(int ClassId, int Type, int Loadout, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58615);
			byte params[20] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = Loadout;
			*(int*)&params[12] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsEquipOwned(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58645);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsEquipMaxed(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58647);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetEquipLevel(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58649);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool HasReticule(int EquipId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58654);
			byte params[8] = { NULL };
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetMasteryPrice(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58689);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetEquipPrice(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58704);
			byte params[20] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		bool RequestPurchaseMastery(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58760);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RequestPurchaseEquip(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58762);
			byte params[20] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool SetReticuleValue(int EquipId, TrObject::ReticuleDataType Type, int nValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58766);
			byte params[13] = { NULL };
			*(int*)params = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			*(int*)&params[8] = nValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetReticuleString(int EquipId, TrObject::ReticuleDataType Type, ScriptString* sValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(58768);
			byte params[21] = { NULL };
			*(int*)params = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			*(ScriptString**)&params[8] = sValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		int GetLoadoutPrice(int ClassId, int Loadout, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59411);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			*(int*)&params[8] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool RequestPurchaseLoadout(int ClassId, int Loadout, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59426);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Loadout;
			*(int*)&params[8] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsDailyDealOwned()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59556);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		int GetDailyDealOldPrice()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59561);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetDailyDealNewPrice()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59563);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetDailyDealClass()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59565);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetDailyDealType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59567);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetDailyDealSecsLeft()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59575);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetDailyDealXPPrice()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61264);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		bool RequestPurchaseDeal(int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61281);
			byte params[8] = { NULL };
			*(int*)params = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OwnsReticule(int EquipId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(61583);
			byte params[8] = { NULL };
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DelegateOnMarshalEvent(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87425);
			byte params[4] = { NULL };
			*(Object::Pointer*)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadInventory()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87428);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitClass(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87429);
			byte params[4] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDefaultEquip(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87431);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMarshalEvent(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87435);
			byte params[4] = { NULL };
			*(Object::Pointer*)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RegisterMarshalCallback(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87437);
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetClassCount()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87442);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		int GetClassRibbon(int ClassId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87447);
			byte params[8] = { NULL };
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetNextEquipId(int ClassId, int Type, int PrevClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87469);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = PrevClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetEquipRibbon(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87474);
			byte params[16] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetFirstEquipId(int ClassId, int Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87479);
			byte params[12] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetDailyDealLootId()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87498);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		void RetrieveActives()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87501);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetUpgradePrice(int ClassId, int Type, int equip, int Upgrade, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87509);
			byte params[24] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Upgrade;
			*(int*)&params[16] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		bool RequestPurchaseReticule(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87528);
			byte params[20] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool RequestPurchaseUpgrade(int ClassId, int Type, int equip, int Upgrade, int Currency)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87534);
			byte params[24] = { NULL };
			*(int*)params = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Upgrade;
			*(int*)&params[16] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void SaveProfile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87541);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitEquipManager()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87570);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitClassList()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(87571);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
