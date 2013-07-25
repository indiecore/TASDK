#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
#include "GFxUI.GFxClikWidget.h"
#include "GFxUI.GFxObject.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_PasswordDialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_PasswordDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		ADD_OBJECT(GFxClikWidget, JoinBtn)
		ADD_OBJECT(GFxObject, PasswordTextField)
		ADD_OBJECT(GFxClikWidget, PasswordRendererMC)
		ScriptArray<wchar_t> GetPassword()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.GetPassword");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ClearPasswordRenderer()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.ClearPasswordRenderer");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.OnViewClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bEnableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bEnableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBackButtonListener(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DelegateListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.SetBackButtonListener");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DelegateListener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetOKButtonListener(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* DelegateListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.SetOKButtonListener");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = DelegateListener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_PasswordDialog.WidgetInitialized");
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
