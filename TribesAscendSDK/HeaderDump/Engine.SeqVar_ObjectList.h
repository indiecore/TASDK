#pragma once
#include "Engine.SeqVar_Object.h"
#include "Core.Object.h"
namespace UnrealScript
{
	class SeqVar_ObjectList : public SeqVar_Object
	{
	public:
		class Object* GetObjectValue()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqVar_ObjectList.GetObjectValue");
			byte* params = (byte*)malloc(4);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(class Object**)params;
			free(params);
			return returnVal;
		}
		void SetObjectValue(class Object* NewValue)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.SeqVar_ObjectList.SetObjectValue");
			byte* params = (byte*)malloc(4);
			*(class Object**)params = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
