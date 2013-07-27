#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
#include "UTGame.UTDataStore_GameSearchDM.h"
#include "UTGame.UTUIDataStore_StringList.h"
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
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_FilterDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		struct Option
		{
		public:
			ADD_STRUCT(ScriptArray<ScriptString*>, OptionData, 24)
			ADD_STRUCT(ScriptString*, OptionLabel, 12)
			ADD_STRUCT(ScriptString*, OptionName, 0)
		};
		ADD_STRUCT(ScriptArray<GFxUDKFrontEnd_FilterDialog::Option>, ListOptions, 196)
		ADD_OBJECT(GFxObject, GameTypeOptionItem, 192)
		ADD_OBJECT(GFxObject, DataProvider, 188)
		ADD_BOOL(bFiltersHaveChanged, 184, 0x1)
		ADD_OBJECT(GFxClikWidget, FilterListMC, 180)
		ADD_OBJECT(UTDataStore_GameSearchDM, SearchDataStore, 176)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore, 172)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore, 168)
		void OnSwitchedGameType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38059);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38074);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38075);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38077);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bEnableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38078);
			byte params[4] = { NULL };
			*(bool*)params = bEnableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBackButtonListener(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DelegateListener)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38080);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DelegateListener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ValidateServerType()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38082);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceLANOption(int PlayerIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38085);
			byte params[4] = { NULL };
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetGameClassByFriendlyName(ScriptString* FriendlyName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38089);
			byte params[24] = { NULL };
			*(ScriptString**)params = FriendlyName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void OnFilterList_OptionChanged(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38092);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetupListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38102);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushFilterListUpdate()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38111);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38112);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
