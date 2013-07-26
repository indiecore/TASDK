#pragma once
#include "Core.Object.Vector.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty AnimNotify_Trails.TrailSocketSamplePoint." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class TrailSocketSamplePoint
	{
	public:
		ADD_STRUCT(::VectorProperty, Velocity, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, Position, 0xFFFFFFFF)
	};
}
#undef ADD_STRUCT
