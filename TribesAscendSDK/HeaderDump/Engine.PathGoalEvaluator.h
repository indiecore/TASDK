#pragma once
#include "Core.Object.h"
#include "Engine.NavigationPoint.h"
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
	class PathGoalEvaluator : public Object
	{
	public:
		ADD_STRUCT(int, CacheIdx, 72)
		ADD_STRUCT(int, MaxPathVisits, 68)
		ADD_OBJECT(NavigationPoint, GeneratedGoal, 64)
		ADD_OBJECT(PathGoalEvaluator, NextEvaluator, 60)
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18164);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetDumpString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(18165);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
