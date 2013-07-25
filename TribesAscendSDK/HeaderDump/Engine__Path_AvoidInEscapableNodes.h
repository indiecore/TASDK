#pragma once
#include "Engine__PathConstraint.h"
#include "Engine__Pawn.h"
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
		// Here lies the not-yet-implemented method 'CachePawnReacFlags'
		// Here lies the not-yet-implemented method 'DontGetStuck'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_VAR
