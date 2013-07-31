#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_InfoDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		void OnViewClosed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38349);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38350);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38352);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTitle(ScriptString* Title)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38354);
			byte params[12] = { NULL };
			*(ScriptString**)params = Title;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInfo(ScriptString* Info)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38356);
			byte params[12] = { NULL };
			*(ScriptString**)params = Info;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAcceptButtonLabel(ScriptString* Label)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38358);
			byte params[12] = { NULL };
			*(ScriptString**)params = Label;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetBackButtonLabel(ScriptString* Label)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38360);
			byte params[12] = { NULL };
			*(ScriptString**)params = Label;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetAcceptButton_OnPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* EventListener)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38362);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = EventListener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
