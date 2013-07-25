#pragma once
#include "UTGame.GFxUDKFrontEnd_View.h"
#include "GFxUI.GFxClikWidget.h"
#include "GFxUI.GFxObject.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_Dialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Dialog : public GFxUDKFrontEnd_View
	{
	public:
		ADD_OBJECT(GFxClikWidget, AcceptBtn)
		ADD_OBJECT(GFxClikWidget, BackBtn)
		ADD_OBJECT(GFxObject, InfoTxt)
		ADD_OBJECT(GFxObject, TitleTxt)
		ADD_OBJECT(GFxObject, DialogMC)
		void AcceptDelegate(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.AcceptDelegate");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.OnViewClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PlayOpenAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.PlayOpenAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void PlayCloseAnimation()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.PlayCloseAnimation");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetBackButton(class GFxObject* InBackButton)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.SetBackButton");
			byte* params = (byte*)malloc(4);
			*(class GFxObject**)params = InBackButton;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBackButton_OnPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EventListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.SetBackButton_OnPress");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = EventListener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void Select_Back(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void* ev)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.Select_Back");
			byte* params = (byte*)malloc(36);
			*(
// WARNING: Unknown structure type 'ScriptStruct GFxUI.GFxClikWidget.EventData'!
void**)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_Dialog.WidgetInitialized");
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
#undef ADD_OBJECT
