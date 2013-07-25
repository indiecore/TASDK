#pragma once
#include "Engine__PathConstraint.h"
#include "Engine__Pawn.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Path_WithinTraversalDist." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_WithinTraversalDist : public PathConstraint
	{
	public:
		ADD_VAR(::FloatProperty, SoftStartPenalty, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bSoft, 0x1)
		ADD_VAR(::FloatProperty, MaxTraversalDist, 0xFFFFFFFF)
		// Here lies the not-yet-implemented method 'DontExceedMaxDist'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_VAR
