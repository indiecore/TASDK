#pragma once
#include "Engine.SequenceVariable.h"
#include "Core.Object.h"
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
	class SeqVar_Object : public SequenceVariable
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptClass*>, SupportedClasses, 164)
		ADD_STRUCT(Vector, ActorLocation, 152)
		ADD_OBJECT(Object, ObjValue, 148)
		class Object* GetObjectValue()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(9740);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(class Object**)params;
		}
		void SetObjectValue(class Object* NewValue)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26220);
			byte params[4] = { NULL };
			*(class Object**)params = NewValue;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
