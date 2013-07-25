#pragma once
#include "UTGame.GFxUDKFrontEnd_View.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " UTGame.GFxUDKFrontEnd_Screen." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Screen." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Screen : public GFxUDKFrontEnd_View
	{
	public:
		ADD_VAR(::StrProperty, CancelButtonImage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AcceptButtonImage, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, CancelButtonHelpText, 0xFFFFFFFF)
		ADD_VAR(::StrProperty, AcceptButtonHelpText, 0xFFFFFFFF)
		ADD_OBJECT(GFxObject, InfoTxt)
		ADD_OBJECT(GFxObject, HelpTxt)
		ADD_OBJECT(GFxObject, LogoMC)
		ADD_OBJECT(GFxObject, FooterMC)
		ADD_OBJECT(GFxObject, TitleMC)
		ADD_OBJECT(GFxClikWidget, BackBtn)
		ADD_VAR(::StrProperty, ViewTitle, 0xFFFFFFFF)
		void FocusIn_BackButton(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Screen.FocusIn_BackButton");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void UpdateHelpButtonImages()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Screen.UpdateHelpButtonImages");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Screen.WidgetInitialized");
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
