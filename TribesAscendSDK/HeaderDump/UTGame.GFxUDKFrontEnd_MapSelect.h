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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.GetImageMarkupByMapName");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = InMapName;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.OnTopMostView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.DisableSubComponents");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnMapList_ValueChanged(ScriptString* InMapSelected, ScriptString* InMapImageSelected)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.OnMapList_ValueChanged");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = InMapSelected;
			*(ScriptString**)&params[12] = InMapImageSelected;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetList(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.SetList");
			byte params[4] = { NULL };
			*(class GFxObject**)&params[0] = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnListItemPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.OnListItemPress");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetMapFriendlyName(ScriptString* Map)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.GetMapFriendlyName");
			byte params[24] = { NULL };
			*(ScriptString**)&params[0] = Map;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[12];
		}
		void SetImgScroller(class GFxClikWidget* InImgScroller)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.SetImgScroller");
			byte params[4] = { NULL };
			*(class GFxClikWidget**)&params[0] = InImgScroller;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptName GetCurrentGameMode()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.GetCurrentGameMode");
			byte params[8] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptName*)&params[0];
		}
		void SetupMapCycle(ScriptString* SelectedMap)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.SetupMapCycle");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = SelectedMap;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetSelectedMap()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.GetSelectedMap");
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[0];
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_MapSelect.WidgetInitialized");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
