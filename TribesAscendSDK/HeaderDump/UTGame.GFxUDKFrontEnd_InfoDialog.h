#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_InfoDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		void OnViewClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.OnViewClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTitle(ScriptArray<wchar_t> Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetTitle");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Title;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetInfo(ScriptArray<wchar_t> Info)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetInfo");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Info;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAcceptButtonLabel(ScriptArray<wchar_t> Label)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetAcceptButtonLabel");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Label;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetBackButtonLabel(ScriptArray<wchar_t> Label)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetBackButtonLabel");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Label;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetAcceptButton_OnPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EventListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetAcceptButton_OnPress");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = EventListener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
