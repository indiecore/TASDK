#pragma once
#include "UTGame.GFxUDKFrontEnd_SettingsBase.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.EventData.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_ServerSettings." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_ServerSettings : public GFxUDKFrontEnd_SettingsBase
	{
	public:
		ADD_VAR(::BoolProperty, bDataChangedByReqs, 0x1)
		void SetSelectedOptionSet()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.SetSelectedOptionSet");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnOptionChanged(EventData ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.OnOptionChanged");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
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
		void PopulateOptionDataProviderForIndex(int Index, class GFxObject*& OutDataProvider, ScriptArray<wchar_t>& OutDefaultValue, int& OutDefaultIndex)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.PopulateOptionDataProviderForIndex");
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
		ScriptArray<wchar_t> FindControlByUTClassName(byte UTUIControlClass)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ServerSettings.FindControlByUTClassName");
			byte* params = (byte*)malloc(13);
			*params = UTUIControlClass;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 4);
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
