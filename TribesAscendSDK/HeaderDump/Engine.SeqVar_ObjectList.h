#pragma once
#include "Engine.SeqVar_Object.h"
#include "Core.Object.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class SeqVar_ObjectList : public SeqVar_Object
	{
	public:
		ADD_STRUCT(ScriptArray<class Object*>, ObjList, 176)
		class Object* GetObjectValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26237);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)params;
		}
		void SetObjectValue(class Object* NewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26239);
			byte params[4] = { NULL };
			*(class Object**)params = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
