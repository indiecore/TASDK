#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
namespace UnrealScript
{
	class GFxUDKFrontEnd_ErrorDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38043);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTitle(ScriptString* Title)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38045);
			byte params[12] = { NULL };
			*(ScriptString**)params = Title;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetInfo(ScriptString* Info)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38047);
			byte params[12] = { NULL };
			*(ScriptString**)params = Info;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetButtonLabel(ScriptString* ButtonLabel)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38049);
			byte params[12] = { NULL };
			*(ScriptString**)params = ButtonLabel;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnViewClosed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38051);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38052);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
