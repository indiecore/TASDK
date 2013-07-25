#pragma once
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrEquipInterface." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrEquipInterface : public Object
	{
	public:
		ADD_VAR(::BoolProperty, m_bLoadComplete, 0x1)
		bool IsClassOwned(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsClassOwned");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsLoadoutOwned(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsLoadoutOwned");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetLoadoutName(int ClassId, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetLoadoutName");
			byte* params = (byte*)malloc(20);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		float GetClassUnlockPercent(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassUnlockPercent");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(float*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetClassPrice(int ClassId, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassPrice");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetDailyDealItemId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealItemId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetDailyDealPercentOff()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealPercentOff");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetBundleParent(int BundleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetBundleParent");
			byte* params = (byte*)malloc(8);
			*(int*)params = BundleId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool IsBundleOwned(int BundleId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsBundleOwned");
			byte* params = (byte*)malloc(8);
			*(int*)params = BundleId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetVendorSize(int VendorId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorSize");
			byte* params = (byte*)malloc(8);
			*(int*)params = VendorId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetVendorItemId(int VendorId, int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorItemId");
			byte* params = (byte*)malloc(12);
			*(int*)params = VendorId;
			*(int*)(params + 4) = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		bool GetVendorItemPrice(int VendorId, int VendorItemId, int Currency, int& Price)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorItemPrice");
			byte* params = (byte*)malloc(20);
			*(int*)params = VendorId;
			*(int*)(params + 4) = VendorItemId;
			*(int*)(params + 8) = Currency;
			*(int*)(params + 12) = Price;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			Price = *(int*)(params + 12);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool GetVendorItemInfo(int VendorId, int VendorItemId, ScriptArray<wchar_t>& ItemName, ScriptArray<wchar_t>& itemDescr, ScriptArray<wchar_t>& ribbonDesc)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetVendorItemInfo");
			byte* params = (byte*)malloc(48);
			*(int*)params = VendorId;
			*(int*)(params + 4) = VendorItemId;
			*(ScriptArray<wchar_t>*)(params + 8) = ItemName;
			*(ScriptArray<wchar_t>*)(params + 20) = itemDescr;
			*(ScriptArray<wchar_t>*)(params + 32) = ribbonDesc;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			ItemName = *(ScriptArray<wchar_t>*)(params + 8);
			itemDescr = *(ScriptArray<wchar_t>*)(params + 20);
			ribbonDesc = *(ScriptArray<wchar_t>*)(params + 32);
			auto returnVal = *(bool*)(params + 44);
			free(params);
			return returnVal;
		}
		bool RequestPurchaseGeneral(int VendorId, int VendorItemId, int Currency, ScriptArray<wchar_t> UserCustomInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseGeneral");
			byte* params = (byte*)malloc(28);
			*(int*)params = VendorId;
			*(int*)(params + 4) = VendorItemId;
			*(int*)(params + 8) = Currency;
			*(ScriptArray<wchar_t>*)(params + 12) = UserCustomInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 24);
			free(params);
			return returnVal;
		}
		int GetActiveEquipId(int ClassId, int Type, int Loadout)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetActiveEquipId");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = Loadout;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetEquipCount(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipCount");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetEquipId(int ClassId, int Type, int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipId");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		bool SetLoadoutName(int ClassId, int Loadout, ScriptArray<wchar_t> loadoutName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetLoadoutName");
			byte* params = (byte*)malloc(24);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			*(ScriptArray<wchar_t>*)(params + 8) = loadoutName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		int GetFirstClassId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetFirstClassId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetNextClassId(int PrevClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetNextClassId");
			byte* params = (byte*)malloc(8);
			*(int*)params = PrevClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetClassId(int Index)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassId");
			byte* params = (byte*)malloc(8);
			*(int*)params = Index;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		bool RequestPurchaseClass(int ClassId, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseClass");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetReticuleValue(int EquipId, byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetReticuleValue");
			byte* params = (byte*)malloc(9);
			*(int*)params = EquipId;
			*(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetReticuleString(int EquipId, byte Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetReticuleString");
			byte* params = (byte*)malloc(17);
			*(int*)params = EquipId;
			*(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		bool SetActiveEquipId(int ClassId, int Type, int Loadout, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetActiveEquipId");
			byte* params = (byte*)malloc(20);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = Loadout;
			*(int*)(params + 12) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool IsEquipOwned(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsEquipOwned");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool IsEquipMaxed(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsEquipMaxed");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetEquipLevel(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipLevel");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		bool HasReticule(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.HasReticule");
			byte* params = (byte*)malloc(8);
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetMasteryPrice(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetMasteryPrice");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetEquipPrice(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipPrice");
			byte* params = (byte*)malloc(20);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			*(int*)(params + 12) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 16);
			free(params);
			return returnVal;
		}
		bool RequestPurchaseMastery(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseMastery");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RequestPurchaseEquip(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseEquip");
			byte* params = (byte*)malloc(20);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			*(int*)(params + 12) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool SetReticuleValue(int EquipId, byte Type, int nValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetReticuleValue");
			byte* params = (byte*)malloc(13);
			*(int*)params = EquipId;
			*(params + 4) = Type;
			*(int*)(params + 8) = nValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool SetReticuleString(int EquipId, byte Type, ScriptArray<wchar_t> sValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetReticuleString");
			byte* params = (byte*)malloc(21);
			*(int*)params = EquipId;
			*(params + 4) = Type;
			*(ScriptArray<wchar_t>*)(params + 8) = sValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
		int GetLoadoutPrice(int ClassId, int Loadout, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetLoadoutPrice");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			*(int*)(params + 8) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		bool RequestPurchaseLoadout(int ClassId, int Loadout, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseLoadout");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Loadout;
			*(int*)(params + 8) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		bool IsDailyDealOwned()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.IsDailyDealOwned");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		int GetDailyDealOldPrice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealOldPrice");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetDailyDealNewPrice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealNewPrice");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetDailyDealClass()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealClass");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetDailyDealType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealType");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetDailyDealSecsLeft()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealSecsLeft");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetDailyDealXPPrice()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealXPPrice");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		bool RequestPurchaseDeal(int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseDeal");
			byte* params = (byte*)malloc(8);
			*(int*)params = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		bool OwnsReticule(int EquipId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.OwnsReticule");
			byte* params = (byte*)malloc(8);
			*(int*)params = EquipId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void DelegateOnMarshalEvent(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void* pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.DelegateOnMarshalEvent");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void**)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void LoadInventory()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.LoadInventory");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void InitClass(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.InitClass");
			byte* params = (byte*)malloc(4);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDefaultEquip(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.SetDefaultEquip");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnMarshalEvent(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void* pMarEvent)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.OnMarshalEvent");
			byte* params = (byte*)malloc(4);
			*(
// WARNING: Unknown structure type 'ScriptStruct Core.Object.Pointer'!
void**)params = pMarEvent;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool RegisterMarshalCallback(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* MarshalEventDelegate)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RegisterMarshalCallback");
			byte* params = (byte*)malloc(16);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = MarshalEventDelegate;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetClassCount()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassCount");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		int GetClassRibbon(int ClassId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetClassRibbon");
			byte* params = (byte*)malloc(8);
			*(int*)params = ClassId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 4);
			free(params);
			return returnVal;
		}
		int GetNextEquipId(int ClassId, int Type, int PrevClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetNextEquipId");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = PrevClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetEquipRibbon(int ClassId, int Type, int equip)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetEquipRibbon");
			byte* params = (byte*)malloc(16);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 12);
			free(params);
			return returnVal;
		}
		int GetFirstEquipId(int ClassId, int Type)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetFirstEquipId");
			byte* params = (byte*)malloc(12);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 8);
			free(params);
			return returnVal;
		}
		int GetDailyDealLootId()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetDailyDealLootId");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		void RetrieveActives()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RetrieveActives");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		int GetUpgradePrice(int ClassId, int Type, int equip, int Upgrade, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.GetUpgradePrice");
			byte* params = (byte*)malloc(24);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			*(int*)(params + 12) = Upgrade;
			*(int*)(params + 16) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)(params + 20);
			free(params);
			return returnVal;
		}
		bool RequestPurchaseReticule(int ClassId, int Type, int equip, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseReticule");
			byte* params = (byte*)malloc(20);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			*(int*)(params + 12) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 16);
			free(params);
			return returnVal;
		}
		bool RequestPurchaseUpgrade(int ClassId, int Type, int equip, int Upgrade, int Currency)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.TrEquipInterface.RequestPurchaseUpgrade");
			byte* params = (byte*)malloc(24);
			*(int*)params = ClassId;
			*(int*)(params + 4) = Type;
			*(int*)(params + 8) = equip;
			*(int*)(params + 12) = Upgrade;
			*(int*)(params + 16) = Currency;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
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
#undef ADD_VAR
