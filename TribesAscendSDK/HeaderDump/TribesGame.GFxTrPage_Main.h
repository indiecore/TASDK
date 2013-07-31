#pragma once
#include "TribesGame.GFxTrPage.h"
#include "TribesGame.GFxTrAction.h"
#include "GFxUI.GFxObject.h"
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
namespace UnrealScript
{
	class GFxTrPage_Main : public GFxTrPage
	{
	public:
		enum EFEATURES : byte
		{
			FEA_GOLD = 0,
			FEA_DOTD = 1,
			FEA_BUNDLEA = 2,
			FEA_BUNDLEB = 3,
			FEA_BUNDLEC = 4,
			FEA_MAX = 5,
		};
		struct BundleData
		{
		public:
			ADD_STRUCT(TrObject::EContentDataType, Model, 4)
			ADD_STRUCT(int, LootId, 0)
		};
		ADD_BOOL(bSwingingCamera, 376, 0x1)
		ADD_STRUCT(ScriptArray<GFxTrPage_Main::BundleData>, ActiveBundles, 404)
		ADD_STRUCT(ScriptString*, TabOffset, 392)
		ADD_STRUCT(ScriptString*, QueueTimer, 380)
		ADD_BOOL(bAnimInit, 376, 0x2)
		ADD_STRUCT(int, FeatureSwapTime, 372)
		ADD_STRUCT(int, FeatureShowTime, 368)
		ADD_STRUCT(int, ActiveFeature, 364)
		ADD_STRUCT(int, GoldDealId, 360)
		ADD_STRUCT(int, NumQuit, 356)
		void Initialize()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59502);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59508);
			byte params[4] = { NULL };
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		int TakeFocus(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59511);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		bool CheckPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59515);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		class GFxObject* FillPricing(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59520);
			byte params[8] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		int ModifyAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59525);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		int TakeAction(int ActionIndex, class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59530);
			byte params[12] = { NULL };
			*(int*)params = ActionIndex;
			*(class GFxObject**)&params[4] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)&params[8];
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59534);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckFeatures(class GFxObject* DataList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59536);
			byte params[4] = { NULL };
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillFeature()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59540);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)params;
		}
		ScriptString* FormatDealTime()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59569);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59580);
			byte params[8] = { NULL };
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void ShowModel()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59595);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateQueueTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59602);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void StartDealTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59603);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateDealTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59605);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void CheckGoldDeal()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59607);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool NeedFeatureUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59611);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		ScriptString* GetEquipTypeName(int Type)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(59613);
			byte params[16] = { NULL };
			*(int*)params = Type;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
