#pragma once
#include "TribesGame.GFxTrPage.h"
#include "GFxUI.GFxObject.h"
#include "PlatformCommon.TgPlayerProfile.h"
#include "TribesGame.GFxTrAction.h"
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
	class GFxTrPage_VideoResolutionTypes : public GFxTrPage
	{
	public:
		ADD_STRUCT(ScriptArray<TgPlayerProfile::PropertyPair>, AllResolutions, 372)
		ADD_STRUCT(ScriptArray<GFxTrPage::ResolutionSet>, FourByThreeGroup, 384)
		ADD_STRUCT(ScriptArray<GFxTrPage::ResolutionSet>, SixteenByNineGroup, 396)
		ADD_STRUCT(ScriptArray<GFxTrPage::ResolutionSet>, SixteenbyTenGroup, 408)
		ADD_STRUCT(ScriptArray<GFxTrPage::ResolutionSet>, OtherGroup, 420)
		ADD_BOOL(bShowingSixteenbyTen, 368, 0x4)
		ADD_BOOL(bShowingSixteenByNine, 368, 0x2)
		ADD_BOOL(bShowingFourByThree, 368, 0x1)
		ADD_STRUCT(int, SixteenbyTen, 364)
		ADD_STRUCT(int, SixteenByNine, 360)
		ADD_STRUCT(int, FourByThree, 356)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoResolutionTypes.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoResolutionTypes.SpecialAction");
			byte params[4] = { NULL };
			*(class GFxTrAction**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoResolutionTypes.FillData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_VideoResolutionTypes.FillOption");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
