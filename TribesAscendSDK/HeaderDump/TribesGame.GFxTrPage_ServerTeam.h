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
	class GFxTrPage_ServerTeam : public GFxTrPage
	{
	public:
		ADD_BOOL(bBoundsPopup, 364, 0x8)
		ADD_BOOL(bPopupBaseDestPopup, 364, 0x4)
		ADD_BOOL(bDisparityPopup, 364, 0x2)
		ADD_BOOL(bMaxPlayerPopup, 364, 0x1)
		ADD_STRUCT(int, MaxBOunds, 360)
		ADD_STRUCT(int, MinBounds, 356)
		void Initialize()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.Initialize");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SpecialAction(class GFxTrAction* Action)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.SpecialAction");
			byte params[4] = { NULL };
			*(class GFxTrAction**)&params[0] = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupData(class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.PopupData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopupComplete(int Action, ScriptString* TextInput)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.PopupComplete");
			byte params[16] = { NULL };
			*(int*)&params[0] = Action;
			*(ScriptString**)&params[4] = TextInput;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ShowBoundsError(int PropId, int PropType)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.ShowBoundsError");
			byte params[8] = { NULL };
			*(int*)&params[0] = PropId;
			*(int*)&params[4] = PropType;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void FillData(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.FillData");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillOption(int ActionIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.FillOption");
			byte params[8] = { NULL };
			*(int*)&params[0] = ActionIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void SetSubTitle(float val, class GFxObject* Obj)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.SetSubTitle");
			byte params[8] = { NULL };
			*(float*)&params[0] = val;
			*(class GFxObject**)&params[4] = Obj;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void CheckDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.CheckDescription");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		class GFxObject* FillDescription(class GFxObject* DataList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.FillDescription");
			byte params[8] = { NULL };
			*(class GFxObject**)&params[0] = DataList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class GFxObject**)&params[4];
		}
		void ShowModel()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function TribesGame.GFxTrPage_ServerTeam.ShowModel");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
