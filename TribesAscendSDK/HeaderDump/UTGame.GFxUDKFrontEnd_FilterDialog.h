#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
#include "UTGame.UTDataStore_GameSearchDM.h"
#include "UTGame.UTUIDataStore_StringList.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_FilterDialog." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_FilterDialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_FilterDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		ADD_OBJECT(GFxObject, GameTypeOptionItem)
		ADD_OBJECT(GFxObject, DataProvider)
		ADD_VAR(::BoolProperty, bFiltersHaveChanged, 0x1)
		ADD_OBJECT(GFxClikWidget, FilterListMC)
		ADD_OBJECT(UTDataStore_GameSearchDM, SearchDataStore)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore)
		ADD_OBJECT(UTUIDataStore_StringList, StringListDataStore)
		void OnSwitchedGameType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.OnSwitchedGameType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.OnViewClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bEnableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBackButtonListener(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DelegateListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.SetBackButtonListener");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DelegateListener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ValidateServerType()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.ValidateServerType");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void ForceLANOption(int PlayerIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.ForceLANOption");
			byte* params = (byte*)malloc(4);
			*(int*)params = PlayerIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetGameClassByFriendlyName(ScriptArray<wchar_t> FriendlyName)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.GetGameClassByFriendlyName");
			byte* params = (byte*)malloc(24);
			*(ScriptArray<wchar_t>*)params = FriendlyName;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 12);
			free(params);
			return returnVal;
		}
		void OnFilterList_OptionChanged(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.OnFilterList_OptionChanged");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetupListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.SetupListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PushFilterListUpdate()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.PushFilterListUpdate");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_FilterDialog.WidgetInitialized");
			byte* params = (byte*)malloc(24);
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)(params + 8) = WidgetPath;
			*(class GFxObject**)(params + 16) = Widget;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 20);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT
