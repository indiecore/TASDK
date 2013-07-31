#pragma once
#include "UTGame.GFxUDKFrontEnd_View.h"
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxClikWidget.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class GFxUDKFrontEnd_Screen : public GFxUDKFrontEnd_View
	{
	public:
		ADD_STRUCT(ScriptString*, CancelButtonImage, 208)
		ADD_STRUCT(ScriptString*, AcceptButtonImage, 196)
		ADD_STRUCT(ScriptString*, CancelButtonHelpText, 184)
		ADD_STRUCT(ScriptString*, AcceptButtonHelpText, 172)
		ADD_OBJECT(GFxObject, InfoTxt, 168)
		ADD_OBJECT(GFxObject, HelpTxt, 164)
		ADD_OBJECT(GFxObject, LogoMC, 160)
		ADD_OBJECT(GFxObject, FooterMC, 156)
		ADD_OBJECT(GFxObject, TitleMC, 152)
		ADD_OBJECT(GFxClikWidget, BackBtn, 148)
		ADD_STRUCT(ScriptString*, ViewTitle, 136)
		void FocusIn_BackButton(GFxClikWidget::EventData ev)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38130);
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)params = ev;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateHelpButtonImages()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38132);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool WidgetInitialized(ScriptName WidgetName, ScriptName WidgetPath, class GFxObject* Widget)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(38133);
			byte params[24] = { NULL };
			*(ScriptName*)params = WidgetName;
			*(ScriptName*)&params[8] = WidgetPath;
			*(class GFxObject**)&params[16] = Widget;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[20];
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
