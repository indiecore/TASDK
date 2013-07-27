#pragma once
#include "GFxUI.GFxObject.h"
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
	class GFxClikWidget : public GFxObject
	{
	public:
		class EventData
		{
		public:
			ADD_STRUCT(int, lastIndex, 32)
			ADD_STRUCT(int, Index, 28)
			ADD_STRUCT(int, Button, 24)
			ADD_STRUCT(int, mouseIndex, 20)
			ADD_STRUCT(int, Data, 16)
			ADD_STRUCT(ScriptString*, Type, 4)
			ADD_OBJECT(GFxObject, Target, 0)
		};
		void EventListener(GFxClikWidget::EventData Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.EventListener");
			byte params[36] = { NULL };
			*(GFxClikWidget::EventData*)&params[0] = Data;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void AddEventListener(ScriptName Type, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* Listener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.AddEventListener");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = Type;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[8] = Listener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		ScriptString* GetEventStringFromTypename(ScriptName Typename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.GetEventStringFromTypename");
			byte params[20] = { NULL };
			*(ScriptName*)&params[0] = Typename;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[8];
		}
		void SetListener(class GFxObject* O, ScriptString* Member, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* Listener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.SetListener");
			byte params[28] = { NULL };
			*(class GFxObject**)&params[0] = O;
			*(ScriptString**)&params[4] = Member;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)&params[16] = Listener;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASAddEventListener(ScriptString* Type, class GFxObject* O, ScriptString* func)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.ASAddEventListener");
			byte params[28] = { NULL };
			*(ScriptString**)&params[0] = Type;
			*(class GFxObject**)&params[12] = O;
			*(ScriptString**)&params[16] = func;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void RemoveAllEventListeners(ScriptString* Event)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.RemoveAllEventListeners");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Event;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ASRemoveAllEventListeners(ScriptString* Event)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.ASRemoveAllEventListeners");
			byte params[12] = { NULL };
			*(ScriptString**)&params[0] = Event;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
