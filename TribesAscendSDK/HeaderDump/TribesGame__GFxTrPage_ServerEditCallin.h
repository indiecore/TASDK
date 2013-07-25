#pragma once
#include "TribesGame__GFxTrPage.h"
#include "TribesGame__GFxTrAction.h"
#include "GFxUI__GFxObject.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.GFxTrPage_ServerEditCallin." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxTrPage_ServerEditCallin : public GFxTrPage
	{
	public:
		ADD_VAR(::IntProperty, CallinType, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bBoundsPopup, 0x2)
		ADD_VAR(::BoolProperty, bPopup, 0x1)
		ADD_VAR(::IntProperty, popupIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, BuildupIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, CooldownIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, PriceIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EnabledIndex, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, ORBNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SUPNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, TACNumber, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxBOunds, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MinBounds, 0xFFFFFFFF)
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.SpecialAction");
			byte* params = (byte*)malloc(4);
			*(class GFxTrAction**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.FillData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.FillOption");
			byte* params = (byte*)malloc(8);
			*(int*)params = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		void SetSubTitle(float val, class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.SetSubTitle");
			byte* params = (byte*)malloc(8);
			*(float*)params = val;
			*(class GFxObject**)(params + 4) = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.PopupData");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = Obj;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopupComplete(int Action, ScriptArray<wchar_t> TextInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.PopupComplete");
			byte* params = (byte*)malloc(16);
			*(int*)params = Action;
			*(ScriptArray<wchar_t>*)(params + 4) = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ShowBoundsError(int PropId, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.ShowBoundsError");
			byte* params = (byte*)malloc(8);
			*(int*)params = PropId;
			*(int*)(params + 4) = PropType;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.CheckDescription");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.FillDescription");
			byte* params = (byte*)malloc(8);
			*(class GFxObject**)params = DataList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class GFxObject**)(params + 4);
			free(params);
			return returnVal;
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerEditCallin.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
