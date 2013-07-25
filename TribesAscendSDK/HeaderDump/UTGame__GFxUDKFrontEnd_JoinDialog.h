#pragma once
#include "GFxUI__GFxClikWidget.h"
#include "UTGame__GFxUDKFrontEnd_Dialog.h"
#include "Engine__OnlineGameSettings.h"
#include "GFxUI__GFxObject.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty UTGame.GFxUDKFrontEnd_JoinDialog." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_JoinDialog : public GFxUDKFrontEnd_Dialog
	{
	public:
		ADD_OBJECT(GFxClikWidget, SpectateBtn)
		ADD_OBJECT(GFxClikWidget, JoinBtn)
		ADD_OBJECT(GFxClikWidget, MutatorListMC)
		ADD_OBJECT(GFxClikWidget, ServerInfoListMC)
		void OnTopMostView(bool bPlayOpenAnimation)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.OnTopMostView");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bPlayOpenAnimation;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void DisableSubComponents(bool bDisableComponents)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.DisableSubComponents");
			byte* params = (byte*)malloc(4);
			*(bool*)params = bDisableComponents;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void PopulateServerInfo(class OnlineGameSettings* GameSettings)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.PopulateServerInfo");
			byte* params = (byte*)malloc(4);
			*(class OnlineGameSettings**)params = GameSettings;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetJoinButtonPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* JoinButtonListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.SetJoinButtonPress");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = JoinButtonListener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSpectateButtonPress(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* SpectateButtonListener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.SetSpectateButtonPress");
			byte* params = (byte*)malloc(12);
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)params = SpectateButtonListener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function UTGame.GFxUDKFrontEnd_JoinDialog.WidgetInitialized");
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
