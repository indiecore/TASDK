#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_ErrorDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetTitle(ScriptArray<wchar_t> Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.SetTitle");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Title;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetInfo(ScriptArray<wchar_t> Info)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.SetInfo");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Info;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetButtonLabel(ScriptArray<wchar_t> ButtonLabel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.SetButtonLabel");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = ButtonLabel;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.OnViewClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
