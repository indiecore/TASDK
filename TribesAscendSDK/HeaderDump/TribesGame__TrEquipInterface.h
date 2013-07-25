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
		// Here lies the not-yet-implemented method 'IsClassOwned'
		// Here lies the not-yet-implemented method 'IsLoadoutOwned'
		// Here lies the not-yet-implemented method 'GetLoadoutName'
		// Here lies the not-yet-implemented method 'GetClassUnlockPercent'
		// Here lies the not-yet-implemented method 'GetClassPrice'
		// Here lies the not-yet-implemented method 'GetDailyDealItemId'
		// Here lies the not-yet-implemented method 'GetDailyDealPercentOff'
		// Here lies the not-yet-implemented method 'GetBundleParent'
		// Here lies the not-yet-implemented method 'IsBundleOwned'
		// Here lies the not-yet-implemented method 'GetVendorSize'
		// Here lies the not-yet-implemented method 'GetVendorItemId'
		// Here lies the not-yet-implemented method 'GetVendorItemPrice'
		// Here lies the not-yet-implemented method 'GetVendorItemInfo'
		// Here lies the not-yet-implemented method 'RequestPurchaseGeneral'
		// Here lies the not-yet-implemented method 'GetActiveEquipId'
		// Here lies the not-yet-implemented method 'GetEquipCount'
		// Here lies the not-yet-implemented method 'GetEquipId'
		// Here lies the not-yet-implemented method 'SetLoadoutName'
		// Here lies the not-yet-implemented method 'GetFirstClassId'
		// Here lies the not-yet-implemented method 'GetNextClassId'
		// Here lies the not-yet-implemented method 'GetClassId'
		// Here lies the not-yet-implemented method 'RequestPurchaseClass'
		// Here lies the not-yet-implemented method 'GetReticuleValue'
		// Here lies the not-yet-implemented method 'GetReticuleString'
		// Here lies the not-yet-implemented method 'SetActiveEquipId'
		// Here lies the not-yet-implemented method 'IsEquipOwned'
		// Here lies the not-yet-implemented method 'IsEquipMaxed'
		// Here lies the not-yet-implemented method 'GetEquipLevel'
		// Here lies the not-yet-implemented method 'HasReticule'
		// Here lies the not-yet-implemented method 'GetMasteryPrice'
		// Here lies the not-yet-implemented method 'GetEquipPrice'
		// Here lies the not-yet-implemented method 'RequestPurchaseMastery'
		// Here lies the not-yet-implemented method 'RequestPurchaseEquip'
		// Here lies the not-yet-implemented method 'SetReticuleValue'
		// Here lies the not-yet-implemented method 'SetReticuleString'
		// Here lies the not-yet-implemented method 'GetLoadoutPrice'
		// Here lies the not-yet-implemented method 'RequestPurchaseLoadout'
		// Here lies the not-yet-implemented method 'IsDailyDealOwned'
		// Here lies the not-yet-implemented method 'GetDailyDealOldPrice'
		// Here lies the not-yet-implemented method 'GetDailyDealNewPrice'
		// Here lies the not-yet-implemented method 'GetDailyDealClass'
		// Here lies the not-yet-implemented method 'GetDailyDealType'
		// Here lies the not-yet-implemented method 'GetDailyDealSecsLeft'
		// Here lies the not-yet-implemented method 'GetDailyDealXPPrice'
		// Here lies the not-yet-implemented method 'RequestPurchaseDeal'
		// Here lies the not-yet-implemented method 'OwnsReticule'
		// Here lies the not-yet-implemented method 'DelegateOnMarshalEvent'
		// Here lies the not-yet-implemented method 'LoadInventory'
		// Here lies the not-yet-implemented method 'InitClass'
		// Here lies the not-yet-implemented method 'SetDefaultEquip'
		// Here lies the not-yet-implemented method 'OnMarshalEvent'
		// Here lies the not-yet-implemented method 'RegisterMarshalCallback'
		// Here lies the not-yet-implemented method 'GetClassCount'
		// Here lies the not-yet-implemented method 'GetClassRibbon'
		// Here lies the not-yet-implemented method 'GetNextEquipId'
		// Here lies the not-yet-implemented method 'GetEquipRibbon'
		// Here lies the not-yet-implemented method 'GetFirstEquipId'
		// Here lies the not-yet-implemented method 'GetDailyDealLootId'
		// Here lies the not-yet-implemented method 'RetrieveActives'
		// Here lies the not-yet-implemented method 'GetUpgradePrice'
		// Here lies the not-yet-implemented method 'RequestPurchaseReticule'
		// Here lies the not-yet-implemented method 'RequestPurchaseUpgrade'
		// Here lies the not-yet-implemented method 'SaveProfile'
		// Here lies the not-yet-implemented method 'InitEquipManager'
		// Here lies the not-yet-implemented method 'InitClassList'
	};
}
#undef ADD_VAR
