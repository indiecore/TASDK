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
	class Path_AlongLine : public PathConstraint
	{
	public:
		ADD_STRUCT(Vector, Direction, 68)
		bool AlongLine(class Pawn* P, Vector Dir)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23956);
			byte params[20] = { NULL };
			*(class Pawn**)params = P;
			*(Vector*)&params[4] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(23961);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
