#pragma once
#include "GFxUI.GFxClikWidget.EventData.h"
#include "GFxUI.GFxObject.h"
namespace UnrealScript
{
	class GFxClikWidget : public GFxObject
	{
	public:
		void EventListener(EventData Data)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.EventListener");
			byte* params = (byte*)malloc(36);
			*(EventData*)params = Data;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void AddEventListener(ScriptName Type, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* Listener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.AddEventListener");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = Type;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 8) = Listener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		ScriptArray<wchar_t> GetEventStringFromTypename(ScriptName Typename)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.GetEventStringFromTypename");
			byte* params = (byte*)malloc(20);
			*(ScriptName*)params = Typename;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)(params + 8);
			free(params);
			return returnVal;
		}
		void SetListener(class GFxObject* O, ScriptArray<wchar_t> Member, 
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void* Listener)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.SetListener");
			byte* params = (byte*)malloc(28);
			*(class GFxObject**)params = O;
			*(ScriptArray<wchar_t>*)(params + 4) = Member;
			*(
// ERROR: Unknown object class 'Class Core.DelegateProperty'!
void**)(params + 16) = Listener;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASAddEventListener(ScriptArray<wchar_t> Type, class GFxObject* O, ScriptArray<wchar_t> func)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.ASAddEventListener");
			byte* params = (byte*)malloc(28);
			*(ScriptArray<wchar_t>*)params = Type;
			*(class GFxObject**)(params + 12) = O;
			*(ScriptArray<wchar_t>*)(params + 16) = func;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void RemoveAllEventListeners(ScriptArray<wchar_t> Event)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.RemoveAllEventListeners");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Event;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void ASRemoveAllEventListeners(ScriptArray<wchar_t> Event)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function GFxUI.GFxClikWidget.ASRemoveAllEventListeners");
			byte* params = (byte*)malloc(12);
			*(ScriptArray<wchar_t>*)params = Event;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
