#pragma once
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "UTGame.UTUIDataProvider_MapInfo.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
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
	class GFxUDKFrontEnd_MapSelect : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_STRUCT(ScriptArray<class UTUIDataProvider_MapInfo*>, MapList, 236)
		ADD_STRUCT(int, LastSelectedItem, 248)
		ADD_OBJECT(GFxObject, MenuMC, 232)
		ADD_OBJECT(GFxClikWidget, ImgScrollerMC, 228)
		ADD_OBJECT(GFxObject, ListDataProvider, 224)
		ADD_OBJECT(GFxClikWidget, ListMC, 220)
		ScriptString* GetImageMarkupByMapName(ScriptString* InMapName)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38166);
			byte params[24] = { NULL };
			*(ScriptString**)params = InMapName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38638);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38639);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38641);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMapList_ValueChanged(ScriptString* InMapSelected, ScriptString* InMapImageSelected)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38643);
			byte params[24] = { NULL };
			*(ScriptString**)params = InMapSelected;
			*(ScriptString**)&params[12] = InMapImageSelected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetList(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38646);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListItemPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38648);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38653);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetMapFriendlyName(ScriptString* Map)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38664);
			byte params[24] = { NULL };
			*(ScriptString**)params = Map;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void SetImgScroller(class GFxClikWidget* InImgScroller)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38665);
			byte params[4] = { NULL };
			*(class GFxClikWidget**)params = InImgScroller;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetCurrentGameMode()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38674);
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)params;
		}
		void SetupMapCycle(ScriptString* SelectedMap)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38780);
			byte params[12] = { NULL };
			*(ScriptString**)params = SelectedMap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSelectedMap()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38785);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38797);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
