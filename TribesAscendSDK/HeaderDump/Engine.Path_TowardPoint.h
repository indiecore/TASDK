#pragma once
#include "Engine.PathConstraint.h"
#include "Core.Object.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Path_TowardPoint : public PathConstraint
	{
	public:
		ADD_STRUCT(Vector, GoalPoint, 68)
		bool TowardPoint(class Pawn* P, Vector Point)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23992);
			byte params[20] = { NULL };
			*(class Pawn**)params = P;
			*(Vector*)&params[4] = Point;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23997);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
