#pragma once
#include "Engine__PathConstraint.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Path_AlongLine." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class Path_AlongLine : public PathConstraint
	{
	public:
		ADD_STRUCT(::VectorProperty, Direction, 0xFFFFFFFF
	};
}
#undef ADD_STRUCT
