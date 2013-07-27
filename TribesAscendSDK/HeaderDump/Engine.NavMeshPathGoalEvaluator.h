#pragma once
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class NavMeshPathGoalEvaluator : public Object
	{
	public:
		struct BiasedGoalActor
		{
		public:
			ADD_STRUCT(int, ExtraCost, 4)
			ADD_OBJECT(Actor, Goal, 0)
		};
		ADD_STRUCT(int, NumNodesProcessed, 76)
		ADD_STRUCT(int, NumNodesThrownOut, 72)
		ADD_BOOL(bAlwaysCallEvaluateGoal, 68, 0x1)
		ADD_STRUCT(int, MaxPathVisits, 64)
		ADD_OBJECT(NavMeshPathGoalEvaluator, NextEvaluator, 60)
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20914);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptString* GetDumpString()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(20915);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
