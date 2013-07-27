#pragma once
#include "UTGame.GFxUDKFrontEnd_SettingsBase.h"
#include "GFxUI.GFxObject.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_Settings : public GFxUDKFrontEnd_SettingsBase
	{
	public:
		void SetSelectedOptionSet()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39065);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39066);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopulateOptionDataProviderForIndex(int Index, class GFxObject*& OutDataProvider, ScriptString*& OutDefaultValue, int& OutDefaultIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(39073);
			byte params[24] = { NULL };
			*(int*)params = Index;
			*(class GFxObject**)&params[4] = OutDataProvider;
			*(ScriptString**)&params[8] = OutDefaultValue;
			*(int*)&params[20] = OutDefaultIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			OutDataProvider = *(class GFxObject**)&params[4];
			OutDefaultValue = *(ScriptString**)&params[8];
			OutDefaultIndex = *(int*)&params[20];
		}
	};
}
