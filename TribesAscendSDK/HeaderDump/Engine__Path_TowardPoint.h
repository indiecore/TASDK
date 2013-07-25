#pragma once
#include "Engine__PathConstraint.h"
#include "Engine__Pawn.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Path_TowardPoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_TowardPoint : public PathConstraint
	{
	public:
		ADD_STRUCT(::VectorProperty, GoalPoint, 0xFFFFFFFF
		// Here lies the not-yet-implemented method 'TowardPoint'
		// Here lies the not-yet-implemented method 'Recycle'
	};
}
#undef ADD_STRUCT
