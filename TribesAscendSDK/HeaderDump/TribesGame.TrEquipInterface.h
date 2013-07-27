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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsClassOwned");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool IsLoadoutOwned(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsLoadoutOwned");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		ScriptString* GetLoadoutName(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetLoadoutName");
			byte params[20] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		float GetClassUnlockPercent(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassUnlockPercent");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)&params[4];
		}
		int GetClassPrice(int ClassId, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassPrice");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetDailyDealItemId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealItemId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetDailyDealPercentOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealPercentOff");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetBundleParent(int BundleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetBundleParent");
			byte params[8] = { NULL };
			*(int*)&params[0] = BundleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool IsBundleOwned(int BundleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsBundleOwned");
			byte params[8] = { NULL };
			*(int*)&params[0] = BundleId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetVendorSize(int VendorId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorSize");
			byte params[8] = { NULL };
			*(int*)&params[0] = VendorId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetVendorItemId(int VendorId, int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorItemId");
			byte params[12] = { NULL };
			*(int*)&params[0] = VendorId;
			*(int*)&params[4] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool GetVendorItemPrice(int VendorId, int VendorItemId, int Currency, int& Price)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorItemPrice");
			byte params[20] = { NULL };
			*(int*)&params[0] = VendorId;
			*(int*)&params[4] = VendorItemId;
			*(int*)&params[8] = Currency;
			*(int*)&params[12] = Price;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Price = *(int*)&params[12];
			return *(bool*)&params[16];
		}
		bool GetVendorItemInfo(int VendorId, int VendorItemId, ScriptString*& ItemName, ScriptString*& itemDescr, ScriptString*& ribbonDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorItemInfo");
			byte params[48] = { NULL };
			*(int*)&params[0] = VendorId;
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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseGeneral");
			byte params[28] = { NULL };
			*(int*)&params[0] = VendorId;
			*(int*)&params[4] = VendorItemId;
			*(int*)&params[8] = Currency;
			*(ScriptString**)&params[12] = UserCustomInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		int GetActiveEquipId(int ClassId, int Type, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetActiveEquipId");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetEquipCount(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipCount");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetEquipId(int ClassId, int Type, int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipId");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool SetLoadoutName(int ClassId, int Loadout, ScriptString* loadoutName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetLoadoutName");
			byte params[24] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			*(ScriptString**)&params[8] = loadoutName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		int GetFirstClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetFirstClassId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetNextClassId(int PrevClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetNextClassId");
			byte params[8] = { NULL };
			*(int*)&params[0] = PrevClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetClassId(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassId");
			byte params[8] = { NULL };
			*(int*)&params[0] = Index;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		bool RequestPurchaseClass(int ClassId, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseClass");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[8];
		}
		int GetReticuleValue(int EquipId, TrObject::ReticuleDataType Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetReticuleValue");
			byte params[9] = { NULL };
			*(int*)&params[0] = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		ScriptString* GetReticuleString(int EquipId, TrObject::ReticuleDataType Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetReticuleString");
			byte params[17] = { NULL };
			*(int*)&params[0] = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		bool SetActiveEquipId(int ClassId, int Type, int Loadout, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetActiveEquipId");
			byte params[20] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = Loadout;
			*(int*)&params[12] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool IsEquipOwned(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsEquipOwned");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsEquipMaxed(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsEquipMaxed");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetEquipLevel(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipLevel");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool HasReticule(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.HasReticule");
			byte params[8] = { NULL };
			*(int*)&params[0] = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		int GetMasteryPrice(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetMasteryPrice");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetEquipPrice(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipPrice");
			byte params[20] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[16];
		}
		bool RequestPurchaseMastery(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseMastery");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool RequestPurchaseEquip(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseEquip");
			byte params[20] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool SetReticuleValue(int EquipId, TrObject::ReticuleDataType Type, int nValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetReticuleValue");
			byte params[13] = { NULL };
			*(int*)&params[0] = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			*(int*)&params[8] = nValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool SetReticuleString(int EquipId, TrObject::ReticuleDataType Type, ScriptString* sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetReticuleString");
			byte params[21] = { NULL };
			*(int*)&params[0] = EquipId;
			*(TrObject::ReticuleDataType*)&params[4] = Type;
			*(ScriptString**)&params[8] = sValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		int GetLoadoutPrice(int ClassId, int Loadout, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetLoadoutPrice");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			*(int*)&params[8] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		bool RequestPurchaseLoadout(int ClassId, int Loadout, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseLoadout");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Loadout;
			*(int*)&params[8] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		bool IsDailyDealOwned()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsDailyDealOwned");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[0];
		}
		int GetDailyDealOldPrice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealOldPrice");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetDailyDealNewPrice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealNewPrice");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetDailyDealClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealClass");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetDailyDealType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealType");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetDailyDealSecsLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealSecsLeft");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetDailyDealXPPrice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealXPPrice");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		bool RequestPurchaseDeal(int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseDeal");
			byte params[8] = { NULL };
			*(int*)&params[0] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		bool OwnsReticule(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.OwnsReticule");
			byte params[8] = { NULL };
			*(int*)&params[0] = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void DelegateOnMarshalEvent(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.DelegateOnMarshalEvent");
			byte params[4] = { NULL };
			*(Object::Pointer*)&params[0] = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void LoadInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.LoadInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitClass(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.InitClass");
			byte params[4] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDefaultEquip(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetDefaultEquip");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMarshalEvent(Object::Pointer pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.OnMarshalEvent");
			byte params[4] = { NULL };
			*(Object::Pointer*)&params[0] = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool RegisterMarshalCallback(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RegisterMarshalCallback");
			byte params[16] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		int GetClassCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassCount");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		int GetClassRibbon(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassRibbon");
			byte params[8] = { NULL };
			*(int*)&params[0] = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[4];
		}
		int GetNextEquipId(int ClassId, int Type, int PrevClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetNextEquipId");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = PrevClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetEquipRibbon(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipRibbon");
			byte params[16] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[12];
		}
		int GetFirstEquipId(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetFirstEquipId");
			byte params[12] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int GetDailyDealLootId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealLootId");
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[0];
		}
		void RetrieveActives()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RetrieveActives");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetUpgradePrice(int ClassId, int Type, int equip, int Upgrade, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetUpgradePrice");
			byte params[24] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Upgrade;
			*(int*)&params[16] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[20];
		}
		bool RequestPurchaseReticule(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseReticule");
			byte params[20] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		bool RequestPurchaseUpgrade(int ClassId, int Type, int equip, int Upgrade, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseUpgrade");
			byte params[24] = { NULL };
			*(int*)&params[0] = ClassId;
			*(int*)&params[4] = Type;
			*(int*)&params[8] = equip;
			*(int*)&params[12] = Upgrade;
			*(int*)&params[16] = Currency;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
		void SaveProfile()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SaveProfile");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitEquipManager()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.InitEquipManager");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitClassList()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.InitClassList");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
