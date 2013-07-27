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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTitle(ScriptString* Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.SetTitle");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Title;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInfo(ScriptString* Info)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.SetInfo");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Info;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetButtonLabel(ScriptString* ButtonLabel)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.SetButtonLabel");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = ButtonLabel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.OnViewClosed");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_ErrorDialog.DisableSubComponents");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
