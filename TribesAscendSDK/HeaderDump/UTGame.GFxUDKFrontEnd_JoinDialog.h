#pragma once
#include "UTGame.GFxUDKFrontEnd_Dialog.h"
#include "GFxUI.GFxClikWidget.h"
#include "Engine.OnlineGameSettings.h"
#include "GFxUI.GFxObject.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_JoinDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		ADD_OBJECT(GFxClikWidget, SpectateBtn, 180)
		ADD_OBJECT(GFxClikWidget, JoinBtn, 176)
		ADD_OBJECT(GFxClikWidget, MutatorListMC, 172)
		ADD_OBJECT(GFxClikWidget, ServerInfoListMC, 168)
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38377);
			byte params[4] = { NULL };
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38379);
			byte params[4] = { NULL };
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopulateServerInfo(class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38381);
			byte params[4] = { NULL };
			*(class OnlineGameSettings**)params = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetJoinButtonPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinButtonListener)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38401);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinButtonListener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectateButtonPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* SpectateButtonListener)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38403);
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = SpectateButtonListener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38405);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_OBJECT
