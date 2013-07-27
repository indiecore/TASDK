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
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.OnTopMostView");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.DisableSubComponents");
			byte params[4] = { NULL };
			*(bool*)&params[0] = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PopulateServerInfo(class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.PopulateServerInfo");
			byte params[4] = { NULL };
			*(class OnlineGameSettings**)&params[0] = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetJoinButtonPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinButtonListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.SetJoinButtonPress");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = JoinButtonListener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetSpectateButtonPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* SpectateButtonListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.SetSpectateButtonPress");
			byte params[12] = { NULL };
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[0] = SpectateButtonListener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.WidgetInitialized");
			byte params[24] = { NULL };
			*(ScriptName*)&params[0] = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_OBJECT
