#pragma once
#include "GFxUI__GFxObject.h"
#include "UTGame__GFxUDKFrontEnd_Screen.h"
#include "UTGame__UTUIDataStore_MenuItems.h"
#include "GFxUI__GFxClikWidget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_Mutators." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Mutators." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Mutators : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_VAR(::BoolProperty, bFirstUpdateAfterActivation, 0x1)
		ADD_OBJECT(GFxObject, ConfigListDataProvider)
		ADD_OBJECT(GFxClikWidget, ConfigListMC)
		ADD_OBJECT(GFxObject, ListDataProvider)
		ADD_OBJECT(GFxObject, MenuMC)
		ADD_OBJECT(GFxClikWidget, ListMC)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore)
		int GetNumEnabledMutators()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.GetNumEnabledMutators");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(int*)params;
			free(params);
			return returnVal;
		}
		ScriptArray<wchar_t> GetEnabledMutators()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.GetEnabledMutators");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.OnViewLoaded");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.OnViewActivated");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SortAllMutatorsBasedOnOfficialArray()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.SortAllMutatorsBasedOnOfficialArray");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayOpenAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.PlayOpenAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnListItemPress(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.OnListItemPress");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		byte FindMutatorIndexByClass(ScriptArray<wchar_t> MutatorClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.FindMutatorIndexByClass");
			byte* params = (byte*)malloc(13);
			*(ScriptArray<wchar_t>*)params = MutatorClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(params + 12);
			free(params);
			return returnVal;
		}
		void OnListChange(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.OnListChange");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.UpdateDescription");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateConfigListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.UpdateConfigListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMutatorEnabled(int MutatorId)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.SetMutatorEnabled");
			byte* params = (byte*)malloc(4);
			*(int*)params = MutatorId;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddMutatorAndFilterList(int NewMutator)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.AddMutatorAndFilterList");
			byte* params = (byte*)malloc(4);
			*(int*)params = NewMutator;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ApplyGameModeFilter()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.ApplyGameModeFilter");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsCurrentMutatorConfigurable()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.IsCurrentMutatorConfigurable");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)params;
			free(params);
			return returnVal;
		}
		void SetList(class GFxObject* List)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.SetList");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetConfigList(class GFxObject* ConfigList)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.SetConfigList");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = ConfigList;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Mutators.WidgetInitialized");
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
