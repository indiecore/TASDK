#pragma once
#include "Engine.PathConstraint.h"
#include "Engine.Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Path_AvoidInEscapableNodes." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_AvoidInEscapableNodes : public PathConstraint
	{
	public:
		ADD_VAR(::IntProperty, MoveFlags, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, MaxFallSpeed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Height, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, Radius, 0xFFFFFFFF)
		void CachePawnReacFlags(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AvoidInEscapableNodes.CachePawnReacFlags");
			byte* params = (byte*)malloc(4);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		bool DontGetStuck(class Pawn* P)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AvoidInEscapableNodes.DontGetStuck");
			byte* params = (byte*)malloc(8);
			*(class Pawn**)params = P;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(bool*)(params + 4);
			free(params);
			return returnVal;
		}
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.Path_AvoidInEscapableNodes.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_VAR
