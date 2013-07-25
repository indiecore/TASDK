#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_Main." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_Main : public GFxTrPage
	{
	public:
		ADD_VAR(::BoolProperty, bSwingingCamera, 0x1)
		ADD_VAR(::StrProperty, TabOffset, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, QueueTimer, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAnimInit, 0x2)
		ADD_VAR(::IntProperty, FeatureSwapTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, FeatureShowTime, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ActiveFeature, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, GoldDealId, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumQuit, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'Initialize'
		// Here lies the not-yet-implemented method 'SpecialAction'
		// Here lies the not-yet-implemented method 'TakeFocus'
		// Here lies the not-yet-implemented method 'CheckPricing'
		// Here lies the not-yet-implemented method 'FillPricing'
		// Here lies the not-yet-implemented method 'ModifyAction'
		// Here lies the not-yet-implemented method 'TakeAction'
		// Here lies the not-yet-implemented method 'FillData'
		// Here lies the not-yet-implemented method 'CheckFeatures'
		// Here lies the not-yet-implemented method 'FillFeature'
		// Here lies the not-yet-implemented method 'FormatDealTime'
		// Here lies the not-yet-implemented method 'FillOption'
		// Here lies the not-yet-implemented method 'ShowModel'
		// Here lies the not-yet-implemented method 'UpdateQueueTimer'
		// Here lies the not-yet-implemented method 'StartDealTimer'
		// Here lies the not-yet-implemented method 'UpdateDealTimer'
		// Here lies the not-yet-implemented method 'CheckGoldDeal'
		// Here lies the not-yet-implemented method 'NeedFeatureUpdate'
		// Here lies the not-yet-implemented method 'GetEquipTypeName'
	};
}
#undef ADD_VAR
