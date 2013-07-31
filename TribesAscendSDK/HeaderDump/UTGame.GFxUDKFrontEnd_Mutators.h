#pragma once
#include "UTGame.GFxUDKFrontEnd_Screen.h"
#include "UTGame.UTUIDataProvider_Mutator.h"
#include "UTGame.UTUIDataStore_MenuItems.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
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
	class GFxUDKFrontEnd_Mutators : public GFxUDKFrontEnd_Screen
	{
	public:
		ADD_STRUCT(ScriptArray<class UTUIDataProvider_Mutator*>, AllMutatorsList, 220)
		ADD_STRUCT(ScriptArray<class UTUIDataProvider_Mutator*>, AvailableMutatorList, 232)
		ADD_STRUCT(ScriptArray<int>, EnabledList, 248)
		ADD_BOOL(bFirstUpdateAfterActivation, 280, 0x1)
		ADD_OBJECT(GFxObject, ConfigListDataProvider, 276)
		ADD_OBJECT(GFxClikWidget, ConfigListMC, 272)
		ADD_OBJECT(GFxObject, ListDataProvider, 268)
		ADD_OBJECT(GFxObject, MenuMC, 264)
		ADD_OBJECT(GFxClikWidget, ListMC, 260)
		ADD_OBJECT(UTUIDataStore_MenuItems, MenuDataStore, 244)
		int GetNumEnabledMutators()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38261);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(int*)params;
		}
		ScriptString* GetEnabledMutators()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38338);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		void OnViewLoaded()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38856);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewActivated()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38857);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SortAllMutatorsBasedOnOfficialArray()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38861);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38868);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38870);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PlayOpenAnimation()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38872);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnListItemPress(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38873);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		byte FindMutatorIndexByClass(ScriptString* MutatorClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38878);
			byte params[13] = { NULL };
			*(ScriptString**)params = MutatorClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return params[12];
		}
		void OnListChange(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38882);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateDescription()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38884);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38889);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateConfigListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38900);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMutatorEnabled(int MutatorId)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38901);
			byte params[4] = { NULL };
			*(int*)params = MutatorId;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddMutatorAndFilterList(int NewMutator)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38903);
			byte params[4] = { NULL };
			*(int*)params = NewMutator;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ApplyGameModeFilter()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38922);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool IsCurrentMutatorConfigurable()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38927);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)params;
		}
		void SetList(class GFxObject* List)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38929);
			byte params[4] = { NULL };
			*(class GFxObject**)params = List;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetConfigList(class GFxObject* ConfigList)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38931);
			byte params[4] = { NULL };
			*(class GFxObject**)params = ConfigList;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38933);
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
