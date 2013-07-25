#pragma once
#include "UTGame__GFxUDKFrontEnd_SettingsBase.h"
#include "GFxUI__GFxObject.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_Settings : public GFxUDKFrontEnd_SettingsBase
	{
	public:
		void SetSelectedOptionSet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Settings.SetSelectedOptionSet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void UpdateListDataProvider()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Settings.UpdateListDataProvider");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PopulateOptionDataProviderForIndex(int Index, class GFxObject*& OutDataProvider, ScriptArray<wchar_t>& OutDefaultValue, int& OutDefaultIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Settings.PopulateOptionDataProviderForIndex");
			byte* params = (byte*)malloc(24);
			*(int*)params = Index;
			*(class GFxObject**)(params + 4) = OutDataProvider;
			*(ScriptArray<wchar_t>*)(params + 8) = OutDefaultValue;
			*(int*)(params + 20) = OutDefaultIndex;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			OutDataProvider = *(class GFxObject**)(params + 4);
			OutDefaultValue = *(ScriptArray<wchar_t>*)(params + 8);
			OutDefaultIndex = *(int*)(params + 20);
			free(params);
		}
	};
}
