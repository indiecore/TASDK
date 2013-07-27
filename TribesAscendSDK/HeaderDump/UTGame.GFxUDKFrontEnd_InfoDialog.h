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
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.DisableSubComponents");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTitle(ScriptString* Title)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetTitle");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Title;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInfo(ScriptString* Info)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetInfo");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Info;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAcceptButtonLabel(ScriptString* Label)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetAcceptButtonLabel");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Label;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBackButtonLabel(ScriptString* Label)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetBackButtonLabel");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Label;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAcceptButton_OnPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EventListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_InfoDialog.SetAcceptButton_OnPress");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = EventListener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
