#pragma once
#include "GFxUI.GFxClikWidget.h"
#include "UTGame.GFxUDKFrontEnd_SettingsBase.h"
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
namespace UnrealScript
{
	class GFxUDKFrontEnd_ServerSettings : public GFxUDKFrontEnd_SettingsBase
	{
	public:
		ADD_BOOL(bDataChangedByReqs, 260, 0x1)
		void SetSelectedOptionSet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.SetSelectedOptionSet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnOptionChanged(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.OnOptionChanged");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SaveState()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.SaveState");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopulateOptionDataProviderForIndex(int Index, class GFxObject*& OutDataProvider, ScriptString*& OutDefaultValue, int& OutDefaultIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.PopulateOptionDataProviderForIndex");
			byte params[24] = { NULL };
			*(int*)&params[0] = Index;
			*(class GFxObject**)&params[4] = OutDataProvider;
			*(ScriptString**)&params[8] = OutDefaultValue;
			*(int*)&params[20] = OutDefaultIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutDataProvider = *(class GFxObject**)&params[4];
			OutDefaultValue = *(ScriptString**)&params[8];
			OutDefaultIndex = *(int*)&params[20];
		}
		ScriptString* FindControlByUTClassName(byte UTUIControlClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.FindControlByUTClassName");
			byte params[13] = { NULL };
			params[0] = UTUIControlClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[4];
		}
	};
}
#undef ADD_BOOL
