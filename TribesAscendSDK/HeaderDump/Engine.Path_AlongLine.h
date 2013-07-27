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
		ADD_STRUCT(Object::Vector, Direction, 68)
		bool AlongLine(class Pawn* P, Object::Vector Dir)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AlongLine.AlongLine");
			byte params[20] = { NULL };
			*(class Pawn**)&params[0] = P;
			*(Object::Vector*)&params[4] = Dir;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AlongLine.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
