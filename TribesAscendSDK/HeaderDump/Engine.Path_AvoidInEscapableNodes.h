#pragma once
#include "Engine.PathConstraint.h"
#include "Engine.Pawn.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class Path_AvoidInEscapableNodes : public PathConstraint
	{
	public:
		ADD_STRUCT(int, MoveFlags, 80)
		ADD_STRUCT(int, MaxFallSpeed, 76)
		ADD_STRUCT(int, Height, 72)
		ADD_STRUCT(int, Radius, 68)
		void CachePawnReacFlags(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AvoidInEscapableNodes.CachePawnReacFlags");
			byte params[4] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool DontGetStuck(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AvoidInEscapableNodes.DontGetStuck");
			byte params[8] = { NULL };
			*(class Pawn**)&params[0] = P;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[4];
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AvoidInEscapableNodes.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
